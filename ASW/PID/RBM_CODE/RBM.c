/*
 * File: RBM.c
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

#include "RBM.h"
#include "RBM_private.h"
#include "asr_s32.h"
#include "div_nde_s32_floor.h"
#include "look1_is16bs16n2lu16n16ys16n7ts16n7Ds32Is_rwYpbjoD.h"
#include "look1_is16lu16n16Ds32_pbinlca.h"
#include "look1_is16lu16n16ys16Ds32Is32_binlcan.h"
#include "look1_is16lu16n16ys16n10ts16n10Ds32Is32_binlcan.h"
#include "look1_is16lu16n16ys16n7Ds32Is32_binlcan.h"
#include "look1_is16lu16n16ys16ts16Ds32Is32_binlcan.h"
#include "look1_is16lu8n8yu8tu8Ds16Is32n23_binlcan.h"
#include "look1_iu8lu32n16ys16ts16Ds32Is32_binlcs.h"
#include "look2_is16s16lu32n16ts16Ds32ds32_binlcs.h"
#include "look2_is16u8lu32n16ys16ts16Ds32Is32_binlcs.h"

/* Named constants for Chart: '<S1>/Chart' */
#define RBM_CALL_EVENT                 (-1)
#define RBM_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Named constants for Chart: '<S12>/RBState_Judge' */
#define RBM_IN_Quit2DisableDelay       ((uint8_T)1U)
#define RBM_IN_RB_Disable              ((uint8_T)2U)
#define RBM_IN_RB_Enable               ((uint8_T)3U)
#define RBM_IN_RB_ForceQuit            ((uint8_T)4U)
#define RBM_IN_RB_Quit                 ((uint8_T)5U)

/* Named constants for Chart: '<S85>/Chart' */
#define RBM_IN_ABS_Active              ((uint8_T)1U)
#define RBM_IN_ABS_DeActive            ((uint8_T)2U)
#define RBM_IN_Normal                  ((uint8_T)3U)

/* Named constants for Chart: '<S8>/Chart' */
#define RBM_IN_DefaultQuit             ((uint8_T)1U)
#define RBM_IN_FastQuit                ((uint8_T)2U)
#define RBM_IN_SlowQuit                ((uint8_T)3U)

/* Named constants for Chart: '<S33>/Chart' */
#define RBM_IN_Disable                 ((uint8_T)1U)
#define RBM_IN_Enable                  ((uint8_T)2U)

/* Named constants for Chart: '<S59>/Chart' */
#define RBM_IN_delay                   ((uint8_T)1U)

/* Named constants for Chart: '<S67>/Lock QuitTorq' */
#define RBM_IN_LockTorq                ((uint8_T)1U)

/* Named constants for Chart: '<S68>/Lock' */
#define RBM_IN_Lock                    ((uint8_T)1U)
#define RBM_IN_UnLock                  ((uint8_T)2U)

/* Exported block signals */
int16_T dAimP;                         /* '<S16>/Add' */
int16_T dPQuit;                        /* '<S20>/Multiport Switch1' */

/* Exported data definition */

/* Definition for custom storage class: Default */
uint8_T RB_Ver[9];

/* Block signals and states (default storage) */
DW_RBM RBM_DW;

/* Model step function */
void RBM_step(void)
{
    boolean_T sf_internal_predicateOutput;
    boolean_T b_sf_internal_predicateOutput;
    boolean_T c_sf_internal_predicateOutput;
    boolean_T d_sf_internal_predicateOutput;
    boolean_T e_sf_internal_predicateOutput;
    boolean_T f_sf_internal_predicateOutput;
    boolean_T g_sf_internal_predicateOutput;
    uint8_T delayLen;
    int_T idxDelay;
    boolean_T sf_internal_predicateOutput_0;
    boolean_T b_sf_internal_predicateOutput_0;
    boolean_T sf_internal_predicateOutput_1;
    boolean_T b_sf_internal_predicateOutput_1;
    uint8_T rtb_Compare_ax;
    uint8_T rtb_Compare_dm;
    int16_T rtb_MtrTqAct;
    int16_T rtb_EHBQuitSpdMap;
    int16_T rtb_MotorCharacterMap;
    int8_T rtPrevAction;
    int8_T rtAction;
    int16_T rtb_Saturation1;
    uint8_T rtb_Switch_be;
    uint8_T rtb_Switch1_p;
    uint8_T rtb_Switch3_f;
    uint8_T rtb_Switch1_n;
    uint8_T rtb_Switch2_h;
    uint8_T rtb_Switch4;
    uint8_T rtb_Switch5_p;
    uint8_T rtb_Switch6_l;
    uint8_T rtb_Switch7;
    uint8_T rtb_Switch8;
    uint8_T rtb_Switch3_ae;
    uint8_T rtb_Switch9;
    uint8_T rtb_Switch10;
    uint8_T rtb_Switch11;
    uint8_T rtb_Switch12;
    uint8_T rtb_Switch13;
    uint8_T rtb_Switch14;
    uint8_T rtb_Switch15;
    uint8_T rtb_Switch16;
    uint8_T rtb_Switch17;
    uint8_T rtb_out_l;
    int16_T rtb_Switch_f;
    int16_T rtb_Switch_m3;
    int16_T rtb_Add_g;
    int16_T rtb_Switch2_k;
    int16_T rtb_Add1_ex;
    int16_T rtb_Switch_g;
    uint8_T rtb_out_k;
    uint8_T rtb_Compare_b;
    int16_T rtb_Min;
    int16_T rtb_Max1_l;
    int16_T rtb_Delay;
    int16_T rtb_TmpSignalConversionAtSumofElementsInport1[8];
    int32_T tmp;
    int32_T i;
    int16_T rtb_TmpSignalConversionAtSumofElements1Inport1[9];
    int32_T tmp_0;
    int32_T i_0;
    int16_T rtb_Add1_n;
    int16_T rtb_Switch_kw;
    int16_T rtb_Switch_i;
    int16_T rtb_Min_n;
    int16_T rtb_Switch1;
    int16_T rtb_Switch2_m;
    int16_T rtb_Switch_mq;
    uint8_T rtb_out_fk;
    uint8_T rtb_out;
    int16_T rtb_outtq;
    uint8_T rtb_DelayMap;
    int16_T rtb_Switch_j;
    int16_T rtb_EPSCharacterMap;
    int16_T rtb_Add1;
    int16_T rtb_Switch2_eb;
    int16_T rtb_Switch_nj;
    int16_T rtb_Switch5;
    int16_T rtb_Switch3;
    int16_T rtb_Switch6;
    int16_T rtb_Switch2;
    int16_T rtb_Switch;
    int16_T rtb_judgeABS;
    int16_T rtb_Switch_m;
    int16_T rtb_Product1;
    int16_T rtb_EHBPrefillPressureMap;
    int16_T rtb_EHBPrefillPressureMap_a;
    int32_T tmp_1;
    int32_T tmp_2;
    int32_T tmp_3;
    int32_T tmp_4;
    int32_T tmp_5;
    uint32_T tmp_6;
    uint32_T tmp_7;
    uint32_T tmp_8;
    uint32_T tmp_9;
    int16_T u0;
    int16_T u0_0;
    int16_T u1;
    int16_T u0_1;
    int16_T y;
    int16_T u1_0;
    int16_T y_0;
    int16_T u;
    int16_T y_1;
    int16_T u_0;
    int16_T y_2;
    int16_T u_1;
    int16_T y_3;
    int16_T u_2;
    int16_T y_4;
    int16_T u_3;

    /* Switch: '<S12>/Switch' incorporates:
     *  Constant: '<S12>/Constant1'
     *  Constant: '<S12>/Constant2'
     *  Constant: '<S1>/Constant'
     */
    if (((int32_T)K_RBM_TotFctEna_u8_Flg) != 0)
    {
        rtb_Switch_be = 15;
    }
    else
    {
        rtb_Switch_be = 1;
    }

    /* End of Switch: '<S12>/Switch' */

    /* Switch: '<S84>/Switch3' incorporates:
     *  Constant: '<S104>/Constant'
     *  Constant: '<S105>/Constant'
     *  Constant: '<S84>/Constant8'
     *  Inport: '<Root>/V_InRBM_EhbErrMod_u8_Mode'
     *  RelationalOperator: '<S104>/Compare'
     *  RelationalOperator: '<S105>/Compare'
     *  Switch: '<S84>/Switch1'
     *
     * Block description for '<Root>/V_InRBM_EhbErrMod_u8_Mode':
     *  0: no error 1: EHB degraded 2: EHB broken
     */
    if (((int32_T)V_InRBM_EhbErrMod_u8_Mode) == 0)
    {
        rtb_Switch3_f = 15;
    }
    else
    {
        if (((int32_T)V_InRBM_EhbErrMod_u8_Mode) == 1)
        {
            /* Switch: '<S84>/Switch1' incorporates:
             *  Constant: '<S84>/Constant1'
             */
            rtb_Switch1_p = 15;
        }
        else
        {
            /* Switch: '<S84>/Switch1' incorporates:
             *  Constant: '<S84>/Constant7'
             */
            rtb_Switch1_p = 9;
        }

        rtb_Switch3_f = rtb_Switch1_p;
    }

    /* End of Switch: '<S84>/Switch3' */

    /* Switch: '<S12>/Switch1' incorporates:
     *  Constant: '<S12>/Constant3'
     *  Constant: '<S12>/Constant4'
     *  Inport: '<Root>/V_InRBM_LostChassisCan_u8_Err'
     */
    if (((int32_T)V_InRBM_LostChassisCan_u8_Err) != 0)
    {
        rtb_Switch1_n = 5;
    }
    else
    {
        rtb_Switch1_n = 15;
    }

    /* End of Switch: '<S12>/Switch1' */

    /* Switch: '<S12>/Switch2' incorporates:
     *  Constant: '<S12>/Constant5'
     *  Constant: '<S12>/Constant6'
     *  Inport: '<Root>/V_InRBM_LostPtCan_u8_Err'
     */
    if (((int32_T)V_InRBM_LostPtCan_u8_Err) != 0)
    {
        rtb_Switch2_h = 1;
    }
    else
    {
        rtb_Switch2_h = 15;
    }

    /* End of Switch: '<S12>/Switch2' */

    /* Switch: '<S12>/Switch4' incorporates:
     *  Constant: '<S12>/Constant10'
     *  Constant: '<S12>/Constant9'
     *  Inport: '<Root>/V_InRBM_RbmEnaFromVcu_u8_Flg'
     */
    if (((int32_T)V_InRBM_RbmEnaFromVcu_u8_Flg) != 0)
    {
        rtb_Switch4 = 15;
    }
    else
    {
        rtb_Switch4 = 1;
    }

    /* End of Switch: '<S12>/Switch4' */

    /* Switch: '<S12>/Switch5' incorporates:
     *  Constant: '<S12>/Constant11'
     *  Constant: '<S12>/Constant12'
     *  Constant: '<S72>/Constant'
     *  Inport: '<Root>/V_InRBM_GasPdlStk_u8_Vld'
     *  RelationalOperator: '<S72>/Compare'
     */
    if (((int32_T)V_InRBM_GasPdlStk_u8_Vld) == 2)
    {
        rtb_Switch5_p = 15;
    }
    else
    {
        rtb_Switch5_p = 13;
    }

    /* End of Switch: '<S12>/Switch5' */

    /* Switch: '<S12>/Switch6' incorporates:
     *  Constant: '<S12>/Constant13'
     *  Constant: '<S12>/Constant14'
     *  Constant: '<S73>/Constant'
     *  Inport: '<Root>/V_InRBM_MtrTqLim_u8_Vld'
     *  RelationalOperator: '<S73>/Compare'
     */
    if (((int32_T)V_InRBM_MtrTqLim_u8_Vld) == 2)
    {
        rtb_Switch6_l = 15;
    }
    else
    {
        rtb_Switch6_l = 1;
    }

    /* End of Switch: '<S12>/Switch6' */

    /* Switch: '<S12>/Switch7' incorporates:
     *  Constant: '<S12>/Constant15'
     *  Constant: '<S12>/Constant16'
     *  Inport: '<Root>/V_InRBM_PtMinorFlt_u8_Err'
     */
    if (((int32_T)V_InRBM_PtMinorFlt_u8_Err) != 0)
    {
        rtb_Switch7 = 5;
    }
    else
    {
        rtb_Switch7 = 15;
    }

    /* End of Switch: '<S12>/Switch7' */

    /* Switch: '<S12>/Switch8' incorporates:
     *  Constant: '<S12>/Constant17'
     *  Constant: '<S12>/Constant18'
     *  Inport: '<Root>/V_InRBM_PtSevereFlt_u8_Err'
     */
    if (((int32_T)V_InRBM_PtSevereFlt_u8_Err) != 0)
    {
        rtb_Switch8 = 1;
    }
    else
    {
        rtb_Switch8 = 15;
    }

    /* End of Switch: '<S12>/Switch8' */

    /* Switch: '<S86>/Switch' incorporates:
     *  Constant: '<S86>/Constant'
     *  Constant: '<S86>/Constant1'
     *  Inport: '<Root>/V_InRBM_GearPosnAct_u8_Mode'
     */
    if (((int32_T)K_RB_GearOverride_Ena) > 0)
    {
        rtb_Switch3_ae = K_RB_GearOverride_Flg;
    }
    else
    {
        rtb_Switch3_ae = V_InRBM_GearPosnAct_u8_Mode;
    }

    /* End of Switch: '<S86>/Switch' */

    /* Switch: '<S12>/Switch9' incorporates:
     *  Constant: '<S12>/Constant19'
     *  Constant: '<S12>/Constant20'
     */
    if (((int32_T)rtb_Switch3_ae) != 0)
    {
        rtb_Switch9 = 15;
    }
    else
    {
        rtb_Switch9 = 1;
    }

    /* End of Switch: '<S12>/Switch9' */

    /* Switch: '<S12>/Switch10' incorporates:
     *  Constant: '<S12>/Constant21'
     *  Constant: '<S12>/Constant22'
     *  Constant: '<S74>/Constant'
     *  Inport: '<Root>/V_InRBM_VehSpd_u8_Vld'
     *  RelationalOperator: '<S74>/Compare'
     */
    if (((int32_T)V_InRBM_VehSpd_u8_Vld) == 2)
    {
        rtb_Switch10 = 15;
    }
    else
    {
        rtb_Switch10 = 1;
    }

    /* End of Switch: '<S12>/Switch10' */

    /* Switch: '<S12>/Switch11' incorporates:
     *  Constant: '<S12>/Constant23'
     *  Constant: '<S12>/Constant24'
     *  Inport: '<Root>/V_InRBM_ChassisFlt_u8_Err'
     */
    if (((int32_T)V_InRBM_ChassisFlt_u8_Err) != 0)
    {
        rtb_Switch11 = 5;
    }
    else
    {
        rtb_Switch11 = 15;
    }

    /* End of Switch: '<S12>/Switch11' */

    /* Switch: '<S12>/Switch12' incorporates:
     *  Constant: '<S12>/Constant25'
     *  Constant: '<S12>/Constant26'
     *  Constant: '<S75>/Constant'
     *  Inport: '<Root>/V_InRBM_EpsSteerAg_u8_Vld'
     *  RelationalOperator: '<S75>/Compare'
     */
    if (((int32_T)V_InRBM_EpsSteerAg_u8_Vld) == 2)
    {
        rtb_Switch12 = 15;
    }
    else
    {
        rtb_Switch12 = 1;
    }

    /* End of Switch: '<S12>/Switch12' */

    /* Switch: '<S12>/Switch13' incorporates:
     *  Constant: '<S12>/Constant27'
     *  Constant: '<S12>/Constant28'
     *  Constant: '<S76>/Constant'
     *  Inport: '<Root>/V_InRBM_MtrSpd_u8_Vld'
     *  RelationalOperator: '<S76>/Compare'
     */
    if (((int32_T)V_InRBM_MtrSpd_u8_Vld) == 2)
    {
        rtb_Switch13 = 15;
    }
    else
    {
        rtb_Switch13 = 1;
    }

    /* End of Switch: '<S12>/Switch13' */

    /* Switch: '<S12>/Switch14' incorporates:
     *  Constant: '<S12>/Constant29'
     *  Constant: '<S12>/Constant30'
     *  Constant: '<S77>/Constant'
     *  Inport: '<Root>/V_InRBM_MtrTqAct_u8_Vld'
     *  RelationalOperator: '<S77>/Compare'
     */
    if (((int32_T)V_InRBM_MtrTqAct_u8_Vld) == 2)
    {
        rtb_Switch14 = 15;
    }
    else
    {
        rtb_Switch14 = 1;
    }

    /* End of Switch: '<S12>/Switch14' */

    /* Chart: '<S85>/Chart' incorporates:
     *  Inport: '<Root>/V_InRBM_AbsActv_u8_Flg'
     *  Inport: '<Root>/V_InRBM_PTar_s16s7_Bar'
     */
    /* Gateway: Subsystem/RB_State_Judge/Subsystem1/Chart */
    /* During: Subsystem/RB_State_Judge/Subsystem1/Chart */
    if (((uint32_T)RBM_DW.is_active_c5_RBM) == 0U)
    {
        /* Entry: Subsystem/RB_State_Judge/Subsystem1/Chart */
        RBM_DW.is_active_c5_RBM = 1;

        /* Entry Internal: Subsystem/RB_State_Judge/Subsystem1/Chart */
        /* Transition: '<S106>:7' */
        RBM_DW.is_c5_RBM = RBM_IN_Normal;

        /* Entry 'Normal': '<S106>:6' */
        rtb_out_l = 15;
    }
    else
    {
        switch (RBM_DW.is_c5_RBM)
        {
          case RBM_IN_ABS_Active:
            /* During 'ABS_Active': '<S106>:8' */
            if (!(((int32_T)V_InRBM_AbsActv_u8_Flg) != 0))
            {
                /* Transition: '<S106>:19' */
                RBM_DW.is_c5_RBM = RBM_IN_ABS_DeActive;

                /* Entry 'ABS_DeActive': '<S106>:18' */
                rtb_out_l = 5;
            }
            else
            {
                rtb_out_l = 5;
            }
            break;

          case RBM_IN_ABS_DeActive:
            /* During 'ABS_DeActive': '<S106>:18' */
            if (V_InRBM_PTar_s16s7_Bar < 128)
            {
                /* Transition: '<S106>:15' */
                RBM_DW.is_c5_RBM = RBM_IN_Normal;

                /* Entry 'Normal': '<S106>:6' */
                rtb_out_l = 15;
            }
            else
            {
                rtb_out_l = 5;
            }
            break;

          default:
            /* During 'Normal': '<S106>:6' */
            if (((int32_T)V_InRBM_AbsActv_u8_Flg) != 0)
            {
                /* Transition: '<S106>:12' */
                RBM_DW.is_c5_RBM = RBM_IN_ABS_Active;

                /* Entry 'ABS_Active': '<S106>:8' */
                rtb_out_l = 5;
            }
            else
            {
                rtb_out_l = 15;
            }
            break;
        }
    }

    /* End of Chart: '<S85>/Chart' */

    /* Delay: '<S1>/Delay2' */
    V_RBM_FormerTorqueErrorOver_u8_Err = RBM_DW.Delay2_DSTATE;

    /* Switch: '<S12>/Switch15' incorporates:
     *  Constant: '<S12>/Constant33'
     *  Constant: '<S12>/Constant34'
     */
    if (((int32_T)V_RBM_FormerTorqueErrorOver_u8_Err) != 0)
    {
        rtb_Switch15 = 5;
    }
    else
    {
        rtb_Switch15 = 15;
    }

    /* End of Switch: '<S12>/Switch15' */

    /* Outputs for Enabled SubSystem: '<S1>/Subsystem' incorporates:
     *  EnablePort: '<S13>/Enable'
     */
    /* RelationalOperator: '<S6>/Compare' incorporates:
     *  Inport: '<Root>/V_InRBM_PTar_s16s7_Bar'
     */
    if (V_InRBM_PTar_s16s7_Bar >= 384)
    {
        if (!RBM_DW.Subsystem_MODE)
        {
            RBM_DW.Subsystem_MODE = true;
        }

        /* Sum: '<S13>/Add3' incorporates:
         *  Inport: '<Root>/V_InRBM_RRWhlSpd_s16_0P1Kph'
         *  Inport: '<Root>/V_InRBM_VehSpd_s16_0P1Kph'
         */
        u = (int16_T)(V_InRBM_RRWhlSpd_s16_0P1Kph - V_InRBM_VehSpd_s16_0P1Kph);

        /* Abs: '<S13>/Abs3' */
        if (u < 0)
        {
            y_0 = (int16_T)(-u);
        }
        else
        {
            y_0 = u;
        }

        /* End of Abs: '<S13>/Abs3' */

        /* Sum: '<S13>/Add' incorporates:
         *  Inport: '<Root>/V_InRBM_FLWhlSpd_s16_0P1Kph'
         *  Inport: '<Root>/V_InRBM_VehSpd_s16_0P1Kph'
         */
        u_1 = (int16_T)(V_InRBM_FLWhlSpd_s16_0P1Kph - V_InRBM_VehSpd_s16_0P1Kph);

        /* Abs: '<S13>/Abs' */
        if (u_1 < 0)
        {
            y_2 = (int16_T)(-u_1);
        }
        else
        {
            y_2 = u_1;
        }

        /* End of Abs: '<S13>/Abs' */

        /* Sum: '<S13>/Add1' incorporates:
         *  Inport: '<Root>/V_InRBM_FRWhlSpd_s16_0P1Kph'
         *  Inport: '<Root>/V_InRBM_VehSpd_s16_0P1Kph'
         */
        u_2 = (int16_T)(V_InRBM_FRWhlSpd_s16_0P1Kph - V_InRBM_VehSpd_s16_0P1Kph);

        /* Abs: '<S13>/Abs1' */
        if (u_2 < 0)
        {
            y_3 = (int16_T)(-u_2);
        }
        else
        {
            y_3 = u_2;
        }

        /* End of Abs: '<S13>/Abs1' */

        /* Sum: '<S13>/Add2' incorporates:
         *  Inport: '<Root>/V_InRBM_RLWhlSpd_s16_0P1Kph'
         *  Inport: '<Root>/V_InRBM_VehSpd_s16_0P1Kph'
         */
        u_3 = (int16_T)(V_InRBM_RLWhlSpd_s16_0P1Kph - V_InRBM_VehSpd_s16_0P1Kph);

        /* Abs: '<S13>/Abs2' */
        if (u_3 < 0)
        {
            y_4 = (int16_T)(-u_3);
        }
        else
        {
            y_4 = u_3;
        }

        /* End of Abs: '<S13>/Abs2' */

        /* DataTypeConversion: '<S13>/Data Type Conversion' incorporates:
         *  Constant: '<S107>/Constant'
         *  Constant: '<S108>/Constant'
         *  Constant: '<S109>/Constant'
         *  Constant: '<S110>/Constant'
         *  Logic: '<S13>/Logical Operator'
         *  RelationalOperator: '<S107>/Compare'
         *  RelationalOperator: '<S108>/Compare'
         *  RelationalOperator: '<S109>/Compare'
         *  RelationalOperator: '<S110>/Compare'
         */
        V_RBM_WhlSpdSlip_u8_Err = (uint8_T)(((((y_2 >=
            K_RB_WheelSpdThreshold_kph) || (y_3 >= K_RB_WheelSpdThreshold_kph)) ||
            (y_4 >= K_RB_WheelSpdThreshold_kph)) || (y_0 >=
            K_RB_WheelSpdThreshold_kph)) ? 1 : 0);
    }
    else
    {
        if (RBM_DW.Subsystem_MODE)
        {
            /* Disable for Outport: '<S13>/Out1' */
            V_RBM_WhlSpdSlip_u8_Err = 0;
            RBM_DW.Subsystem_MODE = false;
        }
    }

    /* End of RelationalOperator: '<S6>/Compare' */
    /* End of Outputs for SubSystem: '<S1>/Subsystem' */

    /* Switch: '<S12>/Switch3' incorporates:
     *  Constant: '<S12>/Constant35'
     *  Constant: '<S12>/Constant8'
     */
    if (((int32_T)V_RBM_WhlSpdSlip_u8_Err) != 0)
    {
        rtb_Switch3_ae = 5;
    }
    else
    {
        rtb_Switch3_ae = 15;
    }

    /* End of Switch: '<S12>/Switch3' */

    /* Switch: '<S12>/Switch16' incorporates:
     *  Constant: '<S12>/Constant32'
     *  Constant: '<S12>/Constant37'
     *  Constant: '<S12>/Constant38'
     */
    if (((int32_T)K_RB_ForceQuit_Ena) != 0)
    {
        rtb_Switch16 = 5;
    }
    else
    {
        rtb_Switch16 = 15;
    }

    /* End of Switch: '<S12>/Switch16' */

    /* Switch: '<S12>/Switch17' incorporates:
     *  Constant: '<S12>/Constant39'
     *  Constant: '<S12>/Constant40'
     *  Constant: '<S12>/Constant41'
     */
    if (((int32_T)K_RB_ForceDisable_Ena) != 0)
    {
        rtb_Switch17 = 1;
    }
    else
    {
        rtb_Switch17 = 15;
    }

    /* End of Switch: '<S12>/Switch17' */

    /* S-Function (sfix_bitop): '<S12>/Bitwise Operator' */
    V_RB_RBModeMask_Flg = (uint8_T)(((uint8_T)(((uint8_T)(((uint8_T)(((uint8_T)
        (((uint8_T)(((uint8_T)(((uint8_T)(((uint8_T)(((uint8_T)(((uint8_T)
        (((uint8_T)(((uint8_T)(((uint8_T)(((uint8_T)(((uint8_T)(((uint8_T)
        (((uint8_T)(((uint8_T)(rtb_Switch_be & rtb_Switch3_f)) & rtb_Switch1_n))
        & rtb_Switch2_h)) & rtb_Switch4)) & rtb_Switch5_p)) & rtb_Switch6_l)) &
        rtb_Switch7)) & rtb_Switch8)) & rtb_Switch9)) & rtb_Switch10)) &
        rtb_Switch11)) & rtb_Switch12)) & rtb_Switch13)) & rtb_Switch14)) &
         rtb_out_l)) & rtb_Switch15)) & rtb_Switch3_ae)) & rtb_Switch16)) &
        rtb_Switch17);

    /* RelationalOperator: '<S79>/Compare' incorporates:
     *  Constant: '<S79>/Constant'
     *  S-Function (sfix_bitop): '<S12>/Bitwise OR1'
     */
    rtb_Compare_ax = (uint8_T)((((int32_T)((uint8_T)(((uint32_T)
        V_RB_RBModeMask_Flg) & 2))) == 2) ? 1 : 0);

    /* RelationalOperator: '<S80>/Compare' incorporates:
     *  Constant: '<S80>/Constant'
     *  S-Function (sfix_bitop): '<S12>/Bitwise OR2'
     */
    rtb_Compare_dm = (uint8_T)((((int32_T)((uint8_T)(((uint32_T)
        V_RB_RBModeMask_Flg) & 4))) == 4) ? 1 : 0);

    /* Saturate: '<S1>/Saturation' incorporates:
     *  Inport: '<Root>/V_InRBM_MtrTqAct_s16_0P1Nm'
     */
    if (V_InRBM_MtrTqAct_s16_0P1Nm > 0)
    {
        rtb_MtrTqAct = 0;
    }
    else if (V_InRBM_MtrTqAct_s16_0P1Nm < -4000)
    {
        rtb_MtrTqAct = -4000;
    }
    else
    {
        rtb_MtrTqAct = V_InRBM_MtrTqAct_s16_0P1Nm;
    }

    /* End of Saturate: '<S1>/Saturation' */

    /* Lookup_n-D: '<S12>/EHB QuitSpd Map' incorporates:
     *  Inport: '<Root>/V_InRBM_PTar_s16s7_Bar'
     */
    rtb_EHBQuitSpdMap = look1_is16lu16n16ys16ts16Ds32Is32_binlcan
        (V_InRBM_PTar_s16s7_Bar, (&(K_RB_MapQuitMotorSpd_InP_s16En7Bar[0])),
         (&(K_RB_MapQuitMotorSpd_OutSpd_Rpm[0])), 12U);

    /* Sum: '<S12>/Add1' incorporates:
     *  Constant: '<S12>/Constant31'
     */
    rtb_Add1_n = (int16_T)(rtb_EHBQuitSpdMap + K_RB_CutInMotorSpdDelta_Rpm);

    /* Chart: '<S12>/RBState_Judge' incorporates:
     *  Constant: '<S12>/Constant36'
     *  Constant: '<S12>/Constant42'
     *  Constant: '<S78>/Constant'
     *  Inport: '<Root>/V_InRBM_MtrSpd_s16_rpm'
     *  Inport: '<Root>/V_InRBM_PTar_s16s7_Bar'
     *  RelationalOperator: '<S78>/Compare'
     *  S-Function (sfix_bitop): '<S12>/Bitwise OR'
     */
    /* Gateway: Subsystem/RB_State_Judge/RBState_Judge */
    /* During: Subsystem/RB_State_Judge/RBState_Judge */
    if (((uint32_T)RBM_DW.is_active_c3_RBM) == 0U)
    {
        /* Entry: Subsystem/RB_State_Judge/RBState_Judge */
        RBM_DW.is_active_c3_RBM = 1;

        /* Entry Internal: Subsystem/RB_State_Judge/RBState_Judge */
        /* Transition: '<S83>:6' */
        RBM_DW.is_c3_RBM = RBM_IN_RB_Disable;

        /* Entry 'RB_Disable': '<S83>:5' */
        V_RB_RBState_Flg = 1;
    }
    else
    {
        switch (RBM_DW.is_c3_RBM)
        {
          case RBM_IN_Quit2DisableDelay:
            /* During 'Quit2DisableDelay': '<S83>:70' */
            if ((((int32_T)RBM_DW.Q2DEna) == 1) && (((int32_T)((uint8_T)
                    (((uint32_T)V_RB_RBModeMask_Flg) & 1))) == 1))
            {
                c_sf_internal_predicateOutput = true;
            }
            else
            {
                c_sf_internal_predicateOutput = false;
            }

            if (c_sf_internal_predicateOutput)
            {
                /* Transition: '<S83>:71' */
                RBM_DW.is_c3_RBM = RBM_IN_RB_Disable;

                /* Entry 'RB_Disable': '<S83>:5' */
                V_RB_RBState_Flg = 1;
            }
            else
            {
                /* Transition: '<S83>:89' */
                /* Transition: '<S83>:81' */
                tmp_8 = ((uint32_T)RBM_DW.DelayCnt) + 1U;
                if (tmp_8 > 65535U)
                {
                    tmp_8 = 65535U;
                }

                RBM_DW.DelayCnt = (uint16_T)tmp_8;

                /* Transition: '<S83>:88' */
                if (RBM_DW.DelayCnt < K_RB_Q2DDelay_u8_5ms)
                {
                    /* Transition: '<S83>:78' */
                    /* Transition: '<S83>:75' */
                    RBM_DW.Q2DEna = 0;
                }
                else
                {
                    if (RBM_DW.DelayCnt >= K_RB_Q2DDelay_u8_5ms)
                    {
                        /* Transition: '<S83>:82' */
                        /* Transition: '<S83>:77' */
                        RBM_DW.DelayCnt = K_RB_Q2DDelay_u8_5ms;

                        /* Transition: '<S83>:85' */
                        RBM_DW.Q2DEna = 1;
                    }
                }
            }
            break;

          case RBM_IN_RB_Disable:
            /* During 'RB_Disable': '<S83>:5' */
            if ((((int32_T)rtb_Compare_ax) != 0) && (V_InRBM_MtrSpd_s16_Rpm >
                    rtb_Add1_n))
            {
                d_sf_internal_predicateOutput = true;
            }
            else
            {
                d_sf_internal_predicateOutput = false;
            }

            if (d_sf_internal_predicateOutput)
            {
                /* Transition: '<S83>:14' */
                /* Transition: '<S83>:41' */
                RBM_DW.is_c3_RBM = RBM_IN_RB_Enable;

                /* Entry 'RB_Enable': '<S83>:7' */
                V_RB_RBState_Flg = 2;
            }
            else
            {
                V_RB_RBState_Flg = 1;
            }
            break;

          case RBM_IN_RB_Enable:
            /* During 'RB_Enable': '<S83>:7' */
            if (((int32_T)rtb_Compare_ax) == 0)
            {
                /* Transition: '<S83>:54' */
                if ((((int32_T)rtb_Compare_dm) != 0) && (V_InRBM_PTar_s16s7_Bar >
                     256))
                {
                    e_sf_internal_predicateOutput = true;
                }
                else
                {
                    e_sf_internal_predicateOutput = false;
                }

                if (e_sf_internal_predicateOutput)
                {
                    /* Transition: '<S83>:56' */
                    RBM_DW.is_c3_RBM = RBM_IN_RB_ForceQuit;

                    /* Entry 'RB_ForceQuit': '<S83>:53' */
                    V_RB_RBState_Flg = 3;
                }
                else
                {
                    /* Transition: '<S83>:50' */
                    RBM_DW.is_c3_RBM = RBM_IN_RB_Disable;

                    /* Entry 'RB_Disable': '<S83>:5' */
                    V_RB_RBState_Flg = 1;
                }
            }
            else if (V_InRBM_MtrSpd_s16_Rpm < rtb_EHBQuitSpdMap)
            {
                /* Transition: '<S83>:32' */
                if (V_InRBM_PTar_s16s7_Bar > 256)
                {
                    /* Transition: '<S83>:62' */
                    RBM_DW.is_c3_RBM = RBM_IN_RB_Quit;

                    /* Entry 'RB_Quit': '<S83>:8' */
                    V_RB_RBState_Flg = 3;
                }
                else
                {
                    /* Transition: '<S83>:63' */
                    /* Transition: '<S83>:66' */
                    /* Transition: '<S83>:67' */
                    RBM_DW.is_c3_RBM = RBM_IN_RB_Disable;

                    /* Entry 'RB_Disable': '<S83>:5' */
                    V_RB_RBState_Flg = 1;
                }
            }
            else
            {
                V_RB_RBState_Flg = 2;
            }
            break;

          case RBM_IN_RB_ForceQuit:
            /* During 'RB_ForceQuit': '<S83>:53' */
            if (((V_InRBM_MtrSpd_s16_Rpm < K_RB_CutOutMotorSpd_Rpm) ||
                    (((int32_T)rtb_Compare_dm) == 0)) || (V_InRBM_PTar_s16s7_Bar
                 < 256))
            {
                f_sf_internal_predicateOutput = true;
            }
            else
            {
                f_sf_internal_predicateOutput = false;
            }

            if (f_sf_internal_predicateOutput)
            {
                /* Transition: '<S83>:59' */
                /* Transition: '<S83>:43' */
                RBM_DW.is_c3_RBM = RBM_IN_Quit2DisableDelay;

                /* Entry Internal 'Quit2DisableDelay': '<S83>:70' */
                /* Transition: '<S83>:73' */
                RBM_DW.DelayCnt = 0;
                RBM_DW.Q2DEna = 0;

                /* Transition: '<S83>:81' */
                tmp_9 = ((uint32_T)RBM_DW.DelayCnt) + 1U;
                if (tmp_9 > 65535U)
                {
                    tmp_9 = 65535U;
                }

                RBM_DW.DelayCnt = (uint16_T)tmp_9;

                /* Transition: '<S83>:88' */
                if (RBM_DW.DelayCnt < K_RB_Q2DDelay_u8_5ms)
                {
                    /* Transition: '<S83>:78' */
                    /* Transition: '<S83>:75' */
                    RBM_DW.Q2DEna = 0;
                }
                else
                {
                    if (RBM_DW.DelayCnt >= K_RB_Q2DDelay_u8_5ms)
                    {
                        /* Transition: '<S83>:82' */
                        /* Transition: '<S83>:77' */
                        RBM_DW.DelayCnt = K_RB_Q2DDelay_u8_5ms;

                        /* Transition: '<S83>:85' */
                        RBM_DW.Q2DEna = 1;
                    }
                }
            }
            else
            {
                if (((((int32_T)rtb_Compare_ax) != 0) && (V_InRBM_MtrSpd_s16_Rpm
                      > rtb_Add1_n)) && (V_InRBM_PTar_s16s7_Bar < 128))
                {
                    g_sf_internal_predicateOutput = true;
                }
                else
                {
                    g_sf_internal_predicateOutput = false;
                }

                if (g_sf_internal_predicateOutput)
                {
                    /* Transition: '<S83>:98' */
                    RBM_DW.is_c3_RBM = RBM_IN_RB_Enable;

                    /* Entry 'RB_Enable': '<S83>:7' */
                    V_RB_RBState_Flg = 2;
                }
                else
                {
                    V_RB_RBState_Flg = 3;
                }
            }
            break;

          default:
            /* During 'RB_Quit': '<S83>:8' */
            if (((V_InRBM_MtrSpd_s16_Rpm < K_RB_CutOutMotorSpd_Rpm) ||
                    (((int32_T)rtb_Compare_dm) == 0)) || (V_InRBM_PTar_s16s7_Bar
                 < 256))
            {
                sf_internal_predicateOutput = true;
            }
            else
            {
                sf_internal_predicateOutput = false;
            }

            if (sf_internal_predicateOutput)
            {
                /* Transition: '<S83>:38' */
                /* Transition: '<S83>:43' */
                RBM_DW.is_c3_RBM = RBM_IN_Quit2DisableDelay;

                /* Entry Internal 'Quit2DisableDelay': '<S83>:70' */
                /* Transition: '<S83>:73' */
                RBM_DW.DelayCnt = 0;
                RBM_DW.Q2DEna = 0;

                /* Transition: '<S83>:81' */
                tmp_7 = ((uint32_T)RBM_DW.DelayCnt) + 1U;
                if (tmp_7 > 65535U)
                {
                    tmp_7 = 65535U;
                }

                RBM_DW.DelayCnt = (uint16_T)tmp_7;

                /* Transition: '<S83>:88' */
                if (RBM_DW.DelayCnt < K_RB_Q2DDelay_u8_5ms)
                {
                    /* Transition: '<S83>:78' */
                    /* Transition: '<S83>:75' */
                    RBM_DW.Q2DEna = 0;
                }
                else
                {
                    if (RBM_DW.DelayCnt >= K_RB_Q2DDelay_u8_5ms)
                    {
                        /* Transition: '<S83>:82' */
                        /* Transition: '<S83>:77' */
                        RBM_DW.DelayCnt = K_RB_Q2DDelay_u8_5ms;

                        /* Transition: '<S83>:85' */
                        RBM_DW.Q2DEna = 1;
                    }
                }
            }
            else
            {
                if ((((int32_T)rtb_Compare_ax) != 0) && (V_InRBM_MtrSpd_s16_Rpm >
                     rtb_Add1_n))
                {
                    b_sf_internal_predicateOutput = true;
                }
                else
                {
                    b_sf_internal_predicateOutput = false;
                }

                if (b_sf_internal_predicateOutput)
                {
                    /* Transition: '<S83>:45' */
                    /* Transition: '<S83>:46' */
                    RBM_DW.is_c3_RBM = RBM_IN_RB_Enable;

                    /* Entry 'RB_Enable': '<S83>:7' */
                    V_RB_RBState_Flg = 2;
                }
                else
                {
                    V_RB_RBState_Flg = 3;
                }
            }
            break;
        }
    }

    /* End of Chart: '<S12>/RBState_Judge' */

    /* Switch: '<S5>/Switch' incorporates:
     *  Constant: '<S5>/Constant'
     *  Inport: '<Root>/V_InRBM_CoastLvl_u8_Mode'
     *  Inport: '<Root>/V_InRBM_MtrSpd_s16_rpm'
     *  Lookup_n-D: '<S5>/Coast Level Map1'
     *  Lookup_n-D: '<S5>/CoastDown Spd Map'
     */
    if (((int32_T)K_RB_MultiCoastTenseEna_u8_Flg) > 0)
    {
        V_RBM_MtrTqCoast_s16_0P1Nm = look1_iu8lu32n16ys16ts16Ds32Is32_binlcs
            (V_InRBM_CoastLvl_u8_Mode, (&(K_RB_MapVCUCoastLevelIn_u8[0])),
             (&(K_RB_MapVCUCoastTorq_0P1Nm[0])), 4U);
    }
    else
    {
        V_RBM_MtrTqCoast_s16_0P1Nm = look1_is16lu16n16ys16Ds32Is32_binlcan
            (V_InRBM_MtrSpd_s16_Rpm, (&(K_RB_MapCoastDown_InSpd_rpm[0])),
             (&(K_RB_MapCoastDown_OutTq_0P1Nm[0])), 4U);
    }

    /* End of Switch: '<S5>/Switch' */

    /* Sum: '<S16>/Add' incorporates:
     *  Delay: '<S16>/Delay3'
     *  Inport: '<Root>/V_InRBM_PTar_s16s7_Bar'
     */
    dAimP = (int16_T)(V_InRBM_PTar_s16s7_Bar - RBM_DW.Delay3_DSTATE);

    /* Delay: '<S1>/Delay' */
    V_RBM_MtrTqTarFormer_s16_0P1Nm = RBM_DW.Delay_DSTATE;

    /* Delay: '<S1>/Delay1' */
    V_RBM_PTarFormer_s16s7_Bar = RBM_DW.Delay1_DSTATE;

    /* Sum: '<S17>/Add' incorporates:
     *  Constant: '<S17>/Constant'
     *  Constant: '<S17>/Constant1'
     *  Inport: '<Root>/V_InRBM_PTar_s16s7_Bar'
     *  Lookup_n-D: '<S3>/EHB P2P Decouple Map'
     *  Product: '<S17>/Product'
     */
    rtb_MotorCharacterMap = (int16_T)(((int16_T)asr_s32(((int32_T)
        look1_is16lu16n16ys16n7Ds32Is32_binlcan(V_InRBM_PTar_s16s7_Bar,
        (&(K_RB_MapP2PDecouple_InP_s16En7Bar[0])),
        (&(K_RB_MapP2PDecouple_OutP_s16En7Bar[0])), 12U)) * ((int32_T)
        K_RB_P2TqGain_null), 14U)) + K_RB_P2TqOffset_null);

    /* Switch: '<S17>/Switch' incorporates:
     *  Constant: '<S17>/Constant2'
     */
    if (rtb_MotorCharacterMap > 0)
    {
        rtb_Switch_f = 0;
    }
    else
    {
        rtb_Switch_f = rtb_MotorCharacterMap;
    }

    /* End of Switch: '<S17>/Switch' */

    /* Sum: '<S18>/Add' incorporates:
     *  Constant: '<S18>/Constant'
     *  Constant: '<S18>/Constant1'
     *  Inport: '<Root>/V_InRBM_BrkPdlStk_s16s5_mm'
     *  Lookup_n-D: '<S3>/EHB S2P Decouple Map'
     *  Product: '<S18>/Product'
     */
    rtb_MotorCharacterMap = (int16_T)(((int16_T)asr_s32(((int32_T)
        look1_is16bs16n2lu16n16ys16n7ts16n7Ds32Is_rwYpbjoD
        (V_InRBM_BrkPdlStk_s16s5_mm, (&(K_RB_MapS2PDecouple_InS_s16En5mm[0])), (
        &(K_RB_MapS2PDecouple_OutP_s16En7Bar[0])), 8U)) * ((int32_T)
        K_RB_P2TqGain_null), 14U)) + K_RB_P2TqOffset_null);

    /* Switch: '<S18>/Switch' incorporates:
     *  Constant: '<S18>/Constant2'
     */
    if (rtb_MotorCharacterMap > 0)
    {
        rtb_Switch_m3 = 0;
    }
    else
    {
        rtb_Switch_m3 = rtb_MotorCharacterMap;
    }

    /* End of Switch: '<S18>/Switch' */

    /* Abs: '<S3>/Abs' incorporates:
     *  Inport: '<Root>/V_InRBM_EpsSteerAg_s16_Deg'
     */
    if (V_InRBM_EpsSteerAg_s16_Deg < 0)
    {
        y = (int16_T)(-V_InRBM_EpsSteerAg_s16_Deg);
    }
    else
    {
        y = V_InRBM_EpsSteerAg_s16_Deg;
    }

    /* End of Abs: '<S3>/Abs' */

    /* Lookup_n-D: '<S3>/EPS Character Map' */
    rtb_EPSCharacterMap = look1_is16lu16n16Ds32_pbinlca(y,
        (&(K_RB_EPSLimitTorqueMap_Angle_Deg[0])),
        (&(K_RB_EPSLimitTorqueMap_Tq_0P1Nm[0])), &RBM_DW.m_bpIndex, 3U);

    /* Lookup_n-D: '<S3>/Motor Character Map' incorporates:
     *  Inport: '<Root>/V_InRBM_MtrSpd_s16_rpm'
     */
    rtb_MotorCharacterMap = look1_is16lu16n16Ds32_pbinlca(V_InRBM_MtrSpd_s16_Rpm,
        (&(K_RB_MapMotorCharacter_InSpd_Rpm[0])),
        (&(K_RB_MapMotorCharacter_OutTq_Rpm[0])), &RBM_DW.m_bpIndex_b, 8U);

    /* MinMax: '<S3>/Min1' incorporates:
     *  Inport: '<Root>/V_InRBM_MtrTqLim_s16_0P1Nm'
     */
    if (rtb_Switch_f > rtb_Switch_m3)
    {
        u0_1 = rtb_Switch_f;
    }
    else
    {
        u0_1 = rtb_Switch_m3;
    }

    if (u0_1 > V_InRBM_MtrTqLim_s16_0P1Nm)
    {
        u0_0 = u0_1;
    }
    else
    {
        u0_0 = V_InRBM_MtrTqLim_s16_0P1Nm;
    }

    if (u0_0 > rtb_EPSCharacterMap)
    {
        u0 = u0_0;
    }
    else
    {
        u0 = rtb_EPSCharacterMap;
    }

    if (u0 > rtb_MotorCharacterMap)
    {
        V_RBM_MtrTqAllwd_s16_0P1Nm = u0;
    }
    else
    {
        V_RBM_MtrTqAllwd_s16_0P1Nm = rtb_MotorCharacterMap;
    }

    /* End of MinMax: '<S3>/Min1' */

    /* SwitchCase: '<S1>/Switch Case' */
    rtPrevAction = RBM_DW.SwitchCase_ActiveSubsystem;
    rtAction = -1;
    switch (V_RB_RBState_Flg)
    {
      case 1:
        rtAction = 0;
        break;

      case 2:
        rtAction = 1;
        break;

      case 3:
        rtAction = 2;
        break;

      case 4:
        rtAction = 3;
        break;

      default:
        /* no actions */
        break;
    }

    RBM_DW.SwitchCase_ActiveSubsystem = rtAction;
    switch (rtAction)
    {
      case 0:
        if (rtAction != rtPrevAction)
        {
            /* SystemReset for IfAction SubSystem: '<S1>/RB_Disable_Mode' incorporates:
             *  ActionPort: '<S8>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S1>/Switch Case' incorporates:
             *  Chart: '<S8>/Chart'
             */
            RBM_DW.is_active_c8_RBM = 0;
            RBM_DW.is_c8_RBM = RBM_IN_NO_ACTIVE_CHILD;
            RBM_DW.DetnCnt = 0;

            /* End of SystemReset for SubSystem: '<S1>/RB_Disable_Mode' */
        }

        /* Outputs for IfAction SubSystem: '<S1>/RB_Disable_Mode' incorporates:
         *  ActionPort: '<S8>/Action Port'
         */
        /* Chart: '<S8>/Chart' incorporates:
         *  Inport: '<Root>/V_InRBM_GearPosnAct_u8_Mode'
         *  Inport: '<Root>/V_InRBM_PTar_s16s7_Bar'
         */
        /* Gateway: Subsystem/RB_Disable_Mode/Chart */
        /* During: Subsystem/RB_Disable_Mode/Chart */
        if (((uint32_T)RBM_DW.is_active_c8_RBM) == 0U)
        {
            /* Entry: Subsystem/RB_Disable_Mode/Chart */
            RBM_DW.is_active_c8_RBM = 1;

            /* Entry Internal: Subsystem/RB_Disable_Mode/Chart */
            /* Transition: '<S19>:74' */
            tmp_3 = (int32_T)V_InRBM_PTar_s16s7_Bar;
            tmp_4 = (int32_T)V_RBM_PTarFormer_s16s7_Bar;
            tmp_2 = (((tmp_3 & 65536) != 0) ? (tmp_3 | -65536) : (tmp_3 & 65535))
                - (((tmp_4 & 65536) != 0) ? (tmp_4 | -65536) : (tmp_4 & 65535));
            if ((rtb_MtrTqAct <= -230) && ((((tmp_2 & 65536) != 0) ? (tmp_2 |
                    -65536) : (tmp_2 & 65535)) > 640))
            {
                b_sf_internal_predicateOutput_0 = true;
            }
            else
            {
                b_sf_internal_predicateOutput_0 = false;
            }

            if (b_sf_internal_predicateOutput_0)
            {
                /* Transition: '<S19>:83' */
                /* Transition: '<S19>:112' */
                RBM_DW.is_c8_RBM = RBM_IN_FastQuit;

                /* Entry Internal 'FastQuit': '<S19>:87' */
                /* Transition: '<S19>:102' */
                RBM_DW.DetnCnt = 0;

                /* Transition: '<S19>:103' */
                tmp_1 = ((int32_T)RBM_DW.DetnCnt) + 1;
                if (tmp_1 > 32767)
                {
                    tmp_1 = 32767;
                }
                else
                {
                    if (tmp_1 < -32768)
                    {
                        tmp_1 = -32768;
                    }
                }

                RBM_DW.DetnCnt = (int16_T)tmp_1;

                /* Transition: '<S19>:104' */
                if (RBM_DW.DetnCnt >= 24)
                {
                    /* Transition: '<S19>:105' */
                    /* Transition: '<S19>:107' */
                    RBM_DW.DetnCnt = 24;

                    /* Transition: '<S19>:108' */
                }
                else
                {
                    /* Transition: '<S19>:106' */
                }

                /* Transition: '<S19>:109' */
                V_RBM_DiModSts_u8_Mode = 1;
            }
            else
            {
                /* Transition: '<S19>:111' */
                RBM_DW.is_c8_RBM = RBM_IN_DefaultQuit;

                /* Entry Internal 'DefaultQuit': '<S19>:3' */
                /* Transition: '<S19>:8' */
                /* Transition: '<S19>:86' */
                V_RBM_DiModSts_u8_Mode = 0;
            }
        }
        else
        {
            switch (RBM_DW.is_c8_RBM)
            {
              case RBM_IN_DefaultQuit:
                /* During 'DefaultQuit': '<S19>:3' */
                /* Transition: '<S19>:8' */
                /* Transition: '<S19>:86' */
                V_RBM_DiModSts_u8_Mode = 0;
                break;

              case RBM_IN_FastQuit:
                /* During 'FastQuit': '<S19>:87' */
                if (((((int32_T)V_InRBM_GearPosnAct_u8_Mode) == 1) || (((int32_T)
                        V_InRBM_GearPosnAct_u8_Mode) == 2)) && (RBM_DW.DetnCnt <
                     24))
                {
                    sf_internal_predicateOutput_0 = true;
                }
                else
                {
                    sf_internal_predicateOutput_0 = false;
                }

                if (sf_internal_predicateOutput_0)
                {
                    /* Transition: '<S19>:17' */
                    RBM_DW.is_c8_RBM = RBM_IN_SlowQuit;

                    /* Entry Internal 'SlowQuit': '<S19>:49' */
                    /* Transition: '<S19>:67' */
                    RBM_DW.DetnCnt = 0;

                    /* Transition: '<S19>:51' */
                    V_RBM_DiModSts_u8_Mode = 2;
                }
                else
                {
                    /* Transition: '<S19>:98' */
                    /* Transition: '<S19>:103' */
                    tmp_5 = ((int32_T)RBM_DW.DetnCnt) + 1;
                    if (tmp_5 > 32767)
                    {
                        tmp_5 = 32767;
                    }
                    else
                    {
                        if (tmp_5 < -32768)
                        {
                            tmp_5 = -32768;
                        }
                    }

                    RBM_DW.DetnCnt = (int16_T)tmp_5;

                    /* Transition: '<S19>:104' */
                    if (RBM_DW.DetnCnt >= 24)
                    {
                        /* Transition: '<S19>:105' */
                        /* Transition: '<S19>:107' */
                        RBM_DW.DetnCnt = 24;

                        /* Transition: '<S19>:108' */
                    }
                    else
                    {
                        /* Transition: '<S19>:106' */
                    }

                    /* Transition: '<S19>:109' */
                    V_RBM_DiModSts_u8_Mode = 1;
                }
                break;

              default:
                /* During 'SlowQuit': '<S19>:49' */
                /* Transition: '<S19>:54' */
                /* Transition: '<S19>:51' */
                V_RBM_DiModSts_u8_Mode = 2;
                break;
            }
        }

        /* End of Chart: '<S8>/Chart' */

        /* MultiPortSwitch: '<S20>/Multiport Switch1' incorporates:
         *  Constant: '<S20>/Constant1'
         *  Constant: '<S20>/Constant3'
         */
        switch (V_RBM_DiModSts_u8_Mode)
        {
          case 0:
            dPQuit = K_RB_FastQuitSpdOfSts1_s16s7_Bar;
            break;

          case 1:
            dPQuit = K_RB_FastQuitSpdOfSts1_s16s7_Bar;
            break;

          case 2:
            dPQuit = K_RB_SlowQuitSpdOfSts1_s16s7_Bar;
            break;

          default:
            dPQuit = K_RB_FastQuitSpdOfSts1_s16s7_Bar;
            break;
        }

        /* End of MultiPortSwitch: '<S20>/Multiport Switch1' */

        /* Sum: '<S20>/Add1' */
        rtb_Add1 = (int16_T)((dAimP + V_RBM_PTarFormer_s16s7_Bar) + dPQuit);

        /* Switch: '<S21>/Switch2' incorporates:
         *  Inport: '<Root>/V_InRBM_PTar_s16s7_Bar'
         *  RelationalOperator: '<S21>/LowerRelop1'
         *  RelationalOperator: '<S21>/UpperRelop'
         *  Switch: '<S21>/Switch'
         */
        if (rtb_Add1 > V_InRBM_PTar_s16s7_Bar)
        {
            rtb_Switch2_eb = V_InRBM_PTar_s16s7_Bar;
        }
        else
        {
            if (rtb_Add1 < 0)
            {
                /* Switch: '<S21>/Switch' incorporates:
                 *  Constant: '<S20>/Constant5'
                 */
                rtb_Switch_nj = 0;
            }
            else
            {
                /* Switch: '<S21>/Switch' */
                rtb_Switch_nj = rtb_Add1;
            }

            rtb_Switch2_eb = rtb_Switch_nj;
        }

        /* End of Switch: '<S21>/Switch2' */

        /* MultiPortSwitch: '<S20>/Multiport Switch' */
        switch (V_RBM_DiModSts_u8_Mode)
        {
          case 0:
            /* SignalConversion: '<S8>/Signal Copy' incorporates:
             *  Inport: '<Root>/V_InRBM_PTar_s16s7_Bar'
             */
            RBM_DW.signal2 = V_InRBM_PTar_s16s7_Bar;
            break;

          case 1:
            /* SignalConversion: '<S8>/Signal Copy' */
            RBM_DW.signal2 = rtb_Switch2_eb;
            break;

          case 2:
            /* SignalConversion: '<S8>/Signal Copy' */
            RBM_DW.signal2 = rtb_Switch2_eb;
            break;

          default:
            /* SignalConversion: '<S8>/Signal Copy' incorporates:
             *  Inport: '<Root>/V_InRBM_PTar_s16s7_Bar'
             */
            RBM_DW.signal2 = V_InRBM_PTar_s16s7_Bar;
            break;
        }

        /* End of MultiPortSwitch: '<S20>/Multiport Switch' */

        /* SignalConversion: '<S8>/Signal Copy1' incorporates:
         *  Constant: '<S8>/Constant'
         */
        V_OutRBM_RbmActv_u8_Flg = 0;

        /* SignalConversion: '<S8>/Signal Copy2' incorporates:
         *  Constant: '<S8>/Constant'
         */
        RBM_DW.signal3 = 0;

        /* SignalConversion: '<S8>/Signal Copy3' incorporates:
         *  Constant: '<S8>/Constant'
         */
        V_OutRBM_TqErrOver_u8_Err = 0;

        /* SignalConversion: '<S8>/Signal Copy4' incorporates:
         *  Constant: '<S8>/Constant'
         */
        V_OutRBM_MtrTqFolwReq_u8_Flg = 0;

        /* Sum: '<S20>/Add' incorporates:
         *  Constant: '<S20>/Constant2'
         *  Product: '<S20>/Product'
         */
        rtb_Add_g = (int16_T)(V_RBM_MtrTqTarFormer_s16_0P1Nm - ((int16_T)asr_s32
                               (((int32_T)dPQuit) * ((int32_T)K_RB_P2TqGain_null),
                                14U)));

        /* Switch: '<S22>/Switch2' incorporates:
         *  Constant: '<S20>/Constant4'
         *  RelationalOperator: '<S22>/LowerRelop1'
         *  RelationalOperator: '<S22>/UpperRelop'
         *  Switch: '<S22>/Switch'
         */
        if (rtb_Add_g > 0)
        {
            rtb_Switch2_k = 0;
        }
        else
        {
            if (rtb_Add_g < V_RBM_MtrTqAllwd_s16_0P1Nm)
            {
                /* Switch: '<S22>/Switch' */
                rtb_Switch_kw = V_RBM_MtrTqAllwd_s16_0P1Nm;
            }
            else
            {
                /* Switch: '<S22>/Switch' */
                rtb_Switch_kw = rtb_Add_g;
            }

            rtb_Switch2_k = rtb_Switch_kw;
        }

        /* End of Switch: '<S22>/Switch2' */

        /* MultiPortSwitch: '<S20>/Multiport Switch2' */
        switch (V_RBM_DiModSts_u8_Mode)
        {
          case 0:
            /* SignalConversion: '<S8>/Signal Copy5' incorporates:
             *  Constant: '<S20>/Constant'
             */
            RBM_DW.signal6 = 0;
            break;

          case 1:
            /* SignalConversion: '<S8>/Signal Copy5' */
            RBM_DW.signal6 = rtb_Switch2_k;
            break;

          case 2:
            /* SignalConversion: '<S8>/Signal Copy5' */
            RBM_DW.signal6 = rtb_Switch2_k;
            break;

          default:
            /* SignalConversion: '<S8>/Signal Copy5' incorporates:
             *  Constant: '<S20>/Constant'
             */
            RBM_DW.signal6 = 0;
            break;
        }

        /* End of MultiPortSwitch: '<S20>/Multiport Switch2' */
        /* End of Outputs for SubSystem: '<S1>/RB_Disable_Mode' */
        break;

      case 1:
        if (rtAction != rtPrevAction)
        {
            /* SystemReset for IfAction SubSystem: '<S1>/RB_Enable_Mode' incorporates:
             *  ActionPort: '<S10>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S1>/Switch Case' incorporates:
             *  Chart: '<S33>/Chart'
             *  Chart: '<S35>/Err_Debounce'
             */
            RBM_DW.is_active_c2_RBM = 0;
            RBM_DW.is_c2_RBM = RBM_IN_NO_ACTIVE_CHILD;
            RBM_DW.cnt = 0;

            /* End of SystemReset for SubSystem: '<S1>/RB_Enable_Mode' */
        }

        /* Outputs for IfAction SubSystem: '<S1>/RB_Enable_Mode' incorporates:
         *  ActionPort: '<S10>/Action Port'
         */
        /* Switch: '<S36>/Switch' incorporates:
         *  Constant: '<S36>/Constant'
         *  Inport: '<Root>/V_InRBM_CoastLvl_u8_Mode'
         *  Inport: '<Root>/V_InRBM_MtrSpd_s16_rpm'
         *  Lookup_n-D: '<S36>/Coast Level Map1'
         *  Lookup_n-D: '<S36>/CoastDown Spd Map'
         */
        if (((int32_T)K_RB_MultiCoastTenseEna_u8_Flg) > 0)
        {
            rtb_Switch_i = look1_iu8lu32n16ys16ts16Ds32Is32_binlcs
                (V_InRBM_CoastLvl_u8_Mode, (&(K_RB_MapVCUCoastLevelIn_u8[0])), (
                  &(K_RB_MapVCUCoastTorq_0P1Nm[0])), 4U);
        }
        else
        {
            rtb_Switch_i = look1_is16lu16n16ys16Ds32Is32_binlcan
                (V_InRBM_MtrSpd_s16_Rpm, (&(K_RB_MapCoastDown_InSpd_rpm[0])),
                 (&(K_RB_MapCoastDown_OutTq_0P1Nm[0])), 4U);
        }

        /* End of Switch: '<S36>/Switch' */

        /* MinMax: '<S32>/Min' */
        if (V_RBM_MtrTqAllwd_s16_0P1Nm < rtb_Switch_i)
        {
            rtb_Min_n = V_RBM_MtrTqAllwd_s16_0P1Nm;
        }
        else
        {
            rtb_Min_n = rtb_Switch_i;
        }

        /* End of MinMax: '<S32>/Min' */

        /* Switch: '<S32>/Switch2' incorporates:
         *  Constant: '<S32>/Constant'
         */
        if (((int32_T)K_RB_MultiCoastTenseEna_u8_Flg) > 0)
        {
            /* Switch: '<S32>/Switch' incorporates:
             *  Inport: '<Root>/V_InRBM_CoastLvl_u8_Mode'
             *  Inport: '<Root>/V_InRBM_PTar_s16s7_Bar'
             *  Lookup_n-D: '<S32>/Light Brake Overlay'
             *  RelationalOperator: '<S37>/Compare'
             *  Sum: '<S32>/Add1'
             */
            if (V_InRBM_PTar_s16s7_Bar <= 0)
            {
                rtb_Switch_j = rtb_Min_n;
            }
            else
            {
                rtb_Switch_j = (int16_T)(rtb_Switch_i +
                    look2_is16u8lu32n16ys16ts16Ds32Is32_binlcs
                    (V_InRBM_PTar_s16s7_Bar, V_InRBM_CoastLvl_u8_Mode,
                     (&(K_RB_MapTorqCompensationPoint_s16En7Bar[0])),
                     (&(K_RB_MapVCUCoastLevelIn_u8[0])),
                     (&(K_RB_MapCoastTorqIncrementCoffe[0])),
                     RBM_ConstP.LightBrakeOverlay_maxIndex, 11U));
            }

            /* End of Switch: '<S32>/Switch' */

            /* Switch: '<S32>/Switch1' incorporates:
             *  RelationalOperator: '<S32>/Relational Operator'
             */
            if (V_RBM_MtrTqAllwd_s16_0P1Nm < rtb_Switch_j)
            {
                rtb_Switch1 = rtb_Min_n;
            }
            else
            {
                rtb_Switch1 = rtb_Switch_j;
            }

            /* End of Switch: '<S32>/Switch1' */
            rtb_Switch2_m = rtb_Switch1;
        }
        else
        {
            rtb_Switch2_m = V_RBM_MtrTqAllwd_s16_0P1Nm;
        }

        /* End of Switch: '<S32>/Switch2' */

        /* Switch: '<S23>/Switch1' incorporates:
         *  Constant: '<S23>/K_RB_ABSActive_ena'
         *  Constant: '<S26>/Constant'
         *  Constant: '<S27>/Constant'
         *  Inport: '<Root>/V_InRBM_AbsActv_u8_Flg'
         *  Logic: '<S23>/Logical Operator'
         *  MinMax: '<S23>/Max'
         *  RelationalOperator: '<S26>/Compare'
         *  RelationalOperator: '<S27>/Compare'
         */
        if ((((int32_T)K_RB_AbsActvCoastCnclEna_u8_Flg) > 0) && (((int32_T)
                V_InRBM_AbsActv_u8_Flg) > 0))
        {
            rtb_Add1_ex = rtb_Switch2_m;
        }
        else if (V_RBM_MtrTqCoast_s16_0P1Nm < rtb_Switch2_m)
        {
            /* MinMax: '<S23>/Max' */
            rtb_Add1_ex = V_RBM_MtrTqCoast_s16_0P1Nm;
        }
        else
        {
            /* MinMax: '<S23>/Max' */
            rtb_Add1_ex = rtb_Switch2_m;
        }

        /* End of Switch: '<S23>/Switch1' */

        /* MinMax: '<S23>/Max1' incorporates:
         *  Inport: '<Root>/V_InRBM_MtrTqLim_s16_0P1Nm'
         */
        if (rtb_Add1_ex > V_InRBM_MtrTqLim_s16_0P1Nm)
        {
            /* SignalConversion: '<S10>/Signal Copy2' */
            RBM_DW.signal6 = rtb_Add1_ex;
        }
        else
        {
            /* SignalConversion: '<S10>/Signal Copy2' */
            RBM_DW.signal6 = V_InRBM_MtrTqLim_s16_0P1Nm;
        }

        /* End of MinMax: '<S23>/Max1' */

        /* Product: '<S41>/Divide' incorporates:
         *  Constant: '<S41>/Constant'
         *  Constant: '<S41>/Constant1'
         *  Sum: '<S41>/Add'
         */
        rtb_Switch_g = (int16_T)div_nde_s32_floor(((int32_T)((int16_T)
            (rtb_MtrTqAct - K_RB_P2TqOffset_null))) * 16384, (int32_T)
            K_RB_P2TqGain_null);

        /* Switch: '<S42>/Switch' incorporates:
         *  Constant: '<S42>/Constant2'
         */
        if (rtb_Switch_g > 0)
        {
            rtb_Add1_ex = rtb_Switch_g;
        }
        else
        {
            rtb_Add1_ex = 0;
        }

        /* End of Switch: '<S42>/Switch' */

        /* Sum: '<S33>/Aim total minus RB total' incorporates:
         *  Inport: '<Root>/V_InRBM_PTar_s16s7_Bar'
         */
        rtb_Switch_g = (int16_T)(V_InRBM_PTar_s16s7_Bar - rtb_Add1_ex);

        /* Switch: '<S39>/Switch' incorporates:
         *  Constant: '<S39>/Constant2'
         */
        if (rtb_Switch_g > 0)
        {
            rtb_Switch = rtb_Switch_g;
        }
        else
        {
            rtb_Switch = 0;
        }

        /* End of Switch: '<S39>/Switch' */

        /* Chart: '<S33>/Chart' incorporates:
         *  Constant: '<S33>/Constant2'
         *  Inport: '<Root>/V_InRBM_MtrSpd_s16_rpm'
         *  Inport: '<Root>/V_InRBM_PTar_s16s7_Bar'
         *  Lookup_n-D: '<S33>/EHB QuitSpd Map'
         *  Sum: '<S33>/Add'
         */
        /* Gateway: Subsystem/RB_Enable_Mode/RBEna Signals/Prefill Function Judger/Chart */
        /* During: Subsystem/RB_Enable_Mode/RBEna Signals/Prefill Function Judger/Chart */
        if (((uint32_T)RBM_DW.is_active_c2_RBM) == 0U)
        {
            /* Entry: Subsystem/RB_Enable_Mode/RBEna Signals/Prefill Function Judger/Chart */
            RBM_DW.is_active_c2_RBM = 1;

            /* Entry Internal: Subsystem/RB_Enable_Mode/RBEna Signals/Prefill Function Judger/Chart */
            /* Transition: '<S38>:2' */
            RBM_DW.is_c2_RBM = RBM_IN_Disable;

            /* Entry 'Disable': '<S38>:3' */
            rtb_out_k = 0;
        }
        else
        {
            switch (RBM_DW.is_c2_RBM)
            {
              case RBM_IN_Disable:
                /* During 'Disable': '<S38>:3' */
                if (((V_InRBM_PTar_s16s7_Bar > 0) && (rtb_Switch <= 32)) &&
                        (V_InRBM_MtrSpd_s16_Rpm <= ((int16_T)
                        (look1_is16lu16n16ys16ts16Ds32Is32_binlcan
                         (V_InRBM_PTar_s16s7_Bar,
                          (&(K_RB_MapQuitMotorSpd_InP_s16En7Bar[0])),
                          (&(K_RB_MapQuitMotorSpd_OutSpd_Rpm[0])), 12U) +
                         K_RB_PrefillCutInMotorSpdDelta_Rpm))))
                {
                    b_sf_internal_predicateOutput_1 = true;
                }
                else
                {
                    b_sf_internal_predicateOutput_1 = false;
                }

                if (b_sf_internal_predicateOutput_1)
                {
                    /* Transition: '<S38>:4' */
                    RBM_DW.is_c2_RBM = RBM_IN_Enable;

                    /* Entry 'Enable': '<S38>:1' */
                    rtb_out_k = 1;
                }
                else
                {
                    rtb_out_k = 0;
                }
                break;

              default:
                /* During 'Enable': '<S38>:1' */
                if ((V_InRBM_PTar_s16s7_Bar == 0) || (rtb_Switch >= 640))
                {
                    sf_internal_predicateOutput_1 = true;
                }
                else
                {
                    sf_internal_predicateOutput_1 = false;
                }

                if (sf_internal_predicateOutput_1)
                {
                    /* Transition: '<S38>:5' */
                    RBM_DW.is_c2_RBM = RBM_IN_Disable;

                    /* Entry 'Disable': '<S38>:3' */
                    rtb_out_k = 0;
                }
                else
                {
                    rtb_out_k = 1;
                }
                break;
            }
        }

        /* End of Chart: '<S33>/Chart' */

        /* DataTypeConversion: '<S10>/Data Type Conversion' */
        RBM_DW.signal3 = rtb_out_k;

        /* Switch: '<S40>/Switch' */
        if (((int32_T)rtb_out_k) > 0)
        {
            /* Lookup_n-D: '<S40>/EHB PrefillPressure Map' incorporates:
             *  Inport: '<Root>/V_InRBM_PTar_s16s7_Bar'
             */
            rtb_EHBPrefillPressureMap_a =
                look1_is16lu16n16ys16n7Ds32Is32_binlcan(V_InRBM_PTar_s16s7_Bar,
                (&(K_RB_MapPrefillForcePressure_InP_s16En7Bar[0])),
                (&(K_RB_MapPrefillForcePressure_OutP_s16En7Bar[0])), 12U);

            /* MinMax: '<S40>/Max1' */
            if (rtb_EHBPrefillPressureMap_a > rtb_Switch)
            {
                /* SignalConversion: '<S10>/Signal Copy3' */
                RBM_DW.signal2 = rtb_EHBPrefillPressureMap_a;
            }
            else
            {
                /* SignalConversion: '<S10>/Signal Copy3' */
                RBM_DW.signal2 = rtb_Switch;
            }

            /* End of MinMax: '<S40>/Max1' */
        }
        else
        {
            /* SignalConversion: '<S10>/Signal Copy3' */
            RBM_DW.signal2 = rtb_Switch;
        }

        /* End of Switch: '<S40>/Switch' */

        /* Sum: '<S35>/Add1' */
        /* Gateway: Subsystem/RB_Enable_Mode/RBEna Signals/Torque Err Debounce/Err_Debounce */
        /* During: Subsystem/RB_Enable_Mode/RBEna Signals/Torque Err Debounce/Err_Debounce */
        /* Entry Internal: Subsystem/RB_Enable_Mode/RBEna Signals/Torque Err Debounce/Err_Debounce */
        /* Transition: '<S45>:2' */
        u_0 = (int16_T)(V_RBM_MtrTqTarFormer_s16_0P1Nm - rtb_MtrTqAct);

        /* Abs: '<S35>/Abs' */
        if (u_0 < 0)
        {
            y_1 = (int16_T)(-u_0);
        }
        else
        {
            y_1 = u_0;
        }

        /* End of Abs: '<S35>/Abs' */

        /* Chart: '<S35>/Err_Debounce' incorporates:
         *  Constant: '<S35>/Constant2'
         *  Constant: '<S44>/Constant'
         *  RelationalOperator: '<S44>/Compare'
         */
        if (y_1 >= K_RB_TorqueErrorThreshold_0P1Nm)
        {
            /* Transition: '<S45>:8' */
            if (((int16_T)RBM_DW.cnt) < K_RB_TorqueErrorTimeThreshold_5ms)
            {
                /* Transition: '<S45>:16' */
                /* Transition: '<S45>:14' */
                tmp_6 = ((uint32_T)RBM_DW.cnt) + 1U;
                if (tmp_6 > 255U)
                {
                    tmp_6 = 255U;
                }

                RBM_DW.cnt = (uint8_T)tmp_6;

                /* SignalConversion: '<S10>/Signal Copy' */
                V_OutRBM_TqErrOver_u8_Err = 0;
            }
            else
            {
                /* SignalConversion: '<S10>/Signal Copy' */
                /* Transition: '<S45>:18' */
                /* Transition: '<S45>:20' */
                /* Transition: '<S45>:22' */
                V_OutRBM_TqErrOver_u8_Err = 1;

                /* Transition: '<S45>:26' */
            }
        }
        else
        {
            /* Transition: '<S45>:10' */
            /* Transition: '<S45>:12' */
            RBM_DW.cnt = 0;

            /* SignalConversion: '<S10>/Signal Copy' */
            V_OutRBM_TqErrOver_u8_Err = 0;

            /* Transition: '<S45>:30' */
        }

        /* End of Chart: '<S35>/Err_Debounce' */

        /* SignalConversion: '<S10>/Signal Copy1' incorporates:
         *  Inport: '<Root>/V_InRBM_PTar_s16s7_Bar'
         *  RelationalOperator: '<S43>/Compare'
         */
        V_OutRBM_MtrTqFolwReq_u8_Flg = (uint8_T)((V_InRBM_PTar_s16s7_Bar > 0) ?
            1 : 0);

        /* SignalConversion: '<S10>/TmpBufferAtRB Algorithm ActiveOutport1' incorporates:
         *  Constant: '<S10>/RB Algorithm Active'
         */
        V_OutRBM_RbmActv_u8_Flg = 1;

        /* End of Outputs for SubSystem: '<S1>/RB_Enable_Mode' */
        break;

      case 2:
        if (rtAction != rtPrevAction)
        {
            /* InitializeConditions for IfAction SubSystem: '<S1>/RB_Quit_Mode' incorporates:
             *  ActionPort: '<S11>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S1>/Switch Case' incorporates:
             *  Delay: '<S59>/Delay'
             */
            RBM_DW.icLoad = 1;

            /* End of InitializeConditions for SubSystem: '<S1>/RB_Quit_Mode' */

            /* SystemReset for IfAction SubSystem: '<S1>/RB_Quit_Mode' incorporates:
             *  ActionPort: '<S11>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S1>/Switch Case' incorporates:
             *  Chart: '<S59>/Chart'
             *  Chart: '<S67>/Lock QuitTorq'
             *  Chart: '<S68>/Lock'
             */
            RBM_DW.is_active_c10_RBM = 0;
            RBM_DW.is_c10_RBM = RBM_IN_NO_ACTIVE_CHILD;
            RBM_DW.is_active_c11_RBM = 0;
            RBM_DW.is_c11_RBM = RBM_IN_NO_ACTIVE_CHILD;
            RBM_DW.is_active_c12_RBM = 0;
            RBM_DW.is_c12_RBM = RBM_IN_NO_ACTIVE_CHILD;

            /* End of SystemReset for SubSystem: '<S1>/RB_Quit_Mode' */
        }

        /* Outputs for IfAction SubSystem: '<S1>/RB_Quit_Mode' incorporates:
         *  ActionPort: '<S11>/Action Port'
         */
        /* Chart: '<S68>/Lock' incorporates:
         *  Constant: '<S68>/Constant3'
         *  Constant: '<S68>/Constant4'
         *  Inport: '<Root>/V_InRBM_MtrSpd_s16_rpm'
         *  Logic: '<S68>/OR'
         *  RelationalOperator: '<S68>/Relational Operator'
         *  RelationalOperator: '<S68>/Relational Operator1'
         */
        /* Gateway: Subsystem/RB_Quit_Mode/Subsystem2/dpcaculator/pressure_rising_stopping/Lock */
        /* During: Subsystem/RB_Quit_Mode/Subsystem2/dpcaculator/pressure_rising_stopping/Lock */
        if (((uint32_T)RBM_DW.is_active_c10_RBM) == 0U)
        {
            /* Entry: Subsystem/RB_Quit_Mode/Subsystem2/dpcaculator/pressure_rising_stopping/Lock */
            RBM_DW.is_active_c10_RBM = 1;

            /* Entry Internal: Subsystem/RB_Quit_Mode/Subsystem2/dpcaculator/pressure_rising_stopping/Lock */
            /* Transition: '<S70>:5' */
            RBM_DW.is_c10_RBM = RBM_IN_UnLock;

            /* Entry 'UnLock': '<S70>:6' */
            rtb_out = 0;
        }
        else
        {
            switch (RBM_DW.is_c10_RBM)
            {
              case RBM_IN_Lock:
                /* During 'Lock': '<S70>:10' */
                rtb_out = 1;
                break;

              default:
                /* During 'UnLock': '<S70>:6' */
                if ((V_RBM_MtrTqTarFormer_s16_0P1Nm >= K_RB_TqQuitStop_s16_0P1Nm)
                    || (V_InRBM_MtrSpd_s16_Rpm <= K_RB_MtrSpdQuitStop_s16_Rpm))
                {
                    /* Transition: '<S70>:11' */
                    RBM_DW.is_c10_RBM = RBM_IN_Lock;

                    /* Entry 'Lock': '<S70>:10' */
                    rtb_out = 1;
                }
                else
                {
                    rtb_out = 0;
                }
                break;
            }
        }

        /* End of Chart: '<S68>/Lock' */

        /* Chart: '<S67>/Lock QuitTorq' */
        /* Gateway: Subsystem/RB_Quit_Mode/Subsystem2/dpcaculator/dp_norm_caculator/Lock QuitTorq */
        /* During: Subsystem/RB_Quit_Mode/Subsystem2/dpcaculator/dp_norm_caculator/Lock QuitTorq */
        if (((uint32_T)RBM_DW.is_active_c11_RBM) == 0U)
        {
            /* Entry: Subsystem/RB_Quit_Mode/Subsystem2/dpcaculator/dp_norm_caculator/Lock QuitTorq */
            RBM_DW.is_active_c11_RBM = 1;

            /* Entry Internal: Subsystem/RB_Quit_Mode/Subsystem2/dpcaculator/dp_norm_caculator/Lock QuitTorq */
            /* Transition: '<S69>:7' */
            RBM_DW.is_c11_RBM = RBM_IN_LockTorq;

            /* Entry Internal 'LockTorq': '<S69>:6' */
            /* Transition: '<S69>:31' */
            /* Transition: '<S69>:32' */
            RBM_DW.pretq = rtb_MtrTqAct;

            /* Transition: '<S69>:13' */
            rtb_outtq = RBM_DW.pretq;
        }
        else
        {
            /* During 'LockTorq': '<S69>:6' */
            /* Transition: '<S69>:9' */
            /* Transition: '<S69>:13' */
            rtb_outtq = RBM_DW.pretq;
        }

        /* End of Chart: '<S67>/Lock QuitTorq' */

        /* Switch: '<S47>/Switch' incorporates:
         *  Constant: '<S67>/Constant9'
         *  Inport: '<Root>/V_InRBM_AbsActv_u8_Flg'
         *  Switch: '<S57>/Switch5'
         *  Switch: '<S67>/Switch6'
         */
        if (((int32_T)V_InRBM_AbsActv_u8_Flg) > 0)
        {
            /* Switch: '<S58>/Switch3' incorporates:
             *  Constant: '<S58>/Constant1'
             *  Constant: '<S58>/Constant7'
             *  Constant: '<S71>/Constant'
             *  Inport: '<Root>/V_InRBM_PAct_s16s7_Bar'
             *  RelationalOperator: '<S71>/Compare'
             *  Switch: '<S58>/Switch2'
             */
            if (((int32_T)K_RB_ABSDelay_Disable) > 0)
            {
                rtb_Switch3 = K_RB_ABSStepP_s16En7Bar;
            }
            else
            {
                if (V_InRBM_PAct_s16s7_Bar >= K_RBM_AbsDlyP_s16s7_Bar)
                {
                    /* Switch: '<S58>/Switch2' incorporates:
                     *  Constant: '<S58>/Constant1'
                     */
                    rtb_Switch2 = K_RB_ABSStepP_s16En7Bar;
                }
                else
                {
                    /* Switch: '<S58>/Switch2' incorporates:
                     *  Constant: '<S58>/Constant6'
                     */
                    rtb_Switch2 = 0;
                }

                rtb_Switch3 = rtb_Switch2;
            }

            /* End of Switch: '<S58>/Switch3' */
            V_RB_dpQuitMod_s16s7_Bar = rtb_Switch3;
        }
        else
        {
            if (((int32_T)rtb_out) > 0)
            {
                /* Switch: '<S57>/Switch5' incorporates:
                 *  Constant: '<S57>/1'
                 */
                rtb_Switch5 = 0;
            }
            else
            {
                if (((int32_T)K_RB_FullChargeQuit_Disable) > 0)
                {
                    /* Switch: '<S67>/Switch6' incorporates:
                     *  Inport: '<Root>/V_InRBM_PTar_s16s7_Bar'
                     *  Lookup_n-D: '<S67>/1-D Lookup Table'
                     *  Switch: '<S57>/Switch5'
                     */
                    rtb_Switch6 = look2_is16s16lu32n16ts16Ds32ds32_binlcs
                        (rtb_outtq, V_InRBM_PTar_s16s7_Bar,
                         (&(K_RB_MapStepPressure_InTq_s16_0P1Nm[0])),
                         (&(K_RB_MapStepPressure_InP_s16En7Bar[0])),
                         (&(K_RB_MutiMapStepPressure_OutP_s16En7Bar[0])),
                         RBM_ConstP.uDLookupTable_maxIndex, 5U);
                }
                else
                {
                    /* Switch: '<S67>/Switch6' incorporates:
                     *  Inport: '<Root>/V_InRBM_PTar_s16s7_Bar'
                     *  Lookup_n-D: '<S67>/EHB StepPressure Map'
                     *  Switch: '<S57>/Switch5'
                     */
                    rtb_Switch6 = look1_is16lu16n16ys16n7Ds32Is32_binlcan
                        (V_InRBM_PTar_s16s7_Bar,
                         (&(K_RB_MapStepPressure_InP_s16En7Bar[0])),
                         (&(K_RB_MapStepPressure_OutP_s16En7Bar[0])), 12U);
                }

                /* Switch: '<S57>/Switch5' */
                rtb_Switch5 = rtb_Switch6;
            }

            V_RB_dpQuitMod_s16s7_Bar = rtb_Switch5;
        }

        /* End of Switch: '<S47>/Switch' */

        /* Switch: '<S48>/judge ABS' incorporates:
         *  Inport: '<Root>/V_InRBM_AbsActv_u8_Flg'
         *  Inport: '<Root>/V_InRBM_PTar_s16s7_Bar'
         *  Sum: '<S48>/Add2'
         */
        if (((int32_T)V_InRBM_AbsActv_u8_Flg) > 0)
        {
            rtb_judgeABS = V_InRBM_PTar_s16s7_Bar;
        }
        else
        {
            /* Product: '<S51>/Product1' incorporates:
             *  Inport: '<Root>/V_InRBM_PAct_s16s7_Bar'
             *  Inport: '<Root>/V_InRBM_PTar_s16s7_Bar'
             *  Lookup_n-D: '<S51>/EHB QuitPBrkGain Map'
             *  Lookup_n-D: '<S51>/EHB QuitdP2dPGain Map'
             *  Lookup_n-D: '<S51>/EHB QuitdP2dPOffset Map'
             *  Product: '<S51>/Product'
             *  Sum: '<S51>/Add'
             */
            rtb_Product1 = (int16_T)asr_s32(((int32_T)((int16_T)(((int16_T)
                asr_s32(((int32_T)V_RB_dpQuitMod_s16s7_Bar) * ((int32_T)
                look1_is16lu16n16ys16n7Ds32Is32_binlcan(V_InRBM_PTar_s16s7_Bar,
                (&(K_RB_MapQuitdP2dPGain_InP_s16En7Bar[0])),
                (&(K_RB_MapQuitdP2dPGain_OutP_s16En7[0])), 12U)), 7U)) +
                look1_is16lu16n16ys16n7Ds32Is32_binlcan(V_InRBM_PTar_s16s7_Bar,
                (&(K_RB_MapQuitdP2dPOffset_InP_s16En7Bar[0])),
                (&(K_RB_MapQuitdP2dPOffset_OutP_s16En7Bar[0])), 12U)))) *
                ((int32_T)look1_is16lu16n16ys16n10ts16n10Ds32Is32_binlcan
                 (V_InRBM_PAct_s16s7_Bar, (&(M_RB_BreakPntOfPAct_s16s7_Bar[0])),
                  (&(K_RB_PBrkCoeff_s16s10_null[0])), 5U)), 10U);

            /* Switch: '<S51>/Switch' incorporates:
             *  Constant: '<S51>/Constant2'
             */
            if (rtb_Product1 > 0)
            {
                rtb_Switch_m = rtb_Product1;
            }
            else
            {
                rtb_Switch_m = 0;
            }

            /* End of Switch: '<S51>/Switch' */
            rtb_judgeABS = (int16_T)((dAimP + V_RBM_PTarFormer_s16s7_Bar) +
                rtb_Switch_m);
        }

        /* End of Switch: '<S48>/judge ABS' */

        /* Switch: '<S49>/Switch1' incorporates:
         *  Constant: '<S49>/Prefill Disable'
         *  Constant: '<S49>/Prefill Enable'
         *  Inport: '<Root>/V_InRBM_PTar_s16s7_Bar'
         */
        if (V_InRBM_PTar_s16s7_Bar > 64)
        {
            rtb_Compare_b = 1;
        }
        else
        {
            rtb_Compare_b = 0;
        }

        /* End of Switch: '<S49>/Switch1' */

        /* Switch: '<S49>/Switch' */
        if (((int32_T)rtb_Compare_b) > 0)
        {
            /* Lookup_n-D: '<S49>/EHB PrefillPressure Map' incorporates:
             *  Inport: '<Root>/V_InRBM_PTar_s16s7_Bar'
             */
            rtb_EHBPrefillPressureMap = look1_is16lu16n16ys16n7Ds32Is32_binlcan
                (V_InRBM_PTar_s16s7_Bar,
                 (&(K_RB_MapPrefillForcePressure_InP_s16En7Bar[0])),
                 (&(K_RB_MapPrefillForcePressure_OutP_s16En7Bar[0])), 12U);

            /* MinMax: '<S49>/Max1' */
            if (rtb_EHBPrefillPressureMap > rtb_judgeABS)
            {
                /* SignalConversion: '<S11>/Signal Copy1' */
                RBM_DW.signal2 = rtb_EHBPrefillPressureMap;
            }
            else
            {
                /* SignalConversion: '<S11>/Signal Copy1' */
                RBM_DW.signal2 = rtb_judgeABS;
            }

            /* End of MinMax: '<S49>/Max1' */
        }
        else
        {
            /* SignalConversion: '<S11>/Signal Copy1' */
            RBM_DW.signal2 = rtb_judgeABS;
        }

        /* End of Switch: '<S49>/Switch' */

        /* SignalConversion: '<S11>/Signal Copy2' */
        RBM_DW.signal3 = rtb_Compare_b;

        /* Sum: '<S60>/Add' incorporates:
         *  Constant: '<S60>/Constant'
         *  Constant: '<S60>/Constant1'
         *  Product: '<S60>/Divide'
         */
        u1 = (int16_T)(((int16_T)asr_s32((int32_T)((int16_T)asr_s32(((int32_T)
                            V_RB_dpQuitMod_s16s7_Bar) * ((int32_T)
                            K_RB_P2TqGain_null), 7U)), 7U)) +
                       K_RB_P2TqOffset_null);

        /* MinMax: '<S60>/Min' incorporates:
         *  Constant: '<S60>/Constant2'
         */
        if (0 < u1)
        {
            rtb_Min = 0;
        }
        else
        {
            rtb_Min = u1;
        }

        /* End of MinMax: '<S60>/Min' */

        /* Switch: '<S54>/Switch1' incorporates:
         *  Constant: '<S54>/K_RB_ABSActive_ena'
         *  Constant: '<S64>/Constant'
         *  Constant: '<S65>/Constant'
         *  Inport: '<Root>/V_InRBM_AbsActv_u8_Flg'
         *  Logic: '<S54>/Logical Operator'
         *  RelationalOperator: '<S64>/Compare'
         *  RelationalOperator: '<S65>/Compare'
         *  Sum: '<S53>/Add1'
         */
        if ((((int32_T)K_RB_AbsActvCoastCnclEna_u8_Flg) > 0) && (((int32_T)
                V_InRBM_AbsActv_u8_Flg) > 0))
        {
            rtb_Delay = (int16_T)(V_RBM_MtrTqTarFormer_s16_0P1Nm - rtb_Min);
        }
        else
        {
            /* Sum: '<S53>/Add1' */
            u1_0 = (int16_T)(V_RBM_MtrTqTarFormer_s16_0P1Nm - rtb_Min);

            /* MinMax: '<S54>/Max' */
            if (V_RBM_MtrTqCoast_s16_0P1Nm < u1_0)
            {
                rtb_Delay = V_RBM_MtrTqCoast_s16_0P1Nm;
            }
            else
            {
                rtb_Delay = u1_0;
            }

            /* End of MinMax: '<S54>/Max' */
        }

        /* End of Switch: '<S54>/Switch1' */

        /* MinMax: '<S54>/Max1' incorporates:
         *  Inport: '<Root>/V_InRBM_MtrTqLim_s16_0P1Nm'
         */
        if (rtb_Delay > V_InRBM_MtrTqLim_s16_0P1Nm)
        {
            rtb_Max1_l = rtb_Delay;
        }
        else
        {
            rtb_Max1_l = V_InRBM_MtrTqLim_s16_0P1Nm;
        }

        /* End of MinMax: '<S54>/Max1' */

        /* Switch: '<S56>/Switch2' incorporates:
         *  Constant: '<S47>/0'
         *  RelationalOperator: '<S56>/LowerRelop1'
         *  RelationalOperator: '<S56>/UpperRelop'
         *  Switch: '<S56>/Switch'
         */
        if (rtb_Max1_l > 0)
        {
            rtb_Delay = 0;
        }
        else
        {
            if (rtb_Max1_l < V_RBM_MtrTqAllwd_s16_0P1Nm)
            {
                /* Switch: '<S56>/Switch' */
                rtb_Switch_mq = V_RBM_MtrTqAllwd_s16_0P1Nm;
            }
            else
            {
                /* Switch: '<S56>/Switch' */
                rtb_Switch_mq = rtb_Max1_l;
            }

            rtb_Delay = rtb_Switch_mq;
        }

        /* End of Switch: '<S56>/Switch2' */

        /* SignalConversion: '<S11>/Signal Copy3' */
        RBM_DW.signal6 = rtb_Delay;

        /* SignalConversion: '<S11>/Signal Copy6' incorporates:
         *  Inport: '<Root>/V_InRBM_PTar_s16s7_Bar'
         *  RelationalOperator: '<S52>/Compare'
         */
        V_OutRBM_MtrTqFolwReq_u8_Flg = (uint8_T)((V_InRBM_PTar_s16s7_Bar > 0) ?
            1 : 0);

        /* Lookup_n-D: '<S59>/Delay Map' incorporates:
         *  Inport: '<Root>/V_InRBM_PTar_s16s7_Bar'
         */
        rtb_DelayMap = look1_is16lu8n8yu8tu8Ds16Is32n23_binlcan
            (V_InRBM_PTar_s16s7_Bar, (&(K_RB_MapQuitTqDelay_InP_s16En7Bar[0])),
             (&(K_RB_MapQuitTqDelay_Out_5ms[0])), 12U);

        /* Chart: '<S59>/Chart' */
        /* Gateway: Subsystem/RB_Quit_Mode/Subsystem2/AimTorque/TqDelay/Chart */
        /* During: Subsystem/RB_Quit_Mode/Subsystem2/AimTorque/TqDelay/Chart */
        if (((uint32_T)RBM_DW.is_active_c12_RBM) == 0U)
        {
            /* Entry: Subsystem/RB_Quit_Mode/Subsystem2/AimTorque/TqDelay/Chart */
            RBM_DW.is_active_c12_RBM = 1;

            /* Entry Internal: Subsystem/RB_Quit_Mode/Subsystem2/AimTorque/TqDelay/Chart */
            /* Transition: '<S61>:5' */
            RBM_DW.is_c12_RBM = RBM_IN_delay;

            /* Entry 'delay': '<S61>:6' */
            RBM_DW.lock_value = rtb_DelayMap;
            rtb_out_fk = rtb_DelayMap;
        }
        else
        {
            /* During 'delay': '<S61>:6' */
            rtb_out_fk = RBM_DW.lock_value;
        }

        /* End of Chart: '<S59>/Chart' */

        /* Delay: '<S59>/Delay' incorporates:
         *  Constant: '<S59>/Constant1'
         */
        if (((int32_T)RBM_DW.icLoad) != 0)
        {
            memset(&RBM_DW.Delay_DSTATE_i[0], 0, 40U * (sizeof(int16_T)));
        }

        if (((int32_T)rtb_out_fk) <= 0)
        {
            rtb_Delay = rtb_Min;
        }
        else
        {
            if (((int32_T)rtb_out_fk) > 40)
            {
                delayLen = 40;
            }
            else
            {
                delayLen = rtb_out_fk;
            }

            rtb_Delay = RBM_DW.Delay_DSTATE_i[(uint8_T)(40U - ((uint32_T)
                delayLen))];
        }

        /* End of Delay: '<S59>/Delay' */

        /* Switch: '<S59>/Switch' incorporates:
         *  Constant: '<S59>/Constant2'
         *  Constant: '<S63>/Constant'
         *  RelationalOperator: '<S63>/Compare'
         */
        if (rtb_Min >= 0)
        {
            V_RBM_DTqQuitMode_s16_0P1Nm = 0;
        }
        else
        {
            V_RBM_DTqQuitMode_s16_0P1Nm = rtb_Delay;
        }

        /* End of Switch: '<S59>/Switch' */

        /* SignalConversion: '<S11>/TmpBufferAtErr Judger DisableOutport1' incorporates:
         *  Constant: '<S11>/Err Judger Disable'
         */
        V_OutRBM_TqErrOver_u8_Err = 0;

        /* SignalConversion: '<S11>/TmpBufferAtRB Algorithm Active1Outport1' incorporates:
         *  Constant: '<S11>/RB Algorithm Active1'
         */
        V_OutRBM_RbmActv_u8_Flg = 1;

        /* Update for Delay: '<S59>/Delay' */
        RBM_DW.icLoad = 0;
        for (idxDelay = 0; idxDelay < 39; idxDelay = idxDelay + 1)
        {
            RBM_DW.Delay_DSTATE_i[idxDelay + 0] = RBM_DW.Delay_DSTATE_i
                [(idxDelay + 1) + 0];
        }

        RBM_DW.Delay_DSTATE_i[39] = rtb_Min;

        /* End of Update for Delay: '<S59>/Delay' */
        /* End of Outputs for SubSystem: '<S1>/RB_Quit_Mode' */
        break;

      case 3:
        /* Outputs for IfAction SubSystem: '<S1>/RB_E_Bak_Mode' incorporates:
         *  ActionPort: '<S9>/Action Port'
         */
        /* SignalConversion: '<S9>/Signal Copy' incorporates:
         *  Inport: '<Root>/V_InRBM_PTar_s16s7_Bar'
         */
        RBM_DW.signal2 = V_InRBM_PTar_s16s7_Bar;

        /* SignalConversion: '<S9>/Signal Copy1' incorporates:
         *  Constant: '<S9>/Constant'
         */
        V_OutRBM_RbmActv_u8_Flg = 0;

        /* SignalConversion: '<S9>/Signal Copy2' incorporates:
         *  Constant: '<S9>/Constant'
         */
        RBM_DW.signal3 = 0;

        /* SignalConversion: '<S9>/Signal Copy3' incorporates:
         *  Constant: '<S9>/Constant'
         */
        V_OutRBM_TqErrOver_u8_Err = 0;

        /* SignalConversion: '<S9>/Signal Copy4' incorporates:
         *  Constant: '<S9>/Constant'
         */
        V_OutRBM_MtrTqFolwReq_u8_Flg = 0;

        /* SignalConversion: '<S9>/Signal Copy5' incorporates:
         *  Constant: '<S9>/Constant1'
         */
        RBM_DW.signal6 = 0;

        /* End of Outputs for SubSystem: '<S1>/RB_E_Bak_Mode' */
        break;

      default:
        /* no actions */
        break;
    }

    /* End of SwitchCase: '<S1>/Switch Case' */

    /* Switch: '<S1>/Switch' incorporates:
     *  Constant: '<S1>/Constant'
     *  Inport: '<Root>/V_InRBM_PTar_s16s7_Bar'
     */
    if (((int32_T)K_RBM_TotFctEna_u8_Flg) > 0)
    {
        /* Switch: '<S15>/Switch' incorporates:
         *  Constant: '<S15>/Constant'
         */
        if (RBM_DW.signal2 > K_RB_OutPMinPressure_s16En7Bar)
        {
            V_OutRBM_PTar_s16s7_Bar = RBM_DW.signal2;
        }
        else
        {
            V_OutRBM_PTar_s16s7_Bar = 0;
        }

        /* End of Switch: '<S15>/Switch' */
    }
    else
    {
        V_OutRBM_PTar_s16s7_Bar = V_InRBM_PTar_s16s7_Bar;
    }

    /* End of Switch: '<S1>/Switch' */

    /* Switch: '<S7>/Switch' incorporates:
     *  Constant: '<S7>/Constant'
     *  Constant: '<S7>/Constant1'
     */
    if (((int32_T)K_RB_Prefill_Ena) > 0)
    {
        V_OutRBM_PreFillEna_u8_Flg = RBM_DW.signal3;
    }
    else
    {
        V_OutRBM_PreFillEna_u8_Flg = 0;
    }

    /* End of Switch: '<S7>/Switch' */

    /* Saturate: '<S1>/Saturation1' */
    if (RBM_DW.signal6 > 0)
    {
        rtb_Saturation1 = 0;
    }
    else if (RBM_DW.signal6 < -5000)
    {
        rtb_Saturation1 = -5000;
    }
    else
    {
        rtb_Saturation1 = RBM_DW.signal6;
    }

    /* End of Saturate: '<S1>/Saturation1' */

    /* Chart: '<S1>/Chart' */
    /* Gateway: Subsystem/Chart */
    /* During: Subsystem/Chart */
    /* Entry Internal: Subsystem/Chart */
    /* Transition: '<S4>:2' */
    if (rtb_Saturation1 >= V_RBM_MtrTqAllwd_s16_0P1Nm)
    {
        /* Transition: '<S4>:4' */
        /* Transition: '<S4>:16' */
        V_OutRBM_MtrTqTar_s16_0P1Nm = rtb_Saturation1;
    }
    else
    {
        /* Transition: '<S4>:10' */
        V_OutRBM_MtrTqTar_s16_0P1Nm = V_RBM_MtrTqAllwd_s16_0P1Nm;
    }

    /* End of Chart: '<S1>/Chart' */

    /* Outputs for Enabled SubSystem: '<S12>/Diag' incorporates:
     *  EnablePort: '<S82>/Enable'
     */
    /* Constant: '<S12>/Constant7' */
    if (((int32_T)K_RB_DiagAssistant_Ena) > 0)
    {
        /* SignalConversion: '<S82>/TmpSignal ConversionAtSum of ElementsInport1' incorporates:
         *  Constant: '<S100>/Constant'
         *  Constant: '<S101>/Constant'
         *  Constant: '<S87>/Constant'
         *  Constant: '<S88>/Constant'
         *  Constant: '<S96>/Constant'
         *  Constant: '<S97>/Constant'
         *  Constant: '<S98>/Constant'
         *  Constant: '<S99>/Constant'
         *  Product: '<S82>/Product1'
         *  Product: '<S82>/Product2'
         *  Product: '<S82>/Product3'
         *  Product: '<S82>/Product4'
         *  Product: '<S82>/Product5'
         *  Product: '<S82>/Product6'
         *  Product: '<S82>/Product7'
         *  RelationalOperator: '<S100>/Compare'
         *  RelationalOperator: '<S101>/Compare'
         *  RelationalOperator: '<S87>/Compare'
         *  RelationalOperator: '<S88>/Compare'
         *  RelationalOperator: '<S96>/Compare'
         *  RelationalOperator: '<S97>/Compare'
         *  RelationalOperator: '<S98>/Compare'
         *  RelationalOperator: '<S99>/Compare'
         */
        rtb_TmpSignalConversionAtSumofElementsInport1[0] = (int16_T)((((int32_T)
            rtb_Switch_be) != 15) ? 1 : 0);
        rtb_TmpSignalConversionAtSumofElementsInport1[1] = (int16_T)(((int32_T)
            ((int16_T)((uint8_T)((((int32_T)rtb_Switch3_f) != 15) ? 1 : 0)))) *
            2);
        rtb_TmpSignalConversionAtSumofElementsInport1[2] = (int16_T)(((int32_T)
            ((int16_T)((uint8_T)((((int32_T)rtb_Switch1_n) != 15) ? 1 : 0)))) *
            4);
        rtb_TmpSignalConversionAtSumofElementsInport1[3] = (int16_T)(((int32_T)
            ((int16_T)((uint8_T)((((int32_T)rtb_Switch2_h) != 15) ? 1 : 0)))) *
            8);
        rtb_TmpSignalConversionAtSumofElementsInport1[4] = (int16_T)(((int32_T)
            ((int16_T)((uint8_T)((((int32_T)rtb_Switch4) != 15) ? 1 : 0)))) * 16);
        rtb_TmpSignalConversionAtSumofElementsInport1[5] = (int16_T)(((int32_T)
            ((int16_T)((uint8_T)((((int32_T)rtb_Switch5_p) != 15) ? 1 : 0)))) *
            32);
        rtb_TmpSignalConversionAtSumofElementsInport1[6] = (int16_T)(((int32_T)
            ((int16_T)((uint8_T)((((int32_T)rtb_Switch6_l) != 15) ? 1 : 0)))) *
            64);
        rtb_TmpSignalConversionAtSumofElementsInport1[7] = (int16_T)(((int32_T)
            ((int16_T)((uint8_T)((((int32_T)rtb_Switch7) != 15) ? 1 : 0)))) *
            128);

        /* Sum: '<S82>/Sum of Elements' */
        tmp = (int32_T)rtb_TmpSignalConversionAtSumofElementsInport1[0];
        for (i = 1; i < 8; i = i + 1)
        {
            tmp = tmp + ((int32_T)rtb_TmpSignalConversionAtSumofElementsInport1
                         [0 + i]);
        }

        V_RBM_DiagInfo1_u16_Mode = (int16_T)tmp;

        /* End of Sum: '<S82>/Sum of Elements' */

        /* SignalConversion: '<S82>/TmpSignal ConversionAtSum of Elements1Inport1' incorporates:
         *  Constant: '<S102>/Constant'
         *  Constant: '<S103>/Constant'
         *  Constant: '<S89>/Constant'
         *  Constant: '<S90>/Constant'
         *  Constant: '<S91>/Constant'
         *  Constant: '<S92>/Constant'
         *  Constant: '<S93>/Constant'
         *  Constant: '<S94>/Constant'
         *  Constant: '<S95>/Constant'
         *  Product: '<S82>/Product10'
         *  Product: '<S82>/Product11'
         *  Product: '<S82>/Product12'
         *  Product: '<S82>/Product13'
         *  Product: '<S82>/Product14'
         *  Product: '<S82>/Product15'
         *  Product: '<S82>/Product16'
         *  Product: '<S82>/Product9'
         *  RelationalOperator: '<S102>/Compare'
         *  RelationalOperator: '<S103>/Compare'
         *  RelationalOperator: '<S89>/Compare'
         *  RelationalOperator: '<S90>/Compare'
         *  RelationalOperator: '<S91>/Compare'
         *  RelationalOperator: '<S92>/Compare'
         *  RelationalOperator: '<S93>/Compare'
         *  RelationalOperator: '<S94>/Compare'
         *  RelationalOperator: '<S95>/Compare'
         */
        rtb_TmpSignalConversionAtSumofElements1Inport1[0] = (int16_T)((((int32_T)
            rtb_Switch8) != 15) ? 1 : 0);
        rtb_TmpSignalConversionAtSumofElements1Inport1[1] = (int16_T)(((int32_T)
            ((int16_T)((uint8_T)((((int32_T)rtb_Switch9) != 15) ? 1 : 0)))) * 2);
        rtb_TmpSignalConversionAtSumofElements1Inport1[2] = (int16_T)(((int32_T)
            ((int16_T)((uint8_T)((((int32_T)rtb_Switch10) != 15) ? 1 : 0)))) * 4);
        rtb_TmpSignalConversionAtSumofElements1Inport1[3] = (int16_T)(((int32_T)
            ((int16_T)((uint8_T)((((int32_T)rtb_Switch11) != 15) ? 1 : 0)))) * 8);
        rtb_TmpSignalConversionAtSumofElements1Inport1[4] = (int16_T)(((int32_T)
            ((int16_T)((uint8_T)((((int32_T)rtb_Switch12) != 15) ? 1 : 0)))) *
            16);
        rtb_TmpSignalConversionAtSumofElements1Inport1[5] = (int16_T)(((int32_T)
            ((int16_T)((uint8_T)((((int32_T)rtb_Switch13) != 15) ? 1 : 0)))) *
            32);
        rtb_TmpSignalConversionAtSumofElements1Inport1[6] = (int16_T)(((int32_T)
            ((int16_T)((uint8_T)((((int32_T)rtb_Switch14) != 15) ? 1 : 0)))) *
            64);
        rtb_TmpSignalConversionAtSumofElements1Inport1[7] = (int16_T)(((int32_T)
            ((int16_T)((uint8_T)((((int32_T)rtb_out_l) != 15) ? 1 : 0)))) * 128);
        rtb_TmpSignalConversionAtSumofElements1Inport1[8] = (int16_T)(((int32_T)
            ((int16_T)((uint8_T)((((int32_T)rtb_Switch15) != 15) ? 1 : 0)))) *
            256);

        /* Sum: '<S82>/Sum of Elements1' */
        tmp_0 = (int32_T)rtb_TmpSignalConversionAtSumofElements1Inport1[0];
        for (i_0 = 1; i_0 < 9; i_0 = i_0 + 1)
        {
            tmp_0 = tmp_0 + ((int32_T)
                             rtb_TmpSignalConversionAtSumofElements1Inport1[0 +
                             i_0]);
        }

        V_RBM_DiagInfo2_u16_Mode = (int16_T)tmp_0;

        /* End of Sum: '<S82>/Sum of Elements1' */
    }

    /* End of Constant: '<S12>/Constant7' */
    /* End of Outputs for SubSystem: '<S12>/Diag' */

    /* Update for Delay: '<S1>/Delay2' */
    RBM_DW.Delay2_DSTATE = V_OutRBM_TqErrOver_u8_Err;

    /* Update for Delay: '<S16>/Delay3' incorporates:
     *  Inport: '<Root>/V_InRBM_PTar_s16s7_Bar'
     */
    RBM_DW.Delay3_DSTATE = V_InRBM_PTar_s16s7_Bar;

    /* Update for Delay: '<S1>/Delay' */
    RBM_DW.Delay_DSTATE = RBM_DW.signal6;

    /* Update for Delay: '<S1>/Delay1' */
    RBM_DW.Delay1_DSTATE = RBM_DW.signal2;
}

/* Model initialize function */
void RBM_initialize(void)
{
    /* Registration code */

    /* block I/O */

    /* exported global signals */
    dAimP = 0;
    dPQuit = 0;

    /* custom signals */
    V_RBM_PTarFormer_s16s7_Bar = 0;
    V_OutRBM_PTar_s16s7_Bar = 0;
    V_RB_dpQuitMod_s16s7_Bar = 0;
    V_RBM_MtrTqCoast_s16_0P1Nm = 0;
    V_RBM_MtrTqTarFormer_s16_0P1Nm = 0;
    V_RBM_MtrTqAllwd_s16_0P1Nm = 0;
    V_RBM_DTqQuitMode_s16_0P1Nm = 0;
    V_RBM_DiagInfo1_u16_Mode = 0;
    V_RBM_DiagInfo2_u16_Mode = 0;
    V_OutRBM_MtrTqTar_s16_0P1Nm = 0;
    V_RBM_FormerTorqueErrorOver_u8_Err = 0U;
    V_RB_RBModeMask_Flg = 0U;
    V_OutRBM_RbmActv_u8_Flg = 0U;
    V_OutRBM_PreFillEna_u8_Flg = 0U;
    V_OutRBM_TqErrOver_u8_Err = 0U;
    V_OutRBM_MtrTqFolwReq_u8_Flg = 0U;
    V_RBM_DiModSts_u8_Mode = 0U;
    V_RBM_WhlSpdSlip_u8_Err = 0U;
    V_RB_RBState_Flg = 0U;

    /* states (dwork) */
    (void) memset((void *)&RBM_DW, 0,
                  sizeof(DW_RBM));

    /* external inputs */
    V_InRBM_EhbErrMod_u8_Mode = 0U;
    V_InRBM_PTar_s16s7_Bar = 0;
    V_InRBM_PAct_s16s7_Bar = 0;
    V_InRBM_BrkPdlStk_s16s5_mm = 0;
    V_InRBM_RbmEnaFromVcu_u8_Flg = 0U;
    V_InRBM_GasPdlStk_s16_Perc = 0;
    V_InRBM_GasPdlStk_u8_Vld = 0U;
    V_InRBM_MtrTqLim_s16_0P1Nm = 0;
    V_InRBM_MtrTqLim_u8_Vld = 0U;
    V_InRBM_PtMinorFlt_u8_Err = 0U;
    V_InRBM_PtSevereFlt_u8_Err = 0U;
    V_InRBM_GearPosnAct_u8_Mode = 0U;
    V_InRBM_AbsActv_u8_Flg = 0U;
    V_InRBM_BmsI_s16_0P1A = 0;
    V_InRBM_BmsU_s16_0P1V = 0;
    V_InRBM_EpsSteerAg_s16_Deg = 0;
    V_InRBM_EpsSteerAg_u8_Vld = 0U;
    V_InRBM_ChassisFlt_u8_Err = 0U;
    V_InRBM_MtrSpd_s16_Rpm = 0;
    V_InRBM_MtrSpd_u8_Vld = 0U;
    V_InRBM_MtrTqAct_s16_0P1Nm = 0;
    V_InRBM_MtrTqAct_u8_Vld = 0U;
    V_InRBM_LostChassisCan_u8_Err = 0U;
    V_InRBM_LostPtCan_u8_Err = 0U;
    V_InRBM_VehSpd_s16_0P1Kph = 0;
    V_InRBM_VehSpd_u8_Vld = 0U;
    V_InRBM_FLWhlSpd_s16_0P1Kph = 0;
    V_InRBM_FRWhlSpd_s16_0P1Kph = 0;
    V_InRBM_RLWhlSpd_s16_0P1Kph = 0;
    V_InRBM_RRWhlSpd_s16_0P1Kph = 0;
    V_InRBM_CoastLvl_u8_Mode = 0U;

    {
        char_T tmp[9];
        int32_T i;

        /* Start for SwitchCase: '<S1>/Switch Case' */
        RBM_DW.SwitchCase_ActiveSubsystem = -1;

        /* ConstCode for StringToASCII: '<S1>/String to ASCII' */
        strncpy(&tmp[0], RBM_ConstB.StringConstant, 9U);
        for (i = 0; i < 9; i = i + 1)
        {
            RB_Ver[(i)] = (uint8_T)tmp[i];
        }

        /* End of ConstCode for StringToASCII: '<S1>/String to ASCII' */

        /* SystemInitialize for Chart: '<S85>/Chart' */
        RBM_DW.is_active_c5_RBM = 0;
        RBM_DW.is_c5_RBM = RBM_IN_NO_ACTIVE_CHILD;

        /* SystemInitialize for Chart: '<S12>/RBState_Judge' */
        RBM_DW.is_active_c3_RBM = 0;
        RBM_DW.is_c3_RBM = RBM_IN_NO_ACTIVE_CHILD;

        /* SystemInitialize for IfAction SubSystem: '<S1>/RB_Disable_Mode' */
        /* SystemInitialize for Chart: '<S8>/Chart' */
        RBM_DW.is_active_c8_RBM = 0;
        RBM_DW.is_c8_RBM = RBM_IN_NO_ACTIVE_CHILD;
        RBM_DW.DetnCnt = 0;

        /* End of SystemInitialize for SubSystem: '<S1>/RB_Disable_Mode' */

        /* SystemInitialize for IfAction SubSystem: '<S1>/RB_Enable_Mode' */
        /* SystemInitialize for Chart: '<S33>/Chart' */
        RBM_DW.is_active_c2_RBM = 0;
        RBM_DW.is_c2_RBM = RBM_IN_NO_ACTIVE_CHILD;

        /* SystemInitialize for Chart: '<S35>/Err_Debounce' */
        RBM_DW.cnt = 0;

        /* End of SystemInitialize for SubSystem: '<S1>/RB_Enable_Mode' */

        /* SystemInitialize for IfAction SubSystem: '<S1>/RB_Quit_Mode' */
        /* InitializeConditions for Delay: '<S59>/Delay' */
        RBM_DW.icLoad = 1;

        /* SystemInitialize for Chart: '<S68>/Lock' */
        RBM_DW.is_active_c10_RBM = 0;
        RBM_DW.is_c10_RBM = RBM_IN_NO_ACTIVE_CHILD;

        /* SystemInitialize for Chart: '<S67>/Lock QuitTorq' */
        RBM_DW.is_active_c11_RBM = 0;
        RBM_DW.is_c11_RBM = RBM_IN_NO_ACTIVE_CHILD;

        /* SystemInitialize for Chart: '<S59>/Chart' */
        RBM_DW.is_active_c12_RBM = 0;
        RBM_DW.is_c12_RBM = RBM_IN_NO_ACTIVE_CHILD;

        /* End of SystemInitialize for SubSystem: '<S1>/RB_Quit_Mode' */

        /* SystemInitialize for Merge: '<S1>/Merge' */
        V_OutRBM_RbmActv_u8_Flg = 0;
        RBM_DW.signal2 = 0;
        RBM_DW.signal3 = 0;
        V_OutRBM_TqErrOver_u8_Err = 0;
        V_OutRBM_MtrTqFolwReq_u8_Flg = 0;
        RBM_DW.signal6 = 0;
    }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
