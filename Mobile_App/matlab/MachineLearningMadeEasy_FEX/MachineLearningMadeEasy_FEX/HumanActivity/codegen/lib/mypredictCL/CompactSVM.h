/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CompactSVM.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 04-Apr-2018 06:26:45
 */

#ifndef COMPACTSVM_H
#define COMPACTSVM_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mypredictCL_types.h"

/* Function Declarations */
extern void CompactSVM_CompactSVM(c_classreg_learning_coder_class *obj);
extern void CompactSVM_score(const double obj_Alpha[317], const double obj_Mu[2],
  const double obj_Sigma[2], const double Xin[30], double S[15]);
extern void b_CompactSVM_CompactSVM(d_classreg_learning_coder_class *obj);
extern void b_CompactSVM_score(const double obj_Alpha[500], const double obj_Mu
  [2], const double obj_Sigma[2], const double Xin[30], double S[15]);
extern void c_CompactSVM_CompactSVM(e_classreg_learning_coder_class *obj);
extern void c_CompactSVM_score(const double obj_Alpha[353], const double obj_Mu
  [2], const double obj_Sigma[2], const double Xin[30], double S[15]);
extern void d_CompactSVM_CompactSVM(f_classreg_learning_coder_class *obj);
extern void d_CompactSVM_score(const double obj_Alpha[605], const double obj_Mu
  [2], const double obj_Sigma[2], const double Xin[30], double S[15]);
extern void e_CompactSVM_CompactSVM(g_classreg_learning_coder_class *obj);
extern void e_CompactSVM_score(const double obj_Alpha[227], const double obj_Mu
  [2], const double obj_Sigma[2], const double Xin[30], double S[15]);
extern void f_CompactSVM_CompactSVM(h_classreg_learning_coder_class *obj);
extern void f_CompactSVM_score(const double obj_Alpha[230], const double obj_Mu
  [2], const double obj_Sigma[2], const double Xin[30], double S[15]);
extern void g_CompactSVM_CompactSVM(i_classreg_learning_coder_class *obj);
extern void g_CompactSVM_score(const double obj_Alpha[855], const double obj_Mu
  [2], const double obj_Sigma[2], const double Xin[30], double S[15]);
extern void h_CompactSVM_CompactSVM(j_classreg_learning_coder_class *obj);
extern void h_CompactSVM_score(const double obj_Alpha[194], const double obj_Mu
  [2], const double obj_Sigma[2], const double Xin[30], double S[15]);
extern void i_CompactSVM_CompactSVM(k_classreg_learning_coder_class *obj);
extern void j_CompactSVM_CompactSVM(l_classreg_learning_coder_class *obj);
extern void k_CompactSVM_CompactSVM(m_classreg_learning_coder_class *obj);

#endif

/*
 * File trailer for CompactSVM.h
 *
 * [EOF]
 */
