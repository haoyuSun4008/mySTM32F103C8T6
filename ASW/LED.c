#include "..\MCAL\FWLib\stm32f10x_gpio.h"
#include "LED.h"

//placed at 10ms proc
void LED_flashing(void)
{
    static uint8_t flg;
    static uint8_t t;
	t++;
	if(t == 50)
	{
        if(flg)
        {
            /* led off */
            GPIO_SetBits(GPIOB, GPIO_Pin_12);
        }
        else
        {
            /* led on */
            GPIO_ResetBits(GPIOB, GPIO_Pin_12);
        }
        flg = ~flg;
        t = 0;
    }
}
/*EOF*/
