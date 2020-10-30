#include ".\can.h"
#include "..\FWLib\misc.h"
#include "..\FWLib\stm32f10x_can.h"
#include "..\FWLib\stm32f10x_rcc.h"
#include "..\FWLib\stm32f10x_gpio.h"

/**
 * @brief Test CAN Func
 **/
void CAN_init(void)
{
    CAN_InitTypeDef        CAN_InitStructure;
    CAN_FilterInitTypeDef  CAN_FilterInitStructure;
    GPIO_InitTypeDef       GPIO_InitStructure;
    NVIC_InitTypeDef       NVIC_InitStructure;

#if (_CAN1_FUNC_ON_)
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE);
#elif (_CAN2_FUNC_ON_)
    RCC_APB2PeriphClockCmd(RCC_APB1Periph_CAN2, ENABLE);
#endif
    
    GPIO_StructInit(&GPIO_InitStructure);    
    /* CAN1 IO Config Start */
    /* CanRx = PA11 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    /* CanTx = PA12 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    /* CAN1 IO Config End */

    /* Enable CAN1 RX0 interrupt IRQ channel */
#if (_CAN_INT_RX_FUNC_ON_)
    NVIC_InitStructure.NVIC_IRQChannel = USB_LP_CAN1_RX0_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
#endif

    /* Set to Default */
#if (_CAN1_FUNC_ON_)
    CAN_DeInit(CAN1);
#elif (_CAN2_FUNC_ON_)
    CAN_DeInit(CAN2);
#endif
    CAN_StructInit(&CAN_InitStructure);
    CAN_InitStructure.CAN_TTCM = DISABLE;
    CAN_InitStructure.CAN_ABOM = ENABLE;
    CAN_InitStructure.CAN_AWUM = DISABLE;
    CAN_InitStructure.CAN_NART = DISABLE;
    CAN_InitStructure.CAN_RFLM = DISABLE;
    CAN_InitStructure.CAN_TXFP = ENABLE;
    //CAN_InitStructure.CAN_Mode = CAN_Mode_Normal;
    CAN_InitStructure.CAN_Mode = CAN_Mode_LoopBack;

#if (_CAN_BAUDRATE_250_ON_)
    CAN_InitStructure.CAN_SJW = CAN_SJW_1tq;
    CAN_InitStructure.CAN_BS1 = CAN_BS1_9tq;
    CAN_InitStructure.CAN_BS2 = CAN_BS2_8tq;
    CAN_InitStructure.CAN_Prescaler = 4;
#elif (_CAN_BAUDRATE_500_ON_)
    CAN_InitStructure.CAN_SJW = CAN_SJW_1tq;
    CAN_InitStructure.CAN_BS1 = CAN_BS1_9tq;
    CAN_InitStructure.CAN_BS2 = CAN_BS2_8tq;
    CAN_InitStructure.CAN_Prescaler = 4;
#endif

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
#if (_CAN_INT_RX_FUNC_ON_)
#if (_CAN1_FUNC_ON_)
    CAN_Init(CAN1, &CAN_InitStructure);
    CAN_ITConfig(CAN1, CAN_IT_FMP0, ENABLE);
#elif (_CAN2_FUNC_ON_)
    CAN_Init(CAN2, &CAN_InitStructure);
    CAN_ITConfig(CAN2, CAN_IT_FMP0, ENABLE);
#endif
#endif
}

/**
 * @brief send a COM data
 * IMPORTANT: no debug
 * */
void com_send(uint32_t id, uint8_t *dat, uint8_t dlc)
{
    CanTxMsg txbuf;
    uint8_t i;
    uint8_t INDEX = 0xff;

    for (i=0; i < 8; i++)
    {
        txbuf.Data[i] = *(dat + i);
    }

    /* check id belongs to COM signal */
    for (i = 0; i < _CAN_COM_ID_NUM_; i++)
    {
        while (id == CAN_ID_LIST[i]);
        INDEX = i;
    }
    txbuf.DLC = dlc;
    txbuf.StdId = CAN_ID_LIST[INDEX];
    txbuf.IDE = CAN_Id_Standard;
    txbuf.RTR = CAN_RTR_Data;

#if (_CAN1_FUNC_ON_)
    CAN_Transmit(CAN1, &txbuf);
#elif (_CAN2_FUNC_ON_)
    CAN_Transmit(CAN2, &txbuf);
#endif
}

/**
 * @brief send a CCP data
 * IMPORTANT: no debug
 * */
void ccp_send(uint32_t id, uint8_t *dat, uint8_t dlc)
{
    CanTxMsg txbuf;
    uint8_t i;
    uint8_t INDEX = 0xff;

    for (i=0; i < 8; i++)
    {
        txbuf.Data[i] = *(dat + i);
    }

    /* check id belongs to COM signal */
    for (i = _CAN_COM_ID_NUM_; i < _CAN_COM_ID_NUM_; i++)
    {
        while (id == CAN_ID_LIST[i]);
        INDEX = i;
    }
    txbuf.DLC = dlc;
    txbuf.StdId = CAN_ID_LIST[INDEX];
    txbuf.IDE = CAN_Id_Standard;
    txbuf.RTR = CAN_RTR_Data;

#if (_CAN1_FUNC_ON_)
    CAN_Transmit(CAN1, &txbuf);
#elif (_CAN2_FUNC_ON_)
    CAN_Transmit(CAN2, &txbuf);
#endif
}

/**
 * @brief receive data by IT
 * IMPORTANT: no debug
 * */
#if (_CAN_INT_RX_FUNC_ON_)

#endif

/**
 * @brief send a data for debug
 * IMPORTANT: no debug
 * */
#if (_CAN_DEBUGE_FUNC_ON_)
void CAN_debug(void)
{
    uint16_t temp;
    uint8_t data[8];
    temp = ADC1_Temperature_sample();
    data[0] = (uint8_t)(temp / 100);    // Temperature integer part
    data[1] = (uint8_t)(temp % 100);    // Temperature fraction part
    data[2] = 0;
    data[3] = 0;
    data[4] = 0;
    data[5] = 0;
    data[6] = 0;
    data[7] = 0;

#if (_CAN1_FUNC_ON_)
    com_send(0x94, data, 8);
#elif (_CAN2_FUNC_ON_)
    CAN_Transmit(CAN2, &debug);
#endif
}

#endif
/*EOF*/
