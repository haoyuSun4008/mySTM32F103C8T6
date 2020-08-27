/*
 * File: RBM_Input.c
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

/* Definition for custom storage class: RBM_Input */
uint8_T V_InRBM_AbsActv_u8_Flg;
int16_T V_InRBM_BmsI_s16_0P1A;
int16_T V_InRBM_BmsU_s16_0P1V;
int16_T V_InRBM_BrkPdlStk_s16s5_mm;
uint8_T V_InRBM_ChassisFlt_u8_Err;
uint8_T V_InRBM_CoastLvl_u8_Mode;
uint8_T V_InRBM_EhbErrMod_u8_Mode;     /* 0: no err
                                          1: degraded
                                          2: broken */
int16_T V_InRBM_EpsSteerAg_s16_Deg;
uint8_T V_InRBM_EpsSteerAg_u8_Vld;
int16_T V_InRBM_FLWhlSpd_s16_0P1Kph;
int16_T V_InRBM_FRWhlSpd_s16_0P1Kph;
int16_T V_InRBM_GasPdlStk_s16_Perc;
uint8_T V_InRBM_GasPdlStk_u8_Vld;
uint8_T V_InRBM_GearPosnAct_u8_Mode;
uint8_T V_InRBM_LostChassisCan_u8_Err;
uint8_T V_InRBM_LostPtCan_u8_Err;
int16_T V_InRBM_MtrSpd_s16_Rpm;
uint8_T V_InRBM_MtrSpd_u8_Vld;
int16_T V_InRBM_MtrTqAct_s16_0P1Nm;
uint8_T V_InRBM_MtrTqAct_u8_Vld;
int16_T V_InRBM_MtrTqLim_s16_0P1Nm;
uint8_T V_InRBM_MtrTqLim_u8_Vld;
int16_T V_InRBM_PAct_s16s7_Bar;
int16_T V_InRBM_PTar_s16s7_Bar;
uint8_T V_InRBM_PtMinorFlt_u8_Err;
uint8_T V_InRBM_PtSevereFlt_u8_Err;
int16_T V_InRBM_RLWhlSpd_s16_0P1Kph;
int16_T V_InRBM_RRWhlSpd_s16_0P1Kph;
uint8_T V_InRBM_RbmEnaFromVcu_u8_Flg;
int16_T V_InRBM_VehSpd_s16_0P1Kph;
uint8_T V_InRBM_VehSpd_u8_Vld;

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
