#ifndef _PWM_H_
#define _PWM_H_
#include "..\std_typ.h"

typedef enum
{
    UH = 1,
    VH,
    WH,
} motor_drv_port_t;

void TIM1_PWM_init(void);
void TIM1_PWM_func_ctrl(std_device_state_t STATE);
void TIM1_PWM_duty_set(motor_drv_port_t PORT, uint16_t PULSE);
void TIM1_PWM_duty_test(void);

#endif
/* EOF */
