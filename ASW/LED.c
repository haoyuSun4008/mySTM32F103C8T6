#include "..\MCAL\stm32f10x_gpio.h"
#include "LED.h"

uint16_t debug_LED_flashing_cnt = 0;

void LED_IO_init(void)
{
    GPIOB->CRL = 0x04448444;
    GPIOB->CRH = 0x04433444;
    GPIOB->BSRR = GPIO_Pin_12;
}

//placed at 10ms proc
void LED_flashing(void)
{
    static uint8_t flg;
    static uint16_t t;
	  t++;
	  if(t == 50)
	  {
        if(flg == 0)
        {
            /* led off */
            //GPIO_WriteBit( GPIOB, GPIO_Pin_12, Bit_SET );
            //GPIO_SetBits(GPIOB, GPIO_Pin_All);
            GPIOB->BSRR = GPIO_Pin_12;
            debug_LED_flashing_cnt++;
        }
        else
        {
            /* led on */
            //GPIO_WriteBit( GPIOB, GPIO_Pin_12, Bit_RESET );
            //GPIO_ResetBits(GPIOB, GPIO_Pin_All);
            GPIOB->BRR = GPIO_Pin_12;
        }
        flg = ~flg;
        t = 0;
    }
}