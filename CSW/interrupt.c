#include "interrupt.h"

void Interrupt_Config(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
}
