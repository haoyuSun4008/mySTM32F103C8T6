#include "timer.h"

/**
 * @brief init a 1ms Timer to generate schedule by TIM4
 * */
void TIM4_timer_init(void)
{
    TIM_TimeBaseInitTypeDef TimerStruct;
    
    TimerStruct.TIM_ClockDivision = TIM_CKD_DIV1;
    TimerStruct.TIM_CounterMode = TIM_CounterMode_Up;
    TimerStruct.TIM_Period = 71;
    TimerStruct.TIM_Prescaler = 999;
    TIM_TimeBaseInit(TIM4, &TimerStruct);
    TIM_ClearFlag(TIM4, TIM_IT_Update);
    TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);

    //Enable TIM4
    TIM_Cmd(TIM4, ENABLE);
}

/*EOF*/
