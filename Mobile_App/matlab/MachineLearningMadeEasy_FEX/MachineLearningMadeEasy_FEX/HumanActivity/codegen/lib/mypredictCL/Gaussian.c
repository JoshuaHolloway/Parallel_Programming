/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Gaussian.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 04-Apr-2018 06:26:45
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "mypredictCL.h"
#include "Gaussian.h"

/* Function Definitions */

/*
 * Arguments    : const double svT[634]
 *                const double svInnerProduct[317]
 *                const double x[2]
 *                double kernelProduct[317]
 * Return Type  : void
 */
void Gaussian(const double svT[634], const double svInnerProduct[317], const
              double x[2], double kernelProduct[317])
{
  int k;
  double y;
  double b_y[317];
  int i3;
  for (k = 0; k < 317; k++) {
    b_y[k] = 0.0;
    for (i3 = 0; i3 < 2; i3++) {
      b_y[k] += -2.0 * x[i3] * svT[i3 + (k << 1)];
    }
  }

  y = 0.0;
  for (k = 0; k < 2; k++) {
    y += x[k] * x[k];
  }

  for (k = 0; k < 317; k++) {
    kernelProduct[k] = exp(-((b_y[k] + y) + svInnerProduct[k]));
  }
}

/*
 * Arguments    : const double svT[352]
 *                const double svInnerProduct[176]
 *                const double x[2]
 *                double kernelProduct[176]
 * Return Type  : void
 */
void b_Gaussian(const double svT[352], const double svInnerProduct[176], const
                double x[2], double kernelProduct[176])
{
  int k;
  double y;
  double b_y[176];
  int i5;
  for (k = 0; k < 176; k++) {
    b_y[k] = 0.0;
    for (i5 = 0; i5 < 2; i5++) {
      b_y[k] += -2.0 * x[i5] * svT[i5 + (k << 1)];
    }
  }

  y = 0.0;
  for (k = 0; k < 2; k++) {
    y += x[k] * x[k];
  }

  for (k = 0; k < 176; k++) {
    kernelProduct[k] = exp(-((b_y[k] + y) + svInnerProduct[k]));
  }
}

/*
 * Arguments    : const double svT[144]
 *                const double svInnerProduct[72]
 *                const double x[2]
 *                double kernelProduct[72]
 * Return Type  : void
 */
void c_Gaussian(const double svT[144], const double svInnerProduct[72], const
                double x[2], double kernelProduct[72])
{
  int k;
  double y;
  double b_y[72];
  int i6;
  for (k = 0; k < 72; k++) {
    b_y[k] = 0.0;
    for (i6 = 0; i6 < 2; i6++) {
      b_y[k] += -2.0 * x[i6] * svT[i6 + (k << 1)];
    }
  }

  y = 0.0;
  for (k = 0; k < 2; k++) {
    y += x[k] * x[k];
  }

  for (k = 0; k < 72; k++) {
    kernelProduct[k] = exp(-((b_y[k] + y) + svInnerProduct[k]));
  }
}

/*
 * Arguments    : const double svT[278]
 *                const double svInnerProduct[139]
 *                const double x[2]
 *                double kernelProduct[139]
 * Return Type  : void
 */
void d_Gaussian(const double svT[278], const double svInnerProduct[139], const
                double x[2], double kernelProduct[139])
{
  int k;
  double y;
  double b_y[139];
  int i7;
  for (k = 0; k < 139; k++) {
    b_y[k] = 0.0;
    for (i7 = 0; i7 < 2; i7++) {
      b_y[k] += -2.0 * x[i7] * svT[i7 + (k << 1)];
    }
  }

  y = 0.0;
  for (k = 0; k < 2; k++) {
    y += x[k] * x[k];
  }

  for (k = 0; k < 139; k++) {
    kernelProduct[k] = exp(-((b_y[k] + y) + svInnerProduct[k]));
  }
}

/*
 * Arguments    : const double svT[1000]
 *                const double svInnerProduct[500]
 *                const double x[2]
 *                double kernelProduct[500]
 * Return Type  : void
 */
void e_Gaussian(const double svT[1000], const double svInnerProduct[500], const
                double x[2], double kernelProduct[500])
{
  int k;
  double y;
  double b_y[500];
  int i9;
  for (k = 0; k < 500; k++) {
    b_y[k] = 0.0;
    for (i9 = 0; i9 < 2; i9++) {
      b_y[k] += -2.0 * x[i9] * svT[i9 + (k << 1)];
    }
  }

  y = 0.0;
  for (k = 0; k < 2; k++) {
    y += x[k] * x[k];
  }

  for (k = 0; k < 500; k++) {
    kernelProduct[k] = exp(-((b_y[k] + y) + svInnerProduct[k]));
  }
}

/*
 * Arguments    : const double svT[170]
 *                const double svInnerProduct[85]
 *                const double x[2]
 *                double kernelProduct[85]
 * Return Type  : void
 */
void f_Gaussian(const double svT[170], const double svInnerProduct[85], const
                double x[2], double kernelProduct[85])
{
  int k;
  double y;
  double b_y[85];
  int i10;
  for (k = 0; k < 85; k++) {
    b_y[k] = 0.0;
    for (i10 = 0; i10 < 2; i10++) {
      b_y[k] += -2.0 * x[i10] * svT[i10 + (k << 1)];
    }
  }

  y = 0.0;
  for (k = 0; k < 2; k++) {
    y += x[k] * x[k];
  }

  for (k = 0; k < 85; k++) {
    kernelProduct[k] = exp(-((b_y[k] + y) + svInnerProduct[k]));
  }
}

/*
 * Arguments    : const double svT[706]
 *                const double svInnerProduct[353]
 *                const double x[2]
 *                double kernelProduct[353]
 * Return Type  : void
 */
void g_Gaussian(const double svT[706], const double svInnerProduct[353], const
                double x[2], double kernelProduct[353])
{
  int k;
  double y;
  double b_y[353];
  int i12;
  for (k = 0; k < 353; k++) {
    b_y[k] = 0.0;
    for (i12 = 0; i12 < 2; i12++) {
      b_y[k] += -2.0 * x[i12] * svT[i12 + (k << 1)];
    }
  }

  y = 0.0;
  for (k = 0; k < 2; k++) {
    y += x[k] * x[k];
  }

  for (k = 0; k < 353; k++) {
    kernelProduct[k] = exp(-((b_y[k] + y) + svInnerProduct[k]));
  }
}

/*
 * Arguments    : const double svT[74]
 *                const double svInnerProduct[37]
 *                const double x[2]
 *                double kernelProduct[37]
 * Return Type  : void
 */
void h_Gaussian(const double svT[74], const double svInnerProduct[37], const
                double x[2], double kernelProduct[37])
{
  int k;
  double y;
  double b_y[37];
  int i13;
  for (k = 0; k < 37; k++) {
    b_y[k] = 0.0;
    for (i13 = 0; i13 < 2; i13++) {
      b_y[k] += -2.0 * x[i13] * svT[i13 + (k << 1)];
    }
  }

  y = 0.0;
  for (k = 0; k < 2; k++) {
    y += x[k] * x[k];
  }

  for (k = 0; k < 37; k++) {
    kernelProduct[k] = exp(-((b_y[k] + y) + svInnerProduct[k]));
  }
}

/*
 * Arguments    : const double svT[110]
 *                const double svInnerProduct[55]
 *                const double x[2]
 *                double kernelProduct[55]
 * Return Type  : void
 */
void i_Gaussian(const double svT[110], const double svInnerProduct[55], const
                double x[2], double kernelProduct[55])
{
  int k;
  double y;
  double b_y[55];
  int i14;
  for (k = 0; k < 55; k++) {
    b_y[k] = 0.0;
    for (i14 = 0; i14 < 2; i14++) {
      b_y[k] += -2.0 * x[i14] * svT[i14 + (k << 1)];
    }
  }

  y = 0.0;
  for (k = 0; k < 2; k++) {
    y += x[k] * x[k];
  }

  for (k = 0; k < 55; k++) {
    kernelProduct[k] = exp(-((b_y[k] + y) + svInnerProduct[k]));
  }
}

/*
 * Arguments    : const double svT[210]
 *                const double svInnerProduct[105]
 *                const double x[2]
 *                double kernelProduct[105]
 * Return Type  : void
 */
void j_Gaussian(const double svT[210], const double svInnerProduct[105], const
                double x[2], double kernelProduct[105])
{
  int k;
  double y;
  double b_y[105];
  int i15;
  for (k = 0; k < 105; k++) {
    b_y[k] = 0.0;
    for (i15 = 0; i15 < 2; i15++) {
      b_y[k] += -2.0 * x[i15] * svT[i15 + (k << 1)];
    }
  }

  y = 0.0;
  for (k = 0; k < 2; k++) {
    y += x[k] * x[k];
  }

  for (k = 0; k < 105; k++) {
    kernelProduct[k] = exp(-((b_y[k] + y) + svInnerProduct[k]));
  }
}

/*
 * Arguments    : const double svT[102]
 *                const double svInnerProduct[51]
 *                const double x[2]
 *                double kernelProduct[51]
 * Return Type  : void
 */
void k_Gaussian(const double svT[102], const double svInnerProduct[51], const
                double x[2], double kernelProduct[51])
{
  int k;
  double y;
  double b_y[51];
  int i16;
  for (k = 0; k < 51; k++) {
    b_y[k] = 0.0;
    for (i16 = 0; i16 < 2; i16++) {
      b_y[k] += -2.0 * x[i16] * svT[i16 + (k << 1)];
    }
  }

  y = 0.0;
  for (k = 0; k < 2; k++) {
    y += x[k] * x[k];
  }

  for (k = 0; k < 51; k++) {
    kernelProduct[k] = exp(-((b_y[k] + y) + svInnerProduct[k]));
  }
}

/*
 * Arguments    : const double svT[150]
 *                const double svInnerProduct[75]
 *                const double x[2]
 *                double kernelProduct[75]
 * Return Type  : void
 */
void l_Gaussian(const double svT[150], const double svInnerProduct[75], const
                double x[2], double kernelProduct[75])
{
  int k;
  double y;
  double b_y[75];
  int i17;
  for (k = 0; k < 75; k++) {
    b_y[k] = 0.0;
    for (i17 = 0; i17 < 2; i17++) {
      b_y[k] += -2.0 * x[i17] * svT[i17 + (k << 1)];
    }
  }

  y = 0.0;
  for (k = 0; k < 2; k++) {
    y += x[k] * x[k];
  }

  for (k = 0; k < 75; k++) {
    kernelProduct[k] = exp(-((b_y[k] + y) + svInnerProduct[k]));
  }
}

/*
 * Arguments    : const double svT[166]
 *                const double svInnerProduct[83]
 *                const double x[2]
 *                double kernelProduct[83]
 * Return Type  : void
 */
void m_Gaussian(const double svT[166], const double svInnerProduct[83], const
                double x[2], double kernelProduct[83])
{
  int k;
  double y;
  double b_y[83];
  int i18;
  for (k = 0; k < 83; k++) {
    b_y[k] = 0.0;
    for (i18 = 0; i18 < 2; i18++) {
      b_y[k] += -2.0 * x[i18] * svT[i18 + (k << 1)];
    }
  }

  y = 0.0;
  for (k = 0; k < 2; k++) {
    y += x[k] * x[k];
  }

  for (k = 0; k < 83; k++) {
    kernelProduct[k] = exp(-((b_y[k] + y) + svInnerProduct[k]));
  }
}

/*
 * Arguments    : const double svT[214]
 *                const double svInnerProduct[107]
 *                const double x[2]
 *                double kernelProduct[107]
 * Return Type  : void
 */
void n_Gaussian(const double svT[214], const double svInnerProduct[107], const
                double x[2], double kernelProduct[107])
{
  int k;
  double y;
  double b_y[107];
  int i19;
  for (k = 0; k < 107; k++) {
    b_y[k] = 0.0;
    for (i19 = 0; i19 < 2; i19++) {
      b_y[k] += -2.0 * x[i19] * svT[i19 + (k << 1)];
    }
  }

  y = 0.0;
  for (k = 0; k < 2; k++) {
    y += x[k] * x[k];
  }

  for (k = 0; k < 107; k++) {
    kernelProduct[k] = exp(-((b_y[k] + y) + svInnerProduct[k]));
  }
}

/*
 * Arguments    : const double svT[136]
 *                const double svInnerProduct[68]
 *                const double x[2]
 *                double kernelProduct[68]
 * Return Type  : void
 */
void o_Gaussian(const double svT[136], const double svInnerProduct[68], const
                double x[2], double kernelProduct[68])
{
  int k;
  double y;
  double b_y[68];
  int i20;
  for (k = 0; k < 68; k++) {
    b_y[k] = 0.0;
    for (i20 = 0; i20 < 2; i20++) {
      b_y[k] += -2.0 * x[i20] * svT[i20 + (k << 1)];
    }
  }

  y = 0.0;
  for (k = 0; k < 2; k++) {
    y += x[k] * x[k];
  }

  for (k = 0; k < 68; k++) {
    kernelProduct[k] = exp(-((b_y[k] + y) + svInnerProduct[k]));
  }
}

/*
 * Arguments    : const double svT[1210]
 *                const double svInnerProduct[605]
 *                const double x[2]
 *                double kernelProduct[605]
 * Return Type  : void
 */
void p_Gaussian(const double svT[1210], const double svInnerProduct[605], const
                double x[2], double kernelProduct[605])
{
  int k;
  double y;
  double b_y[605];
  int i22;
  for (k = 0; k < 605; k++) {
    b_y[k] = 0.0;
    for (i22 = 0; i22 < 2; i22++) {
      b_y[k] += -2.0 * x[i22] * svT[i22 + (k << 1)];
    }
  }

  y = 0.0;
  for (k = 0; k < 2; k++) {
    y += x[k] * x[k];
  }

  for (k = 0; k < 605; k++) {
    kernelProduct[k] = exp(-((b_y[k] + y) + svInnerProduct[k]));
  }
}

/*
 * Arguments    : const double svT[454]
 *                const double svInnerProduct[227]
 *                const double x[2]
 *                double kernelProduct[227]
 * Return Type  : void
 */
void q_Gaussian(const double svT[454], const double svInnerProduct[227], const
                double x[2], double kernelProduct[227])
{
  int k;
  double y;
  double b_y[227];
  int i24;
  for (k = 0; k < 227; k++) {
    b_y[k] = 0.0;
    for (i24 = 0; i24 < 2; i24++) {
      b_y[k] += -2.0 * x[i24] * svT[i24 + (k << 1)];
    }
  }

  y = 0.0;
  for (k = 0; k < 2; k++) {
    y += x[k] * x[k];
  }

  for (k = 0; k < 227; k++) {
    kernelProduct[k] = exp(-((b_y[k] + y) + svInnerProduct[k]));
  }
}

/*
 * Arguments    : const double svT[460]
 *                const double svInnerProduct[230]
 *                const double x[2]
 *                double kernelProduct[230]
 * Return Type  : void
 */
void r_Gaussian(const double svT[460], const double svInnerProduct[230], const
                double x[2], double kernelProduct[230])
{
  int k;
  double y;
  double b_y[230];
  int i26;
  for (k = 0; k < 230; k++) {
    b_y[k] = 0.0;
    for (i26 = 0; i26 < 2; i26++) {
      b_y[k] += -2.0 * x[i26] * svT[i26 + (k << 1)];
    }
  }

  y = 0.0;
  for (k = 0; k < 2; k++) {
    y += x[k] * x[k];
  }

  for (k = 0; k < 230; k++) {
    kernelProduct[k] = exp(-((b_y[k] + y) + svInnerProduct[k]));
  }
}

/*
 * Arguments    : const double svT[1710]
 *                const double svInnerProduct[855]
 *                const double x[2]
 *                double kernelProduct[855]
 * Return Type  : void
 */
void s_Gaussian(const double svT[1710], const double svInnerProduct[855], const
                double x[2], double kernelProduct[855])
{
  int k;
  double y;
  double b_y[855];
  int i28;
  for (k = 0; k < 855; k++) {
    b_y[k] = 0.0;
    for (i28 = 0; i28 < 2; i28++) {
      b_y[k] += -2.0 * x[i28] * svT[i28 + (k << 1)];
    }
  }

  y = 0.0;
  for (k = 0; k < 2; k++) {
    y += x[k] * x[k];
  }

  for (k = 0; k < 855; k++) {
    kernelProduct[k] = exp(-((b_y[k] + y) + svInnerProduct[k]));
  }
}

/*
 * Arguments    : const double svT[388]
 *                const double svInnerProduct[194]
 *                const double x[2]
 *                double kernelProduct[194]
 * Return Type  : void
 */
void t_Gaussian(const double svT[388], const double svInnerProduct[194], const
                double x[2], double kernelProduct[194])
{
  int k;
  double y;
  double b_y[194];
  int i30;
  for (k = 0; k < 194; k++) {
    b_y[k] = 0.0;
    for (i30 = 0; i30 < 2; i30++) {
      b_y[k] += -2.0 * x[i30] * svT[i30 + (k << 1)];
    }
  }

  y = 0.0;
  for (k = 0; k < 2; k++) {
    y += x[k] * x[k];
  }

  for (k = 0; k < 194; k++) {
    kernelProduct[k] = exp(-((b_y[k] + y) + svInnerProduct[k]));
  }
}

/*
 * Arguments    : const double svT[256]
 *                const double svInnerProduct[128]
 *                const double x[2]
 *                double kernelProduct[128]
 * Return Type  : void
 */
void u_Gaussian(const double svT[256], const double svInnerProduct[128], const
                double x[2], double kernelProduct[128])
{
  int k;
  double y;
  double b_y[128];
  int i31;
  for (k = 0; k < 128; k++) {
    b_y[k] = 0.0;
    for (i31 = 0; i31 < 2; i31++) {
      b_y[k] += -2.0 * x[i31] * svT[i31 + (k << 1)];
    }
  }

  y = 0.0;
  for (k = 0; k < 2; k++) {
    y += x[k] * x[k];
  }

  for (k = 0; k < 128; k++) {
    kernelProduct[k] = exp(-((b_y[k] + y) + svInnerProduct[k]));
  }
}

/*
 * File trailer for Gaussian.c
 *
 * [EOF]
 */
