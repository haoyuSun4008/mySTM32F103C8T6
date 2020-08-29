#include "..\MCAL\stm32f10x_tim.h"
#include "interrupt.h"
#include "timer.h"

void timer4_init(void)
{
    TIM_TimeBaseInitTypeDef TimerStruct;
    NVIC_InitTypeDef NvicStruct;
    
    TimerStruct.TIM_ClockDivision = TIM_CKD_DIV1;
    TimerStruct.TIM_CounterMode = TIM_CounterMode_Up;
    TimerStruct.TIM_Period = 71;
    TimerStruct.TIM_Prescaler = 999;
    TIM_TimeBaseInit(TIM4, &TimerStruct);
    TIM_ClearFlag(TIM4, TIM_IT_Update);
    TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
    
    NvicStruct.NVIC_IRQChannel = TIM4_IRQn;
    NvicStruct.NVIC_IRQChannelPreemptionPriority = 0;
    NvicStruct.NVIC_IRQChannelSubPriority = 3;
    NvicStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NvicStruct);

    //Enable TIM4
    TIM_Cmd(TIM4, ENABLE);
}

/**
 * @brief 1ms IRQ
 **/
#include "..\BSW\os.h"
void TIM4_IRQHandler(void)
{
    if (TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET)
    {
        TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
        os_tick();
    }
}
/*EOF*/
