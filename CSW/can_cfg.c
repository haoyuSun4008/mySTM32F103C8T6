#include "std_typ.h"
#include "can_cfg.h"

#define CAN_ID_NUM      (6U)

uint32_t CAN_ID_LIST[CAN_ID_NUM] =
{
    //for debug
    0x0094,

    //for ASW Test
    0x0000,

    //for CCP Type 1
    0x07f1,
    0x07f9,

    //for CCP Type 2
    0x07f3,
    0x07f5
};

uint16_t CAN_ID_TIMEOUT_MAX_LIST[CAN_ID_NUM] =
{
    100,

    100,

    100,
    100,

    100,
    100
};

/**
 * @brief COM sig to CAN Data
 * */
//2020/08/22 write init incomplete
void can_data_mapping(CanTxMsg* tempMsg)
{
    tempMsg->Data[0] = 0;
    tempMsg->Data[1] = 0;
    tempMsg->Data[2] = 0;
    tempMsg->Data[3] = 0;
    tempMsg->Data[4] = 0;
    tempMsg->Data[5] = 0;
    tempMsg->Data[6] = 0;
    tempMsg->Data[7] = 0;
}

/**
 * @brief this func is used to convert a signals to CAN Data
 * */
//2020/08/22 write init incomplete
void com_sig_mapping(CanTxMsg* tempMsg)
{
    tempMsg->Data[0] = 0;
    tempMsg->Data[1] = 0;
    tempMsg->Data[2] = 0;
    tempMsg->Data[3] = 0;
    tempMsg->Data[4] = 0;
    tempMsg->Data[5] = 0;
    tempMsg->Data[6] = 0;
    tempMsg->Data[7] = 0;
}
/* EOF */
