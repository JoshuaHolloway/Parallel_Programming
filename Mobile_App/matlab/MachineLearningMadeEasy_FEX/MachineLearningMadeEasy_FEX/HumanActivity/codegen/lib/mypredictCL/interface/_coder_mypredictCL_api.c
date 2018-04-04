/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_mypredictCL_api.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 04-Apr-2018 06:26:45
 */

/* Include Files */
#include "tmwtypes.h"
#include "_coder_mypredictCL_api.h"
#include "_coder_mypredictCL_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131466U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "mypredictCL",                       /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

/* Function Declarations */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[105];
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[105];
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *X, const
  char_T *identifier))[105];
static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const cell_wrap_0
  u[15]);

/* Function Definitions */

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[105]
 */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[105]
{
  real_T (*y)[105];
  y = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[105]
 */
  static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[105]
{
  real_T (*ret)[105];
  static const int32_T dims[2] = { 15, 7 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[105])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *X
 *                const char_T *identifier
 * Return Type  : real_T (*)[105]
 */
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *X, const
  char_T *identifier))[105]
{
  real_T (*y)[105];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(X), &thisId);
  emlrtDestroyArray(&X);
  return y;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const cell_wrap_0 u[15]
 * Return Type  : const mxArray *
 */
  static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const
  cell_wrap_0 u[15])
{
  const mxArray *y;
  int32_T iv0[1];
  int32_T i0;
  int32_T u_size[2];
  int32_T loop_ub;
  int32_T i1;
  const mxArray *b_y;
  char_T u_data[3];
  const mxArray *m0;
  y = NULL;
  iv0[0] = 15;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(1, iv0));
  for (i0 = 0; i0 < 15; i0++) {
    u_size[0] = 1;
    u_size[1] = u[i0].f1.size[1];
    loop_ub = u[i0].f1.size[0] * u[i0].f1.size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      u_data[i1] = u[i0].f1.data[i1];
    }

    b_y = NULL;
    m0 = emlrtCreateCharArray(2, u_size);
    emlrtInitCharArrayR2013a(sp, u_size[1], m0, &u_data[0]);
    emlrtAssign(&b_y, m0);
    emlrtSetCell(y, i0, b_y);
  }

  return y;
}

/*
 * Arguments    : const mxArray * const prhs[1]
 *                int32_T nlhs
 *                const mxArray *plhs[1]
 * Return Type  : void
 */
void mypredictCL_api(const mxArray * const prhs[1], int32_T nlhs, const mxArray *
                     plhs[1])
{
  real_T (*X)[105];
  cell_wrap_0 label[15];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  (void)nlhs;
  st.tls = emlrtRootTLSGlobal;

  /* Marshall function inputs */
  X = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "X");

  /* Invoke the target function */
  mypredictCL(*X, label);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(&st, label);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void mypredictCL_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  mypredictCL_xil_terminate();
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void mypredictCL_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void mypredictCL_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * File trailer for _coder_mypredictCL_api.c
 *
 * [EOF]
 */
