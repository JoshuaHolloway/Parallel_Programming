/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: matlab_func_initialize.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 05-Apr-2018 07:10:16
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "matlab_func.h"
#include "matlab_func_initialize.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void matlab_func_initialize(void)
{
  rt_InitInfAndNaN(8U);
}

/*
 * File trailer for matlab_func_initialize.c
 *
 * [EOF]
 */
