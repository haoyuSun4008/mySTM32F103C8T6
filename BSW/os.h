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

//extern os_state_t os_state;
//call in timer.c
void os_tick(void);
//call in main.c
void os_preinit(void);
void os(void);
//call in ASW
void os_goto_preshutdown(void);

#endif
/*EOF*/
