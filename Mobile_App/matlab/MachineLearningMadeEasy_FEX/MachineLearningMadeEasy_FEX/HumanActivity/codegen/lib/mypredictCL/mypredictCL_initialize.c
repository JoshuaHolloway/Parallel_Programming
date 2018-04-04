/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: mypredictCL_initialize.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 04-Apr-2018 06:26:45
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "mypredictCL.h"
#include "mypredictCL_initialize.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void mypredictCL_initialize(void)
{
  rt_InitInfAndNaN(8U);
}

/*
 * File trailer for mypredictCL_initialize.c
 *
 * [EOF]
 */
