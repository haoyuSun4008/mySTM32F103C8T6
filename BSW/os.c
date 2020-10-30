/*====include OS Func====*/
#include "os.h"

#define OS_TICK (1U)

#if (_OS_DEBUG_ON_)
NON_INT_LEN_t p;
#endif

os_state_t os_state = OS_UNINIT;

uint8_t os_wait_tick = 1;
uint8_t os_5ms_tick = 0;
uint8_t os_10ms_tick = 0;
uint16_t os_1s_tick = 0;
uint16_t os_led_tick = 0;

uint16_t _LED_FLASH_TIME_MS_ = 500;

/**
 * @brief os state switches there
 * @param Void
 * @retval Void
 * IMPORTANT: Never Return
 **/
void os(void)
{
    //
    while(1)
    {
        switch (os_state)
        {
            case OS_UNINIT:
            {
                os_state = OS_INIT;
                break;
            }

            case OS_INIT:
            {
                os_init();
                os_state = OS_RUN;
                break;
            }

            case OS_RUN:
            {
                os_run();
                break;
            }

            case OS_PRESHUTDOWN:
            {
                // os_preshutdown();
                os_state = OS_SHUTDOWN;
                break;
            }

            case OS_SHUTDOWN:
            {
                // os_shutdown();
                //os_state = OS_IDLE;
                break;
            }

            case OS_IDLE:
            {
                // os_shutdown();
                //os_state = OS_IDLE;
                break;
            }

            case OS_ERROR:
            {
                // os_shutdown();
                //os_state = OS_IDLE;
                break;
            }

            default:
                break;
        }
    }
}

/**
 * @brief os schedules.
 * IMPORTANT:
 **/
void os_run(void)
{
    //
    while(os_wait_tick);
    os_wait_tick = 1;

    os_1ms_proc();

    if (os_5ms_tick >= 5)
    {
        os_5ms_tick = 0;
        os_5ms_proc();
    }

    if (os_10ms_tick >= 10)
    {
        os_10ms_tick = 0;
        os_10ms_proc();
    }

    if (os_1s_tick >= 1000)
    {
        os_1s_tick = 0;
        os_1s_proc();
    }

    if (os_led_tick >= _LED_FLASH_TIME_MS_)
    {
        os_led_tick = 0;
        os_led_toggle();
    }
}

/**
 * @brief 1ms tick
 * IMPORTANT:
 **/
void os_tick(void)
{
    os_5ms_tick += OS_TICK;
    os_10ms_tick += OS_TICK;
    os_1s_tick += OS_TICK;
    os_led_tick += OS_TICK;
    os_wait_tick = 0;
}

#if (_OS_DEBUG_ON_)
void os_non_int_len_test(void)
{
    p.DOUBLE_LEN = sizeof(double);
    p.FLOAT_LEN = sizeof(float);
}
#endif
/* EOF */
