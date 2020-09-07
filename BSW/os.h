#ifndef _OS_H_
#define _OS_H_

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

void os_config(void);
void os(void);
void os_goto_preshutdown(void);

#endif
/*EOF*/
