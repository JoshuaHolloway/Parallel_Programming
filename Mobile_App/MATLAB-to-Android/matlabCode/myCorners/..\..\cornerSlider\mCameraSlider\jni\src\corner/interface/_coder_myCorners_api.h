/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_myCorners_api.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 02-Apr-2018 02:26:12
 */

#ifndef _CODER_MYCORNERS_API_H
#define _CODER_MYCORNERS_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_myCorners_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void myCorners(uint8_T R[101376], uint8_T G[101376], uint8_T B[101376],
                      real32_T fThresh, real32_T hThresh, real32_T mThresh);
extern void myCorners_api(const mxArray * const prhs[6], int32_T nlhs, const
  mxArray *plhs[3]);
extern void myCorners_atexit(void);
extern void myCorners_initialize(void);
extern void myCorners_terminate(void);
extern void myCorners_xil_terminate(void);

#endif

/*
 * File trailer for _coder_myCorners_api.h
 *
 * [EOF]
 */
