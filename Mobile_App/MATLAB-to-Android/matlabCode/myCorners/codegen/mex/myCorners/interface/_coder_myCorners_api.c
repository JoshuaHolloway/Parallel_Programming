/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_myCorners_api.c
 *
 * Code generation for function '_coder_myCorners_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "myCorners.h"
#include "_coder_myCorners_api.h"
#include "myCorners_data.h"

/* Function Declarations */
static uint8_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[307200];
static real32_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *fThresh,
  const char_T *identifier);
static real32_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static uint8_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[307200];
static uint8_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *R, const
  char_T *identifier))[307200];
static void emlrt_marshallOut(const uint8_T u[307200], const mxArray *y);
static real32_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);

/* Function Definitions */
static uint8_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[307200]
{
  uint8_T (*y)[307200];
  y = e_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
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

static real32_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real32_T y;
  y = f_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static uint8_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[307200]
{
  uint8_T (*ret)[307200];
  static const int32_T dims[2] = { 480, 640 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "uint8", false, 2U, dims);
  ret = (uint8_T (*)[307200])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static uint8_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *R,
  const char_T *identifier))[307200]
{
  uint8_T (*y)[307200];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(R), &thisId);
  emlrtDestroyArray(&R);
  return y;
}

static void emlrt_marshallOut(const uint8_T u[307200], const mxArray *y)
{
  static const int32_T iv0[2] = { 480, 640 };

  emlrtMxSetData((mxArray *)y, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)y, iv0, 2);
}

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

void myCorners_api(const mxArray * const prhs[6], int32_T nlhs, const mxArray
                   *plhs[3])
{
  const mxArray *prhs_copy_idx_0;
  const mxArray *prhs_copy_idx_1;
  const mxArray *prhs_copy_idx_2;
  uint8_T (*R)[307200];
  uint8_T (*G)[307200];
  uint8_T (*B)[307200];
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

/* End of code generation (_coder_myCorners_api.c) */
