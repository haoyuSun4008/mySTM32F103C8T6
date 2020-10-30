#include "usart.h"
#include "..\FWLib\misc.h"
#include "..\FWLib\stm32f10x_usart.h"
#include "..\FWLib\stm32f10x_rcc.h"
#include "..\FWLib\stm32f10x_gpio.h"

#if (_USART_DEBUG_FUNC_ON_)
const double _x_step_ = 0.01;
const double  _x_limt_ = 10;
#endif

void Usart_Init(void)
{
    //
    USART_InitTypeDef USART_InitType;
    GPIO_InitTypeDef GPIO_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

#if (_USART1_FUNC_ON_)
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
#elif (_USART2_FUNC_ON_)
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
#endif

#if (_USART1_FUNC_ON_)
    /* USART1 TX Config Start */
    GPIO_StructInit(&GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    /* USART1 TX Config Start */
    /* USART1 RX Config Start */
    //GPIO_StructInit(&GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
    //GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    /* USART1 RX Config Start */
#elif (_USART2_FUNC_ON_)
    /* USART2 TX Config Start */
    GPIO_StructInit(&GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    /* USART2 TX Config Start */
    /* USART2 RX Config Start */
    //GPIO_StructInit(&GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    //GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    /* USART2 RX Config Start */
#endif

    USART_InitType.USART_BaudRate = 115200;
    USART_InitType.USART_WordLength = USART_WordLength_8b;
    USART_InitType.USART_StopBits = USART_StopBits_1;
    USART_InitType.USART_Parity = USART_Parity_No;
    USART_InitType.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitType.USART_Mode = (USART_Mode_Rx | USART_Mode_Tx);

#if (_USART1_FUNC_ON_)
    USART_Init(USART1, &USART_InitType);

    NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);

    USART_Cmd(USART1, ENABLE);
#elif (_USART2_FUNC_ON_)
    USART_Init(USART2, &USART_InitType);  

    NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);

    USART_Cmd(USART2, ENABLE);
#endif
}

void Usart_SendByte(uint8_t ch)
{
    //
#if (_USART1_FUNC_ON_)
    USART_SendData(USART1, ch);

    // wait sendbuffer empty then return
    while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
#elif (_USART2_FUNC_ON_)
    USART_SendData(USART2, ch);

    // wait buffer empty then return
    while (USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET);
#endif
}

#if (_USART_DEBUG_FUNC_ON_)
/**
 * @brief send ASCII code every 1s
 * IMPORTANT: debug ok
 * */
void USART_SendAscii(void)
{
    static uint8_t cnt;
    static uint8_t ch = 0x21;
    static uint8_t space_flg;
    cnt++;
    if (cnt == 100)
    {
        cnt = 0;
        space_flg = ~space_flg;
        if (space_flg)
            Usart_SendByte(ch++);
        else
            Usart_SendByte(0x20);
        if (ch > 0x7F)
        {
            ch = 0x21;
        }
    }
}

/**
 * @brief send a string by USART
 * IMPORTANT: debug ok
 * */
void USART_SendString(char* str)
{
    uint8_t i = 0;
	while( *(str + i) != '\0' )
	{
		Usart_SendByte( *(str + i) );
        i++;
	}
#if (_USART1_FUNC_ON_)
    // wait sendbuffer empty then return
    while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
#elif (_USART2_FUNC_ON_)
    // wait sendbuffer empty then return
    while (USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);
#endif
}
#endif

/**
 * @brief send sine wave data
 * IMPORTANT: no debug
 * */
#include "math.h"
#include "stdio.h"
void USART_SendSine(void)
{
    char ystr[7], xstr[7];
    static NON_INT_DATA_t x, y;
    
    y.s64dat = sin(x.s64dat);
    x.s64dat += _x_step_;
    sprintf(ystr, "%3.3f", y.s64dat);
    sprintf(xstr, "%3.3f", x.s64dat);

    USART_SendString(xstr);
    // SPACE
    Usart_SendByte(0x20);
    USART_SendString(ystr);
    // add ENTER
    USART_SendString("\n");

    if (x.s64dat >= _x_limt_)
    {
        x.s64dat = 0;
    }
}
//DEBUG FUNC OVER

#if (_USART1_FUNC_ON_)
/**
 * @brief USART1 receive data by IT
 * IMPORTANT: no debug
 * */
void USART1_IRQHandler(void)
{
    uint8_t chTemp;
    if (USART_GetITStatus(USART1,USART_IT_RXNE) != RESET)
    {
        chTemp = USART_ReceiveData(USART1);
#if (_USART_DEBUG_FUNC_ON_)
        USART_SendData(USART1, chTemp);
#endif
    }
}
#elif (_USART2_FUNC_ON_)
/**
 * @brief USART2 receive data by IT
 * IMPORTANT: debug ok
 * */
void USART2_IRQHandler(void)
{
    uint8_t chTemp;
    if (USART_GetITStatus(USART2,USART_IT_RXNE) != RESET)
    {
        chTemp = USART_ReceiveData(USART2);
#if (_USART_DEBUG_FUNC_ON_)
        USART_SendData(USART2, chTemp);
#endif
    }
}
#endif

/* EOF */
