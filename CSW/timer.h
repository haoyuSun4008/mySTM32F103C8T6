#ifndef _TIMER_H_
#define _TIMER_H_
#include "..\MCAL\stm32f10x_tim.h"
#include "..\MCAL\misc.h"

extern uint8_t os_tick;  // bug fixed,
void Timer4_Config(void);
void delay(uint16_t ms);
extern void TIM4_IRQHandler(void);

#endif