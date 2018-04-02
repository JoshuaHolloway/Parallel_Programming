/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_myCorners_api.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 02-Apr-2018 02:26:12
 */

/* Include Files */
#include "tmwtypes.h"
#include "_coder_myCorners_api.h"
#include "_coder_myCorners_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131466U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "myCorners",                         /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

/* Function Declarations */
static uint8_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[101376];
static real32_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *fThresh,
  const char_T *identifier);
static real32_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static uint8_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[101376];
static uint8_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *R, const
  char_T *identifier))[101376];
static void emlrt_marshallOut(const uint8_T u[101376], const mxArray *y);
static real32_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);

/* Function Definitions */

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : uint8_T (*)[101376]
 */
static uint8_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[101376]
{
  uint8_T (*y)[101376];
  y = e_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *fThresh
 *                const char_T *identifier
 * Return Type  : real32_T
 */
  static real32_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *fThresh, const char_T *identifier)
{
  real32_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(fThresh), &thisId);
  emlrtDestroyArray(&fThresh);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real32_T
 */
static real32_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real32_T y;
  y = f_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : uint8_T (*)[101376]
 */
static uint8_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[101376]
{
  uint8_T (*ret)[101376];
  static const int32_T dims[2] = { 352, 288 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "uint8", false, 2U, dims);
  ret = (uint8_T (*)[101376])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *R
 *                const char_T *identifier
 * Return Type  : uint8_T (*)[101376]
 */
  static uint8_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *R,
  const char_T *identifier))[101376]
{
  uint8_T (*y)[101376];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(R), &thisId);
  emlrtDestroyArray(&R);
  return y;
}

/*
 * Arguments    : const uint8_T u[101376]
 *                const mxArray *y
 * Return Type  : void
 */
static void emlrt_marshallOut(const uint8_T u[101376], const mxArray *y)
{
  static const int32_T iv0[2] = { 352, 288 };

  emlrtMxSetData((mxArray *)y, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)y, iv0, 2);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real32_T
 */
static real32_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  real32_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "single", false, 0U, &dims);
  ret = *(real32_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const mxArray * const prhs[6]
 *                int32_T nlhs
 *                const mxArray *plhs[3]
 * Return Type  : void
 */
void myCorners_api(const mxArray * const prhs[6], int32_T nlhs, const mxArray
                   *plhs[3])
{
  const mxArray *prhs_copy_idx_0;
  const mxArray *prhs_copy_idx_1;
  const mxArray *prhs_copy_idx_2;
  uint8_T (*R)[101376];
  uint8_T (*G)[101376];
  uint8_T (*B)[101376];
  real32_T fThresh;
  real32_T hThresh;
  real32_T mThresh;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  prhs_copy_idx_0 = emlrtProtectR2012b(prhs[0], 0, true, -1);
  prhs_copy_idx_1 = emlrtProtectR2012b(prhs[1], 1, true, -1);
  prhs_copy_idx_2 = emlrtProtectR2012b(prhs[2], 2, true, -1);

  /* Marshall function inputs */
  R = emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_0), "R");
  G = emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_1), "G");
  B = emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_2), "B");
  fThresh = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "fThresh");
  hThresh = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "hThresh");
  mThresh = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "mThresh");

  /* Invoke the target function */
  myCorners(*R, *G, *B, fThresh, hThresh, mThresh);

  /* Marshall function outputs */
  emlrt_marshallOut(*R, prhs_copy_idx_0);
  plhs[0] = prhs_copy_idx_0;
  if (nlhs > 1) {
    emlrt_marshallOut(*G, prhs_copy_idx_1);
    plhs[1] = prhs_copy_idx_1;
  }

  if (nlhs > 2) {
    emlrt_marshallOut(*B, prhs_copy_idx_2);
    plhs[2] = prhs_copy_idx_2;
  }
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void myCorners_atexit(void)
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
  myCorners_xil_terminate();
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void myCorners_initialize(void)
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
void myCorners_terminate(void)
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
 * File trailer for _coder_myCorners_api.c
 *
 * [EOF]
 */
