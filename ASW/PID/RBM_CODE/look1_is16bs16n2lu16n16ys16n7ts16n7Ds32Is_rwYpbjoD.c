/*
 * File: look1_is16bs16n2lu16n16ys16n7ts16n7Ds32Is_rwYpbjoD.c
 *
 * Code generated for Simulink model 'RBM'.
 *
 * Model version                  : 1.1842
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Aug 27 10:51:32 2020
 */

#include "rtwtypes.h"
#include "div_nzp_repeat_u32_near.h"
#include "mul_ssu32_loSR_near.h"
#include "look1_is16bs16n2lu16n16ys16n7ts16n7Ds32Is_rwYpbjoD.h"

int16_T look1_is16bs16n2lu16n16ys16n7ts16n7Ds32Is_rwYpbjoD(int16_T u0, const
    int16_T bp0[], const int16_T table[], uint32_T maxIndex)
{
    uint16_T frac;
    int32_T finalAccum;
    uint32_T iRght;
    uint32_T iLeft;
    uint32_T bpIdx;
    int16_T uCast;

    /* Column-major Lookup 1-D
       Canonical function name: look1_is16bs16n2lu16n16ys16n7ts16n7Ds32Is32_binlcan
       Search method: 'binary'
       Use previous index: 'off'
       Interpolation method: 'Linear point-slope'
       Extrapolation method: 'Clip'
       Use last breakpoint for index at or above upper limit: 'on'
       Remove protection against out-of-range input in generated code: 'off'
       Rounding mode: 'nearest'
     */
    /* Prelookup - Index and Fraction
       Index Search method: 'binary'
       Extrapolation method: 'Clip'
       Use previous index: 'off'
       Use last breakpoint for index at or above upper limit: 'on'
       Remove protection against out-of-range input in generated code: 'off'
       Rounding mode: 'nearest'
     */
    if (u0 > 8191)
    {
        uCast = MAX_int16_T;
    }
    else if (u0 <= -8192)
    {
        uCast = MIN_int16_T;
    }
    else
    {
        uCast = (int16_T)(((int32_T)u0) * 4);
    }

    if ((((int32_T)u0) * 4) < ((int32_T)bp0[0U]))
    {
        iLeft = 0U;
        frac = 0;
    }
    else if (uCast < bp0[maxIndex])
    {
        /* Binary Search */
        bpIdx = (maxIndex >> 1U);
        iLeft = 0U;
        iRght = maxIndex;
        while ((iRght - iLeft) > 1U)
        {
            if (uCast < bp0[bpIdx])
            {
                iRght = bpIdx;
            }
            else
            {
                iLeft = bpIdx;
            }

            bpIdx = ((iRght + iLeft) >> 1U);
        }

        frac = (uint16_T)div_nzp_repeat_u32_near((((uint32_T)u0) << 2) -
            ((uint32_T)bp0[iLeft]), (uint32_T)((uint16_T)((int32_T)(((int32_T)
            bp0[iLeft + 1U]) - ((int32_T)bp0[iLeft])))), 16U);
    }
    else
    {
        iLeft = maxIndex;
        frac = 0;
    }

    /* Column-major Interpolation 1-D
       Interpolation method: 'Linear point-slope'
       Use last breakpoint for index at or above upper limit: 'on'
       Rounding mode: 'nearest'
       Overflow mode: 'wrapping'
     */
    if (iLeft == maxIndex)
    {
        finalAccum = (int32_T)table[iLeft];
    }
    else
    {
        finalAccum = mul_ssu32_loSR_near(((int32_T)table[iLeft + 1U]) -
            ((int32_T)table[iLeft]), (uint32_T)frac, 16U) + ((int32_T)
            table[iLeft]);
    }

    return (int16_T)finalAccum;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
