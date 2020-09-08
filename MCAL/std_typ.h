#ifndef _STD_TYP_H
#define _STD_TYP_H

typedef signed char int8_t;
typedef unsigned char   uint8_t;
typedef short  int16_t;
typedef unsigned short  uint16_t;
typedef int  int32_t;
typedef unsigned   uint32_t;
typedef long long  int64_t;
typedef unsigned long long   uint64_t;

typedef enum std_device_state_t
{
    STOP = 0,
    START,
    IDLE,
} std_device_state_t;

typedef enum std_HallSig_t
{
    INACTIVE = 0,
    ACTIVE
} std_HallSig_t;

typedef struct Motor_DrvState_t
{
    std_HallSig_t UH;
    std_HallSig_t UL;

    std_HallSig_t VH;
    std_HallSig_t VL;

    std_HallSig_t WH;
    std_HallSig_t WL;
} Motor_DrvState_t;

#endif
/*EOF*/
