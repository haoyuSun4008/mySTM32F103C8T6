/*
 * File: mul_wide_su32.c
 *
 * Code generated for Simulink model 'RBM'.
 *
 * Model version                  : 1.1842
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Aug 27 10:51:32 2020
 */

#include "rtwtypes.h"
#include "mul_wide_su32.h"

void mul_wide_su32(int32_T in0, uint32_T in1, uint32_T *ptrOutBitsHi, uint32_T
                   *ptrOutBitsLo)
{
    uint32_T outBitsLo;
    uint32_T absIn0;
    uint32_T in0Hi;
    uint32_T in1Lo;
    uint32_T in1Hi;
    uint32_T productHiLo;
    uint32_T productLoHi;
    absIn0 = (in0 < 0) ? ((~((uint32_T)in0)) + 1U) : ((uint32_T)in0);
    in0Hi = (absIn0 >> 16U);
    absIn0 = absIn0 & 65535U;
    in1Hi = (in1 >> 16U);
    in1Lo = in1 & 65535U;
    productHiLo = in0Hi * in1Lo;
    productLoHi = absIn0 * in1Hi;
    absIn0 = absIn0 * in1Lo;
    in1Lo = 0U;
    outBitsLo = (productLoHi << 16U) + absIn0;
    if (outBitsLo < absIn0)
    {
        in1Lo = 0U + 1U;
    }

    absIn0 = outBitsLo;
    outBitsLo = (productHiLo << 16U) + outBitsLo;
    if (outBitsLo < absIn0)
    {
        in1Lo = in1Lo + 1U;
    }

    absIn0 = (((productLoHi >> 16U) + (productHiLo >> 16U)) + (in0Hi * in1Hi)) +
        in1Lo;
    if (!((in1 == 0U) || (in0 >= 0)))
    {
        absIn0 = ~absIn0;
        outBitsLo = ~outBitsLo;
        outBitsLo = outBitsLo + 1U;
        if (outBitsLo == 0U)
        {
            absIn0 = absIn0 + 1U;
        }
    }

    *ptrOutBitsHi = absIn0;
    *ptrOutBitsLo = outBitsLo;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
