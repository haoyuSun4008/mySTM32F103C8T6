/*
 * File: look1_is16lu8n8yu8tu8Ds16Is32n23_binlcan.c
 *
 * Code generated for Simulink model 'RBM'.
 *
 * Model version                  : 1.1842
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Aug 27 10:51:32 2020
 */

#include "rtwtypes.h"
#include "asr_s32.h"
#include "div_nzp_u32_near.h"
#include "look1_is16lu8n8yu8tu8Ds16Is32n23_binlcan.h"

uint8_T look1_is16lu8n8yu8tu8Ds16Is32n23_binlcan(int16_T u0, const int16_T bp0[],
    const uint8_T table[], uint32_T maxIndex)
{
    uint8_T frac;
    int32_T finalAccum;
    uint32_T iRght;
    uint32_T iLeft;
    uint32_T bpIdx;

    /* Column-major Lookup 1-D
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
    if (u0 <= bp0[0U])
    {
        iLeft = 0U;
        frac = 0;
    }
    else if (u0 < bp0[maxIndex])
    {
        /* Binary Search */
        bpIdx = (maxIndex >> 1U);
        iLeft = 0U;
        iRght = maxIndex;
        while ((iRght - iLeft) > 1U)
        {
            if (u0 < bp0[bpIdx])
            {
                iRght = bpIdx;
            }
            else
            {
                iLeft = bpIdx;
            }

            bpIdx = ((iRght + iLeft) >> 1U);
        }

        bpIdx = div_nzp_u32_near(((uint32_T)((uint16_T)((int32_T)(((int32_T)u0)
            - ((int32_T)bp0[iLeft]))))) << 8, (uint32_T)((uint16_T)((int32_T)
            (((int32_T)bp0[iLeft + 1U]) - ((int32_T)bp0[iLeft])))));
        if (bpIdx > 255U)
        {
            bpIdx = 255U;
        }

        frac = (uint8_T)bpIdx;
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
        finalAccum = (int32_T)((uint32_T)(((uint32_T)table[iLeft]) << 23));
    }
    else
    {
        finalAccum = ((((int32_T)((int16_T)((int32_T)(((int32_T)table[iLeft + 1U])
                           - ((int32_T)table[iLeft]))))) * ((int32_T)frac)) *
                      32768) + ((int32_T)((uint32_T)(((uint32_T)table[iLeft]) <<
            23)));
    }

    return (uint8_T)((int32_T)(((int32_T)(((finalAccum & 4194304) != 0) ? 1 : 0))
                      + asr_s32(finalAccum, 23U)));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
