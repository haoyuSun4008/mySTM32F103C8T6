#ifndef _CAN_H_
#define _CAN_H_
#include "std_err.h"
#include "..\MCAL\stm32f10x_can.h"

typedef struct
{
    uint32_t id;
    uint8_t ide;
    uint8_t rtr;
    uint8_t len;
    uint8_t mbox;
    uint8_t dat[8];
} CanMsg_t;

void CAN1_init(void);
std_err_t can_msg_send(CanTxMsg* tempTxMsg);
std_err_t can_msg_receive(CanRxMsg* tempRxMsg);

#endif