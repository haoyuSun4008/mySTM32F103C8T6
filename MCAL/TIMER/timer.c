#include "timer.h"
#include "..\FWLib\misc.h"
#include "..\FWLib\stm32f10x_rcc.h"
#include "..\FWLib\stm32f10x_tim.h"

/**
 * @brief init a 1ms Timer to generate schedule by TIM4
 * */
void TIM4_timer_init(void)
{
    TIM_TimeBaseInitTypeDef TimerStruct;
    NVIC_InitTypeDef       NVIC_InitStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
    
    TimerStruct.TIM_ClockDivision = TIM_CKD_DIV1;
    TimerStruct.TIM_CounterMode = TIM_CounterMode_Up;
    TimerStruct.TIM_Period = 71;
    TimerStruct.TIM_Prescaler = 999;
    TIM_TimeBaseInit(TIM4, &TimerStruct);
    
    /* TIM4_IRQn Setting Start */
    NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    /* TIM4_IRQn Setting End */
#if 0
    /* TIM2_IRQn Setting Start */
    NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    /* TIM2_IRQn Setting End */

    /* TIM1_TRG_COM_IRQn Setting Start */
    NVIC_InitStructure.NVIC_IRQChannel = TIM1_TRG_COM_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    /* TIM1_TRG_COM_IRQn Setting End */

#if (BLDC_EmergencyStop_ENABLE)
    /* TIM1_BRK_IRQn Setting Start */
    NVIC_InitStructure.NVIC_IRQChannel = TIM1_BRK_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    /* TIM1_BRK_IRQn Setting End */
#endif

#endif

    TIM_ClearFlag(TIM4, TIM_IT_Update);

    TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
    
    TIM_Cmd(TIM4, ENABLE);
}

/**
 * @brief 1ms IRQ by TIM4
 **/
extern void os_tick(void);
void TIM4_IRQHandler(void)
{
    if (TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET)
    {
        TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
        //ISR Write Below
        os_tick();
    }
}
/*EOF*/
