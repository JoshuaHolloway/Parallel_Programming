/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: dot.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 04-Apr-2018 05:25:33
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "mypredictCL.h"
#include "dot.h"

/* Function Definitions */

/*
 * Arguments    : const double a[1000]
 *                const double b[1000]
 *                double c[500]
 * Return Type  : void
 */
void b_dot(const double a[1000], const double b[1000], double c[500])
{
  int i2;
  int ic;
  int i;
  int i1;
  double b_c;
  int iy;
  int k;
  i2 = 1;
  ic = -1;
  for (i = 0; i < 500; i++) {
    i1 = i2 - 1;
    ic++;
    i2 += 2;
    b_c = 0.0;
    iy = i1;
    for (k = 0; k < 2; k++) {
      b_c += a[i1] * b[iy];
      i1++;
      iy++;
    }

    c[ic] = b_c;
  }
}

/*
 * Arguments    : const double a[706]
 *                const double b[706]
 *                double c[353]
 * Return Type  : void
 */
void c_dot(const double a[706], const double b[706], double c[353])
{
  int i2;
  int ic;
  int i;
  int i1;
  double b_c;
  int iy;
  int k;
  i2 = 1;
  ic = -1;
  for (i = 0; i < 353; i++) {
    i1 = i2 - 1;
    ic++;
    i2 += 2;
    b_c = 0.0;
    iy = i1;
    for (k = 0; k < 2; k++) {
      b_c += a[i1] * b[iy];
      i1++;
      iy++;
    }

    c[ic] = b_c;
  }
}

/*
 * Arguments    : const double a[1210]
 *                const double b[1210]
 *                double c[605]
 * Return Type  : void
 */
void d_dot(const double a[1210], const double b[1210], double c[605])
{
  int i2;
  int ic;
  int i;
  int i1;
  double b_c;
  int iy;
  int k;
  i2 = 1;
  ic = -1;
  for (i = 0; i < 605; i++) {
    i1 = i2 - 1;
    ic++;
    i2 += 2;
    b_c = 0.0;
    iy = i1;
    for (k = 0; k < 2; k++) {
      b_c += a[i1] * b[iy];
      i1++;
      iy++;
    }

    c[ic] = b_c;
  }
}

/*
 * Arguments    : const double a[634]
 *                const double b[634]
 *                double c[317]
 * Return Type  : void
 */
void dot(const double a[634], const double b[634], double c[317])
{
  int i2;
  int ic;
  int i;
  int i1;
  double b_c;
  int iy;
  int k;
  i2 = 1;
  ic = -1;
  for (i = 0; i < 317; i++) {
    i1 = i2 - 1;
    ic++;
    i2 += 2;
    b_c = 0.0;
    iy = i1;
    for (k = 0; k < 2; k++) {
      b_c += a[i1] * b[iy];
      i1++;
      iy++;
    }

    c[ic] = b_c;
  }
}

/*
 * Arguments    : const double a[1710]
 *                const double b[1710]
 *                double c[855]
 * Return Type  : void
 */
void e_dot(const double a[1710], const double b[1710], double c[855])
{
  int i2;
  int ic;
  int i;
  int i1;
  double b_c;
  int iy;
  int k;
  i2 = 1;
  ic = -1;
  for (i = 0; i < 855; i++) {
    i1 = i2 - 1;
    ic++;
    i2 += 2;
    b_c = 0.0;
    iy = i1;
    for (k = 0; k < 2; k++) {
      b_c += a[i1] * b[iy];
      i1++;
      iy++;
    }

    c[ic] = b_c;
  }
}

/*
 * File trailer for dot.c
 *
 * [EOF]
 */
