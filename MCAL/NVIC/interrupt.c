#include "interrupt.h"
#include "..\CAN\can.h"

/**
 * @brief all interrupt init there
 * */
void Interrupt_config(void)
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
    
    /* TIM2_IRQn Setting Start */
    NvicStruct.NVIC_IRQChannel = TIM2_IRQn;
    NvicStruct.NVIC_IRQChannelPreemptionPriority = 1;
    NvicStruct.NVIC_IRQChannelSubPriority = 1;
    NvicStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NvicStruct);
    /* TIM2_IRQn Setting End */

    /* TIM1_TRG_COM_IRQn Setting Start */
    NvicStruct.NVIC_IRQChannel = TIM1_TRG_COM_IRQn;
    NvicStruct.NVIC_IRQChannelPreemptionPriority = 1;
    NvicStruct.NVIC_IRQChannelSubPriority = 0;
    NvicStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NvicStruct);
    /* TIM1_TRG_COM_IRQn Setting End */

#if (BLDC_EmergencyStop_ENABLE)
    /* TIM1_BRK_IRQn Setting Start */
    NvicStruct.NVIC_IRQChannel = TIM1_BRK_IRQn;
    NvicStruct.NVIC_IRQChannelPreemptionPriority = 1;
    NvicStruct.NVIC_IRQChannelSubPriority = 2;
    NvicStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NvicStruct);
    /* TIM1_BRK_IRQn Setting End */
#endif
}

/**
 * @brief Handle with Hall COM Event
 **/
void TIM1_TRG_COM_IRQHandler(void)
{
    if (TIM_GetITStatus(TIM1, TIM_IT_COM) != RESET)
    {
        TIM_ClearITPendingBit(TIM4, TIM_IT_COM);
        //ISR Write Below
    }
}

/**
 * @brief Handle with TIM2 Hall Edge Trigger Event
 **/
void TIM2_IRQHandler(void)
{
    if (TIM_GetITStatus(TIM2, TIM_IT_CC1) != RESET)
    {
        TIM_ClearITPendingBit(TIM2, TIM_IT_CC1);
        //ISR Write Below
        //calculate MtrSpeed
    }

    // Enters This Branch after Motor Commutation Event Over
    // Prepares for the Next Drive State
    else if (TIM_GetITStatus(TIM2, TIM_IT_CC2) != RESET)
    {
        TIM_ClearITPendingBit(TIM2, TIM_IT_CC1);
        //ISR Write Below
        //BLDC_Next_Drive_State_Prepare();
    }
    else
    {
        /* dead code */
    }    
}

/**
 * @brief 1ms IRQ by TIM4
 **/
void TIM4_IRQHandler(void)
{
    if (TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET)
    {
        TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
        //ISR Write Below
        os_tick();
    }
}

/**
 * @brief CAN MSG RECEIVE IRQ
 **/
#if (CAN_RX0_INT_ENABLE)
void USB_LP_CAN1_RX0_IRQHandler(void)
{
    //
    CanRxMsg* RxMsg;
    CAN_Receive(CAN1, 0, RxMsg);
}
#endif

/**
 * @brief CAN MSG SEND IRQ
 **/
void USB_HP_CAN1_TX_IRQHandler(void)
{
    //
}

/**
 * @brief CAN MSG SEND IRQ
 **/
void CAN1_RX1_IRQHandler(void)
{
    //
}

/**
 * @brief CAN MSG SEND IRQ
 **/
void CAN1_SCE_IRQHandler(void)
{
    //
}

#if 0
static inline void BLDC_Next_Drive_State_Prepare(void)
{
    //
}
#endif
/*EOF*/
