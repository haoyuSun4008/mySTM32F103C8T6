/*
 * File: look2_is16u8lu32n16ys16ts16Ds32Is32_binlcs.c
 *
 * Code generated for Simulink model 'RBM'.
 *
 * Model version                  : 1.1842
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Aug 27 10:51:32 2020
 */

#include "rtwtypes.h"
#include "mul_ssu32_loSR.h"
#include "look2_is16u8lu32n16ys16ts16Ds32Is32_binlcs.h"

int16_T look2_is16u8lu32n16ys16ts16Ds32Is32_binlcs(int16_T u0, uint8_T u1, const
    int16_T bp0[], const uint8_T bp1[], const int16_T table[], const uint32_T
    maxIndex[], uint32_T stride)
{
    uint32_T frac;
    uint32_T bpIndices[2];
    uint32_T fractions[2];
    int32_T yL_1d;
    uint32_T bpIdx;
    uint32_T iLeft;

    /* Column-major Lookup 2-D
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
    else if (u0 < bp0[maxIndex[0U]])
    {
        /* Binary Search */
        bpIdx = (maxIndex[0U] >> 1U);
        iLeft = 0U;
        frac = maxIndex[0U];
        while ((frac - iLeft) > 1U)
        {
            if (u0 < bp0[bpIdx])
            {
                frac = bpIdx;
            }
            else
            {
                iLeft = bpIdx;
            }

            bpIdx = ((frac + iLeft) >> 1U);
        }

        frac = (((uint32_T)((uint16_T)((int32_T)(((int32_T)u0) - ((int32_T)
                     bp0[iLeft]))))) << 16) / ((uint32_T)((uint16_T)((int32_T)
            (((int32_T)bp0[iLeft + 1U]) - ((int32_T)bp0[iLeft])))));
    }
    else
    {
        iLeft = maxIndex[0U] - 1U;
        frac = 65536U;
    }

    fractions[0U] = frac;
    bpIndices[0U] = iLeft;

    /* Prelookup - Index and Fraction
       Index Search method: 'binary'
       Extrapolation method: 'Clip'
       Use previous index: 'off'
       Use last breakpoint for index at or above upper limit: 'off'
       Remove protection against out-of-range input in generated code: 'off'
       Rounding mode: 'simplest'
     */
    if (u1 <= bp1[0U])
    {
        iLeft = 0U;
        frac = 0U;
    }
    else if (u1 < bp1[maxIndex[1U]])
    {
        /* Binary Search */
        bpIdx = (maxIndex[1U] >> 1U);
        iLeft = 0U;
        frac = maxIndex[1U];
        while ((frac - iLeft) > 1U)
        {
            if (u1 < bp1[bpIdx])
            {
                frac = bpIdx;
            }
            else
            {
                iLeft = bpIdx;
            }

            bpIdx = ((frac + iLeft) >> 1U);
        }

        frac = (((uint32_T)((uint8_T)(((uint32_T)u1) - ((uint32_T)bp1[iLeft]))))
                << 16) / ((uint32_T)((uint8_T)(((uint32_T)bp1[iLeft + 1U]) -
                            ((uint32_T)bp1[iLeft]))));
    }
    else
    {
        iLeft = maxIndex[1U] - 1U;
        frac = 65536U;
    }

    /* Column-major Interpolation 2-D
       Interpolation method: 'Linear point-slope'
       Use last breakpoint for index at or above upper limit: 'off'
       Rounding mode: 'simplest'
       Overflow mode: 'wrapping'
     */
    bpIdx = (iLeft * stride) + bpIndices[0U];
    yL_1d = mul_ssu32_loSR(((int32_T)table[bpIdx + 1U]) - ((int32_T)table[bpIdx]),
                           fractions[0U], 16U) + ((int32_T)table[bpIdx]);
    bpIdx = bpIdx + stride;
    return (int16_T)(mul_ssu32_loSR((mul_ssu32_loSR(((int32_T)table[bpIdx + 1U])
                        - ((int32_T)table[bpIdx]), fractions[0U], 16U) +
                       ((int32_T)table[bpIdx])) - yL_1d, frac, 16U) + yL_1d);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
