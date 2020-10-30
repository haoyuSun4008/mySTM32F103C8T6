/*===include Config Func===*/
#include "..\MCAL\TIMER\timer.h"
#include "..\MCAL\HWIO\hwio.h"
#include "..\MCAL\CAN\can_output.h"
#include "..\MCAL\WATCHDOG\watchdog.h"
#include "..\MCAL\TimingTest.h"
#include "..\MCAL\PWM\PWM.h"
#include "..\MCAL\HALL\hall.h"
#include "..\MCAL\ADC\adc.h"
#include "..\MCAL\USART\usart.h"
#include "..\MCAL\FWLib\misc.h"
/*====include Test Func====*/
#include "..\ASW\PID\pid_model.h"

#include "os.h"

#if (_OS_DEBUG_ON_)
//for debug
uint8_t _init_run_disp_ = 0;
#endif

/**
 * @brief Config MCU Resource
 * IMPORTANT:
 **/
void os_init(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
#if (_OS_DEBUG_ON_)
    _init_run_disp_ += 1;
#endif

    watchdog_init();  //20200815 check ok
#if (_OS_DEBUG_ON_)
    _init_run_disp_ += 1;
#endif
    
    hwio_init();
#if (_OS_DEBUG_ON_)
    _init_run_disp_ += 1;
#endif
    
	CAN_init();
#if (_OS_DEBUG_ON_)
    _init_run_disp_ += 1;
#endif

    //TIM2_Hall_init();
    //debug += 1;

    //TIM1_PWM_init();
    //debug += 1;

    ADC1_Temperature_init();
#if (_OS_DEBUG_ON_)
    _init_run_disp_ += 1;
#endif

    Usart_Init();
#if (_OS_DEBUG_ON_)
    _init_run_disp_ += 1;
#endif

    //keep called there
    //pid_model_initilize();
    //debug += 1;

    //keep as the last one to call
    //TIM1_PWM_func_ctrl(START);
    //debug += 1;
    //os_non_int_len_test();
    
	TIM4_timer_init();  //fixme    //fixed
#if (_OS_DEBUG_ON_)
    _init_run_disp_ += 1;
#endif
}

/**
 * @brief 1ms assignment write there
 * IMPORTANT:
 **/
void os_1ms_proc(void)
{
    //for debug
}

/**
 * @brief 5ms assignment write there
 * IMPORTANT:
 **/
void os_5ms_proc(void)
{
	//service the dog
    watchdog_reinit();
    //EHB Pressure Control
    //pid_model_proc();
}

/**
 * @brief 10ms assignment write there
 * IMPORTANT:
 **/
void os_10ms_proc(void)
{
    //
    //TimingTest_PA3_Set(0);

    //USART_SendAscii();

    //TimingTest_PA3_Set(1);
}

/**
 * @brief 1s assignment write there
 * IMPORTANT:
 **/
void os_1s_proc(void)
{
    //
    //TimingTest_PA3_Set(0);

    USART_SendSine();
    //Timing Test Ok 50us
    //TimingTest_PA3_Set(1);
}

/**
 * @brief Switch OS into preshutdown state
 * IMPORTANT:
 **/
void os_goto_preshutdown(void)
{
    //
    os_state = OS_PRESHUTDOWN;
}
/*EOF*/
