#include "..\FWLib\stm32f10x_gpio.h"
#include "..\FWLib\stm32f10x_rcc.h"
#include "hwio.h"

void hwio_func_init(void);
void hwio_clock_init(void);

/**
 * @brief init MCU Ports
 * IMPORTANT:
 * */
void hwio_init(void)
{
    hwio_clock_init();
    hwio_func_init();
}

/**
 * @brief init MCU Ports Func
 * IMPORTANT:
 * */
void hwio_func_init(void)
{
    //Creat GPIO_InitStructure
    GPIO_InitTypeDef GPIO_InitStructure;

    //Set GPIO_InitStructure to Default
    GPIO_StructInit(&GPIO_InitStructure);
    
    /* TimingPorts IO Config Start */
    /* TimingPorts = P3 */
    //GPIO_StructInit(&GPIO_InitStructure);
    //GPIO_InitStructure.GPIO_Pin = (/*GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3*/);
    //GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    //GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    //GPIO_Init(GPIOA, &GPIO_InitStructure);
    /* TimingPorts IO Config End */
    
    /* LED IO Config Start */
    /* Led2 = PB12*/
    GPIO_StructInit(&GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    // 
    GPIO_SetBits(GPIOB, GPIO_Pin_12);
    /* LED IO Config End */
#if 0
    /* TIM1 PWM IO Config Start */
    // PA8~10 for TIM1_CH1~3
    GPIO_StructInit(&GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = (GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10);
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    // PB13~15 for TIM1_CH1~3N
    GPIO_InitStructure.GPIO_Pin = (GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    /* TIM1 PWM IO Config End */

    /* TIM2 Hall IO Config Start */
    // PA0~2 mapping to TIM2_CH1~3 for Hall A-B-C
    GPIO_StructInit(&GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = (GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2);
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    /* TIM2 Hall IO Config End */

    /* IR2136 ENA IO Config Start */
    /* Led2 = PB12*/
    GPIO_StructInit(&GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    // disable by default
    GPIO_SetBits(GPIOB, GPIO_Pin_12);
    /* IR2136 ENA IO Config End */
#endif
}

/**
 * @brief init MCU Ports Clock
 * IMPORTANT:
 * */
void hwio_clock_init(void)
{
    /* GPIO Clock Open */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
}

/**
 * @brief toggle led state whether prg dead ?
 * IMPORTANT: no debug
 * */
void os_led_toggle(void)
{
    static uint8_t flg;
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
}
/*EOF*/
