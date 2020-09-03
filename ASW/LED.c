#include "..\MCAL\FWLib\stm32f10x_gpio.h"
#include "LED.h"

uint16_t debug_LED_flashing_cnt = 0;

//placed at 10ms proc
void LED_flashing(void)
{
    static uint8_t flg;
    static uint16_t t;
	t++;
	if(t == 50)
	{
        if(flg)
        {
            /* led off */
            GPIO_SetBits(GPIOB, GPIO_Pin_12);
            debug_LED_flashing_cnt++;
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
