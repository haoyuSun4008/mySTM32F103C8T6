#include "..\MCAL\stm32f10x_gpio.h"
#include "interrupt.h"
#include "can.h"

#define BaudRate_250Kbps        (0U)
#define BaudRate_500Kbps        (1U)
#define CAN_RX0_INT_ENABLE      (0U)

/**
 * @brief Test CAN Func
 **/
void CAN1_init(void)
{
    CAN_InitTypeDef        CAN_InitStructure;
    CAN_FilterInitTypeDef  CAN_FilterInitStructure;

    /* Enable CAN1 RX0 interrupt IRQ channel */
    #if (CAN_RX0_INT_ENABLE)
    NVIC_InitTypeDef       NVIC_InitStructure;
    NVIC_InitStructure.NVIC_IRQChannel = USB_LP_CAN1_RX0_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    #endif

    /* Set to Default */
    CAN_DeInit(CAN1);
    CAN_StructInit(&CAN_InitStructure);

    /* CAN Regs Init */
    CAN_InitStructure.CAN_TTCM = DISABLE;
    CAN_InitStructure.CAN_ABOM = ENABLE;
    CAN_InitStructure.CAN_AWUM = DISABLE;
    CAN_InitStructure.CAN_NART = DISABLE;
    CAN_InitStructure.CAN_RFLM = DISABLE;
    CAN_InitStructure.CAN_TXFP = ENABLE;
    CAN_InitStructure.CAN_Mode = CAN_Mode_Normal;

    #if (BaudRate_500Kbps)
    CAN_InitStructure.CAN_SJW = CAN_SJW_1tq;
    CAN_InitStructure.CAN_BS1 = CAN_BS1_9tq;
    CAN_InitStructure.CAN_BS2 = CAN_BS2_8tq;
    CAN_InitStructure.CAN_Prescaler = 4;
    #endif

    if (CAN_Init(CAN1,&CAN_InitStructure) == CANINITFAILED)
    {
       //Can Init Failure Handler
    }
    /* CAN Filter Init */
    CAN_FilterInitStructure.CAN_FilterNumber = 0;
    CAN_FilterInitStructure.CAN_FilterMode = CAN_FilterMode_IdMask;
    CAN_FilterInitStructure.CAN_FilterScale = CAN_FilterScale_32bit;
    CAN_FilterInitStructure.CAN_FilterIdHigh = 0x0000;
    CAN_FilterInitStructure.CAN_FilterIdLow = 0x0000;
    CAN_FilterInitStructure.CAN_FilterMaskIdHigh = 0x0000;
    CAN_FilterInitStructure.CAN_FilterMaskIdLow = 0x0000;
    CAN_FilterInitStructure.CAN_FilterFIFOAssignment = CAN_Filter_FIFO0;
    CAN_FilterInitStructure.CAN_FilterActivation = ENABLE;
    CAN_FilterInit(&CAN_FilterInitStructure);

    /* Enable CAN Rx Interrupt */
    CAN_ITConfig(CAN1,CAN_IT_FMP0, ENABLE);
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
/*EOF*/
