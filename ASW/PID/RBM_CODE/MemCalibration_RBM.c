/*
 * File: MemCalibration_RBM.c
 *
 * Code generated for Simulink model 'RBM'.
 *
 * Model version                  : 1.1842
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Aug 27 10:51:32 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: STMicroelectronics->STM32 32-bit Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. ROM efficiency
 *    3. RAM efficiency
 *    4. Traceability
 *    5. Safety precaution
 *    6. Debugging
 *    7. MISRA C:2012 guidelines
 *    8. Polyspace
 * Validation result: Not run
 */

#include "rtwtypes.h"
#include "RBM_types.h"

/* Exported data definition */

/* this segment is list for calibration data */
/* Definition for custom storage class: PragmaCalibration */
int16_T K_RBM_AbsDlyP_s16s7_Bar = 640;
uint8_T K_RBM_TotFctEna_u8_Flg = 1U;
uint8_T K_RB_ABSDelay_Disable = 0U;
int16_T K_RB_ABSStepP_s16En7Bar = 51;
uint8_T K_RB_AbsActvCoastCnclEna_u8_Flg = 0U;
int16_T K_RB_CutInMotorSpdDelta_Rpm = 300;
int16_T K_RB_CutInPdlStk_Pct = 1;
int16_T K_RB_CutOutMotorSpd_Rpm = 5;
uint8_T K_RB_DiagAssistant_Ena = 1U;
int16_T K_RB_EPSLimitTorqueMap_Angle_Deg[4] =
{
    0, 90, 270, 780
} ;

int16_T K_RB_EPSLimitTorqueMap_Tq_0P1Nm[4] =
{
    -1500, -1500, 0, 0
} ;

int16_T K_RB_FastQuitSpdOfSts1_s16s7_Bar = 1024;
uint8_T K_RB_ForceDisable_Ena = 0U;
uint8_T K_RB_ForceQuit_Ena = 0U;
uint8_T K_RB_FullChargeQuit_Disable = 0U;
uint8_T K_RB_GearOverride_Ena = 0U;
uint8_T K_RB_GearOverride_Flg = 1U;
int16_T K_RB_MapCoastDown_InSpd_rpm[5] =
{
    0, 300, 320, 3000, 8000
} ;

int16_T K_RB_MapCoastDown_OutTq_0P1Nm[5] =
{
    -150, -150, -150, -150, -150
} ;

int16_T K_RB_MapCoastTorqIncrementCoffe[55] =
{
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -20, -60, -90, -130, 0, 0, 0, 0, 0, 0, 0,
    -20, -33, -59, -82, -98, -123, -165, -220, -360, -425, 0, -20, -33, -59, -82,
    -98, -123, -165, -220, -360, -425, 0, -20, -33, -59, -82, -98, -123, -165,
    -220, -360, -425
} ;

int16_T K_RB_MapMotorCharacter_InSpd_Rpm[9] =
{
    0, 200, 500, 800, 1000, 1400, 1500, 3000, 8000
} ;

int16_T K_RB_MapMotorCharacter_OutTq_Rpm[9] =
{
    -1190, -1190, -1190, -1190, -1190, -1340, -1340, -1340, -1000
} ;

int16_T K_RB_MapP2PDecouple_InP_s16En7Bar[13] =
{
    0, 640, 1280, 1920, 2560, 3200, 3840, 4480, 5120, 6400, 8960, 11520, 19200
} ;

int16_T K_RB_MapP2PDecouple_OutP_s16En7Bar[13] =
{
    0, 525, 1165, 1805, 2445, 3098, 3738, 4096, 4480, 5120, 2560, 0, 0
} ;

int16_T K_RB_MapPrefillForcePressure_InP_s16En7Bar[13] =
{
    0, 640, 1280, 1920, 2560, 3200, 3840, 4480, 5120, 6400, 8960, 11520, 19200
} ;

int16_T K_RB_MapPrefillForcePressure_OutP_s16En7Bar[13] =
{
    192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192
} ;

int16_T K_RB_MapQuitMotorSpd_InP_s16En7Bar[13] =
{
    0, 640, 1280, 1920, 2560, 3200, 3840, 4480, 5120, 6400, 8960, 11520, 19200
} ;

int16_T K_RB_MapQuitMotorSpd_OutSpd_Rpm[13] =
{
    400, 400, 550, 770, 900, 930, 930, 1000, 1100, 1100, 1100, 1100, 1100
} ;

int16_T K_RB_MapQuitTqDelay_InP_s16En7Bar[13] =
{
    0, 640, 1280, 1920, 2560, 3200, 3840, 4480, 5120, 6400, 8960, 11520, 19200
} ;

uint8_T K_RB_MapQuitTqDelay_Out_5ms[13] =
{
    28U, 28U, 28U, 22U, 18U, 15U, 15U, 10U, 5U, 0U, 0U, 0U, 0U
} ;

int16_T K_RB_MapQuitdP2dPGain_InP_s16En7Bar[13] =
{
    0, 640, 1280, 1920, 2560, 3200, 3840, 4480, 5120, 6400, 8960, 11520, 19200
} ;

int16_T K_RB_MapQuitdP2dPGain_OutP_s16En7[13] =
{
    138, 137, 136, 136, 136, 115, 115, 128, 128, 128, 128, 128, 128
} ;

int16_T K_RB_MapQuitdP2dPOffset_InP_s16En7Bar[13] =
{
    0, 640, 1280, 1920, 2560, 3200, 3840, 4480, 5120, 6400, 8960, 11520, 19200
} ;

int16_T K_RB_MapQuitdP2dPOffset_OutP_s16En7Bar[13] =
{
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
} ;

int16_T K_RB_MapS2PDecouple_InS_s16En5mm[9] =
{
    0, 384, 640, 896, 1280, 1664, 1920, 2560, 3840
} ;

int16_T K_RB_MapS2PDecouple_OutP_s16En7Bar[9] =
{
    6400, 6400, 6400, 6400, 6400, 6400, 6400, 6400, 6400
} ;

int16_T K_RB_MapStepPressure_InP_s16En7Bar[13] =
{
    0, 640, 1280, 1920, 2560, 3200, 3840, 4480, 5120, 6400, 8960, 11520, 19200
} ;

int16_T K_RB_MapStepPressure_InTq_s16_0P1Nm[5] =
{
    -1300, -900, -500, -200, 0
} ;

int16_T K_RB_MapStepPressure_OutP_s16En7Bar[13] =
{
    3, 3, 5, 6, 8, 15, 18, 19, 20, 22, 23, 24, 25
} ;

int16_T K_RB_MapTorqCompensationPoint_s16En7Bar[11] =
{
    0, 256, 512, 768, 1024, 1280, 1536, 1792, 2048, 2304, 2560
} ;

uint8_T K_RB_MapVCUCoastLevelIn_u8[5] =
{
    0U, 1U, 2U, 3U, 4U
} ;

int16_T K_RB_MapVCUCoastTorq_0P1Nm[5] =
{
    0, -150, -250, -350, -450
} ;

int16_T K_RB_MtrSpdQuitStop_s16_Rpm = -200;
uint8_T K_RB_MultiCoastTenseEna_u8_Flg = 0U;
int16_T K_RB_MutiMapStepPressure_OutP_s16En7Bar[65] =
{
    6, 7, 11, 13, 16, 6, 7, 11, 13, 16, 8, 9, 13, 15, 18, 9, 10, 14, 16, 19, 44,
    65, 133, 184, 241, 18, 19, 23, 25, 28, 21, 22, 26, 28, 31, 22, 23, 27, 29,
    32, 23, 24, 28, 31, 33, 24, 25, 29, 32, 34, 25, 27, 31, 33, 36, 27, 28, 32,
    34, 37, 28, 29, 33, 36, 38
} ;

int16_T K_RB_OutPMinPressure_s16En7Bar = 26;
int16_T K_RB_P2TqGain_null = -6016;
int16_T K_RB_P2TqOffset_null = 0;
int16_T K_RB_PBrkCoeff_s16s10_null[6] =
{
    1024, 922, 819, 768, 717, 717
} ;

int16_T K_RB_PrefillCutInMotorSpdDelta_Rpm = 100;
uint8_T K_RB_Prefill_Ena = 1U;
uint16_T K_RB_Q2DDelay_u8_5ms = 0U;
int16_T K_RB_SlowQuitSpdOfSts1_s16s7_Bar = 64;
int16_T K_RB_TorqueErrorThreshold_0P1Nm = 100;
int16_T K_RB_TorqueErrorTimeThreshold_5ms = 200;
int16_T K_RB_TqQuitStop_s16_0P1Nm = 20;
int16_T K_RB_WheelSpdThreshold_kph = 100;
int16_T M_RB_BreakPntOfPAct_s16s7_Bar[6] =
{
    0, 640, 1024, 2560, 3840, 5120
} ;

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
