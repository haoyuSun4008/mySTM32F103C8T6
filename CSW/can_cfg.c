#include "can_cfg.h"

uint32_t CAN_ID_LIST[_CAN_TOTAL_ID_NUM_] =
{
    // debug
    0x0094,

    // EHB Msg ID
    0x0095,
    // VCU Msg ID
    0x0096,

    // CCP Type 1
    0x07f1,
    0x07f9,

    // CCP Type 2
    0x07f3,
    0x07f5
};

uint16_t CAN_ID_TIMEOUT_MAX_LIST[_CAN_TOTAL_ID_NUM_] =
{
    100,

    100,

    100,
    100,

    100,
    100
};

/**
 * @brief VCU COM Signals Mapping to CAN Data
 * IMPORTANT:
 * */
void VCU_COM_Signals_Mapping(uint8_t* dat)
{
    //
}

/**
 * @brief EHB COM Signals Mapping to CAN Data
 * IMPORTANT:
 * */
void EHB_COM_Signals_Mapping(uint8_t* dat)
{
    //
}
/*EOF*/
