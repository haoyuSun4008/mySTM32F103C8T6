#include "main.h"

uint8_t debug = 0;
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
		#if 0
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
		delay(50);
		led2_flashing_test();
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
	//Timer4_Config();  //fixme
	debug = 3;
	//
	Led_Config();
	debug = 4;
}

//
void os_1ms_proc(void)
{
	//
}

void os_5ms_proc(void)
{
	//
}

void os_10ms_proc(void)
{
	//
	led2_flashing();
}