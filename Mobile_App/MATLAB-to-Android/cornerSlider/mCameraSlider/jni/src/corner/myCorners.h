/*
 * File: myCorners.h
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 10-Sep-2015 15:39:50
 */

#ifndef __MYCORNERS_H__
#define __MYCORNERS_H__

/* Include Files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "myCorners_types.h"

/* Function Declarations */
extern void myCorners(unsigned char R[101376], unsigned char G[101376], unsigned
                      char B[101376], float fThresh, float hThresh, float
                      mThresh);
extern void myCorners_initialize(void);
extern void myCorners_terminate(void);

#endif

/*
 * File trailer for myCorners.h
 *
 * [EOF]
 */
