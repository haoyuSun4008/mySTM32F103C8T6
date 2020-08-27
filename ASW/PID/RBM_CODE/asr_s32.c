/*
 * File: asr_s32.c
 *
 * Code generated for Simulink model 'RBM'.
 *
 * Model version                  : 1.1842
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Aug 27 10:51:32 2020
 */

#include "rtwtypes.h"
#include "asr_s32.h"

int32_T asr_s32(int32_T u, uint32_T n)
{
    int32_T y;
    if (u >= 0)
    {
        y = (int32_T)((uint32_T)(((uint32_T)u) >> n));
    }
    else
    {
        y = (-((int32_T)((uint32_T)(((uint32_T)((int32_T)(-1 - u))) >> n)))) - 1;
    }

    return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
