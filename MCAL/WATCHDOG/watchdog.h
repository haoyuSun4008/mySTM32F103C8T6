#ifndef _WATCHDOG_H_
#define _WATCHDOG_H_

#include "..\FWLib\stm32f10x.h"

void watchdog_init(void);
void watchdog_reinit(void);
FlagStatus get_wwdt_pvu_sts(void);
FlagStatus get_wwdt_rvu_sts(void);
FlagStatus get_iwdt_sts(void);

#endif
