#include "..\MCAL\stm32f10x_gpio.h"
#include "interrupt.h"
#include "can.h"

#define BaudRate_250Kbps        (0U)
#define BaudRate_500Kbps        (1U)
#define CAN_RX0_INT_ENABLE      (1U)

void CAN1_NVIC_init(void);

/**
 * @brief Test CAN Func
 **/
void CAN1_init(void)
{
    //
    //NVIC_InitTypeDef* CanType1;
    uint32_t i = 0;

    //CanType1->NVIC_IRQChannel = USB_LP_CAN1_RX0_IRQn;
    //CanType1->NVIC_IRQChannelPreemptionPriority = 1;
    //CanType1->NVIC_IRQChannelSubPriority = 0;

    /* RCC Setting in clock.c/h */

    //CAN io init
    //GPIOA->Pin11  CANRx
    //GPIOA->Pin12  CANTx
    GPIOA->CRL = 0x44444444||0x44444444;
    GPIOA->CRH = 0x88848444||0x888B8444;

    //Basic CAN init
    CAN1->MCR = 0x0000;           //stop sleep mode, clear all setting
    CAN1->MCR |= 1<<0;            //request to enter init mode
    while((CAN1->MSR & (1 << 0)) == 0)
    {
        i++;
        if(i > 100) return;       //failed to enter init mode
    }
    CAN1->MCR |= (0 << 7);        //Not time-triggered communicaton mode
    CAN1->MCR |= (0 << 6);        //software auto offline gover
    CAN1->MCR |= (0 << 5);        //software wakeup sleep mode
    CAN1->MCR |= (1 << 4);        //stop msg auto transfer
    CAN1->MCR |= (0 << 3);        //stop msg lock, new msg cover the old
    CAN1->MCR |= (0 << 2);        //the prior up to the msg ID
    CAN1->BTR |= 0X00000000;
    //CAN1->BTR |= (0 << 30);        //Normal Mode
    CAN1->BTR |= (1 << 30);        //Loop Mode for Debug

#if BaudRate_250Kbps
    CAN1->BTR |= (1 << 24);        //Tsjw=1+1 time-unit
    CAN1->BTR |= (8 << 20);        //Tbs2=8+1 time-unit
    CAN1->BTR |= (9 << 20);        //Tbs1=9+1 time-unit
    CAN1->BTR |= (8 << 0);         //Fdiv=4+1
    //BuradRate = Fpclk/(8+9+1)/8 = 36000Kbps/18/8 = 250Kbps
#endif

#if BaudRate_500Kbps
    CAN1->BTR |= (1 << 24);        //Tsjw=1+1 time-unit
    CAN1->BTR |= (8 << 20);        //Tbs2=8+1 time-unit
    CAN1->BTR |= (9 << 20);        //Tbs1=9+1 time-unit
    CAN1->BTR |= (4 << 0);         //Fdiv=4+1
    //BuradRate = Fpclk/(8+9+1)/4 = 36000Kbps/18/4 = 500Kbps
#endif

    CAN1->MCR &= ~(1 << 0);        //request to exit init mode
    while((CAN1->MSR & (1 << 0)) == 1)
    {
        i++;
        if(i > 0xFFF0) return;     //failed to exit init mode
    }

    //CAN filter0 init
    CAN1->FMR |= (1 << 0);         //filter group in init mode
    CAN1->FA1R &= ~(1 << 0);       //filtr 0 not activated
    CAN1->FS1R |= (1 << 0);        //filter select 32bit
    CAN1->FM1R |= (0 << 0);        //filter 0 in flg masked mode
    CAN1->FFA1R |= (0 << 0);       //filter 0 linked to FIFO 0
    CAN1->sFilterRegister[0].FR1 = 0x00000000;    //32bit ID
    CAN1->sFilterRegister[0].FR2 = 0x00000000;    //32bit MASK
    CAN1->FA1R |= (1 << 0);        //filter 0 activated
    CAN1->FMR &= (0 << 0);         //filter group in normal mode

#if CAN_RX0_INT_ENABLE             //use INT to receive
    CAN1->IER |= (1 << 1);         //enable FIFO 0 msg registered INT
    CAN1_NVIC_init();
#endif
}

#if 1
/**
 * @brief rewrite the NVIC_init()
 * */ 
void CAN1_NVIC_init(void)
{
    uint32_t tmppriority = 0x00, tmppre = 0x00, tmpsub = 0x0F;
    //CanType1->NVIC_IRQChannel = ENABLE;

    /* Compute the Corresponding IRQ Priority --------------------------------*/    
    tmppriority = (0x700 - ((SCB->AIRCR) & (uint32_t)0x700))>> 0x08;
    tmppre = (0x4 - tmppriority);
    tmpsub = tmpsub >> tmppriority;

    tmppriority = (uint32_t)1 << tmppre;
    tmppriority |=  0 & tmpsub;
    tmppriority = tmppriority << 0x04;

    NVIC->IP[USB_LP_CAN1_RX0_IRQn] = tmppriority;

    /* Enable the Selected IRQ Channels --------------------------------------*/
    NVIC->ISER[USB_LP_CAN1_RX0_IRQn >> 0x05] =
      (uint32_t)0x01 << (USB_LP_CAN1_RX0_IRQn & (uint8_t)0x1F);
}
#endif

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