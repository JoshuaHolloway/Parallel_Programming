/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: mypredictCL.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 04-Apr-2018 05:25:33
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "mypredictCL.h"
#include "CompactClassificationECOC.h"

/* Function Definitions */

/*
 * MYPREDICTCL Classify credit rating using model exported from
 * Classification Learner
 *    MYPREDICTCL loads trained classification model (SVM) and model
 *    parameters (removeVars, pcaCenters, and pcaCoefficients), removes the
 *    columns of the raw matrix of predictor data in X corresponding to the
 *    indices in removeVars, transforms the resulting matrix using the PCA
 *    centers in pcaCenters and PCA coefficients in pcaCoefficients, and then
 *    uses the transformed data to classify credit ratings. X is a numeric
 *    matrix with n rows and 7 columns. label is an n-by-1 cell array of
 *    predicted labels.
 * Arguments    : const double X[105]
 *                cell_wrap_0 label[15]
 * Return Type  : void
 */
void mypredictCL(const double X[105], cell_wrap_0 label[15])
{
  int i;
  char SVM_ClassNames[21];
  static const char cv0[21] = { 'A', 'A', 'A', 'B', 'B', 'B', 'C', ' ', 'A', 'A',
    ' ', 'B', 'B', 'C', ' ', ' ', 'A', ' ', ' ', 'B', 'C' };

  int SVM_ClassNamesLength[7];
  static const signed char iv0[7] = { 1, 2, 3, 1, 2, 3, 3 };

  double SVM_CodingMatrix[147];
  static const signed char iv1[147] = { 1, -1, 0, 0, 0, 0, 0, 1, 0, -1, 0, 0, 0,
    0, 1, 0, 0, -1, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, 1, 0, 0, 0, 0, -1, 0, 1, 0, 0,
    0, 0, 0, -1, 0, 1, -1, 0, 0, 0, 0, 0, 1, 0, -1, 0, 0, 0, 0, 1, 0, 0, -1, 0,
    0, 0, 1, 0, 0, 0, -1, 0, 0, 1, 0, 0, 0, 0, -1, 0, 0, 1, -1, 0, 0, 0, 0, 0, 1,
    0, -1, 0, 0, 0, 0, 1, 0, 0, -1, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, 0, 1, -1, 0,
    0, 0, 0, 0, 1, 0, -1, 0, 0, 0, 0, 1, 0, 0, -1, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0,
    0, 1, 0, -1, 0, 0, 0, 0, 0, 1, -1 };

  double SVM_Prior[7];
  static const double dv0[7] = { 0.14623601220752797, 0.0979145473041709,
    0.14750762970498474, 0.081383519837232965, 0.23575788402848424,
    0.25813835198372331, 0.033062054933875887 };

  int k;
  double c[90];
  static const double b[6] = { 0.14075356052899238, 0.20745091556459816,
    0.051558748728382606, 2.0588540183112913, 0.30717166836215659,
    6.390386571719227 };

  double b_c[30];
  int i0;
  static const double b_b[12] = { 0.016118667843829319, 0.039869604088608644,
    0.0025435266290782551, 0.99747474597509378, 0.051036428752726869,
    -0.02415673345333131, 0.00083647638086990837, 0.0018375557138558415,
    0.00010411702995422707, 0.024054922492637229, 0.0013418701088167152,
    0.99970769375072455 };

  /*  Load trained classification model and model parameters */
  for (i = 0; i < 21; i++) {
    SVM_ClassNames[i] = cv0[i];
  }

  for (i = 0; i < 7; i++) {
    SVM_ClassNamesLength[i] = iv0[i];
  }

  for (i = 0; i < 147; i++) {
    SVM_CodingMatrix[i] = iv1[i];
  }

  for (i = 0; i < 7; i++) {
    SVM_Prior[i] = dv0[i];
  }

  /*  Remove unused predictor variables */
  /*  Transform predictors via PCA */
  for (i = 0; i < 6; i++) {
    for (k = 0; k < 15; k++) {
      c[k + 15 * i] = X[k + 15 * (1 + i)] - b[i];
    }
  }

  /*  Generate label from SVM */
  for (i = 0; i < 15; i++) {
    for (k = 0; k < 2; k++) {
      b_c[i + 15 * k] = 0.0;
      for (i0 = 0; i0 < 6; i0++) {
        b_c[i + 15 * k] += c[i + 15 * i0] * b_b[i0 + 6 * k];
      }
    }
  }

  c_CompactClassificationECOC_pre(SVM_ClassNames, SVM_ClassNamesLength,
    SVM_Prior, SVM_CodingMatrix, b_c, label);
}

/*
 * File trailer for mypredictCL.c
 *
 * [EOF]
 */
