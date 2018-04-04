/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: unaryMinOrMax.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 04-Apr-2018 06:26:45
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "mypredictCL.h"
#include "unaryMinOrMax.h"

/* Function Definitions */

/*
 * Arguments    : const double x[7]
 *                double *ex
 *                int *idx
 * Return Type  : void
 */
void minOrMaxRealFloatVector(const double x[7], double *ex, int *idx)
{
  int k;
  boolean_T exitg1;
  if (!rtIsNaN(x[0])) {
    *idx = 1;
  } else {
    *idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 8)) {
      if (!rtIsNaN(x[k - 1])) {
        *idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (*idx == 0) {
    *ex = x[0];
    *idx = 1;
  } else {
    *ex = x[*idx - 1];
    for (k = *idx; k + 1 < 8; k++) {
      if (*ex < x[k]) {
        *ex = x[k];
        *idx = k + 1;
      }
    }
  }
}

/*
 * File trailer for unaryMinOrMax.c
 *
 * [EOF]
 */
