#include "..\CSW\can.h"
#include "CanSend.h"

//uint16_t can_msg_send_cnt;
//CanTxMsg* TestMsg;
//CanMsg_t* TestMsg;

uint8_t mbox;

/**
 * @brief Call once 10ms
 * */
void CanTestMsg_init(void)
{
    #if 0
    //can_msg_send_cnt = 0;
    
    TestMsg->IDE = CAN_Id_Standard;
    //TestMsg->RTR = CAN_RTR_Data;
    TestMsg->RTR = ((uint32_t)0x00000000);
    TestMsg->StdId = 0x94;
    TestMsg->DLC = 8;
    TestMsg->Data[0] = 0x00;
    TestMsg->Data[1] = 0x01;
    TestMsg->Data[2] = 0x02;
    TestMsg->Data[3] = 0x03;
    TestMsg->Data[4] = 0x04;
    TestMsg->Data[5] = 0x05;
    TestMsg->Data[6] = 0x06;
    TestMsg->Data[7] = 0x07;

    //record fail
    if (can_msg_send(TestMsg) == ErrNotOk)
    {
        can_msg_send_cnt++;
        can_msg_send_cnt %= 0xFFFF;
    }
    #endif
    uint8_t ide = 0;
    uint8_t rtr = 0;
    uint32_t id = 0x94;
    uint8_t len = 8;
    uint8_t dat[8] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07};

    if(CAN1->TSR & (1 << 26))
    {
        //mbox0 empty
        mbox = 0;
    }
    else if(CAN1->TSR & (1 << 27))
    {
        //mbox1 empty
        mbox = 1;
    }
    else if(CAN1->TSR & (1 << 28))
    {
        //mbox2 empty
        mbox = 2;
    }
    else
    {
        //no mbox
        //return 0xff;
        return;
    }
    //clear formal setting
    CAN1->sTxMailBox[mbox].TIR = 0;
    CAN1->sTxMailBox[mbox].TIR |= (id);
    CAN1->sTxMailBox[mbox].TIR |= (ide << 2);
    CAN1->sTxMailBox[mbox].TIR |= (rtr << 1);
    //TestMsg->len &= 0x0f;
    CAN1->sTxMailBox[mbox].TDTR &= ~(0x0000000f);
    CAN1->sTxMailBox[mbox].TDTR |= len;
    CAN1->sTxMailBox[mbox].TDHR = (((uint32_t)dat[7] << 24) |
                                   ((uint32_t)dat[6] << 16) |
                                   ((uint32_t)dat[5] << 8)  |
                                   ((uint32_t)dat[4]));
    
    CAN1->sTxMailBox[mbox].TDLR = (((uint32_t)dat[3] << 24) |
                                   ((uint32_t)dat[2] << 16) |
                                   ((uint32_t)dat[1] << 8)  |
                                   ((uint32_t)dat[0]));
}

/**
 * @brief Can Msg Send in Reg
 * */
void CanTx_Test(void)
{
    //Request to Send Msg
    CAN1->sTxMailBox[mbox].TIR |= (1 << 0);
}