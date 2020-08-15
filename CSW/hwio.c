#include "..\MCAL\stm32f10x_gpio.h"
#include "hwio.h"

/**
 * @brief config Hardware IO
 **/
void hwio_init(void)
{
    /* for led Module */
    GPIO_InitTypeDef* led2;
    
    /* for CAN1 Module */
    GPIO_InitTypeDef* canTx;
    GPIO_InitTypeDef* canRx;

    led2->GPIO_Pin = GPIO_Pin_12;
    led2->GPIO_Mode = GPIO_Mode_Out_PP;
    led2->GPIO_Speed = GPIO_Speed_50MHz;

    //2020/08/14 enter HardFault
    GPIO_Init(GPIOB, led2);
    
    //GPIO_ResetBits(GPIOB, GPIO_Pin_12);   //Low Out
    GPIO_SetBits(GPIOB, GPIO_Pin_12);       //High Out
    
    canTx->GPIO_Pin = GPIO_Pin_11;
    canRx->GPIO_Pin = GPIO_Pin_12;
    canTx->GPIO_Mode = GPIO_Mode_IPU;
    canRx->GPIO_Mode = GPIO_Mode_AF_PP;
    canTx->GPIO_Speed = GPIO_Speed_50MHz;
    canRx->GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, canTx);
    GPIO_Init(GPIOA, canRx);
}