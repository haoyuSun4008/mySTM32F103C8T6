#include "TimingTest.h"
#include "..\MCAL\stm32f10x_gpio.h"

/**
 * @brief init IO for PA0 PA1 PA2 PA3
 * */
void TimingTest_IO_init(void)
{
    //PA0~3 TimingTest Ports
    GPIOA->CRL = 0x00000001;
    GPIOA->CRH = 0x00003333;
    GPIOA->BRR = (GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3);
}

/**
 * @brief pull down port
 * */
void TimingTest_SetLow(uint8_t flg)
{
    switch (flg)
    {
        case 0:
            GPIOA->BRR = GPIO_Pin_0;
            break;
        case 1:
            GPIOA->BRR = GPIO_Pin_1;
            break;
        case 2:
            GPIOA->BRR = GPIO_Pin_2;
            break;
        case 3:
            GPIOA->BRR = GPIO_Pin_3;
            break;    
        default:
            break;
    }
}

/**
 * @brief pull up port
 * */
void TimingTest_SetHigh(uint8_t flg)
{
    switch (flg)
    {
        case 0:
            GPIOA->BSRR = GPIO_Pin_0;
            break;
        case 1:
            GPIOA->BSRR = GPIO_Pin_1;
            break;
        case 2:
            GPIOA->BSRR = GPIO_Pin_2;
            break;
        case 3:
            GPIOA->BSRR = GPIO_Pin_3;
            break;
        default:
            break;
    }
}