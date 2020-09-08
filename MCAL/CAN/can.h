#ifndef _CAN_H_
#define _CAN_H_
#include "..\std_err.h"
#include "..\FWLib\stm32f10x_can.h"

#define CAN_RX0_INT_ENABLE      (0U)

void CAN1_init(void);

#endif
/*EOF*/
