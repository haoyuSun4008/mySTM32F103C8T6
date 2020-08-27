#ifndef _TIMER_H_
#define _TIMER_H_
#include "std_typ.h"

void timer4_init(void);
void delay(uint16_t ms);
extern void TIM4_IRQHandler(void);

#endif