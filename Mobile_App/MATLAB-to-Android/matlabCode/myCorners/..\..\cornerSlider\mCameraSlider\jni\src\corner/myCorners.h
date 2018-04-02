/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: myCorners.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 02-Apr-2018 02:26:12
 */

#ifndef MYCORNERS_H
#define MYCORNERS_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "myCorners_types.h"

/* Function Declarations */
extern void myCorners(unsigned char R[101376], const unsigned char G[101376],
                      const unsigned char B[101376], float fThresh, float
                      hThresh, float mThresh);
extern void myCorners_initialize(void);
extern void myCorners_terminate(void);

#endif

/*
 * File trailer for myCorners.h
 *
 * [EOF]
 */
