#include "hwio.h"

/**
    * @brief be called to init hardware IO for led flashing on demo board
    * @date 2020 05 04 sunhaoyu
    * @param
    * @retval
**/
void Led_Config(void)
{
    GPIO_InitTypeDef GPIOcfg;
    GPIOcfg.GPIO_Pin = GPIO_Pin_12;
    GPIOcfg.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIOcfg.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIOcfg);
    //GPIO_ResetBits(GPIOB, GPIO_Pin_12);   //Low Out
    GPIO_SetBits(GPIOB, GPIO_Pin_12);       //High Out
}