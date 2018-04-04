/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CompactClassificationSVM.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 04-Apr-2018 05:25:33
 */

#ifndef COMPACTCLASSIFICATIONSVM_H
#define COMPACTCLASSIFICATIONSVM_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mypredictCL_types.h"

/* Function Declarations */
extern void CompactClassificationSVM_score(const double obj_Alpha[176], const
  double obj_Mu[2], const double obj_Sigma[2], const double obj_ClassNames[2],
  const double obj_NonzeroProbClasses[2], const double X[30], double S[30]);

#endif

/*
 * File trailer for CompactClassificationSVM.h
 *
 * [EOF]
 */
