#include "interrupt.h"

void Interrupt_init(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
}