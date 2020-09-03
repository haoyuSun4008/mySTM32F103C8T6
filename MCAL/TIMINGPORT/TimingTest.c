#include "TimingTest.h"
#include "..\FWLib\stm32f10x_gpio.h"

#define PWM_PORT_TEST   (0U)

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
#if (PWM_PORT_TEST)
    GPIOA->BRR = GPIO_Pin_8;
    __NOP();
    GPIOA->BRR = GPIO_Pin_9;
    __NOP();
    GPIOA->BRR = GPIO_Pin_10;
    __NOP();
    GPIOB->BRR = GPIO_Pin_13;
    __NOP();
    GPIOB->BRR = GPIO_Pin_14;
    __NOP();
    GPIOB->BRR = GPIO_Pin_15;
#endif
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
#if (PWM_PORT_TEST)
    GPIOA->BSRR = GPIO_Pin_8;
    __NOP();
    GPIOA->BSRR = GPIO_Pin_9;
    __NOP();
    GPIOA->BSRR = GPIO_Pin_10;
    __NOP();
    GPIOB->BSRR = GPIO_Pin_13;
    __NOP();
    GPIOB->BSRR = GPIO_Pin_14;
    __NOP();
    GPIOB->BSRR = GPIO_Pin_15;
#endif
}
/*EOF*/
