#include "..\FWLib\stm32f10x_gpio.h"
#include "hwio.h"

/**
 * @brief config Hardware IO
 **/
void hwio_init(void)
{
    //Creat GPIO_InitStructure
    GPIO_InitTypeDef GPIO_InitStructure;

    //Set GPIO_InitStructure to Default
    GPIO_StructInit(&GPIO_InitStructure);
    
    /* CAN1 IO Config Start */
    /* CanRx = PA11 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    /* CanTx = PA12 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    /* CAN1 IO Config End */
    
    /* TimingPorts IO Config Start */
    /* TimingPorts = PA0~3 */
    GPIO_StructInit(&GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = (GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3);
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    /* TimingPorts IO Config End */
    
    /* LED IO Config Start */
    /* Led2 = PB12*/
    GPIO_StructInit(&GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    //GPIO_SetBits(GPIOB, GPIO_Pin_12);
    GPIO_ResetBits(GPIOB, GPIO_Pin_12);
    /* LED IO Config End */

    /* TIM1 PWM IO Config Start */
    // PA8~10 for TIM1_CH1~3
    GPIO_StructInit(&GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = (/*GPIO_Pin_8 | */GPIO_Pin_9 | GPIO_Pin_10);
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    // PB13~15 for TIM1_CH1~3N
    GPIO_InitStructure.GPIO_Pin = (GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    /* TIM1 PWM IO Config End */
}
/*EOF*/
