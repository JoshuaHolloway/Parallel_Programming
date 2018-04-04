/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Gaussian.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 04-Apr-2018 06:26:45
 */

#ifndef GAUSSIAN_H
#define GAUSSIAN_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mypredictCL_types.h"

/* Function Declarations */
extern void Gaussian(const double svT[634], const double svInnerProduct[317],
                     const double x[2], double kernelProduct[317]);
extern void b_Gaussian(const double svT[352], const double svInnerProduct[176],
  const double x[2], double kernelProduct[176]);
extern void c_Gaussian(const double svT[144], const double svInnerProduct[72],
  const double x[2], double kernelProduct[72]);
extern void d_Gaussian(const double svT[278], const double svInnerProduct[139],
  const double x[2], double kernelProduct[139]);
extern void e_Gaussian(const double svT[1000], const double svInnerProduct[500],
  const double x[2], double kernelProduct[500]);
extern void f_Gaussian(const double svT[170], const double svInnerProduct[85],
  const double x[2], double kernelProduct[85]);
extern void g_Gaussian(const double svT[706], const double svInnerProduct[353],
  const double x[2], double kernelProduct[353]);
extern void h_Gaussian(const double svT[74], const double svInnerProduct[37],
  const double x[2], double kernelProduct[37]);
extern void i_Gaussian(const double svT[110], const double svInnerProduct[55],
  const double x[2], double kernelProduct[55]);
extern void j_Gaussian(const double svT[210], const double svInnerProduct[105],
  const double x[2], double kernelProduct[105]);
extern void k_Gaussian(const double svT[102], const double svInnerProduct[51],
  const double x[2], double kernelProduct[51]);
extern void l_Gaussian(const double svT[150], const double svInnerProduct[75],
  const double x[2], double kernelProduct[75]);
extern void m_Gaussian(const double svT[166], const double svInnerProduct[83],
  const double x[2], double kernelProduct[83]);
extern void n_Gaussian(const double svT[214], const double svInnerProduct[107],
  const double x[2], double kernelProduct[107]);
extern void o_Gaussian(const double svT[136], const double svInnerProduct[68],
  const double x[2], double kernelProduct[68]);
extern void p_Gaussian(const double svT[1210], const double svInnerProduct[605],
  const double x[2], double kernelProduct[605]);
extern void q_Gaussian(const double svT[454], const double svInnerProduct[227],
  const double x[2], double kernelProduct[227]);
extern void r_Gaussian(const double svT[460], const double svInnerProduct[230],
  const double x[2], double kernelProduct[230]);
extern void s_Gaussian(const double svT[1710], const double svInnerProduct[855],
  const double x[2], double kernelProduct[855]);
extern void t_Gaussian(const double svT[388], const double svInnerProduct[194],
  const double x[2], double kernelProduct[194]);
extern void u_Gaussian(const double svT[256], const double svInnerProduct[128],
  const double x[2], double kernelProduct[128]);

#endif

/*
 * File trailer for Gaussian.h
 *
 * [EOF]
 */
