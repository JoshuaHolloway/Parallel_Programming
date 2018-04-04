/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_mypredictCL_api.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 04-Apr-2018 05:25:33
 */

#ifndef _CODER_MYPREDICTCL_API_H
#define _CODER_MYPREDICTCL_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_mypredictCL_api.h"

/* Type Definitions */
#ifndef struct_emxArray_char_T_1x3
#define struct_emxArray_char_T_1x3

struct emxArray_char_T_1x3
{
  char_T data[3];
  int32_T size[2];
};

#endif                                 /*struct_emxArray_char_T_1x3*/

#ifndef typedef_emxArray_char_T_1x3
#define typedef_emxArray_char_T_1x3

typedef struct emxArray_char_T_1x3 emxArray_char_T_1x3;

#endif                                 /*typedef_emxArray_char_T_1x3*/

#ifndef struct_syQG36Cs4NTpeuokvXGrgCB_tag
#define struct_syQG36Cs4NTpeuokvXGrgCB_tag

struct syQG36Cs4NTpeuokvXGrgCB_tag
{
  emxArray_char_T_1x3 f1;
};

#endif                                 /*struct_syQG36Cs4NTpeuokvXGrgCB_tag*/

#ifndef typedef_cell_wrap_0
#define typedef_cell_wrap_0

typedef struct syQG36Cs4NTpeuokvXGrgCB_tag cell_wrap_0;

#endif                                 /*typedef_cell_wrap_0*/

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void mypredictCL(real_T X[105], cell_wrap_0 label[15]);
extern void mypredictCL_api(const mxArray * const prhs[1], int32_T nlhs, const
  mxArray *plhs[1]);
extern void mypredictCL_atexit(void);
extern void mypredictCL_initialize(void);
extern void mypredictCL_terminate(void);
extern void mypredictCL_xil_terminate(void);

#endif

/*
 * File trailer for _coder_mypredictCL_api.h
 *
 * [EOF]
 */
