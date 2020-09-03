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
void TIM1_PWM_start(void);
void TIM1_PWM_stop(void);
void TIM1_PWM_duty_set(motor_drv_port_t port, uint16_t pulse);
void TIM1_PWM_duty_test(void);

#endif
/* EOF */
