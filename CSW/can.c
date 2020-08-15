#include "..\MCAL\stm32f10x_gpio.h"
#include "..\MCAL\stm32f10x_can.h"
#include "..\MCAL\misc.h"
#include "can.h"
#include "std_err.h"
#define CAN_MSG_STD_FRAME_FLG (1U)
#define CAN_Rx0_INT_ENABLE    (0U)

/**
 * @brief init CAN module
 **/
void CAN_init(void)
{
    //
    GPIO_InitTypeDef* CAN_GPIO_Struct;
    CAN_InitTypeDef* CAN_Struct;
    CAN_FilterInitTypeDef* CAN_Filter_Struct;
    #if (CAN_Rx0_INT_ENABLE)
    NVIC_InitTypeDef* CAN_NVIC_Struct;
    #endif

    /* RCC Setting in clock.c/h */
    /* IO  Setting in hwio.c/h */

    //CAN setup 1
    CAN_Struct->CAN_TTCM = DISABLE; //Non Time Trigger
    CAN_Struct->CAN_ABOM = DISABLE; //Sw Auto Offline Gover
    CAN_Struct->CAN_AWUM = DISABLE; //Wakeup by Sw
    CAN_Struct->CAN_NART = ENABLE;  //No Msg Auto Transmit
    CAN_Struct->CAN_RFLM = DISABLE; //No Msg Lock
    CAN_Struct->CAN_TXFP = DISABLE; //Priority by ID
    //CAN_Struct->CAN_Mode = CAN_Mode_LoopBack;
    CAN_Struct->CAN_Mode = CAN_Mode_Normal;
    CAN_Struct->CAN_SJW = CAN_SJW_1tq;
    CAN_Struct->CAN_BS1 = CAN_BS1_9tq;
    CAN_Struct->CAN_BS2 = CAN_BS2_8tq;
    CAN_Struct->CAN_Prescaler = 4;   
    CAN_Init(CAN1, CAN_Struct);

    CAN_Filter_Struct->CAN_FilterNumber = 0;
    CAN_Filter_Struct->CAN_FilterMode = CAN_FilterMode_IdMask;
    CAN_Filter_Struct->CAN_FilterScale = CAN_FilterScale_32bit;
    CAN_Filter_Struct->CAN_FilterIdHigh = 0x0000;
    CAN_Filter_Struct->CAN_FilterIdLow = 0x0000;
    CAN_Filter_Struct->CAN_FilterMaskIdHigh = 0x0000;
    CAN_Filter_Struct->CAN_FilterMaskIdLow = 0x0000;
    CAN_Filter_Struct->CAN_FilterFIFOAssignment = CAN_Filter_FIFO0;
    CAN_Filter_Struct->CAN_FilterActivation = ENABLE;
    CAN_FilterInit(CAN_Filter_Struct);

    #if (CAN_Rx0_INT_ENABLE)
    CAN_ITConfig(CAN1, CAN_IT_FMP0, ENABLE);
    CAN_NVIC_Struct->NVIC_IRQChannel = USB_LP_CAN1_RX0_IRQn;
    CAN_NVIC_Struct->NVIC_IRQChannelPreemptionPriority = 1;
    CAN_NVIC_Struct->NVIC_IRQChannelSubPriority = 0;
    CAN_NVIC_Struct->NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(CAN_NVIC_Struct);
    #endif
}

/**
 * @brief Send Msg 
 **/
std_err_t can_msg_send(CanTxMsg* tempTxMsg)
{
    //
    uint8_t mbox = 0, i = 0;
    mbox = CAN_Transmit(CAN1, tempTxMsg);
    while((CAN_TransmitStatus(CAN1, mbox) != CAN_TxStatus_Ok) && (i < 0xfff))
    {
        i++;
    }
    if (i >= 0xfff) 
    {
        return ErrNotOk;
    }
    else
    {
        return ErrOk;
    }
}

/**
 * @brief Check and Return Msg 
 **/
std_err_t can_msg_receive(CanRxMsg* tempRxMsg)
{
    //
    if (CAN_MessagePending(CAN1, CAN_FIFO0) == 0) return ErrNotOk;
    CAN_Receive(CAN1, CAN_FIFO0, tempRxMsg);
    return ErrOk;
}

/**
 * @brief CAN MSG RECEIVE IRQ
 **/
#if (CAN_Rx0_INT_ENABLE)
void USB_LP_CAN1_RX0_IRQHandler(void)
{
    //
    CanRxMsg* RxMsg;
    int8_t i = 0;
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