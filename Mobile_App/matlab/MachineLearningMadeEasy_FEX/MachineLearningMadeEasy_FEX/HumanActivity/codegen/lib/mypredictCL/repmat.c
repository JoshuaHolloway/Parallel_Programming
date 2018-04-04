/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: repmat.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 04-Apr-2018 06:26:45
 */

/* Include Files */
#include <string.h>
#include "rt_nonfinite.h"
#include "mypredictCL.h"
#include "repmat.h"

/* Function Definitions */

/*
 * Arguments    : const double a[15]
 *                double b[30]
 * Return Type  : void
 */
void repmat(const double a[15], double b[30])
{
  int jtilecol;
  int ibtile;
  for (jtilecol = 0; jtilecol < 2; jtilecol++) {
    ibtile = jtilecol * 15;
    memcpy(&b[ibtile], &a[0], 15U * sizeof(double));
  }
}

/*
 * File trailer for repmat.c
 *
 * [EOF]
 */
