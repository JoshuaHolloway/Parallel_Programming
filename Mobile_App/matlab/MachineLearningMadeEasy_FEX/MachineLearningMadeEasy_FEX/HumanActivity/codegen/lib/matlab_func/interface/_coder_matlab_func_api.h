/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_matlab_func_api.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 05-Apr-2018 07:10:16
 */

#ifndef _CODER_MATLAB_FUNC_API_H
#define _CODER_MATLAB_FUNC_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_matlab_func_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern real_T matlab_func(real_T x, real_T y);
extern void matlab_func_api(const mxArray * const prhs[2], int32_T nlhs, const
  mxArray *plhs[1]);
extern void matlab_func_atexit(void);
extern void matlab_func_initialize(void);
extern void matlab_func_terminate(void);
extern void matlab_func_xil_terminate(void);

#endif

/*
 * File trailer for _coder_matlab_func_api.h
 *
 * [EOF]
 */
