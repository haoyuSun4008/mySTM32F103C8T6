/*
 * File: look1_is16lu16n16Ds32_pbinlca.c
 *
 * Code generated for Simulink model 'RBM'.
 *
 * Model version                  : 1.1842
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Aug 27 10:51:32 2020
 */

#include "rtwtypes.h"
#include "mul_ssu32_loSR_zero.h"
#include "look1_is16lu16n16Ds32_pbinlca.h"

int16_T look1_is16lu16n16Ds32_pbinlca(int16_T u0, const int16_T bp0[], const
    int16_T table[], uint32_T prevIndex[], uint32_T maxIndex)
{
    int16_T y;
    uint16_T frac;
    uint32_T iRght;
    uint32_T iLeft;
    uint32_T bpIdx;
    uint32_T found;

    /* Column-major Lookup 1-D
       Search method: 'binary'
       Use previous index: 'on'
       Interpolation method: 'Linear point-slope'
       Extrapolation method: 'Clip'
       Use last breakpoint for index at or above upper limit: 'on'
       Remove protection against out-of-range input in generated code: 'off'
       Rounding mode: 'zero'
     */
    /* Prelookup - Index and Fraction
       Index Search method: 'binary'
       Extrapolation method: 'Clip'
       Use previous index: 'on'
       Use last breakpoint for index at or above upper limit: 'on'
       Remove protection against out-of-range input in generated code: 'off'
       Rounding mode: 'zero'
     */
    if (u0 <= bp0[0U])
    {
        bpIdx = 0U;
        frac = 0;
    }
    else if (u0 < bp0[maxIndex])
    {
        /* Binary Search using Previous Index */
        bpIdx = prevIndex[0U];
        iLeft = 0U;
        iRght = maxIndex;
        found = 0U;
        while (found == 0U)
        {
            if (u0 < bp0[bpIdx])
            {
                iRght = bpIdx - 1U;
                bpIdx = ((iRght + iLeft) >> 1U);
            }
            else if (u0 < bp0[bpIdx + 1U])
            {
                found = 1U;
            }
            else
            {
                iLeft = bpIdx + 1U;
                bpIdx = ((iRght + iLeft) >> 1U);
            }
        }

        frac = (uint16_T)((((uint32_T)((uint16_T)((int32_T)(((int32_T)u0) -
                               ((int32_T)bp0[bpIdx]))))) << 16) / ((uint32_T)
                           ((uint16_T)((int32_T)(((int32_T)bp0[bpIdx + 1U]) -
                              ((int32_T)bp0[bpIdx]))))));
    }
    else
    {
        bpIdx = maxIndex;
        frac = 0;
    }

    prevIndex[0U] = bpIdx;

    /* Column-major Interpolation 1-D
       Interpolation method: 'Linear point-slope'
       Use last breakpoint for index at or above upper limit: 'on'
       Rounding mode: 'zero'
       Overflow mode: 'wrapping'
     */
    if (bpIdx == maxIndex)
    {
        y = table[bpIdx];
    }
    else
    {
        y = (int16_T)(((int16_T)mul_ssu32_loSR_zero(((int32_T)table[bpIdx + 1U])
                        - ((int32_T)table[bpIdx]), (uint32_T)frac, 16U)) +
                      table[bpIdx]);
    }

    return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
