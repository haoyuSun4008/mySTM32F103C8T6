#include "PWM.h"
#include "..\FWLib\stm32f10x_tim.h"

#define DEFAULT_TEST_PULSE   (20U)
#define PWM_CH1_Ena          (1U)
#define PWM_CH2_Ena          (1U)
#define PWM_CH3_Ena          (1U)

/**
 * @brief init 6 PWM Outputs with TIM1
 *        PWM 1 Output ----> TIM1_CH1N ----> PB13
 *        PWM 2 Output ----> TIM1_CH2N ----> PB14
 *        PWM 3 Output ----> TIM1_CH3N ----> PB15
 *        PWM 4 Output ----> TIM1_CH1  ----> PA8
 *        PWM 5 Output ----> TIM1_CH2  ----> PA9
 *        PWM 6 Output ----> TIM1_CH3  ----> PA10
 * IMPORTANT: TIMx_CHyN outputs inverted waveform to TIMx_CHy.
 * */
void TIM1_PWM_init(void)
{
    //
    TIM_TimeBaseInitTypeDef pwmTimeBaseTyp;
    TIM_BDTRInitTypeDef pwmBDTRTyp;
    TIM_OCInitTypeDef pwmOCTyp;

    //config TIM1 10KHz
    TIM_TimeBaseStructInit(&pwmTimeBaseTyp);
    pwmTimeBaseTyp.TIM_ClockDivision = TIM_CKD_DIV1;
    pwmTimeBaseTyp.TIM_CounterMode   = TIM_CounterMode_Up;
    pwmTimeBaseTyp.TIM_Period        = 99;
    pwmTimeBaseTyp.TIM_Prescaler     = 71;
    TIM_TimeBaseInit(TIM1, &pwmTimeBaseTyp);

    //common config
    TIM_OCStructInit(&pwmOCTyp);
    pwmOCTyp.TIM_OCMode       = TIM_OCMode_PWM1;

    pwmOCTyp.TIM_OutputState  = TIM_OutputState_Enable;     //Ena Postive Channel PA8~10
    pwmOCTyp.TIM_OutputNState = TIM_OutputNState_Enable;     //Ena Negetive Channel PB13~15

    pwmOCTyp.TIM_OCPolarity   = TIM_OCPolarity_High;
    pwmOCTyp.TIM_OCNPolarity  = TIM_OCNPolarity_High;

    pwmOCTyp.TIM_OCIdleState  = TIM_OCIdleState_Set;
    pwmOCTyp.TIM_OCNIdleState = TIM_OCNIdleState_Reset;

    pwmOCTyp.TIM_Pulse        = (DEFAULT_TEST_PULSE);

#if (PWM_CH1_Ena)
    //config TIM1_CH1 and TIM1_CH1N
    TIM_OC1Init(TIM1, &pwmOCTyp);
    TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);
#endif

#if (PWM_CH2_Ena)
    //config TIM1_CH2 and TIM1_CH2N
    pwmOCTyp.TIM_Pulse        = (DEFAULT_TEST_PULSE)*2;
    TIM_OC2Init(TIM1, &pwmOCTyp);
    TIM_OC2PreloadConfig(TIM1, TIM_OCPreload_Enable);
#endif

#if (PWM_CH3_Ena)
    //config TIM1_CH3 and TIM1_CH3N
    pwmOCTyp.TIM_Pulse        = (DEFAULT_TEST_PULSE)*3;
    TIM_OC3Init(TIM1, &pwmOCTyp);
    TIM_OC3PreloadConfig(TIM1, TIM_OCPreload_Enable);
#endif

    //config Break and DeadTime
    TIM_BDTRStructInit(&pwmBDTRTyp);
    pwmBDTRTyp.TIM_AutomaticOutput = TIM_AutomaticOutput_Enable;
    pwmBDTRTyp.TIM_Break           = TIM_Break_Disable;
    pwmBDTRTyp.TIM_BreakPolarity   = TIM_BreakPolarity_Low;
    pwmBDTRTyp.TIM_DeadTime        = 0x00;
    pwmBDTRTyp.TIM_LOCKLevel       = TIM_LOCKLevel_OFF;
    pwmBDTRTyp.TIM_OSSIState       = TIM_OSSIState_Enable;
    pwmBDTRTyp.TIM_OSSRState       = TIM_OSSRState_Enable;
    TIM_BDTRConfig(TIM1, &pwmBDTRTyp);
    
    //config the connection between
    //TIM1 (Motor Drive Timer) and TIM2 (Hall Detect Timer)
    TIM_SelectCOM(TIM1, ENABLE);

    TIM_ARRPreloadConfig(TIM1, ENABLE);
    TIM_CCPreloadControl(TIM1, ENABLE);

    //allow PWM
    TIM_CtrlPWMOutputs(TIM1, ENABLE);

    //config TIM2 To TIM1 Trigger Source
    TIM_SelectInputTrigger(TIM1, TIM_TS_ITR1);

    //config COM Event
    TIM_ITConfig(TIM1, TIM_IT_COM, ENABLE);
    TIM_ClearFlag(TIM1, TIM_FLAG_COM);
}

/**
 * @brief Used to control start and stop
 * @param STATE
 * @arg START or STOP
 * @retval Void
 * */
void TIM1_PWM_func_ctrl(std_device_state_t STATE)
{
    //
    switch (STATE)
    {
        case START:
            TIM_Cmd(TIM1, ENABLE);
            break;
        case STOP:
            TIM_Cmd(TIM1, DISABLE);
            break;
        default:
            break;
    }
}

/**
 * @brief Used to set the pulse width for a PWM channel
 * @param PORT    ranges from 1 to 4
 * @param PULSE   ranges from 0 to 100
 * */
void TIM1_PWM_duty_set(motor_drv_port_t PORT, uint16_t PULSE)
{
    //
    switch (PORT)
    {
        case UH:
            TIM_SetCompare1(TIM1, PULSE);
            break;
        case VH:
            TIM_SetCompare2(TIM1, PULSE);
            break;
        case WH:
            TIM_SetCompare3(TIM1, PULSE);
            break;
        default:
            break;
    }
}


/**
 * @brief Used to TEST the func:
 * void TIM1_PWM_duty_set(motor_drv_port_t port, uint16_t pulse)
 * */
void TIM1_PWM_duty_test(void)
{
    //  TEST START
    static uint16_t PULSE = 10;
#if (PWM_CH1_Ena)
    TIM1_PWM_duty_set(UH, PULSE);
#endif
#if (PWM_CH2_Ena)
    TIM1_PWM_duty_set(VH, PULSE);
#endif
#if (PWM_CH3_Ena)
    TIM1_PWM_duty_set(WH, PULSE);
#endif

    PULSE %= 90;
    PULSE += 10;
}
/* EOF */
