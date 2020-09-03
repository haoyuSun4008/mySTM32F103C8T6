#include "interrupt.h"

/**
 * @brief all interrupt init there
 * */
void Interrupt_init(void)
{
    //creat a cfgstruct
    NVIC_InitTypeDef NvicStruct;

    //set group 2
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    
    /* TIM4_IRQn Setting Start */
    NvicStruct.NVIC_IRQChannel = TIM4_IRQn;
    NvicStruct.NVIC_IRQChannelPreemptionPriority = 0;
    NvicStruct.NVIC_IRQChannelSubPriority = 3;
    NvicStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NvicStruct);
    /* TIM4_IRQn Setting End */
}

/**
 * @brief 1ms IRQ by TIM4
 **/
void TIM4_IRQHandler(void)
{
    if (TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET)
    {
        TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
        os_tick();
    }
}
/*EOF*/
