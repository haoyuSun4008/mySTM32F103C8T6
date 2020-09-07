/*===include Config Func===*/
#include "..\MCAL\RCC\clock.h"
#include "..\MCAL\TIMER\timer.h"
#include "..\MCAL\HWIO\hwio.h"
#include "..\MCAL\NVIC\interrupt.h"
#include "..\MCAL\CAN\can.h"
#include "..\MCAL\WATCHDOG\watchdog.h"
#include "..\MCAL\std_typ.h"
#include "..\MCAL\TimingTest.h"
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
void info_init(void);

os_state_t os_state = OS_UNINIT;

uint8_t os_wait_tick = 1;
uint8_t os_5ms_tick = 0;
uint8_t os_10ms_tick = 0;
uint8_t os_1000ms_tick = 0;

//for debug
uint8_t debug = 0;
uint16_t tick_cnt = 0;
myTestData_t myinfo;

/**
 * @brief Init BLDC Control Information
 * @param Void
 * @retval Void
 * IMPORTANT:
 **/
static void info_init(void)
{
    // clear Day_Hour_Min_Sec
    myinfo.DHMS[0]  = 0;
    myinfo.DHMS[1]  = 0;
    myinfo.DHMS[2]  = 0;
    myinfo.DHMS[3]  = 0;

    // clear Hall Pos
    myinfo.HallPos = INVAILD_Pos0;

    // clear Driving PWM Duty
    myinfo.DrvDuty[0] = 0;
    myinfo.DrvDuty[1] = 0;
    myinfo.DrvDuty[2] = 0;

    // clear Motor Speed
    myinfo.MtrSpd      = 0;

    // clear MCU Temperature
    myinfo.Temperature = 0;
}

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
 * @param Void
 * @retval Void
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
}

/**
 * @brief 1ms tick
 * @param Void
 * @retval Void
 * IMPORTANT:
 **/
void os_tick(void)
{
    os_5ms_tick += OS_TICK;
    os_10ms_tick += OS_TICK;
    os_wait_tick = 0;
}

/**
 * @brief Reconfig sys clock and config NVIC
 * @param Void
 * @retval Void
 * IMPORTANT:
 **/
void os_config(void)
{
    //
	SystemClock_reconfig();
	debug = 1;
    
	Interrupt_config();
    debug = 2;
}

/**
 * @brief Config MCU Resource
 * @param Void
 * @retval Void
 * IMPORTANT:
 **/
void os_init(void)
{
    watchdog_init();  //20200815 check ok
    debug = 3;

    PeriphsClock_init();
    debug = 4;
    
    hwio_init();
	debug = 5;
    
	CAN1_init();
	debug = 6;
    
	TIM4_timer_init();  //fixme    //fixed
	debug = 7;

    TIM1_PWM_init();
    debug = 8;

    pid_model_initilize();
    debug = 9;

    //keep as the last one to call
    TIM1_PWM_start();
    debug = 10;
}

/**
 * @brief 1ms assignment write there
 * @param Void
 * @retval Void
 * IMPORTANT:
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
 * @param Void
 * @retval Void
 * IMPORTANT:
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
 * @param Void
 * @retval Void
 * IMPORTANT:
 **/
void os_10ms_proc(void)
{
    //
    TimingTest_PA3_Set(1);
	//Prg Alive ?
	LED_flashing();
	//Prg Alive ?
    CanTestMsg_Send();
    //Timing Test Ok 50us
    TimingTest_PA3_Set(0);
}

/**
 * @brief called by ASW
 * @param Void
 * @retval Void
 * IMPORTANT:
 **/
void os_goto_preshutdown(void)
{
    //
    os_state = OS_PRESHUTDOWN;
}
/*EOF*/
