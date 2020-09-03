#include "..\FWLib\stm32f10x_rcc.h"
#include "..\FWLib\misc.h"
#include "clock.h"

/**
  * @brief System Clock Configuration
  * */
void SystemClock_reinit(void)
{
    //restore clock config
    RCC_DeInit();
    //disable HSI
    RCC_HSICmd(DISABLE);
    //config PLL clock to be HSE clock 8Mhz / 1 * 9 = 72 MHz
    RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_9);
    //config SYSCLK to be PLL clock
    RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
    //config AHB clock prescaler so HCLK is 72MHz / 1 = 72MHz
    RCC_HCLKConfig(RCC_SYSCLK_Div1);
    //config APB1 prescaler to get PCLK1 with 36MHz max
    RCC_PCLK1Config(RCC_HCLK_Div2);
    //config APB2 prescaler to get PCLK2 with 72MHz max
    RCC_PCLK2Config(RCC_HCLK_Div1);
    //config systick clock
    SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK);
    //debug sysclock
    RCC_MCOConfig(RCC_MCO_SYSCLK);
    
    //enable HSE clock namely the external high speed oscilator
    RCC_HSEConfig(RCC_HSE_ON);
    //wait HSE ready
    while (RCC_WaitForHSEStartUp() != SUCCESS);
    //enable PLL clock
    RCC_PLLCmd(ENABLE);
    //enable CSS
    //RCC_ClockSecuritySystemCmd(ENABLE);
    //enable PeriphClock

    /* GPIO Clock */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
    
    /* Module Clock */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE);  
}
/*EOF*/
