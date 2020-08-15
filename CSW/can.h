#ifndef _CAN_H_
#define _CAN_H_
#include "..\MCAL\stm32f10x_can.h"
#include "std_err.h"

void CAN_init(void);
std_err_t can_msg_send(CanTxMsg* tempTxMsg);
std_err_t can_msg_receive(CanRxMsg* tempRxMsg);

#endif