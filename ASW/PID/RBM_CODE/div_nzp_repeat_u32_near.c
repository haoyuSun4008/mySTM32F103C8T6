/*
 * File: div_nzp_repeat_u32_near.c
 *
 * Code generated for Simulink model 'RBM'.
 *
 * Model version                  : 1.1842
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Aug 27 10:51:32 2020
 */

#include "rtwtypes.h"
#include "div_nzp_repeat_u32_near.h"

uint32_T div_nzp_repeat_u32_near(uint32_T numerator, uint32_T denominator,
    uint32_T nRepeatSub)
{
    uint32_T quotient;
    uint32_T iRepeatSub;
    boolean_T numeratorExtraBit;
    quotient = numerator / denominator;
    numerator = numerator % denominator;
    for (iRepeatSub = 0U; iRepeatSub < nRepeatSub; iRepeatSub = iRepeatSub + 1U)
    {
        numeratorExtraBit = (numerator >= 2147483648U);
        numerator = (numerator << 1U);
        quotient = (quotient << 1U);
        if (numeratorExtraBit || (numerator >= denominator))
        {
            quotient = quotient + 1U;
            numerator = numerator - denominator;
        }
    }

    numeratorExtraBit = (numerator >= 2147483648U);
    numerator = (numerator << 1U);
    if (numeratorExtraBit || (numerator >= denominator))
    {
        quotient = quotient + 1U;
    }

    return quotient;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
