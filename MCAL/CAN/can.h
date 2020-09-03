#ifndef _CAN_H_
#define _CAN_H_
#include "..\std_err.h"
#include "..\FWLib\stm32f10x_can.h"

void CAN1_init(void);
std_err_t can_msg_send(CanTxMsg* tempTxMsg);
std_err_t can_msg_receive(CanRxMsg* tempRxMsg);

#endif
/*EOF*/
