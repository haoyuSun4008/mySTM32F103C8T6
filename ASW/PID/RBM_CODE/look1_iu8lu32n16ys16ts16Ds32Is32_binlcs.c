/*
 * File: look1_iu8lu32n16ys16ts16Ds32Is32_binlcs.c
 *
 * Code generated for Simulink model 'RBM'.
 *
 * Model version                  : 1.1842
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Aug 27 10:51:32 2020
 */

#include "rtwtypes.h"
#include "mul_ssu32_loSR.h"
#include "look1_iu8lu32n16ys16ts16Ds32Is32_binlcs.h"

int16_T look1_iu8lu32n16ys16ts16Ds32Is32_binlcs(uint8_T u0, const uint8_T bp0[],
    const int16_T table[], uint32_T maxIndex)
{
    uint32_T frac;
    uint32_T iRght;
    uint32_T iLeft;

    /* Column-major Lookup 1-D
       Search method: 'binary'
       Use previous index: 'off'
       Interpolation method: 'Linear point-slope'
       Extrapolation method: 'Clip'
       Use last breakpoint for index at or above upper limit: 'off'
       Remove protection against out-of-range input in generated code: 'off'
       Rounding mode: 'simplest'
     */
    /* Prelookup - Index and Fraction
       Index Search method: 'binary'
       Extrapolation method: 'Clip'
       Use previous index: 'off'
       Use last breakpoint for index at or above upper limit: 'off'
       Remove protection against out-of-range input in generated code: 'off'
       Rounding mode: 'simplest'
     */
    if (u0 <= bp0[0U])
    {
        iLeft = 0U;
        frac = 0U;
    }
    else if (u0 < bp0[maxIndex])
    {
        /* Binary Search */
        frac = (maxIndex >> 1U);
        iLeft = 0U;
        iRght = maxIndex;
        while ((iRght - iLeft) > 1U)
        {
            if (u0 < bp0[frac])
            {
                iRght = frac;
            }
            else
            {
                iLeft = frac;
            }

            frac = ((iRght + iLeft) >> 1U);
        }

        frac = (((uint32_T)((uint8_T)(((uint32_T)u0) - ((uint32_T)bp0[iLeft]))))
                << 16) / ((uint32_T)((uint8_T)(((uint32_T)bp0[iLeft + 1U]) -
                            ((uint32_T)bp0[iLeft]))));
    }
    else
    {
        iLeft = maxIndex - 1U;
        frac = 65536U;
    }

    /* Column-major Interpolation 1-D
       Interpolation method: 'Linear point-slope'
       Use last breakpoint for index at or above upper limit: 'off'
       Rounding mode: 'simplest'
       Overflow mode: 'wrapping'
     */
    return (int16_T)(mul_ssu32_loSR(((int32_T)table[iLeft + 1U]) - ((int32_T)
                       table[iLeft]), frac, 16U) + ((int32_T)table[iLeft]));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
