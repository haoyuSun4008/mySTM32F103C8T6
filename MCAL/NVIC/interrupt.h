#ifndef _INTERRUPT_H_
#define _INTERRUPT_H_
#include "..\FWLib\misc.h"
#include "..\TIMER\timer.h"

#define BLDC_EmergencyStop_ENABLE   (0U)

extern void os_tick(void);
extern uint8_t TIM2_Hall_Code_get(void);
void Interrupt_config(void);

#endif
/*EOF*/
