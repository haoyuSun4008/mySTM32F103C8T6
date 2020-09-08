#include "hall.h"
#include "..\FWLib\stm32f10x_tim.h"
#include "..\FWLib\stm32f10x_gpio.h"

//IMPORTANT: Use Hall Code to Cite
static const std_HallSig_t BLDC_DRV_PHASES[8][6] = 
{
//      UH    |    UL    |    VH    |    VL     |    WH    |    WL     |      HallCode   |      MotorPhaseSeq
//=============================================================================================================
    {INACTIVE, INACTIVE,   INACTIVE, INACTIVE,   INACTIVE, INACTIVE},     //     0       |    //      0

    {INACTIVE, ACTIVE  ,   ACTIVE  , INACTIVE,   INACTIVE, INACTIVE},     //     1       |    //      2

    {INACTIVE, INACTIVE,   INACTIVE, ACTIVE  ,   ACTIVE  , INACTIVE},     //     2       |    //      4

    {INACTIVE, ACTIVE  ,   INACTIVE, INACTIVE,   ACTIVE  , INACTIVE},     //     3       |    //      3

    {ACTIVE  , INACTIVE,   INACTIVE, INACTIVE,   INACTIVE, ACTIVE  },     //     4       |    //      6

    {INACTIVE, INACTIVE,   ACTIVE  , INACTIVE,   INACTIVE, ACTIVE  },     //     5       |    //      1

    {ACTIVE  , INACTIVE,   INACTIVE, ACTIVE  ,   INACTIVE, INACTIVE},     //     6       |    //      5

    {INACTIVE, INACTIVE,   INACTIVE, INACTIVE,   INACTIVE, INACTIVE},     //     7       |    //      0
//=============================================================================================================
};

Motor_DrvState_t BLDC_Drv_State;

/**
 * @brief Used to config to capture Hall signals with TIM2
 *        Hall A Input ----> TIM2_CH1 ----> PA0
 *        Hall B Input ----> TIM2_CH2 ----> PA1
 *        Hall C Input ----> TIM2_CH3 ----> PA2
 * @param  None
 * @retval None
 * IMPORTANT:
 *      Supposed that my BLDC is with its Rated Speed 3000rpm
 *      Then, use one percentage of 3000 to be the longest period
 *      Between two changes of Hall Signal
 *      Due to 3 times of Hall Position change every rotation
 * */
void TIM2_Hall_init(void)
{
    //
    TIM_TimeBaseInitTypeDef hallTimeBaseTyp;
    TIM_ICInitTypeDef hallICTyp;
    TIM_OCInitTypeDef hallOCTyp;

    //STEP 1: config 3 inputs in TI1
    TIM_SelectHallSensor(TIM2, ENABLE);

    //STEP 2: config TIM2 counter freq 94KHz
    TIM_TimeBaseStructInit(&hallTimeBaseTyp);
    hallTimeBaseTyp.TIM_ClockDivision = TIM_CKD_DIV1;
    hallTimeBaseTyp.TIM_Prescaler     = 765;
    hallTimeBaseTyp.TIM_CounterMode   = TIM_CounterMode_Up;
    hallTimeBaseTyp.TIM_Period        = 0xFFFF;               //overflow 700ms
    TIM_TimeBaseInit(TIM1, &hallTimeBaseTyp);

    //HallSensor event is delivered with TI1FED
    TIM_SelectInputTrigger(TIM1, TIM_TS_TI1F_ED);

    //
    TIM_SelectSlaveMode(TIM2, TIM_SlaveMode_Reset);

    //STEP 3: config CH1 Input Capture
    TIM_ICStructInit(&hallICTyp);
    hallICTyp.TIM_ICPrescaler = TIM_ICPSC_DIV1;
    hallICTyp.TIM_ICPolarity  = TIM_ICPolarity_Rising;
    hallICTyp.TIM_ICSelection = TIM_ICSelection_TRC;
    hallICTyp.TIM_ICFilter    = 0x0F;
    hallICTyp.TIM_Channel     = TIM_Channel_1;
    TIM_ICInit(TIM2, &hallICTyp);

    //STEP 4: config CH2 Output Compare
    TIM_OCStructInit(&hallOCTyp);
    hallOCTyp.TIM_OCMode      = TIM_OCMode_PWM2;
    hallOCTyp.TIM_OutputState = TIM_OutputState_Enable;
    hallOCTyp.TIM_OCPolarity  = TIM_OCPolarity_High;
    hallOCTyp.TIM_Pulse       = 1;                        //no delay
    TIM_OC2Init(TIM2, &hallOCTyp);

    //STEP 5: Select OC2REF as TRGO Trigger Output
    TIM_SelectOutputTrigger(TIM2, TIM_TRGOSource_OC2Ref);

    //Ena CH2 compare interrupt request
    TIM_ClearFlag(TIM2, TIM_IT_CC1 | TIM_IT_CC2);
    TIM_ITConfig(TIM2, TIM_IT_CC1 | TIM_IT_CC2, ENABLE);
}

/**
 * @brief Used to control start and stop
 * @param STATE
 * @arg START or STOP
 * @retval None
 * */
void TIM2_Hall_func_ctrl(std_device_state_t STATE)
{
    //
    switch (STATE)
    {
        case START:
            TIM_Cmd(TIM2, ENABLE);
            break;
        case STOP:
            TIM_Cmd(TIM2, DISABLE);
            break;
        default:
            break;
    }
}

/**
 * @brief Used to read out Hall Code from PA0~3
 * @param Void
 * @retval HallCode
 * */
uint8_t TIM2_Hall_Code_get(void)
{
    //
    return (uint8_t)(GPIO_ReadInputData(GPIOA) & 0x0007);
}

/**
 * @brief Used to read out Hall Code from PA0~3
 * @param Void
 * @retval HallCode
 * */
void TIM1_PWM_Drive_State_resolve(void)
{
    //
    static uint8_t oldhallcode;
    static uint8_t hallcode;
    uint8_t newhallcode;
    newhallcode = TIM2_Hall_Code_get();

    if (newhallcode == hallcode)
    {
        return;
    }
    else
    {
        oldhallcode = hallcode;
        hallcode = newhallcode;
    }

    BLDC_Drv_State.UH = BLDC_DRV_PHASES[newhallcode][0];
    BLDC_Drv_State.UL = BLDC_DRV_PHASES[newhallcode][1];

    BLDC_Drv_State.VH = BLDC_DRV_PHASES[newhallcode][2];
    BLDC_Drv_State.VL = BLDC_DRV_PHASES[newhallcode][3];

    BLDC_Drv_State.WH = BLDC_DRV_PHASES[newhallcode][4];
    BLDC_Drv_State.WL = BLDC_DRV_PHASES[newhallcode][5];
}

/* EOF */
