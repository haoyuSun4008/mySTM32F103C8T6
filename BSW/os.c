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
#include "..\MCAL\HALL\hall.h"
#include "..\MCAL\ADC\adc.h"
/*====include Test Func====*/
#include "..\ASW\LED.h"
#include "..\ASW\PID\pid_model.h"
/*====include OS Func====*/
#include "os.h"

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

//for debug
uint8_t debug = 0;
CanTxMsg DebugMsg;

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
    debug += 1;
    
	Interrupt_config();
    debug += 1;
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
    debug += 1;

    PeriphsClock_init();
    debug += 1;
    
    hwio_init();
    debug += 1;
    
	CAN1_init();
    debug += 1;
    
	TIM4_timer_init();  //fixme    //fixed
    debug += 1;

    TIM2_Hall_init();
    debug += 1;

    TIM1_PWM_init();
    debug += 1;

    ADC1_Temperature_init();
    debug += 1;

   // keep called there
    pid_model_initilize();
    debug += 1;

    //keep as the last one to call
    TIM1_PWM_func_ctrl(START);
    debug += 1;

    DebugMsg.StdId = 0x94;
    DebugMsg.IDE   = CAN_Id_Standard;
    DebugMsg.RTR   = CAN_RTR_Data;
    DebugMsg.DLC   = 8;
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
    uint16_t temp;
    //
    TimingTest_PA3_Set(0);

	//Prg Alive ?
	LED_flashing();

	//Prg Alive ?
    temp = ADC1_Temperature_sample();
    DebugMsg.Data[0] = (temp >> 8);         // Temperature 8bit H
    DebugMsg.Data[1] = temp;                // Temperature 8bit L

    DebugMsg.Data[2] = TIM1_CCR1_GET();
    DebugMsg.Data[3] = TIM1_CCR2_GET();
    DebugMsg.Data[4] = TIM1_CCR3_GET();

    DebugMsg.Data[5] = 0;
    DebugMsg.Data[6] = 0;
    DebugMsg.Data[7] = 0;
    CAN_Transmit(CAN1, &DebugMsg);

    //Timing Test Ok 50us
    TimingTest_PA3_Set(1);
}

/**
 * @brief Switch OS into preshutdown state
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
