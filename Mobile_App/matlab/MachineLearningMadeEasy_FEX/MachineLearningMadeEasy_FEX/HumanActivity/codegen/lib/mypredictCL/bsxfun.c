/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: bsxfun.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 04-Apr-2018 06:26:45
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "mypredictCL.h"
#include "bsxfun.h"

/* Function Definitions */

/*
 * Arguments    : const double a_data[]
 *                const int a_size[2]
 *                const double b_data[]
 *                const int b_size[2]
 *                double c_data[]
 *                int c_size[2]
 * Return Type  : void
 */
void b_bsxfun(const double a_data[], const int a_size[2], const double b_data[],
              const int b_size[2], double c_data[], int c_size[2])
{
  int acoef;
  int bcoef;
  int sck;
  int b_b_size;
  int k;
  int ia;
  int ib;
  int b_k;
  acoef = b_size[1];
  bcoef = a_size[1];
  if (acoef < bcoef) {
    bcoef = acoef;
  }

  if (b_size[1] == 1) {
    sck = a_size[1];
  } else if (a_size[1] == 1) {
    sck = b_size[1];
  } else if (a_size[1] == b_size[1]) {
    sck = a_size[1];
  } else {
    sck = bcoef;
  }

  c_size[0] = 15;
  acoef = b_size[1];
  bcoef = a_size[1];
  if (acoef < bcoef) {
    bcoef = acoef;
  }

  if (b_size[1] == 1) {
    c_size[1] = (signed char)a_size[1];
  } else if (a_size[1] == 1) {
    c_size[1] = (signed char)b_size[1];
  } else if (a_size[1] == b_size[1]) {
    c_size[1] = (signed char)a_size[1];
  } else {
    c_size[1] = (signed char)bcoef;
  }

  acoef = b_size[1];
  bcoef = a_size[1];
  if (acoef < bcoef) {
    bcoef = acoef;
  }

  if (b_size[1] == 1) {
    b_b_size = a_size[1];
  } else if (a_size[1] == 1) {
    b_b_size = b_size[1];
  } else if (a_size[1] == b_size[1]) {
    b_b_size = a_size[1];
  } else {
    b_b_size = bcoef;
  }

  if ((signed char)b_b_size != 0) {
    acoef = (a_size[1] != 1);
    bcoef = (b_size[1] != 1);
    for (k = 0; k < (signed char)sck; k++) {
      ia = acoef * k;
      ib = bcoef * k;
      for (b_k = 0; b_k < 15; b_k++) {
        c_data[b_k + 15 * k] = a_data[b_k + a_size[0] * ia] / b_data[b_size[0] *
          ib];
      }
    }
  }
}

/*
 * Arguments    : const double a[30]
 *                const double b[2]
 *                double c[30]
 * Return Type  : void
 */
void bsxfun(const double a[30], const double b[2], double c[30])
{
  int k;
  int b_k;
  for (k = 0; k < 2; k++) {
    for (b_k = 0; b_k < 15; b_k++) {
      c[b_k + 15 * k] = a[b_k + 15 * k] - b[k];
    }
  }
}

/*
 * File trailer for bsxfun.c
 *
 * [EOF]
 */
