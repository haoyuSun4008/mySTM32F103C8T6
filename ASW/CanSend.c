#include "..\CSW\can_cfg.h"
#include "..\MCAL\CAN\can.h"
#include "CanSend.h"

//uint16_t can_msg_send_cnt;
CanTxMsg TestMsg;

/**
 * @brief Call once 10ms
 * */
void CanTestMsg_Send(void)
{
    TestMsg.StdId = 0x094;
    TestMsg.RTR = CAN_RTR_Data;
    TestMsg.IDE = CAN_Id_Standard;
    TestMsg.DLC = 8;
    TestMsg.Data[0] = 0x00;
    TestMsg.Data[1] = 0x01;
    TestMsg.Data[2] = 0x02;
    TestMsg.Data[3] = 0x03;
    TestMsg.Data[4] = 0x04;
    TestMsg.Data[5] = 0x05;
    TestMsg.Data[6] = 0x06;
    TestMsg.Data[7] = 0x07;
    CAN_Transmit(CAN1, &TestMsg);
}
/*EOF*/
