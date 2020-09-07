#ifndef _STD_TYP_H
#define _STD_TYP_H

typedef enum std_device_state_t
{
    START = 0,
    STOP,
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

typedef struct myTestData_t
{
    /* Internal Temperature ADC Result */
    int8_t Temperature;

    /* BLDC Control Information */
    int16_t MtrSpd;
    std_HallPos_t HallPos;
    uint8_t DrvDuty[3];

    /* SYS Running Time */
    uint8_t DHMS[4];


} myTestData_t;

typedef signed char int8_t;
typedef unsigned char   uint8_t;
typedef short  int16_t;
typedef unsigned short  uint16_t;
typedef int  int32_t;
typedef unsigned   uint32_t;
typedef long long  int64_t;
typedef unsigned long long   uint64_t;

#endif
/*EOF*/
