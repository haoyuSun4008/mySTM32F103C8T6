#ifndef _TIMINGTEST_H
#define _TIMINGTEST_H
#include "..\std_typ.h"
#include "..\FWLib\stm32f10x_gpio.h"

#define TimingTest_PA3_Set(x)  (x ? (GPIOA->BRR  = GPIO_Pin_3) : (GPIOA->BSRR = GPIO_Pin_3))

#endif
/*EOF*/
