/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: matlab_func.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 04-Apr-2018 04:54:08
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "matlab_func.h"

/* Function Definitions */

/*
 * Arguments    : const double x[4]
 *                const double y[4]
 *                double z[4]
 * Return Type  : void
 */
void matlab_func(const double x[4], const double y[4], double z[4])
{
  int i0;
  int i1;
  int i2;
  for (i0 = 0; i0 < 2; i0++) {
    for (i1 = 0; i1 < 2; i1++) {
      z[i0 + (i1 << 1)] = 0.0;
      for (i2 = 0; i2 < 2; i2++) {
        z[i0 + (i1 << 1)] += x[i0 + (i2 << 1)] * y[i2 + (i1 << 1)];
      }
    }
  }
}

/*
 * File trailer for matlab_func.c
 *
 * [EOF]
 */
