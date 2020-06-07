#ifndef _CLOCK_H_
#define _CLOCK_H_

#include "..\MCAL\stm32f10x_rcc.h"
#include "..\MCAL\misc.h"

void SystemClock_Config(void);
extern void SystemInit(void);

#endif