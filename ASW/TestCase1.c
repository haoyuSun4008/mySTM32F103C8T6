#include "TestCase1.h"
#include "..\MCAL\stm32f10x_gpio.h"

#define Every_1000ms (100U)

void led2_flashing(void)
{
    static uint16_t cnt;
    cnt++;
    cnt %= 5000;
    if ( (cnt%Every_1000ms)%2 == 1 )
    {
        /* led on */
        GPIO_WriteBit( GPIOB, GPIO_Pin_12, Bit_SET );
    }
    else
    {
        /* led off */
        GPIO_WriteBit( GPIOB, GPIO_Pin_12, Bit_RESET );
    }
}

void led2_flashing_test(void)
{
    static uint8_t flg = 0;
    if ( flg == 0 )
    {
        /* led on */
        //GPIO_WriteBit( GPIOB, GPIO_Pin_12, Bit_SET );
        GPIO_SetBits(GPIOB, GPIO_Pin_All);
    }
    else
    {
        /* led off */
        //GPIO_WriteBit( GPIOB, GPIO_Pin_12, Bit_RESET );
        GPIO_ResetBits(GPIOB, GPIO_Pin_All);
    }
    flg = ~flg;
}
