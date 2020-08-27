/*
 * File: mul_ssu32_loSR.c
 *
 * Code generated for Simulink model 'RBM'.
 *
 * Model version                  : 1.1842
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Aug 27 10:51:32 2020
 */

#include "rtwtypes.h"
#include "mul_wide_su32.h"
#include "mul_ssu32_loSR.h"

int32_T mul_ssu32_loSR(int32_T a, uint32_T b, uint32_T aShift)
{
    uint32_T u32_chi;
    uint32_T u32_clo;
    mul_wide_su32(a, b, &u32_chi, &u32_clo);
    u32_clo = (u32_chi << (32U - aShift)) | (u32_clo >> aShift);
    return (int32_T)u32_clo;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
