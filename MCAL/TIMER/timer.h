#ifndef _TIMER_H_
#define _TIMER_H_
#include "..\FWLib\stm32f10x_tim.h"
#include "..\std_typ.h"

void TIM4_timer_init(void);
void delay(uint16_t ms);

#endif
/*EOF*/
