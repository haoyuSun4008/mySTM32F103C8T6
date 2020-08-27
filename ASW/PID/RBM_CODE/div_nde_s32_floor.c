/*
 * File: div_nde_s32_floor.c
 *
 * Code generated for Simulink model 'RBM'.
 *
 * Model version                  : 1.1842
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Aug 27 10:51:32 2020
 */

#include "rtwtypes.h"
#include "div_nde_s32_floor.h"

int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator)
{
    return ((((numerator < 0) != (denominator < 0)) && ((numerator % denominator)
              != 0)) ? -1 : 0) + (numerator / denominator);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
