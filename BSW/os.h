#ifndef _OS_H_
#define _OS_H_
#include "..\MCAL\std_typ.h"

#define _OS_DEBUG_ON_       (0)

typedef enum os_state_t
{
    OS_UNINIT = 0,
    OS_INIT,
    OS_RUN,
    OS_PRESHUTDOWN,
    OS_SHUTDOWN,
    OS_IDLE,
    OS_ERROR
} os_state_t;

typedef struct
{
    uint8_t FLOAT_LEN;
    uint8_t DOUBLE_LEN;
} NON_INT_LEN_t;

extern void os_led_toggle(void);
extern os_state_t os_state;
void os_config(void);
void os(void);
void os_1ms_proc(void);
void os_5ms_proc(void);
void os_10ms_proc(void);
void os_1s_proc(void);
void os_init(void);
void os_run(void);
void os_goto_preshutdown(void);

#if (_OS_DEBUG_ON_)
void os_non_int_len_test(void);
#endif

#endif
/*EOF*/
