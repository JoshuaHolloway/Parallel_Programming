/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_myCorners_info.c
 *
 * Code generation for function '_coder_myCorners_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "myCorners.h"
#include "_coder_myCorners_info.h"

/* Function Definitions */
mxArray *emlrtMexFcnProperties(void)
{
  mxArray *xResult;
  mxArray *xEntryPoints;
  const char * fldNames[6] = { "Name", "NumberOfInputs", "NumberOfOutputs",
    "ConstantInputs", "FullPath", "TimeStamp" };

  mxArray *xInputs;
  const char * b_fldNames[4] = { "Version", "ResolvedFunctions", "EntryPoints",
    "CoverageInfo" };

  xEntryPoints = emlrtCreateStructMatrix(1, 1, 6, fldNames);
  xInputs = emlrtCreateLogicalMatrix(1, 6);
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("myCorners"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(6.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (3.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/josh/Desktop/Parallel_Vision_Research/Mobile_App/MATLAB-to-Android/matlabCode/myCorners/myCorners.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737152.10122685181));
  xResult = emlrtCreateStructMatrix(1, 1, 4, b_fldNames);
  emlrtSetField(xResult, 0, "Version", emlrtMxCreateString(
    "9.4.0.813654 (R2018a)"));
  emlrtSetField(xResult, 0, "ResolvedFunctions", (mxArray *)
                emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

const mxArray *emlrtMexFcnResolvedFunctionsInfo(void)
{
  const mxArray *nameCaptureInfo;
  const char * data[6] = {
    "789ced56cb6ed340149d405bc102e40a892d625d35035524b2ac9bb64a9a276954a14628f5638aa79df198193b4ac4827e081fc10e967c021b58f01db0679cd8"
    "7162344a20c520c895acf1d591efb9f7e43ac72057a9e7000077e5f5f53500bbf7c028ee8c0fa045e70d301b693c179d3753791ceb606de6b95cc4f726ca2de6",
    "fa68e08f13825dd408a889b84c5c83a249199b51ec1aaedf197a08702418e9237b849c63823a98a21a9b4aca5826f4700a9a242114de971c645d1e0714704724"
    "ed92e90444fa84f15131ffda82fa10853e5a0aef1e3c870ea3085e30e1c07d242e7de6c196c10d4210e99d608199db6b23810c6e39b0ce4c394b4ff73c58d73b",
    "357d6fdb67dbba6b73866d480d9f186689d908d2618971177191dce5e9f47c678afe37169c2f7dc6711bdc9a9e7637e61b28ea2daae7a6824f4be188921ef5e5"
    "ef2e7a0e22de68b3c29837f7bc3ed2a1ea238e98efed2ff2c5f5eb73f862bc5ba93d93ab14080e09b30c12ad076cef3c7a5c34a0cf1831d9004a7920c166b42a",
    "907902fea0d86851b2db93abeae6abcf7ab67b99f57bf0e7f8967defee2bf8b4147e746c17aa8346c3ecf827851764583d6d3e39da4ffa68cde199d70750e459"
    "d5ffa0787e511dbb8afa5a0abfd6f7f8a1c52895f66185de2766e63953f47bbd7bd89cfcff5f29ea2daadf03059f96c22de97e3c8fe54706770d92c7622fc0c4",
    "afb8f23303716c2ded0331ffbab29f3112c8168a20d1fbfd927c6d25df2cfe13fb135e5b23bde0562c184c0b36fe6ac8d40fde7dfbf269e507bf892f2b3f68f6"
    "5f96f4f372bfd8795a185a07d4dd393c25e5951ffcdf7ed0fa67fd60239527fd8c119b0526412b3f58f9c1dfc5b7f283e5ea7f0700205384",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 4952U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_myCorners_info.c) */
