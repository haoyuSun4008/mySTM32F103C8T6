#ifndef _HALL_H_
#define _HALL_H_
#include "..\std_typ.h"

void TIM2_Hall_init(void);
void TIM2_Hall_func_ctrl(std_device_state_t STATE);
uint8_t TIM2_Hall_Code_get(void);

#endif
/* EOF */
