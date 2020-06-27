#include "main.h"

uint8_t debug = 0;
uint8_t os_1ms_cnt = 0;
os_state_type os_state = os_uninited;

void os_1ms_proc(void);
void os_5ms_proc(void);
void os_10ms_proc(void);
void os_init(void);

//int __main(void)
int main(void)
{
	os_init();
	
	while (1)
	{
		#if 1
		os_1ms_proc();
		if ((os_tick % 5) == 0)
		{
			os_5ms_proc();
		}
		if ((os_tick % 10) == 0)
		{
			os_10ms_proc();
		}
		#endif
		//delay(50);	//500ms
		//led2_flashing_test();
	}
	
	return 0;
}

void os_init(void)
{
	//
	SystemClock_Config();
	debug = 1;
	//
	Interrupt_Config();
	debug = 2;
	//
	Led_Config();
	debug = 3;
	//
	Timer4_Config();  //fixme
	debug = 4;

	os_state = os_inited;
}

//
void os_1ms_proc(void)
{
	//

}

void os_5ms_proc(void)
{
	//
	if (os_state != os_running)
	{
		os_state = os_running;
	}
}

void os_10ms_proc(void)
{
	//
	static uint8_t t;
	t++;
	if (t==50)
	{
		led2_flashing_test();
		t = 0;
	}
}