/*===include Config Func===*/
#include "..\MCAL\RCC\clock.h"
#include "..\MCAL\TIMER\timer.h"
#include "..\MCAL\HWIO\hwio.h"
#include "..\MCAL\NVIC\interrupt.h"
#include "..\MCAL\CAN\can.h"
#include "..\MCAL\WATCHDOG\watchdog.h"
#include "..\MCAL\std_typ.h"
#include "..\MCAL\TIMINGPORT\TimingTest.h"
#include "..\MCAL\PWM\PWM.h"
#include "os.h"
/*====include Test Func====*/
#include "..\ASW\LED.h"
#include "..\ASW\CanSend.h"
#include "..\ASW\PID\pid_model.h"

#define OS_TICK (1U)

void os_1ms_proc(void);
void os_5ms_proc(void);
void os_10ms_proc(void);
void os_init(void);
void os_run(void);

os_state_t os_state = OS_UNINIT;

uint8_t os_wait_tick = 1;
uint8_t os_5ms_tick = 0;
uint8_t os_10ms_tick = 0;
uint8_t os_1000ms_tick = 0;

//for debug
uint8_t debug = 0;
uint16_t tick_cnt = 0;

/**
 * @brief os state switches there
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
}

/**
 * @brief 1ms tick
 **/
void os_tick(void)
{
    os_5ms_tick += OS_TICK;
    os_10ms_tick += OS_TICK;
    os_wait_tick = 0;
}

/**
 * @brief predefine Test Msg
 **/
void os_preinit(void)
{
    //
    pid_model_initilize();
}

/**
 * @brief Config MCU Resource
 **/
void os_init(void)
{
	SystemClock_reinit();
	debug = 1;
    
	Interrupt_init();
    debug = 2;

    watchdog_init();  //20200815 check ok
    debug = 3;
    
    hwio_init();
	debug = 4;
    
	CAN1_init();
	debug = 5;
    
	TIM4_timer_init();  //fixme    //fixed
	debug = 6;

    TIM1_PWM_init();
    debug = 6;

    //keep as the last one
    TIM1_PWM_start();
}

/**
 * @brief 1ms assignment write there
 **/
void os_1ms_proc(void)
{
    //for debug
    tick_cnt += OS_TICK;
    if (tick_cnt >= 1000)
    {
        os_1000ms_tick += OS_TICK;
        tick_cnt = 0;
    }
    //TIM1 PWM duty TEST
    //TIM1_PWM_duty_test();
}

/**
 * @brief 5ms assignment write there
 **/
void os_5ms_proc(void)
{
	//service the dog
    watchdog_reinit();
    //EHB Pressure Control
    pid_model_proc();
}

/**
 * @brief 10ms assignment write there
 **/
void os_10ms_proc(void)
{
    //
    TimingTest_SetHigh(0);
	//Prg Alive ?
	LED_flashing();
	//Prg Alive ?
    CanTestMsg_Send();
    //Timing Test Ok 50us
    TimingTest_SetLow(0);
}

/**
 * @brief called by ASW
 **/
void os_goto_preshutdown(void)
{
    //
    os_state = OS_PRESHUTDOWN;
}
/*EOF*/
