#include "timer.h"

uint8_t os_tick = 0;

void Timer4_Config(void)
{
    TIM_TimeBaseInitTypeDef *TimCfgStruct;
    NVIC_InitTypeDef *IRQcfgStruct;
    //set basic param
    TimCfgStruct->TIM_ClockDivision = TIM_CKD_DIV1;
    TimCfgStruct->TIM_CounterMode = TIM_CounterMode_Up;
    TimCfgStruct->TIM_Period = 72-1;
    TimCfgStruct->TIM_Prescaler = 1000-1;
    TimCfgStruct->TIM_RepetitionCounter = 0;
    //set IRQ param
    IRQcfgStruct->NVIC_IRQChannel = TIM4_IRQn;
    IRQcfgStruct->NVIC_IRQChannelPreemptionPriority = 0;
    IRQcfgStruct->NVIC_IRQChannelSubPriority = 3;
    IRQcfgStruct->NVIC_IRQChannelCmd = ENABLE;
    //config clock
    //TIM_InternalClockConfig(TIM4);
    //config TIM4
    TIM_TimeBaseInit(TIM4, TimCfgStruct);
    //clear IRQ flag
    TIM_ClearFlag(TIM4, TIM_FLAG_Update);
    //config TIM4 Update Interrupt
    TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
    //config IRQ
    NVIC_Init(IRQcfgStruct);
    //enable TIM4
    TIM_Cmd(TIM4, ENABLE);
}

void TIM4_IRQHandler(void)
{
    if (TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET)
    {
        TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
        os_tick++;
        os_tick %= 0xff;
    }
}

/** @defgroup Based on 72Mhz default clock
 *  @brief 1:18ms
 *  @param ms 0~65535
 **/
void delay(uint16_t ms)
{
    uint16_t t;
    ms *= 2;
    for(; ms > 0; ms--)
    {
        t = 0x9C40;//36000;
        while((t--) > 0);
    }
}