/*
 * File: _coder_myCorners_api.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 10-Sep-2015 15:39:50
 */

/* Include Files */
#include "tmwtypes.h"
#include "_coder_myCorners_api.h"
#include "_coder_myCorners_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true, false, 131419U, NULL, "myCorners",
  NULL, false, { 2045744189U, 2170104910U, 2743257031U, 4284093946U }, NULL };

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
  thisId.fIdentifier = identifier;
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
  ret = (uint8_T (*)[101376])mxGetData(src);
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
  thisId.fIdentifier = identifier;
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

  mxSetData((mxArray *)y, (void *)u);
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
  ret = *(real32_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const mxArray *prhs[6]
 *                const mxArray *plhs[3]
 * Return Type  : void
 */
void myCorners_api(const mxArray *prhs[6], const mxArray *plhs[3])
{
  uint8_T (*R)[101376];
  uint8_T (*G)[101376];
  uint8_T (*B)[101376];
  real32_T fThresh;
  real32_T hThresh;
  real32_T mThresh;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  prhs[0] = emlrtProtectR2012b(prhs[0], 0, true, -1);
  prhs[1] = emlrtProtectR2012b(prhs[1], 1, true, -1);
  prhs[2] = emlrtProtectR2012b(prhs[2], 2, true, -1);

  /* Marshall function inputs */
  R = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "R");
  G = emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "G");
  B = emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "B");
  fThresh = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "fThresh");
  hThresh = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "hThresh");
  mThresh = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "mThresh");

  /* Invoke the target function */
  myCorners(*R, *G, *B, fThresh, hThresh, mThresh);

  /* Marshall function outputs */
  emlrt_marshallOut(*R, prhs[0]);
  plhs[0] = prhs[0];
  emlrt_marshallOut(*G, prhs[1]);
  plhs[1] = prhs[1];
  emlrt_marshallOut(*B, prhs[2]);
  plhs[2] = prhs[2];
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void myCorners_atexit(void)
{
  emlrtStack st = { NULL, NULL, NULL };

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
  emlrtStack st = { NULL, NULL, NULL };

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
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * File trailer for _coder_myCorners_api.c
 *
 * [EOF]
 */
