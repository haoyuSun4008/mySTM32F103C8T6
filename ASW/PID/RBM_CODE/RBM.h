/*
 * File: RBM.h
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

#ifndef RTW_HEADER_RBM_h_
#define RTW_HEADER_RBM_h_
#include <string.h>
#ifndef RBM_COMMON_INCLUDES_
# define RBM_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* RBM_COMMON_INCLUDES_ */

#include "RBM_types.h"

/* Macros for accessing real-time model data structure */

/* Block signals and states (default storage) for system '<Root>' */
typedef struct
{
    uint32_T m_bpIndex;                /* '<S3>/EPS Character Map' (DWork 1)  */
    uint32_T m_bpIndex_b;              /* '<S3>/Motor Character Map' (DWork 1)  */
    int16_T Delay_DSTATE_i[40];        /* '<S59>/Delay' (DWork 1)  */
    int16_T signal2;                   /* '<S1>/Merge' (Output 1)  */
    int16_T signal6;                   /* '<S1>/Merge' (Output 1)  */
    int16_T Delay_DSTATE;              /* '<S1>/Delay' (DWork 1)  */
    int16_T Delay3_DSTATE;             /* '<S16>/Delay3' (DWork 1)  */
    int16_T Delay1_DSTATE;             /* '<S1>/Delay1' (DWork 1)  */
    int16_T pretq;                     /* '<S67>/Lock QuitTorq' (Local data 'pretq')  */
    int16_T DetnCnt;                   /* '<S8>/Chart' (Local data 'DetnCnt')  */
    uint16_T DelayCnt;                 /* '<S12>/RBState_Judge' (Local data 'DelayCnt')  */
    int8_T SwitchCase_ActiveSubsystem; /* '<S1>/Switch Case' (DWork 1)  */
    uint8_T signal3;                   /* '<S1>/Merge' (Output 1)  */
    uint8_T Delay2_DSTATE;             /* '<S1>/Delay2' (DWork 1)  */
    uint8_T icLoad;                    /* '<S59>/Delay' (DWork 2)  */
    uint8_T is_active_c10_RBM;         /* '<S68>/Lock' (Chart is active)  */
    uint8_T is_c10_RBM;                /* '<S68>/Lock' (Active substate of the chart)  */
    uint8_T is_active_c11_RBM;         /* '<S67>/Lock QuitTorq' (Chart is active)  */
    uint8_T is_c11_RBM;                /* '<S67>/Lock QuitTorq' (Active substate of the chart)  */
    uint8_T is_active_c12_RBM;         /* '<S59>/Chart' (Chart is active)  */
    uint8_T is_c12_RBM;                /* '<S59>/Chart' (Active substate of the chart)  */
    uint8_T lock_value;                /* '<S59>/Chart' (Local data 'lock_value')  */
    uint8_T cnt;                       /* '<S35>/Err_Debounce' (Local data 'cnt')  */
    uint8_T is_active_c2_RBM;          /* '<S33>/Chart' (Chart is active)  */
    uint8_T is_c2_RBM;                 /* '<S33>/Chart' (Active substate of the chart)  */
    uint8_T is_active_c8_RBM;          /* '<S8>/Chart' (Chart is active)  */
    uint8_T is_c8_RBM;                 /* '<S8>/Chart' (Active substate of the chart)  */
    uint8_T is_active_c5_RBM;          /* '<S85>/Chart' (Chart is active)  */
    uint8_T is_c5_RBM;                 /* '<S85>/Chart' (Active substate of the chart)  */
    uint8_T is_active_c3_RBM;          /* '<S12>/RBState_Judge' (Chart is active)  */
    uint8_T is_c3_RBM;                 /* '<S12>/RBState_Judge' (Active substate of the chart)  */
    uint8_T Q2DEna;                    /* '<S12>/RBState_Judge' (Local data 'Q2DEna')  */
    boolean_T Subsystem_MODE;          /* '<S1>/Subsystem' (DWork 1)  */
}
DW_RBM;

/* Invariant block signals (default storage) */
typedef struct
{
    const char_T StringConstant[10];   /* '<S1>/String Constant' (Output 1)  */
}
ConstB_RBM;

/* Constant parameters (default storage) */
typedef struct
{
    /* Computed Parameter: LightBrakeOverlay_maxIndex
     * Referenced by: '<S32>/Light Brake Overlay' (Parameter: maxIndex)
     */
    uint32_T LightBrakeOverlay_maxIndex[2];

    /* Computed Parameter: uDLookupTable_maxIndex
     * Referenced by: '<S67>/1-D Lookup Table' (Parameter: maxIndex)
     */
    uint32_T uDLookupTable_maxIndex[2];
}
ConstP_RBM;

/* Block signals and states (default storage) */
extern DW_RBM RBM_DW;
extern const ConstB_RBM RBM_ConstB;    /* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_RBM RBM_ConstP;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern int16_T dAimP;                  /* '<S16>/Add' */
extern int16_T dPQuit;                 /* '<S20>/Multiport Switch1' */

/* Model entry point functions */
extern void RBM_initialize(void);
extern void RBM_step(void);

/* Exported data declaration */

/* Declaration for custom storage class: Default */
extern uint8_T RB_Ver[9];

/* Declaration for custom storage class: RBM_Input */
extern uint8_T V_InRBM_AbsActv_u8_Flg;
extern int16_T V_InRBM_BmsI_s16_0P1A;
extern int16_T V_InRBM_BmsU_s16_0P1V;
extern int16_T V_InRBM_BrkPdlStk_s16s5_mm;
extern uint8_T V_InRBM_ChassisFlt_u8_Err;
extern uint8_T V_InRBM_CoastLvl_u8_Mode;
extern uint8_T V_InRBM_EhbErrMod_u8_Mode;/* 0: no err
                                            1: degraded
                                            2: broken */
extern int16_T V_InRBM_EpsSteerAg_s16_Deg;
extern uint8_T V_InRBM_EpsSteerAg_u8_Vld;
extern int16_T V_InRBM_FLWhlSpd_s16_0P1Kph;
extern int16_T V_InRBM_FRWhlSpd_s16_0P1Kph;
extern int16_T V_InRBM_GasPdlStk_s16_Perc;
extern uint8_T V_InRBM_GasPdlStk_u8_Vld;
extern uint8_T V_InRBM_GearPosnAct_u8_Mode;
extern uint8_T V_InRBM_LostChassisCan_u8_Err;
extern uint8_T V_InRBM_LostPtCan_u8_Err;
extern int16_T V_InRBM_MtrSpd_s16_Rpm;
extern uint8_T V_InRBM_MtrSpd_u8_Vld;
extern int16_T V_InRBM_MtrTqAct_s16_0P1Nm;
extern uint8_T V_InRBM_MtrTqAct_u8_Vld;
extern int16_T V_InRBM_MtrTqLim_s16_0P1Nm;
extern uint8_T V_InRBM_MtrTqLim_u8_Vld;
extern int16_T V_InRBM_PAct_s16s7_Bar;
extern int16_T V_InRBM_PTar_s16s7_Bar;
extern uint8_T V_InRBM_PtMinorFlt_u8_Err;
extern uint8_T V_InRBM_PtSevereFlt_u8_Err;
extern int16_T V_InRBM_RLWhlSpd_s16_0P1Kph;
extern int16_T V_InRBM_RRWhlSpd_s16_0P1Kph;
extern uint8_T V_InRBM_RbmEnaFromVcu_u8_Flg;
extern int16_T V_InRBM_VehSpd_s16_0P1Kph;
extern uint8_T V_InRBM_VehSpd_u8_Vld;

/* Declaration for custom storage class: RBM_Output */
extern uint8_T V_OutRBM_MtrTqFolwReq_u8_Flg;
extern int16_T V_OutRBM_MtrTqTar_s16_0P1Nm;
extern int16_T V_OutRBM_PTar_s16s7_Bar;
extern uint8_T V_OutRBM_PreFillEna_u8_Flg;
extern uint8_T V_OutRBM_RbmActv_u8_Flg;
extern uint8_T V_OutRBM_TqErrOver_u8_Err;

/* this segment is list for calibration data */
/* Declaration for custom storage class: PragmaCalibration */
extern int16_T K_RBM_AbsDlyP_s16s7_Bar;
extern uint8_T K_RBM_TotFctEna_u8_Flg;
extern uint8_T K_RB_ABSDelay_Disable;
extern int16_T K_RB_ABSStepP_s16En7Bar;
extern uint8_T K_RB_AbsActvCoastCnclEna_u8_Flg;
extern int16_T K_RB_CutInMotorSpdDelta_Rpm;
extern int16_T K_RB_CutInPdlStk_Pct;
extern int16_T K_RB_CutOutMotorSpd_Rpm;
extern uint8_T K_RB_DiagAssistant_Ena;
extern int16_T K_RB_EPSLimitTorqueMap_Angle_Deg[4];
extern int16_T K_RB_EPSLimitTorqueMap_Tq_0P1Nm[4];
extern int16_T K_RB_FastQuitSpdOfSts1_s16s7_Bar;
extern uint8_T K_RB_ForceDisable_Ena;
extern uint8_T K_RB_ForceQuit_Ena;
extern uint8_T K_RB_FullChargeQuit_Disable;
extern uint8_T K_RB_GearOverride_Ena;
extern uint8_T K_RB_GearOverride_Flg;
extern int16_T K_RB_MapCoastDown_InSpd_rpm[5];
extern int16_T K_RB_MapCoastDown_OutTq_0P1Nm[5];
extern int16_T K_RB_MapCoastTorqIncrementCoffe[55];
extern int16_T K_RB_MapMotorCharacter_InSpd_Rpm[9];
extern int16_T K_RB_MapMotorCharacter_OutTq_Rpm[9];
extern int16_T K_RB_MapP2PDecouple_InP_s16En7Bar[13];
extern int16_T K_RB_MapP2PDecouple_OutP_s16En7Bar[13];
extern int16_T K_RB_MapPrefillForcePressure_InP_s16En7Bar[13];
extern int16_T K_RB_MapPrefillForcePressure_OutP_s16En7Bar[13];
extern int16_T K_RB_MapQuitMotorSpd_InP_s16En7Bar[13];
extern int16_T K_RB_MapQuitMotorSpd_OutSpd_Rpm[13];
extern int16_T K_RB_MapQuitTqDelay_InP_s16En7Bar[13];
extern uint8_T K_RB_MapQuitTqDelay_Out_5ms[13];
extern int16_T K_RB_MapQuitdP2dPGain_InP_s16En7Bar[13];
extern int16_T K_RB_MapQuitdP2dPGain_OutP_s16En7[13];
extern int16_T K_RB_MapQuitdP2dPOffset_InP_s16En7Bar[13];
extern int16_T K_RB_MapQuitdP2dPOffset_OutP_s16En7Bar[13];
extern int16_T K_RB_MapS2PDecouple_InS_s16En5mm[9];
extern int16_T K_RB_MapS2PDecouple_OutP_s16En7Bar[9];
extern int16_T K_RB_MapStepPressure_InP_s16En7Bar[13];
extern int16_T K_RB_MapStepPressure_InTq_s16_0P1Nm[5];
extern int16_T K_RB_MapStepPressure_OutP_s16En7Bar[13];
extern int16_T K_RB_MapTorqCompensationPoint_s16En7Bar[11];
extern uint8_T K_RB_MapVCUCoastLevelIn_u8[5];
extern int16_T K_RB_MapVCUCoastTorq_0P1Nm[5];
extern int16_T K_RB_MtrSpdQuitStop_s16_Rpm;
extern uint8_T K_RB_MultiCoastTenseEna_u8_Flg;
extern int16_T K_RB_MutiMapStepPressure_OutP_s16En7Bar[65];
extern int16_T K_RB_OutPMinPressure_s16En7Bar;
extern int16_T K_RB_P2TqGain_null;
extern int16_T K_RB_P2TqOffset_null;
extern int16_T K_RB_PBrkCoeff_s16s10_null[6];
extern int16_T K_RB_PrefillCutInMotorSpdDelta_Rpm;
extern uint8_T K_RB_Prefill_Ena;
extern uint16_T K_RB_Q2DDelay_u8_5ms;
extern int16_T K_RB_SlowQuitSpdOfSts1_s16s7_Bar;
extern int16_T K_RB_TorqueErrorThreshold_0P1Nm;
extern int16_T K_RB_TorqueErrorTimeThreshold_5ms;
extern int16_T K_RB_TqQuitStop_s16_0P1Nm;
extern int16_T K_RB_WheelSpdThreshold_kph;
extern int16_T M_RB_BreakPntOfPAct_s16s7_Bar[6];

/* this segment is list for measurable data */
/* Declaration for custom storage class: PragmaMeasured */
extern int16_T V_RBM_DTqQuitMode_s16_0P1Nm;
extern uint8_T V_RBM_DiModSts_u8_Mode;
extern int16_T V_RBM_DiagInfo1_u16_Mode;
extern int16_T V_RBM_DiagInfo2_u16_Mode;
extern uint8_T V_RBM_FormerTorqueErrorOver_u8_Err;
extern int16_T V_RBM_MtrTqAllwd_s16_0P1Nm;
extern int16_T V_RBM_MtrTqCoast_s16_0P1Nm;
extern int16_T V_RBM_MtrTqTarFormer_s16_0P1Nm;
extern int16_T V_RBM_PTarFormer_s16s7_Bar;
extern uint8_T V_RBM_WhlSpdSlip_u8_Err;
extern uint8_T V_RB_RBModeMask_Flg;
extern uint8_T V_RB_RBState_Flg;
extern int16_T V_RB_dpQuitMod_s16s7_Bar;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'RBM'
 * '<S1>'   : 'RBM/Subsystem'
 * '<S2>'   : 'RBM/Subsystem/3X_Average1'
 * '<S3>'   : 'RBM/Subsystem/AllowMotorTorqueCalculator'
 * '<S4>'   : 'RBM/Subsystem/Chart'
 * '<S5>'   : 'RBM/Subsystem/CoastBrakeCalculator'
 * '<S6>'   : 'RBM/Subsystem/Compare To Constant'
 * '<S7>'   : 'RBM/Subsystem/Prefill_Ena'
 * '<S8>'   : 'RBM/Subsystem/RB_Disable_Mode'
 * '<S9>'   : 'RBM/Subsystem/RB_E_Bak_Mode'
 * '<S10>'  : 'RBM/Subsystem/RB_Enable_Mode'
 * '<S11>'  : 'RBM/Subsystem/RB_Quit_Mode'
 * '<S12>'  : 'RBM/Subsystem/RB_State_Judge'
 * '<S13>'  : 'RBM/Subsystem/Subsystem'
 * '<S14>'  : 'RBM/Subsystem/Subsystem1'
 * '<S15>'  : 'RBM/Subsystem/Subsystem2'
 * '<S16>'  : 'RBM/Subsystem/dAimP'
 * '<S17>'  : 'RBM/Subsystem/AllowMotorTorqueCalculator/p2tq'
 * '<S18>'  : 'RBM/Subsystem/AllowMotorTorqueCalculator/p2tq1'
 * '<S19>'  : 'RBM/Subsystem/RB_Disable_Mode/Chart'
 * '<S20>'  : 'RBM/Subsystem/RB_Disable_Mode/Subsystem'
 * '<S21>'  : 'RBM/Subsystem/RB_Disable_Mode/Subsystem/Saturation Dynamic'
 * '<S22>'  : 'RBM/Subsystem/RB_Disable_Mode/Subsystem/Saturation Dynamic1'
 * '<S23>'  : 'RBM/Subsystem/RB_Enable_Mode/CoastCncl'
 * '<S24>'  : 'RBM/Subsystem/RB_Enable_Mode/OutTorq Preprocessor'
 * '<S25>'  : 'RBM/Subsystem/RB_Enable_Mode/RBEna Signals'
 * '<S26>'  : 'RBM/Subsystem/RB_Enable_Mode/CoastCncl/Compare To Constant1'
 * '<S27>'  : 'RBM/Subsystem/RB_Enable_Mode/CoastCncl/Compare To Constant2'
 * '<S28>'  : 'RBM/Subsystem/RB_Enable_Mode/OutTorq Preprocessor/PTorq2NTorqSlowDown'
 * '<S29>'  : 'RBM/Subsystem/RB_Enable_Mode/OutTorq Preprocessor/TestMode Override'
 * '<S30>'  : 'RBM/Subsystem/RB_Enable_Mode/OutTorq Preprocessor/TorqueSaturation'
 * '<S31>'  : 'RBM/Subsystem/RB_Enable_Mode/OutTorq Preprocessor/TorqueSaturation/ExtLimit_Saturation1'
 * '<S32>'  : 'RBM/Subsystem/RB_Enable_Mode/RBEna Signals/AntiLightBrakeAcceleration'
 * '<S33>'  : 'RBM/Subsystem/RB_Enable_Mode/RBEna Signals/Prefill Function Judger'
 * '<S34>'  : 'RBM/Subsystem/RB_Enable_Mode/RBEna Signals/RB Enable To VCU'
 * '<S35>'  : 'RBM/Subsystem/RB_Enable_Mode/RBEna Signals/Torque Err Debounce'
 * '<S36>'  : 'RBM/Subsystem/RB_Enable_Mode/RBEna Signals/AntiLightBrakeAcceleration/CoastBrakeCalculator'
 * '<S37>'  : 'RBM/Subsystem/RB_Enable_Mode/RBEna Signals/AntiLightBrakeAcceleration/Compare To Zero'
 * '<S38>'  : 'RBM/Subsystem/RB_Enable_Mode/RBEna Signals/Prefill Function Judger/Chart'
 * '<S39>'  : 'RBM/Subsystem/RB_Enable_Mode/RBEna Signals/Prefill Function Judger/DownLimitToZero'
 * '<S40>'  : 'RBM/Subsystem/RB_Enable_Mode/RBEna Signals/Prefill Function Judger/PrefillPressure'
 * '<S41>'  : 'RBM/Subsystem/RB_Enable_Mode/RBEna Signals/Prefill Function Judger/tq2p'
 * '<S42>'  : 'RBM/Subsystem/RB_Enable_Mode/RBEna Signals/Prefill Function Judger/tq2p/DownLimitToZero'
 * '<S43>'  : 'RBM/Subsystem/RB_Enable_Mode/RBEna Signals/RB Enable To VCU/Compare To Constant6'
 * '<S44>'  : 'RBM/Subsystem/RB_Enable_Mode/RBEna Signals/Torque Err Debounce/Compare To Constant1'
 * '<S45>'  : 'RBM/Subsystem/RB_Enable_Mode/RBEna Signals/Torque Err Debounce/Err_Debounce'
 * '<S46>'  : 'RBM/Subsystem/RB_Quit_Mode/Subsystem1'
 * '<S47>'  : 'RBM/Subsystem/RB_Quit_Mode/Subsystem2'
 * '<S48>'  : 'RBM/Subsystem/RB_Quit_Mode/Subsystem1/EHBAimP'
 * '<S49>'  : 'RBM/Subsystem/RB_Quit_Mode/Subsystem1/PrefillPressure'
 * '<S50>'  : 'RBM/Subsystem/RB_Quit_Mode/Subsystem1/RB Enable To VCU'
 * '<S51>'  : 'RBM/Subsystem/RB_Quit_Mode/Subsystem1/EHBAimP/quit dp2dp'
 * '<S52>'  : 'RBM/Subsystem/RB_Quit_Mode/Subsystem1/RB Enable To VCU/Compare To Constant6'
 * '<S53>'  : 'RBM/Subsystem/RB_Quit_Mode/Subsystem2/AimTorque'
 * '<S54>'  : 'RBM/Subsystem/RB_Quit_Mode/Subsystem2/CoastLmtCtrl'
 * '<S55>'  : 'RBM/Subsystem/RB_Quit_Mode/Subsystem2/QuitTorqDelayOut'
 * '<S56>'  : 'RBM/Subsystem/RB_Quit_Mode/Subsystem2/Saturation Dynamic'
 * '<S57>'  : 'RBM/Subsystem/RB_Quit_Mode/Subsystem2/dpcaculator'
 * '<S58>'  : 'RBM/Subsystem/RB_Quit_Mode/Subsystem2/dpcaculator_ABSActive'
 * '<S59>'  : 'RBM/Subsystem/RB_Quit_Mode/Subsystem2/AimTorque/TqDelay'
 * '<S60>'  : 'RBM/Subsystem/RB_Quit_Mode/Subsystem2/AimTorque/p2tq'
 * '<S61>'  : 'RBM/Subsystem/RB_Quit_Mode/Subsystem2/AimTorque/TqDelay/Chart'
 * '<S62>'  : 'RBM/Subsystem/RB_Quit_Mode/Subsystem2/AimTorque/TqDelay/Compare To Constant'
 * '<S63>'  : 'RBM/Subsystem/RB_Quit_Mode/Subsystem2/AimTorque/TqDelay/Compare To Constant1'
 * '<S64>'  : 'RBM/Subsystem/RB_Quit_Mode/Subsystem2/CoastLmtCtrl/Compare To Constant1'
 * '<S65>'  : 'RBM/Subsystem/RB_Quit_Mode/Subsystem2/CoastLmtCtrl/Compare To Constant2'
 * '<S66>'  : 'RBM/Subsystem/RB_Quit_Mode/Subsystem2/QuitTorqDelayOut/Chart'
 * '<S67>'  : 'RBM/Subsystem/RB_Quit_Mode/Subsystem2/dpcaculator/dp_norm_caculator'
 * '<S68>'  : 'RBM/Subsystem/RB_Quit_Mode/Subsystem2/dpcaculator/pressure_rising_stopping'
 * '<S69>'  : 'RBM/Subsystem/RB_Quit_Mode/Subsystem2/dpcaculator/dp_norm_caculator/Lock QuitTorq'
 * '<S70>'  : 'RBM/Subsystem/RB_Quit_Mode/Subsystem2/dpcaculator/pressure_rising_stopping/Lock'
 * '<S71>'  : 'RBM/Subsystem/RB_Quit_Mode/Subsystem2/dpcaculator_ABSActive/Compare To Constant2'
 * '<S72>'  : 'RBM/Subsystem/RB_State_Judge/Compare To Constant'
 * '<S73>'  : 'RBM/Subsystem/RB_State_Judge/Compare To Constant1'
 * '<S74>'  : 'RBM/Subsystem/RB_State_Judge/Compare To Constant2'
 * '<S75>'  : 'RBM/Subsystem/RB_State_Judge/Compare To Constant3'
 * '<S76>'  : 'RBM/Subsystem/RB_State_Judge/Compare To Constant4'
 * '<S77>'  : 'RBM/Subsystem/RB_State_Judge/Compare To Constant5'
 * '<S78>'  : 'RBM/Subsystem/RB_State_Judge/Compare To Constant6'
 * '<S79>'  : 'RBM/Subsystem/RB_State_Judge/Compare To Constant7'
 * '<S80>'  : 'RBM/Subsystem/RB_State_Judge/Compare To Constant8'
 * '<S81>'  : 'RBM/Subsystem/RB_State_Judge/Compare To Constant9'
 * '<S82>'  : 'RBM/Subsystem/RB_State_Judge/Diag'
 * '<S83>'  : 'RBM/Subsystem/RB_State_Judge/RBState_Judge'
 * '<S84>'  : 'RBM/Subsystem/RB_State_Judge/Subsystem'
 * '<S85>'  : 'RBM/Subsystem/RB_State_Judge/Subsystem1'
 * '<S86>'  : 'RBM/Subsystem/RB_State_Judge/override'
 * '<S87>'  : 'RBM/Subsystem/RB_State_Judge/Diag/Compare To Constant'
 * '<S88>'  : 'RBM/Subsystem/RB_State_Judge/Diag/Compare To Constant1'
 * '<S89>'  : 'RBM/Subsystem/RB_State_Judge/Diag/Compare To Constant10'
 * '<S90>'  : 'RBM/Subsystem/RB_State_Judge/Diag/Compare To Constant11'
 * '<S91>'  : 'RBM/Subsystem/RB_State_Judge/Diag/Compare To Constant12'
 * '<S92>'  : 'RBM/Subsystem/RB_State_Judge/Diag/Compare To Constant13'
 * '<S93>'  : 'RBM/Subsystem/RB_State_Judge/Diag/Compare To Constant14'
 * '<S94>'  : 'RBM/Subsystem/RB_State_Judge/Diag/Compare To Constant15'
 * '<S95>'  : 'RBM/Subsystem/RB_State_Judge/Diag/Compare To Constant16'
 * '<S96>'  : 'RBM/Subsystem/RB_State_Judge/Diag/Compare To Constant2'
 * '<S97>'  : 'RBM/Subsystem/RB_State_Judge/Diag/Compare To Constant3'
 * '<S98>'  : 'RBM/Subsystem/RB_State_Judge/Diag/Compare To Constant4'
 * '<S99>'  : 'RBM/Subsystem/RB_State_Judge/Diag/Compare To Constant5'
 * '<S100>' : 'RBM/Subsystem/RB_State_Judge/Diag/Compare To Constant6'
 * '<S101>' : 'RBM/Subsystem/RB_State_Judge/Diag/Compare To Constant7'
 * '<S102>' : 'RBM/Subsystem/RB_State_Judge/Diag/Compare To Constant8'
 * '<S103>' : 'RBM/Subsystem/RB_State_Judge/Diag/Compare To Constant9'
 * '<S104>' : 'RBM/Subsystem/RB_State_Judge/Subsystem/Compare To Constant'
 * '<S105>' : 'RBM/Subsystem/RB_State_Judge/Subsystem/Compare To Constant1'
 * '<S106>' : 'RBM/Subsystem/RB_State_Judge/Subsystem1/Chart'
 * '<S107>' : 'RBM/Subsystem/Subsystem/Compare To Constant'
 * '<S108>' : 'RBM/Subsystem/Subsystem/Compare To Constant1'
 * '<S109>' : 'RBM/Subsystem/Subsystem/Compare To Constant2'
 * '<S110>' : 'RBM/Subsystem/Subsystem/Compare To Constant3'
 * '<S111>' : 'RBM/Subsystem/Subsystem1/Chart'
 */

/*-
 * Requirements for '<Root>': RBM
 */
#endif                                 /* RTW_HEADER_RBM_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
