/*
 * File: myCorners.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 10-Sep-2015 15:39:50
 */

/* Include Files */
#include "myCorners.h"

/* Type Definitions */
#ifndef struct_vision_private_CornerMetric_4
#define struct_vision_private_CornerMetric_4

struct vision_private_CornerMetric_4
{
  int S0_isInitialized;
  float W0_DW_PAD[5340];
  int W1_DW_NEXTPADIDX[5];
  int W2_DW_COLPADIDX[292];
  int W3_DW_ROWPADIDX[356];
  float P0_FILTER_RTP[10];
  int P1_COLRANGE_RTP[4];
  int P2_ROWRANGE_RTP[6];
};

#endif                                 /*struct_vision_private_CornerMetric_4*/

#ifndef typedef_vision_private_CornerMetric_4
#define typedef_vision_private_CornerMetric_4

typedef struct vision_private_CornerMetric_4 vision_private_CornerMetric_4;

#endif                                 /*typedef_vision_private_CornerMetric_4*/

#ifndef typedef_vision_CornerDetector
#define typedef_vision_CornerDetector

typedef struct {
  int isInitialized;
  boolean_T TunablePropsChanged;
  double Sensitivity;
  double IntensityThreshold;
  double CornerThreshold;
  vision_private_CornerMetric_4 cCornerMetric;
} vision_CornerDetector;

#endif                                 /*typedef_vision_CornerDetector*/

#ifndef struct_vision_private_CornerMetric_2
#define struct_vision_private_CornerMetric_2

struct vision_private_CornerMetric_2
{
  int S0_isInitialized;
  float P0_THRANGLE_RTP;
  float P1_VALTHR_RTP;
  float P2_DTMIN_RTP;
  float P3_DTMAX_RTP;
  float P4_DTLOW_RTP;
  float P5_DTHIGH_RTP;
  int P6_CIRCLE_RTP[32];
  int P7_STEP_RTP[3];
  int P8_OFFSET_RTP[3];
};

#endif                                 /*struct_vision_private_CornerMetric_2*/

#ifndef typedef_vision_private_CornerMetric_2
#define typedef_vision_private_CornerMetric_2

typedef struct vision_private_CornerMetric_2 vision_private_CornerMetric_2;

#endif                                 /*typedef_vision_private_CornerMetric_2*/

#ifndef typedef_vision_CornerDetector_1
#define typedef_vision_CornerDetector_1

typedef struct {
  int isInitialized;
  boolean_T TunablePropsChanged;
  double Sensitivity;
  double IntensityThreshold;
  double CornerThreshold;
  vision_private_CornerMetric_2 cCornerMetric;
} vision_CornerDetector_1;

#endif                                 /*typedef_vision_CornerDetector_1*/

#ifndef struct_vision_private_CornerMetric_3
#define struct_vision_private_CornerMetric_3

struct vision_private_CornerMetric_3
{
  int S0_isInitialized;
  float W0_DW_PAD[5340];
  int W1_DW_NEXTPADIDX[5];
  int W2_DW_COLPADIDX[292];
  int W3_DW_ROWPADIDX[356];
  float P0_FILTER_RTP[10];
  int P1_COLRANGE_RTP[4];
  int P2_ROWRANGE_RTP[6];
  float P3_FACTOR_RTP;
};

#endif                                 /*struct_vision_private_CornerMetric_3*/

#ifndef typedef_vision_private_CornerMetric_3
#define typedef_vision_private_CornerMetric_3

typedef struct vision_private_CornerMetric_3 vision_private_CornerMetric_3;

#endif                                 /*typedef_vision_private_CornerMetric_3*/

#ifndef typedef_vision_CornerDetector_2
#define typedef_vision_CornerDetector_2

typedef struct {
  int isInitialized;
  boolean_T TunablePropsChanged;
  double Sensitivity;
  double IntensityThreshold;
  double CornerThreshold;
  vision_private_CornerMetric_3 cCornerMetric;
} vision_CornerDetector_2;

#endif                                 /*typedef_vision_CornerDetector_2*/

#ifndef struct_vision_LocalMaximaFinder_0
#define struct_vision_LocalMaximaFinder_0

struct vision_LocalMaximaFinder_0
{
  int S0_isInitialized;
  float W0_TEMP_IN_DWORKS[101376];
  unsigned int W1_NUMPEAKS_DWORK;
  unsigned int P0_NHOODSIZE_RTP[2];
};

#endif                                 /*struct_vision_LocalMaximaFinder_0*/

#ifndef typedef_vision_LocalMaximaFinder_0
#define typedef_vision_LocalMaximaFinder_0

typedef struct vision_LocalMaximaFinder_0 vision_LocalMaximaFinder_0;

#endif                                 /*typedef_vision_LocalMaximaFinder_0*/

#ifndef typedef_visioncodegen_LocalMaximaFinder
#define typedef_visioncodegen_LocalMaximaFinder

typedef struct {
  int isInitialized;
  vision_LocalMaximaFinder_0 cSFunObject;
} visioncodegen_LocalMaximaFinder;

#endif                                 /*typedef_visioncodegen_LocalMaximaFinder*/

#ifndef struct_vision_MarkerInserter_1
#define struct_vision_MarkerInserter_1

struct vision_MarkerInserter_1
{
  int S0_isInitialized;
  unsigned char P0_RTP_FILLCOLOR;
  unsigned int P1_RTP_SIZE;
};

#endif                                 /*struct_vision_MarkerInserter_1*/

#ifndef typedef_vision_MarkerInserter_1
#define typedef_vision_MarkerInserter_1

typedef struct vision_MarkerInserter_1 vision_MarkerInserter_1;

#endif                                 /*typedef_vision_MarkerInserter_1*/

#ifndef typedef_visioncodegen_MarkerInserter
#define typedef_visioncodegen_MarkerInserter

typedef struct {
  int isInitialized;
  vision_MarkerInserter_1 cSFunObject;
} visioncodegen_MarkerInserter;

#endif                                 /*typedef_visioncodegen_MarkerInserter*/

/* Function Declarations */
static vision_CornerDetector_2 *CornerDetector_CornerDetector
  (vision_CornerDetector_2 *obj);
static void CornerDetector_stepImpl(vision_CornerDetector_1 *obj, const float
  in[101376], float out[101376]);
static void Destructor(vision_private_CornerMetric_3 *obj);
static visioncodegen_MarkerInserter *MarkerInserter_MarkerInserter
  (visioncodegen_MarkerInserter *obj);
static void Nondirect_stepImpl(visioncodegen_MarkerInserter *obj, unsigned char
  varargin_1[101376], const unsigned int varargin_2_data[], const int
  varargin_2_size[2]);
static void Outputs(vision_private_CornerMetric_3 *obj, const float U0[101376],
                    float Y0[101376]);
static void SystemCore_step(vision_CornerDetector_1 *obj, const float
  varargin_1[101376], float varargout_1[101376]);
static vision_CornerDetector_1 *b_CornerDetector_CornerDetector
  (vision_CornerDetector_1 *obj);
static void b_Destructor(vision_private_CornerMetric_4 *obj);
static void b_Nondirect_stepImpl(visioncodegen_MarkerInserter *obj, unsigned
  char varargin_1[101376], const unsigned int varargin_2_data[], const int
  varargin_2_size[2]);
static void b_Outputs(vision_private_CornerMetric_4 *obj, const float U0[101376],
                      float Y0[101376]);
static void b_SystemCore_step(visioncodegen_LocalMaximaFinder *obj, const float
  varargin_1[101376], float varargin_2, unsigned int varargout_1_data[], int
  varargout_1_size[2]);
static vision_CornerDetector *c_CornerDetector_CornerDetector
  (vision_CornerDetector *obj);
static void c_Nondirect_stepImpl(visioncodegen_MarkerInserter *obj, unsigned
  char varargin_1[101376], const unsigned int varargin_2_data[], const int
  varargin_2_size[2]);
static void c_SystemCore_step(vision_CornerDetector_2 *obj, const float
  varargin_1[101376], float varargout_1[101376]);
static void d_SystemCore_step(visioncodegen_LocalMaximaFinder *obj, const float
  varargin_1[101376], float varargin_2, unsigned int varargout_1_data[], int
  varargout_1_size[2]);
static int div_s32_floor(int numerator, int denominator);
static void e_SystemCore_step(vision_CornerDetector *obj, const float
  varargin_1[101376], float varargout_1[101376]);
static void f_SystemCore_step(visioncodegen_LocalMaximaFinder *obj, const float
  varargin_1[101376], float varargin_2, unsigned int varargout_1_data[], int
  varargout_1_size[2]);

/* Function Definitions */

/*
 * Arguments    : vision_CornerDetector_2 *obj
 * Return Type  : vision_CornerDetector_2 *
 */
static vision_CornerDetector_2 *CornerDetector_CornerDetector
  (vision_CornerDetector_2 *obj)
{
  vision_CornerDetector_2 *b_obj;
  vision_CornerDetector_2 *c_obj;
  boolean_T flag;
  b_obj = obj;
  b_obj->Sensitivity = 0.04;
  b_obj->IntensityThreshold = 0.1;
  c_obj = b_obj;
  c_obj->isInitialized = 0;
  c_obj = b_obj;
  flag = (c_obj->isInitialized == 1);
  if (flag) {
    c_obj->TunablePropsChanged = true;
  }

  c_obj->CornerThreshold = 2.2204460492503131E-16;
  return b_obj;
}

/*
 * Arguments    : vision_CornerDetector_1 *obj
 *                const float in[101376]
 *                float out[101376]
 * Return Type  : void
 */
static void CornerDetector_stepImpl(vision_CornerDetector_1 *obj, const float
  in[101376], float out[101376])
{
  vision_private_CornerMetric_2 *b_obj;
  int center;
  int col;
  int row;
  float valLow;
  float valHigh;
  int start;
  int stop;
  boolean_T flag;
  boolean_T isValid;
  int idx;
  int pixel;
  int disStart;
  int disStop;
  float brightness;
  float darkness;
  float valCur;
  b_obj = &obj->cCornerMetric;

  /* System object Outputs function: vision.private.CornerMetric */
  memset(&out[0], 0, 101376U * sizeof(float));
  center = 1059;
  for (col = 0; col < 282; col++) {
    for (row = 0; row < 346; row++) {
      if (in[center] > b_obj->P4_DTLOW_RTP) {
        valLow = in[center] - b_obj->P1_VALTHR_RTP;
      } else {
        valLow = b_obj->P2_DTMIN_RTP;
      }

      if (in[center] < b_obj->P5_DTHIGH_RTP) {
        valHigh = in[center] + b_obj->P1_VALTHR_RTP;
      } else {
        valHigh = b_obj->P3_DTMAX_RTP;
      }

      if ((in[center + b_obj->P6_CIRCLE_RTP[0]] > valHigh) || (in[center +
           b_obj->P6_CIRCLE_RTP[8]] > valHigh)) {
        if (in[center + b_obj->P6_CIRCLE_RTP[0]] <= valHigh) {
          start = 1;
          stop = 15;
          flag = false;
        } else if (in[center + b_obj->P6_CIRCLE_RTP[8]] <= valHigh) {
          start = 9;
          stop = 23;
          flag = false;
        } else {
          start = 1;
          stop = 16;
          flag = true;
        }

        isValid = true;
        idx = 0;
        while (isValid && (idx < 3)) {
          pixel = start + b_obj->P8_OFFSET_RTP[idx];
          while (isValid && (pixel <= stop)) {
            if (in[center + b_obj->P6_CIRCLE_RTP[pixel]] <= valHigh) {
              if (flag) {
                start = pixel + 1;
                stop = pixel + 15;
                flag = false;
              } else {
                disStart = pixel - start;
                disStop = stop - pixel;
                if (disStop >= disStart) {
                  if (disStop < 9) {
                    isValid = false;
                  } else {
                    start = pixel + 1;
                  }
                } else if (disStart < 9) {
                  isValid = false;
                } else {
                  stop = pixel - 1;
                }
              }
            }

            pixel += b_obj->P7_STEP_RTP[idx];
          }

          idx++;
        }

        if (isValid) {
          brightness = 0.0F;
          for (idx = start; idx <= stop; idx++) {
            brightness += in[center + b_obj->P6_CIRCLE_RTP[idx]] - valHigh;
          }

          if (stop >= 16) {
            stop -= 16;
          } else {
            start += 16;
          }

          darkness = 0.0F;
          for (idx = stop + 1; idx < start; idx++) {
            valCur = in[center + b_obj->P6_CIRCLE_RTP[idx]];
            if (valCur < valLow) {
              darkness += valLow;
              darkness -= valCur;
            } else {
              if (valCur > valHigh) {
                brightness += valCur;
                brightness -= valHigh;
              }
            }
          }

          if (brightness >= darkness) {
            darkness = brightness;
          }

          out[center] = darkness;
        }
      }

      if ((in[center + b_obj->P6_CIRCLE_RTP[0]] < valLow) || (in[center +
           b_obj->P6_CIRCLE_RTP[8]] < valLow)) {
        if (in[center + b_obj->P6_CIRCLE_RTP[0]] >= valLow) {
          start = 1;
          stop = 15;
          flag = false;
        } else if (in[center + b_obj->P6_CIRCLE_RTP[8]] >= valLow) {
          start = 9;
          stop = 23;
          flag = false;
        } else {
          start = 1;
          stop = 16;
          flag = true;
        }

        isValid = true;
        idx = 0;
        while (isValid && (idx < 3)) {
          pixel = start + b_obj->P8_OFFSET_RTP[idx];
          while (isValid && (pixel <= stop)) {
            if (in[center + b_obj->P6_CIRCLE_RTP[pixel]] >= valLow) {
              if (flag) {
                start = pixel + 1;
                stop = pixel + 15;
                flag = false;
              } else {
                disStart = pixel - start;
                disStop = stop - pixel;
                if (disStop >= disStart) {
                  if (disStop < 9) {
                    isValid = false;
                  } else {
                    start = pixel + 1;
                  }
                } else if (disStart < 9) {
                  isValid = false;
                } else {
                  stop = pixel - 1;
                }
              }
            }

            pixel += b_obj->P7_STEP_RTP[idx];
          }

          idx++;
        }

        if (isValid) {
          darkness = 0.0F;
          for (idx = start; idx <= stop; idx++) {
            darkness += valLow - in[center + b_obj->P6_CIRCLE_RTP[idx]];
          }

          if (stop >= 16) {
            stop -= 16;
          } else {
            start += 16;
          }

          brightness = 0.0F;
          for (idx = stop + 1; idx < start; idx++) {
            valCur = in[center + b_obj->P6_CIRCLE_RTP[idx]];
            if (valCur > valHigh) {
              brightness += valCur;
              brightness -= valHigh;
            } else {
              if (valCur < valLow) {
                darkness += valLow;
                darkness -= valCur;
              }
            }
          }

          if (brightness >= darkness) {
            darkness = brightness;
          }

          out[center] = darkness;
        }
      }

      center++;
    }

    center += 6;
  }
}

/*
 * Arguments    : vision_private_CornerMetric_3 *obj
 * Return Type  : void
 */
static void Destructor(vision_private_CornerMetric_3 *obj)
{
  /* System object Destructor function: vision.private.CornerMetric */
  if ((obj->S0_isInitialized == 1) && (obj->S0_isInitialized != 2)) {
    obj->S0_isInitialized = 2;
  }
}

/*
 * Arguments    : visioncodegen_MarkerInserter *obj
 * Return Type  : visioncodegen_MarkerInserter *
 */
static visioncodegen_MarkerInserter *MarkerInserter_MarkerInserter
  (visioncodegen_MarkerInserter *obj)
{
  visioncodegen_MarkerInserter *b_obj;
  visioncodegen_MarkerInserter *c_obj;
  vision_MarkerInserter_1 *d_obj;
  b_obj = obj;
  c_obj = b_obj;
  c_obj->isInitialized = 0;
  d_obj = &b_obj->cSFunObject;

  /* System object Constructor function: vision.MarkerInserter */
  d_obj->P0_RTP_FILLCOLOR = MAX_uint8_T;
  d_obj->P1_RTP_SIZE = 3U;
  c_obj = b_obj;
  c_obj->cSFunObject.P1_RTP_SIZE = 3U;
  return b_obj;
}

/*
 * Arguments    : visioncodegen_MarkerInserter *obj
 *                unsigned char varargin_1[101376]
 *                const unsigned int varargin_2_data[]
 *                const int varargin_2_size[2]
 * Return Type  : void
 */
static void Nondirect_stepImpl(visioncodegen_MarkerInserter *obj, unsigned char
  varargin_1[101376], const unsigned int varargin_2_data[], const int
  varargin_2_size[2])
{
  visioncodegen_MarkerInserter *b_obj;
  vision_MarkerInserter_1 *c_obj;
  boolean_T isSizeValid;
  int numShape;
  int size;
  int idxROI;
  int row;
  int col;
  int line[4];
  boolean_T visited1;
  boolean_T visited2;
  boolean_T done;
  int b_line[4];
  int i;
  int in;
  int dr;
  int dc;
  b_obj = obj;
  c_obj = &b_obj->cSFunObject;

  /* System object Outputs function: vision.MarkerInserter */
  isSizeValid = true;
  numShape = 0;
  if (varargin_2_size[1] > 1) {
    numShape = varargin_2_size[0];
  } else {
    if (varargin_2_size[1] == 1) {
      numShape = 1;
      isSizeValid = !((varargin_2_size[0] & 1) != 0);
    }
  }

  /* Copy the image from input to output. */
  if (isSizeValid) {
    /* Update view port. */
    /* Draw all pluses. */
    size = (int)b_obj->cSFunObject.P1_RTP_SIZE;
    for (idxROI = 0; idxROI < numShape; idxROI++) {
      row = (int)varargin_2_data[idxROI + numShape] - 1;
      col = (int)varargin_2_data[idxROI] - 1;
      line[0U] = row;
      line[1U] = col - size;
      line[2U] = row;
      line[3U] = col + size;
      isSizeValid = false;

      /* Find the visible portion of a line. */
      visited1 = false;
      visited2 = false;
      done = false;
      for (i = 0; i < 4; i++) {
        b_line[i] = line[i];
      }

      while (!done) {
        i = 0;
        in = 0;

        /* Determine viewport violations. */
        if (b_line[0U] < 0) {
          i = 4;
        } else {
          if (b_line[0U] > 351) {
            i = 8;
          }
        }

        if (b_line[2U] < 0) {
          in = 4;
        } else {
          if (b_line[2U] > 351) {
            in = 8;
          }
        }

        if (b_line[1U] < 0) {
          i |= 1U;
        } else {
          if (b_line[1U] > 287) {
            i |= 2U;
          }
        }

        if (b_line[3U] < 0) {
          in |= 1U;
        } else {
          if (b_line[3U] > 287) {
            in |= 2U;
          }
        }

        if (!(((unsigned int)i | in) != 0U)) {
          /* Line falls completely within bounds. */
          done = true;
          isSizeValid = true;
        } else if (((unsigned int)i & in) != 0U) {
          /* Line falls completely out of bounds. */
          done = true;
          isSizeValid = false;
        } else if ((unsigned int)i != 0U) {
          /* Clip 1st point; if it's in-bounds, clip 2nd point. */
          if (visited1) {
            b_line[0U] = row;
            b_line[1U] = line[1];
          }

          dr = b_line[2] - b_line[0];
          dc = b_line[3] - b_line[1];
          if ((dr > 1073741824) || (dr < -1073741824) || ((dc > 1073741824) ||
               (dc < -1073741824))) {
            /* Possible Inf or Nan. */
            done = true;
            isSizeValid = false;
            visited1 = true;
          } else if ((i & 4U) != 0U) {
            /* Violated RMin. */
            i = -b_line[0] * dc;
            if ((i > 1073741824) || (i < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isSizeValid = false;
            } else if (((i >= 0) && (dr >= 0)) || ((i < 0) && (dr < 0))) {
              b_line[1U] += (div_s32_floor(i << 1, dr) + 1) >> 1;
            } else {
              b_line[1U] -= (div_s32_floor(-i << 1, dr) + 1) >> 1;
            }

            b_line[0U] = 0;
            visited1 = true;
          } else if ((i & 8U) != 0U) {
            /* Violated RMax. */
            i = (351 - b_line[0]) * dc;
            if ((i > 1073741824) || (i < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isSizeValid = false;
            } else if (((i >= 0) && (dr >= 0)) || ((i < 0) && (dr < 0))) {
              b_line[1U] += (div_s32_floor(i << 1, dr) + 1) >> 1;
            } else {
              b_line[1U] -= (div_s32_floor(-i << 1, dr) + 1) >> 1;
            }

            b_line[0U] = 351;
            visited1 = true;
          } else if ((i & 1U) != 0U) {
            /* Violated CMin. */
            i = -b_line[1] * dr;
            if ((i > 1073741824) || (i < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isSizeValid = false;
            } else if (((i >= 0) && (dc >= 0)) || ((i < 0) && (dc < 0))) {
              b_line[0U] += (div_s32_floor(i << 1, dc) + 1) >> 1;
            } else {
              b_line[0U] -= (div_s32_floor(-i << 1, dc) + 1) >> 1;
            }

            b_line[1U] = 0;
            visited1 = true;
          } else {
            /* Violated CMax. */
            i = (287 - b_line[1]) * dr;
            if ((i > 1073741824) || (i < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isSizeValid = false;
            } else if (((i >= 0) && (dc >= 0)) || ((i < 0) && (dc < 0))) {
              b_line[0U] += (div_s32_floor(i << 1, dc) + 1) >> 1;
            } else {
              b_line[0U] -= (div_s32_floor(-i << 1, dc) + 1) >> 1;
            }

            b_line[1U] = 287;
            visited1 = true;
          }
        } else {
          /* Clip the 2nd point. */
          if (visited2) {
            b_line[2U] = row;
            b_line[3U] = line[3];
          }

          dr = b_line[2] - b_line[0];
          dc = b_line[3] - b_line[1];
          if ((dr > 1073741824) || (dr < -1073741824) || ((dc > 1073741824) ||
               (dc < -1073741824))) {
            /* Possible Inf or Nan. */
            done = true;
            isSizeValid = false;
            visited2 = true;
          } else if ((in & 4U) != 0U) {
            /* Violated RMin. */
            i = -b_line[2] * dc;
            if ((i > 1073741824) || (i < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isSizeValid = false;
            } else if (((i >= 0) && (dr >= 0)) || ((i < 0) && (dr < 0))) {
              b_line[3U] += (div_s32_floor(i << 1, dr) + 1) >> 1;
            } else {
              b_line[3U] -= (div_s32_floor(-i << 1, dr) + 1) >> 1;
            }

            b_line[2U] = 0;
            visited2 = true;
          } else if ((in & 8U) != 0U) {
            /* Violated RMax. */
            i = (351 - b_line[2]) * dc;
            if ((i > 1073741824) || (i < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isSizeValid = false;
            } else if (((i >= 0) && (dr >= 0)) || ((i < 0) && (dr < 0))) {
              b_line[3U] += (div_s32_floor(i << 1, dr) + 1) >> 1;
            } else {
              b_line[3U] -= (div_s32_floor(-i << 1, dr) + 1) >> 1;
            }

            b_line[2U] = 351;
            visited2 = true;
          } else if ((in & 1U) != 0U) {
            /* Violated CMin. */
            i = -b_line[3] * dr;
            if ((i > 1073741824) || (i < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isSizeValid = false;
            } else if (((i >= 0) && (dc >= 0)) || ((i < 0) && (dc < 0))) {
              b_line[2U] += (div_s32_floor(i << 1, dc) + 1) >> 1;
            } else {
              b_line[2U] -= (div_s32_floor(-i << 1, dc) + 1) >> 1;
            }

            b_line[3U] = 0;
            visited2 = true;
          } else {
            /* Violated CMax. */
            i = (287 - b_line[3]) * dr;
            if ((i > 1073741824) || (i < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isSizeValid = false;
            } else if (((i >= 0) && (dc >= 0)) || ((i < 0) && (dc < 0))) {
              b_line[2U] += (div_s32_floor(i << 1, dc) + 1) >> 1;
            } else {
              b_line[2U] -= (div_s32_floor(-i << 1, dc) + 1) >> 1;
            }

            b_line[3U] = 287;
            visited2 = true;
          }
        }
      }

      if (isSizeValid) {
        i = b_line[1] * 352 + b_line[0];
        for (in = b_line[1]; in <= b_line[3U]; in++) {
          varargin_1[i] = c_obj->P0_RTP_FILLCOLOR;
          i += 352;
        }
      }

      line[0U] = row - size;
      line[1U] = col;
      line[2U] = row + size;
      line[3U] = col;
      isSizeValid = false;

      /* Find the visible portion of a line. */
      visited1 = false;
      visited2 = false;
      done = false;
      for (i = 0; i < 4; i++) {
        b_line[i] = line[i];
      }

      while (!done) {
        i = 0;
        in = 0;

        /* Determine viewport violations. */
        if (b_line[0U] < 0) {
          i = 4;
        } else {
          if (b_line[0U] > 351) {
            i = 8;
          }
        }

        if (b_line[2U] < 0) {
          in = 4;
        } else {
          if (b_line[2U] > 351) {
            in = 8;
          }
        }

        if (b_line[1U] < 0) {
          i |= 1U;
        } else {
          if (b_line[1U] > 287) {
            i |= 2U;
          }
        }

        if (b_line[3U] < 0) {
          in |= 1U;
        } else {
          if (b_line[3U] > 287) {
            in |= 2U;
          }
        }

        if (!(((unsigned int)i | in) != 0U)) {
          /* Line falls completely within bounds. */
          done = true;
          isSizeValid = true;
        } else if (((unsigned int)i & in) != 0U) {
          /* Line falls completely out of bounds. */
          done = true;
          isSizeValid = false;
        } else if ((unsigned int)i != 0U) {
          /* Clip 1st point; if it's in-bounds, clip 2nd point. */
          if (visited1) {
            b_line[0U] = line[0];
            b_line[1U] = col;
          }

          dr = b_line[2] - b_line[0];
          dc = b_line[3] - b_line[1];
          if ((dr > 1073741824) || (dr < -1073741824) || ((dc > 1073741824) ||
               (dc < -1073741824))) {
            /* Possible Inf or Nan. */
            done = true;
            isSizeValid = false;
            visited1 = true;
          } else if ((i & 4U) != 0U) {
            /* Violated RMin. */
            i = -b_line[0] * dc;
            if ((i > 1073741824) || (i < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isSizeValid = false;
            } else if (((i >= 0) && (dr >= 0)) || ((i < 0) && (dr < 0))) {
              b_line[1U] += (div_s32_floor(i << 1, dr) + 1) >> 1;
            } else {
              b_line[1U] -= (div_s32_floor(-i << 1, dr) + 1) >> 1;
            }

            b_line[0U] = 0;
            visited1 = true;
          } else if ((i & 8U) != 0U) {
            /* Violated RMax. */
            i = (351 - b_line[0]) * dc;
            if ((i > 1073741824) || (i < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isSizeValid = false;
            } else if (((i >= 0) && (dr >= 0)) || ((i < 0) && (dr < 0))) {
              b_line[1U] += (div_s32_floor(i << 1, dr) + 1) >> 1;
            } else {
              b_line[1U] -= (div_s32_floor(-i << 1, dr) + 1) >> 1;
            }

            b_line[0U] = 351;
            visited1 = true;
          } else if ((i & 1U) != 0U) {
            /* Violated CMin. */
            i = -b_line[1] * dr;
            if ((i > 1073741824) || (i < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isSizeValid = false;
            } else if (((i >= 0) && (dc >= 0)) || ((i < 0) && (dc < 0))) {
              b_line[0U] += (div_s32_floor(i << 1, dc) + 1) >> 1;
            } else {
              b_line[0U] -= (div_s32_floor(-i << 1, dc) + 1) >> 1;
            }

            b_line[1U] = 0;
            visited1 = true;
          } else {
            /* Violated CMax. */
            i = (287 - b_line[1]) * dr;
            if ((i > 1073741824) || (i < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isSizeValid = false;
            } else if (((i >= 0) && (dc >= 0)) || ((i < 0) && (dc < 0))) {
              b_line[0U] += (div_s32_floor(i << 1, dc) + 1) >> 1;
            } else {
              b_line[0U] -= (div_s32_floor(-i << 1, dc) + 1) >> 1;
            }

            b_line[1U] = 287;
            visited1 = true;
          }
        } else {
          /* Clip the 2nd point. */
          if (visited2) {
            b_line[2U] = line[2];
            b_line[3U] = col;
          }

          dr = b_line[2] - b_line[0];
          dc = b_line[3] - b_line[1];
          if ((dr > 1073741824) || (dr < -1073741824) || ((dc > 1073741824) ||
               (dc < -1073741824))) {
            /* Possible Inf or Nan. */
            done = true;
            isSizeValid = false;
            visited2 = true;
          } else if ((in & 4U) != 0U) {
            /* Violated RMin. */
            i = -b_line[2] * dc;
            if ((i > 1073741824) || (i < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isSizeValid = false;
            } else if (((i >= 0) && (dr >= 0)) || ((i < 0) && (dr < 0))) {
              b_line[3U] += (div_s32_floor(i << 1, dr) + 1) >> 1;
            } else {
              b_line[3U] -= (div_s32_floor(-i << 1, dr) + 1) >> 1;
            }

            b_line[2U] = 0;
            visited2 = true;
          } else if ((in & 8U) != 0U) {
            /* Violated RMax. */
            i = (351 - b_line[2]) * dc;
            if ((i > 1073741824) || (i < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isSizeValid = false;
            } else if (((i >= 0) && (dr >= 0)) || ((i < 0) && (dr < 0))) {
              b_line[3U] += (div_s32_floor(i << 1, dr) + 1) >> 1;
            } else {
              b_line[3U] -= (div_s32_floor(-i << 1, dr) + 1) >> 1;
            }

            b_line[2U] = 351;
            visited2 = true;
          } else if ((in & 1U) != 0U) {
            /* Violated CMin. */
            i = -b_line[3] * dr;
            if ((i > 1073741824) || (i < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isSizeValid = false;
            } else if (((i >= 0) && (dc >= 0)) || ((i < 0) && (dc < 0))) {
              b_line[2U] += (div_s32_floor(i << 1, dc) + 1) >> 1;
            } else {
              b_line[2U] -= (div_s32_floor(-i << 1, dc) + 1) >> 1;
            }

            b_line[3U] = 0;
            visited2 = true;
          } else {
            /* Violated CMax. */
            i = (287 - b_line[3]) * dr;
            if ((i > 1073741824) || (i < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isSizeValid = false;
            } else if (((i >= 0) && (dc >= 0)) || ((i < 0) && (dc < 0))) {
              b_line[2U] += (div_s32_floor(i << 1, dc) + 1) >> 1;
            } else {
              b_line[2U] -= (div_s32_floor(-i << 1, dc) + 1) >> 1;
            }

            b_line[3U] = 287;
            visited2 = true;
          }
        }
      }

      if (isSizeValid) {
        i = b_line[1] * 352 + b_line[0];
        for (in = b_line[0]; in <= b_line[2U]; in++) {
          varargin_1[i] = c_obj->P0_RTP_FILLCOLOR;
          i++;
        }
      }
    }
  }
}

/*
 * Arguments    : vision_private_CornerMetric_3 *obj
 *                const float U0[101376]
 *                float Y0[101376]
 * Return Type  : void
 */
static void Outputs(vision_private_CornerMetric_3 *obj, const float U0[101376],
                    float Y0[101376])
{
  int i;
  int j;
  int iImgOut;
  int colPad;
  int rowRangeAdj;
  int iRange;
  int col;
  int colPadNext;
  int iPad;
  int row;
  float memObj1;
  float memObj2;
  int iPadDst;
  int iFltr;

  /* System object Outputs function: vision.private.CornerMetric */
  for (i = 0; i < 3; i++) {
    obj->W3_DW_ROWPADIDX[i] = 1;
  }

  for (j = 0; j < 350; j++) {
    obj->W3_DW_ROWPADIDX[i] = j + 1;
    i++;
  }

  for (j = 0; j < 3; j++) {
    obj->W3_DW_ROWPADIDX[i] = 350;
    i++;
  }

  for (i = 0; i < 3; i++) {
    obj->W2_DW_COLPADIDX[i] = 1;
  }

  for (j = 0; j < 286; j++) {
    obj->W2_DW_COLPADIDX[i] = j + 1;
    i++;
  }

  for (j = 0; j < 3; j++) {
    obj->W2_DW_COLPADIDX[i] = 286;
    i++;
  }

  iImgOut = 0;
  colPad = 0;
  rowRangeAdj = 2;
  for (iRange = 0; iRange < 4; iRange += 2) {
    for (col = obj->P1_COLRANGE_RTP[iRange]; col < obj->P1_COLRANGE_RTP[iRange +
         1]; col++) {
      colPadNext = obj->W1_DW_NEXTPADIDX[colPad];
      iPad = colPad * 356;
      i = obj->W2_DW_COLPADIDX[col] * 352 - 1;
      for (row = 0; row < 356; row++) {
        j = i + obj->W3_DW_ROWPADIDX[row];
        memObj1 = U0[j - 351] - U0[j + 353];
        memObj2 = U0[j] - U0[j + 2];
        obj->W0_DW_PAD[iPad] = memObj1 * memObj1;
        obj->W0_DW_PAD[(unsigned int)(iPad + 1780)] = memObj2 * memObj2;
        obj->W0_DW_PAD[(unsigned int)(iPad + 3560)] = memObj1 * memObj2;
        iPad++;
      }

      i = colPadNext * 356;
      for (j = 0; j <= 3560; j += 1780) {
        iPadDst = i + j;
        for (row = obj->P2_ROWRANGE_RTP[rowRangeAdj - 2]; row <
             obj->P2_ROWRANGE_RTP[rowRangeAdj]; row++) {
          memObj1 = 0.0F;
          iPad = row + j;
          for (iFltr = 4 - colPad; iFltr < 9 - colPad; iFltr++) {
            memObj1 += obj->W0_DW_PAD[iPad] * obj->P0_FILTER_RTP[iFltr];
            iPad += 356;
          }

          obj->W0_DW_PAD[iPadDst] = memObj1;
          iPadDst++;
        }

        iPadDst = i + j;
        for (row = obj->P2_ROWRANGE_RTP[rowRangeAdj - 1]; row <
             obj->P2_ROWRANGE_RTP[rowRangeAdj]; row++) {
          iPad = iPadDst;
          memObj1 = 0.0F;
          for (iFltr = 0; iFltr < 5; iFltr++) {
            memObj1 += obj->W0_DW_PAD[iPad] * obj->P0_FILTER_RTP[iFltr];
            iPad++;
          }

          obj->W0_DW_PAD[iPadDst] = memObj1;
          iPadDst++;
        }
      }

      for (iPad = i; iPad < (i + obj->P2_ROWRANGE_RTP[rowRangeAdj]) -
           obj->P2_ROWRANGE_RTP[rowRangeAdj - 1]; iPad++) {
        memObj1 = obj->W0_DW_PAD[iPad] * obj->W0_DW_PAD[iPad + 1780];
        memObj2 = obj->W0_DW_PAD[iPad + 3560] * obj->W0_DW_PAD[iPad + 3560];
        memObj1 -= memObj2;
        memObj2 = obj->W0_DW_PAD[iPad] + obj->W0_DW_PAD[iPad + 1780];
        Y0[iImgOut] = memObj1 - obj->P3_FACTOR_RTP * (memObj2 * memObj2);
        iImgOut++;
      }

      colPad = colPadNext;
    }

    rowRangeAdj += 3;
  }
}

/*
 * Arguments    : vision_CornerDetector_1 *obj
 *                const float varargin_1[101376]
 *                float varargout_1[101376]
 * Return Type  : void
 */
static void SystemCore_step(vision_CornerDetector_1 *obj, const float
  varargin_1[101376], float varargout_1[101376])
{
  vision_CornerDetector_1 *b_obj;
  int i;
  static const short iv0[32] = { -1057, -1056, -1055, -702, -349, 3, 355, 706,
    1057, 1056, 1055, 702, 349, -3, -355, -706, -1057, -1056, -1055, -702, -349,
    3, 355, 706, 1057, 1056, 1055, 702, 349, -3, -355, -706 };

  static const signed char iv1[3] = { 8, 4, 2 };

  static const signed char iv2[3] = { 3, 1, 0 };

  double propValue;
  if (obj->isInitialized != 1) {
    b_obj = obj;
    b_obj->isInitialized = 1;

    /* System object Constructor function: vision.private.CornerMetric */
    b_obj->cCornerMetric.S0_isInitialized = 0;
    b_obj->cCornerMetric.P0_THRANGLE_RTP = 7.0F;
    b_obj->cCornerMetric.P1_VALTHR_RTP = 0.01F;
    b_obj->cCornerMetric.P2_DTMIN_RTP = -3.402823466E+38F;
    b_obj->cCornerMetric.P3_DTMAX_RTP = 3.402823466E+38F;
    b_obj->cCornerMetric.P4_DTLOW_RTP = -3.402823466E+38F;
    b_obj->cCornerMetric.P5_DTHIGH_RTP = 3.402823466E+38F;
    for (i = 0; i < 32; i++) {
      b_obj->cCornerMetric.P6_CIRCLE_RTP[i] = iv0[i];
    }

    for (i = 0; i < 3; i++) {
      b_obj->cCornerMetric.P7_STEP_RTP[i] = iv1[i];
    }

    for (i = 0; i < 3; i++) {
      b_obj->cCornerMetric.P8_OFFSET_RTP[i] = iv2[i];
    }

    propValue = b_obj->IntensityThreshold;
    b_obj->cCornerMetric.P1_VALTHR_RTP = (float)propValue;
    b_obj->TunablePropsChanged = false;
  }

  b_obj = obj;
  if (b_obj->TunablePropsChanged) {
    b_obj->TunablePropsChanged = false;
    propValue = b_obj->IntensityThreshold;
    b_obj->cCornerMetric.P1_VALTHR_RTP = (float)propValue;
  }

  CornerDetector_stepImpl(obj, varargin_1, varargout_1);
}

/*
 * Arguments    : vision_CornerDetector_1 *obj
 * Return Type  : vision_CornerDetector_1 *
 */
static vision_CornerDetector_1 *b_CornerDetector_CornerDetector
  (vision_CornerDetector_1 *obj)
{
  vision_CornerDetector_1 *b_obj;
  vision_CornerDetector_1 *c_obj;
  boolean_T flag;
  b_obj = obj;
  b_obj->Sensitivity = 0.04;
  b_obj->IntensityThreshold = 0.1;
  c_obj = b_obj;
  c_obj->isInitialized = 0;
  c_obj = b_obj;
  flag = (c_obj->isInitialized == 1);
  if (flag) {
    c_obj->TunablePropsChanged = true;
  }

  c_obj->CornerThreshold = 2.2204460492503131E-16;
  return b_obj;
}

/*
 * Arguments    : vision_private_CornerMetric_4 *obj
 * Return Type  : void
 */
static void b_Destructor(vision_private_CornerMetric_4 *obj)
{
  /* System object Destructor function: vision.private.CornerMetric */
  if ((obj->S0_isInitialized == 1) && (obj->S0_isInitialized != 2)) {
    obj->S0_isInitialized = 2;
  }
}

/*
 * Arguments    : visioncodegen_MarkerInserter *obj
 *                unsigned char varargin_1[101376]
 *                const unsigned int varargin_2_data[]
 *                const int varargin_2_size[2]
 * Return Type  : void
 */
static void b_Nondirect_stepImpl(visioncodegen_MarkerInserter *obj, unsigned
  char varargin_1[101376], const unsigned int varargin_2_data[], const int
  varargin_2_size[2])
{
  visioncodegen_MarkerInserter *b_obj;
  vision_MarkerInserter_1 *c_obj;
  boolean_T isSizeValid;
  int numShape;
  int size;
  int idxROI;
  int row;
  int col;
  int line[4];
  boolean_T visited1;
  boolean_T visited2;
  boolean_T done;
  int b_line[4];
  int i;
  int in;
  int dr;
  int dc;
  b_obj = obj;
  c_obj = &b_obj->cSFunObject;

  /* System object Outputs function: vision.MarkerInserter */
  isSizeValid = true;
  numShape = 0;
  if (varargin_2_size[1] > 1) {
    numShape = varargin_2_size[0];
  } else {
    if (varargin_2_size[1] == 1) {
      numShape = 1;
      isSizeValid = !((varargin_2_size[0] & 1) != 0);
    }
  }

  /* Copy the image from input to output. */
  if (isSizeValid) {
    /* Update view port. */
    /* Draw all pluses. */
    size = (int)b_obj->cSFunObject.P1_RTP_SIZE;
    for (idxROI = 0; idxROI < numShape; idxROI++) {
      row = (int)varargin_2_data[idxROI + numShape] - 1;
      col = (int)varargin_2_data[idxROI] - 1;
      line[0U] = row;
      line[1U] = col - size;
      line[2U] = row;
      line[3U] = col + size;
      isSizeValid = false;

      /* Find the visible portion of a line. */
      visited1 = false;
      visited2 = false;
      done = false;
      for (i = 0; i < 4; i++) {
        b_line[i] = line[i];
      }

      while (!done) {
        i = 0;
        in = 0;

        /* Determine viewport violations. */
        if (b_line[0U] < 0) {
          i = 4;
        } else {
          if (b_line[0U] > 351) {
            i = 8;
          }
        }

        if (b_line[2U] < 0) {
          in = 4;
        } else {
          if (b_line[2U] > 351) {
            in = 8;
          }
        }

        if (b_line[1U] < 0) {
          i |= 1U;
        } else {
          if (b_line[1U] > 287) {
            i |= 2U;
          }
        }

        if (b_line[3U] < 0) {
          in |= 1U;
        } else {
          if (b_line[3U] > 287) {
            in |= 2U;
          }
        }

        if (!(((unsigned int)i | in) != 0U)) {
          /* Line falls completely within bounds. */
          done = true;
          isSizeValid = true;
        } else if (((unsigned int)i & in) != 0U) {
          /* Line falls completely out of bounds. */
          done = true;
          isSizeValid = false;
        } else if ((unsigned int)i != 0U) {
          /* Clip 1st point; if it's in-bounds, clip 2nd point. */
          if (visited1) {
            b_line[0U] = row;
            b_line[1U] = line[1];
          }

          dr = b_line[2] - b_line[0];
          dc = b_line[3] - b_line[1];
          if ((dr > 1073741824) || (dr < -1073741824) || ((dc > 1073741824) ||
               (dc < -1073741824))) {
            /* Possible Inf or Nan. */
            done = true;
            isSizeValid = false;
            visited1 = true;
          } else if ((i & 4U) != 0U) {
            /* Violated RMin. */
            i = -b_line[0] * dc;
            if ((i > 1073741824) || (i < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isSizeValid = false;
            } else if (((i >= 0) && (dr >= 0)) || ((i < 0) && (dr < 0))) {
              b_line[1U] += (div_s32_floor(i << 1, dr) + 1) >> 1;
            } else {
              b_line[1U] -= (div_s32_floor(-i << 1, dr) + 1) >> 1;
            }

            b_line[0U] = 0;
            visited1 = true;
          } else if ((i & 8U) != 0U) {
            /* Violated RMax. */
            i = (351 - b_line[0]) * dc;
            if ((i > 1073741824) || (i < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isSizeValid = false;
            } else if (((i >= 0) && (dr >= 0)) || ((i < 0) && (dr < 0))) {
              b_line[1U] += (div_s32_floor(i << 1, dr) + 1) >> 1;
            } else {
              b_line[1U] -= (div_s32_floor(-i << 1, dr) + 1) >> 1;
            }

            b_line[0U] = 351;
            visited1 = true;
          } else if ((i & 1U) != 0U) {
            /* Violated CMin. */
            i = -b_line[1] * dr;
            if ((i > 1073741824) || (i < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isSizeValid = false;
            } else if (((i >= 0) && (dc >= 0)) || ((i < 0) && (dc < 0))) {
              b_line[0U] += (div_s32_floor(i << 1, dc) + 1) >> 1;
            } else {
              b_line[0U] -= (div_s32_floor(-i << 1, dc) + 1) >> 1;
            }

            b_line[1U] = 0;
            visited1 = true;
          } else {
            /* Violated CMax. */
            i = (287 - b_line[1]) * dr;
            if ((i > 1073741824) || (i < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isSizeValid = false;
            } else if (((i >= 0) && (dc >= 0)) || ((i < 0) && (dc < 0))) {
              b_line[0U] += (div_s32_floor(i << 1, dc) + 1) >> 1;
            } else {
              b_line[0U] -= (div_s32_floor(-i << 1, dc) + 1) >> 1;
            }

            b_line[1U] = 287;
            visited1 = true;
          }
        } else {
          /* Clip the 2nd point. */
          if (visited2) {
            b_line[2U] = row;
            b_line[3U] = line[3];
          }

          dr = b_line[2] - b_line[0];
          dc = b_line[3] - b_line[1];
          if ((dr > 1073741824) || (dr < -1073741824) || ((dc > 1073741824) ||
               (dc < -1073741824))) {
            /* Possible Inf or Nan. */
            done = true;
            isSizeValid = false;
            visited2 = true;
          } else if ((in & 4U) != 0U) {
            /* Violated RMin. */
            i = -b_line[2] * dc;
            if ((i > 1073741824) || (i < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isSizeValid = false;
            } else if (((i >= 0) && (dr >= 0)) || ((i < 0) && (dr < 0))) {
              b_line[3U] += (div_s32_floor(i << 1, dr) + 1) >> 1;
            } else {
              b_line[3U] -= (div_s32_floor(-i << 1, dr) + 1) >> 1;
            }

            b_line[2U] = 0;
            visited2 = true;
          } else if ((in & 8U) != 0U) {
            /* Violated RMax. */
            i = (351 - b_line[2]) * dc;
            if ((i > 1073741824) || (i < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isSizeValid = false;
            } else if (((i >= 0) && (dr >= 0)) || ((i < 0) && (dr < 0))) {
              b_line[3U] += (div_s32_floor(i << 1, dr) + 1) >> 1;
            } else {
              b_line[3U] -= (div_s32_floor(-i << 1, dr) + 1) >> 1;
            }

            b_line[2U] = 351;
            visited2 = true;
          } else if ((in & 1U) != 0U) {
            /* Violated CMin. */
            i = -b_line[3] * dr;
            if ((i > 1073741824) || (i < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isSizeValid = false;
            } else if (((i >= 0) && (dc >= 0)) || ((i < 0) && (dc < 0))) {
              b_line[2U] += (div_s32_floor(i << 1, dc) + 1) >> 1;
            } else {
              b_line[2U] -= (div_s32_floor(-i << 1, dc) + 1) >> 1;
            }

            b_line[3U] = 0;
            visited2 = true;
          } else {
            /* Violated CMax. */
            i = (287 - b_line[3]) * dr;
            if ((i > 1073741824) || (i < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isSizeValid = false;
            } else if (((i >= 0) && (dc >= 0)) || ((i < 0) && (dc < 0))) {
              b_line[2U] += (div_s32_floor(i << 1, dc) + 1) >> 1;
            } else {
              b_line[2U] -= (div_s32_floor(-i << 1, dc) + 1) >> 1;
            }

            b_line[3U] = 287;
            visited2 = true;
          }
        }
      }

      if (isSizeValid) {
        i = b_line[1] * 352 + b_line[0];
        for (in = b_line[1]; in <= b_line[3U]; in++) {
          varargin_1[i] = c_obj->P0_RTP_FILLCOLOR;
          i += 352;
        }
      }

      line[0U] = row - size;
      line[1U] = col;
      line[2U] = row + size;
      line[3U] = col;
      isSizeValid = false;

      /* Find the visible portion of a line. */
      visited1 = false;
      visited2 = false;
      done = false;
      for (i = 0; i < 4; i++) {
        b_line[i] = line[i];
      }

      while (!done) {
        i = 0;
        in = 0;

        /* Determine viewport violations. */
        if (b_line[0U] < 0) {
          i = 4;
        } else {
          if (b_line[0U] > 351) {
            i = 8;
          }
        }

        if (b_line[2U] < 0) {
          in = 4;
        } else {
          if (b_line[2U] > 351) {
            in = 8;
          }
        }

        if (b_line[1U] < 0) {
          i |= 1U;
        } else {
          if (b_line[1U] > 287) {
            i |= 2U;
          }
        }

        if (b_line[3U] < 0) {
          in |= 1U;
        } else {
          if (b_line[3U] > 287) {
            in |= 2U;
          }
        }

        if (!(((unsigned int)i | in) != 0U)) {
          /* Line falls completely within bounds. */
          done = true;
          isSizeValid = true;
        } else if (((unsigned int)i & in) != 0U) {
          /* Line falls completely out of bounds. */
          done = true;
          isSizeValid = false;
        } else if ((unsigned int)i != 0U) {
          /* Clip 1st point; if it's in-bounds, clip 2nd point. */
          if (visited1) {
            b_line[0U] = line[0];
            b_line[1U] = col;
          }

          dr = b_line[2] - b_line[0];
          dc = b_line[3] - b_line[1];
          if ((dr > 1073741824) || (dr < -1073741824) || ((dc > 1073741824) ||
               (dc < -1073741824))) {
            /* Possible Inf or Nan. */
            done = true;
            isSizeValid = false;
            visited1 = true;
          } else if ((i & 4U) != 0U) {
            /* Violated RMin. */
            i = -b_line[0] * dc;
            if ((i > 1073741824) || (i < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isSizeValid = false;
            } else if (((i >= 0) && (dr >= 0)) || ((i < 0) && (dr < 0))) {
              b_line[1U] += (div_s32_floor(i << 1, dr) + 1) >> 1;
            } else {
              b_line[1U] -= (div_s32_floor(-i << 1, dr) + 1) >> 1;
            }

            b_line[0U] = 0;
            visited1 = true;
          } else if ((i & 8U) != 0U) {
            /* Violated RMax. */
            i = (351 - b_line[0]) * dc;
            if ((i > 1073741824) || (i < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isSizeValid = false;
            } else if (((i >= 0) && (dr >= 0)) || ((i < 0) && (dr < 0))) {
              b_line[1U] += (div_s32_floor(i << 1, dr) + 1) >> 1;
            } else {
              b_line[1U] -= (div_s32_floor(-i << 1, dr) + 1) >> 1;
            }

            b_line[0U] = 351;
            visited1 = true;
          } else if ((i & 1U) != 0U) {
            /* Violated CMin. */
            i = -b_line[1] * dr;
            if ((i > 1073741824) || (i < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isSizeValid = false;
            } else if (((i >= 0) && (dc >= 0)) || ((i < 0) && (dc < 0))) {
              b_line[0U] += (div_s32_floor(i << 1, dc) + 1) >> 1;
            } else {
              b_line[0U] -= (div_s32_floor(-i << 1, dc) + 1) >> 1;
            }

            b_line[1U] = 0;
            visited1 = true;
          } else {
            /* Violated CMax. */
            i = (287 - b_line[1]) * dr;
            if ((i > 1073741824) || (i < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isSizeValid = false;
            } else if (((i >= 0) && (dc >= 0)) || ((i < 0) && (dc < 0))) {
              b_line[0U] += (div_s32_floor(i << 1, dc) + 1) >> 1;
            } else {
              b_line[0U] -= (div_s32_floor(-i << 1, dc) + 1) >> 1;
            }

            b_line[1U] = 287;
            visited1 = true;
          }
        } else {
          /* Clip the 2nd point. */
          if (visited2) {
            b_line[2U] = line[2];
            b_line[3U] = col;
          }

          dr = b_line[2] - b_line[0];
          dc = b_line[3] - b_line[1];
          if ((dr > 1073741824) || (dr < -1073741824) || ((dc > 1073741824) ||
               (dc < -1073741824))) {
            /* Possible Inf or Nan. */
            done = true;
            isSizeValid = false;
            visited2 = true;
          } else if ((in & 4U) != 0U) {
            /* Violated RMin. */
            i = -b_line[2] * dc;
            if ((i > 1073741824) || (i < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isSizeValid = false;
            } else if (((i >= 0) && (dr >= 0)) || ((i < 0) && (dr < 0))) {
              b_line[3U] += (div_s32_floor(i << 1, dr) + 1) >> 1;
            } else {
              b_line[3U] -= (div_s32_floor(-i << 1, dr) + 1) >> 1;
            }

            b_line[2U] = 0;
            visited2 = true;
          } else if ((in & 8U) != 0U) {
            /* Violated RMax. */
            i = (351 - b_line[2]) * dc;
            if ((i > 1073741824) || (i < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isSizeValid = false;
            } else if (((i >= 0) && (dr >= 0)) || ((i < 0) && (dr < 0))) {
              b_line[3U] += (div_s32_floor(i << 1, dr) + 1) >> 1;
            } else {
              b_line[3U] -= (div_s32_floor(-i << 1, dr) + 1) >> 1;
            }

            b_line[2U] = 351;
            visited2 = true;
          } else if ((in & 1U) != 0U) {
            /* Violated CMin. */
            i = -b_line[3] * dr;
            if ((i > 1073741824) || (i < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isSizeValid = false;
            } else if (((i >= 0) && (dc >= 0)) || ((i < 0) && (dc < 0))) {
              b_line[2U] += (div_s32_floor(i << 1, dc) + 1) >> 1;
            } else {
              b_line[2U] -= (div_s32_floor(-i << 1, dc) + 1) >> 1;
            }

            b_line[3U] = 0;
            visited2 = true;
          } else {
            /* Violated CMax. */
            i = (287 - b_line[3]) * dr;
            if ((i > 1073741824) || (i < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isSizeValid = false;
            } else if (((i >= 0) && (dc >= 0)) || ((i < 0) && (dc < 0))) {
              b_line[2U] += (div_s32_floor(i << 1, dc) + 1) >> 1;
            } else {
              b_line[2U] -= (div_s32_floor(-i << 1, dc) + 1) >> 1;
            }

            b_line[3U] = 287;
            visited2 = true;
          }
        }
      }

      if (isSizeValid) {
        i = b_line[1] * 352 + b_line[0];
        for (in = b_line[0]; in <= b_line[2U]; in++) {
          varargin_1[i] = c_obj->P0_RTP_FILLCOLOR;
          i++;
        }
      }
    }
  }
}

/*
 * Arguments    : vision_private_CornerMetric_4 *obj
 *                const float U0[101376]
 *                float Y0[101376]
 * Return Type  : void
 */
static void b_Outputs(vision_private_CornerMetric_4 *obj, const float U0[101376],
                      float Y0[101376])
{
  int i;
  int j;
  int iImgOut;
  int colPad;
  int rowRangeAdj;
  int iRange;
  int col;
  int colPadNext;
  int iPad;
  int row;
  float memObj2;
  float memObj1;
  int iPadDst;
  int iFltr;

  /* System object Outputs function: vision.private.CornerMetric */
  for (i = 0; i < 3; i++) {
    obj->W3_DW_ROWPADIDX[i] = 1;
  }

  for (j = 0; j < 350; j++) {
    obj->W3_DW_ROWPADIDX[i] = j + 1;
    i++;
  }

  for (j = 0; j < 3; j++) {
    obj->W3_DW_ROWPADIDX[i] = 350;
    i++;
  }

  for (i = 0; i < 3; i++) {
    obj->W2_DW_COLPADIDX[i] = 1;
  }

  for (j = 0; j < 286; j++) {
    obj->W2_DW_COLPADIDX[i] = j + 1;
    i++;
  }

  for (j = 0; j < 3; j++) {
    obj->W2_DW_COLPADIDX[i] = 286;
    i++;
  }

  iImgOut = 0;
  colPad = 0;
  rowRangeAdj = 2;
  for (iRange = 0; iRange < 4; iRange += 2) {
    for (col = obj->P1_COLRANGE_RTP[iRange]; col < obj->P1_COLRANGE_RTP[iRange +
         1]; col++) {
      colPadNext = obj->W1_DW_NEXTPADIDX[colPad];
      iPad = colPad * 356;
      i = obj->W2_DW_COLPADIDX[col] * 352 - 1;
      for (row = 0; row < 356; row++) {
        j = i + obj->W3_DW_ROWPADIDX[row];
        memObj2 = U0[j - 351] - U0[j + 353];
        memObj1 = U0[j] - U0[j + 2];
        obj->W0_DW_PAD[iPad] = memObj2 * memObj2;
        obj->W0_DW_PAD[(unsigned int)(iPad + 1780)] = memObj1 * memObj1;
        obj->W0_DW_PAD[(unsigned int)(iPad + 3560)] = memObj2 * memObj1;
        iPad++;
      }

      i = colPadNext * 356;
      for (j = 0; j <= 3560; j += 1780) {
        iPadDst = i + j;
        for (row = obj->P2_ROWRANGE_RTP[rowRangeAdj - 2]; row <
             obj->P2_ROWRANGE_RTP[rowRangeAdj]; row++) {
          memObj2 = 0.0F;
          iPad = row + j;
          for (iFltr = 4 - colPad; iFltr < 9 - colPad; iFltr++) {
            memObj2 += obj->W0_DW_PAD[iPad] * obj->P0_FILTER_RTP[iFltr];
            iPad += 356;
          }

          obj->W0_DW_PAD[iPadDst] = memObj2;
          iPadDst++;
        }

        iPadDst = i + j;
        for (row = obj->P2_ROWRANGE_RTP[rowRangeAdj - 1]; row <
             obj->P2_ROWRANGE_RTP[rowRangeAdj]; row++) {
          iPad = iPadDst;
          memObj2 = 0.0F;
          for (iFltr = 0; iFltr < 5; iFltr++) {
            memObj2 += obj->W0_DW_PAD[iPad] * obj->P0_FILTER_RTP[iFltr];
            iPad++;
          }

          obj->W0_DW_PAD[iPadDst] = memObj2;
          iPadDst++;
        }
      }

      for (iPad = i; iPad < (i + obj->P2_ROWRANGE_RTP[rowRangeAdj]) -
           obj->P2_ROWRANGE_RTP[rowRangeAdj - 1]; iPad++) {
        memObj1 = obj->W0_DW_PAD[iPad] - obj->W0_DW_PAD[iPad + 1780];
        memObj2 = memObj1 * memObj1;
        memObj1 = obj->W0_DW_PAD[iPad + 3560];
        memObj1 *= obj->W0_DW_PAD[iPad + 3560];
        memObj1 *= 4.0F;
        memObj1 += memObj2;
        memObj2 = (float)sqrt(memObj1);
        memObj1 = obj->W0_DW_PAD[iPad];
        memObj1 += obj->W0_DW_PAD[iPad + 1780];
        Y0[iImgOut] = memObj1 - memObj2;
        iImgOut++;
      }

      colPad = colPadNext;
    }

    rowRangeAdj += 3;
  }
}

/*
 * Arguments    : visioncodegen_LocalMaximaFinder *obj
 *                const float varargin_1[101376]
 *                float varargin_2
 *                unsigned int varargout_1_data[]
 *                int varargout_1_size[2]
 * Return Type  : void
 */
static void b_SystemCore_step(visioncodegen_LocalMaximaFinder *obj, const float
  varargin_1[101376], float varargin_2, unsigned int varargout_1_data[], int
  varargout_1_size[2])
{
  visioncodegen_LocalMaximaFinder *b_obj;
  vision_LocalMaximaFinder_0 *c_obj;
  int countPeak;
  boolean_T done;
  int nhood_center_idx_0;
  int nhood_center_idx_1;
  int i;
  int max_idx;
  float maxValue;
  int p;
  int p1;
  int p2;
  int q2;
  unsigned int fromIdx;
  unsigned int toIdx;
  if (obj->isInitialized != 1) {
    b_obj = obj;
    b_obj->isInitialized = 1;
  }

  b_obj = obj;
  c_obj = &b_obj->cSFunObject;

  /* System object Outputs function: vision.LocalMaximaFinder */
  countPeak = 0;
  done = false;
  nhood_center_idx_0 = (int)((b_obj->cSFunObject.P0_NHOODSIZE_RTP[0] - 1U) >> 1);
  nhood_center_idx_1 = (int)((b_obj->cSFunObject.P0_NHOODSIZE_RTP[1] - 1U) >> 1);
  for (i = 0; i < 101376; i++) {
    c_obj->W0_TEMP_IN_DWORKS[i] = varargin_1[i];
  }

  memset(&varargout_1_data[0], 0, 2000U * sizeof(unsigned int));
  while (!done) {
    max_idx = 0;
    maxValue = c_obj->W0_TEMP_IN_DWORKS[0];
    for (i = 0; i < 101376; i++) {
      if (c_obj->W0_TEMP_IN_DWORKS[i] > maxValue) {
        max_idx = i;
        maxValue = c_obj->W0_TEMP_IN_DWORKS[i];
      }
    }

    p = max_idx % 352;
    i = max_idx / 352;
    if (c_obj->W0_TEMP_IN_DWORKS[max_idx] >= varargin_2) {
      varargout_1_data[countPeak] = (unsigned int)(1 + i);
      varargout_1_data[1000U + countPeak] = (unsigned int)(1 + p);
      countPeak++;
      if (countPeak == 1000) {
        done = true;
      }

      max_idx = p - nhood_center_idx_0;
      if (max_idx >= 0) {
        p1 = max_idx;
      } else {
        p1 = 0;
      }

      max_idx = p + nhood_center_idx_0;
      if (max_idx <= 351) {
        p2 = max_idx;
      } else {
        p2 = 351;
      }

      max_idx = i + nhood_center_idx_1;
      if (max_idx <= 287) {
        q2 = max_idx;
      } else {
        q2 = 287;
      }

      max_idx = i - nhood_center_idx_1;
      if (max_idx >= 0) {
      } else {
        max_idx = 0;
      }

      while (max_idx <= q2) {
        p = max_idx * 352;
        for (i = p1; i <= p2; i++) {
          c_obj->W0_TEMP_IN_DWORKS[i + p] = 0.0F;
        }

        max_idx++;
      }
    } else {
      done = true;
    }
  }

  b_obj->cSFunObject.W1_NUMPEAKS_DWORK = (unsigned int)countPeak;
  fromIdx = 1000U;
  toIdx = (unsigned int)countPeak;
  for (i = 0; i < countPeak; i++) {
    varargout_1_data[toIdx] = varargout_1_data[fromIdx];
    fromIdx++;
    toIdx++;
  }

  varargout_1_size[0] = (int)b_obj->cSFunObject.W1_NUMPEAKS_DWORK;
  varargout_1_size[1] = 2;
}

/*
 * Arguments    : vision_CornerDetector *obj
 * Return Type  : vision_CornerDetector *
 */
static vision_CornerDetector *c_CornerDetector_CornerDetector
  (vision_CornerDetector *obj)
{
  vision_CornerDetector *b_obj;
  vision_CornerDetector *c_obj;
  boolean_T flag;
  b_obj = obj;
  b_obj->Sensitivity = 0.04;
  b_obj->IntensityThreshold = 0.1;
  c_obj = b_obj;
  c_obj->isInitialized = 0;
  c_obj = b_obj;
  flag = (c_obj->isInitialized == 1);
  if (flag) {
    c_obj->TunablePropsChanged = true;
  }

  c_obj->CornerThreshold = 2.2204460492503131E-16;
  return b_obj;
}

/*
 * Arguments    : visioncodegen_MarkerInserter *obj
 *                unsigned char varargin_1[101376]
 *                const unsigned int varargin_2_data[]
 *                const int varargin_2_size[2]
 * Return Type  : void
 */
static void c_Nondirect_stepImpl(visioncodegen_MarkerInserter *obj, unsigned
  char varargin_1[101376], const unsigned int varargin_2_data[], const int
  varargin_2_size[2])
{
  visioncodegen_MarkerInserter *b_obj;
  vision_MarkerInserter_1 *c_obj;
  boolean_T isSizeValid;
  int numShape;
  int size;
  int idxROI;
  int row;
  int col;
  int line[4];
  boolean_T visited1;
  boolean_T visited2;
  boolean_T done;
  int b_line[4];
  int i;
  int in;
  int dr;
  int dc;
  b_obj = obj;
  c_obj = &b_obj->cSFunObject;

  /* System object Outputs function: vision.MarkerInserter */
  isSizeValid = true;
  numShape = 0;
  if (varargin_2_size[1] > 1) {
    numShape = varargin_2_size[0];
  } else {
    if (varargin_2_size[1] == 1) {
      numShape = 1;
      isSizeValid = !((varargin_2_size[0] & 1) != 0);
    }
  }

  /* Copy the image from input to output. */
  if (isSizeValid) {
    /* Update view port. */
    /* Draw all pluses. */
    size = (int)b_obj->cSFunObject.P1_RTP_SIZE;
    for (idxROI = 0; idxROI < numShape; idxROI++) {
      row = (int)varargin_2_data[idxROI + numShape] - 1;
      col = (int)varargin_2_data[idxROI] - 1;
      line[0U] = row;
      line[1U] = col - size;
      line[2U] = row;
      line[3U] = col + size;
      isSizeValid = false;

      /* Find the visible portion of a line. */
      visited1 = false;
      visited2 = false;
      done = false;
      for (i = 0; i < 4; i++) {
        b_line[i] = line[i];
      }

      while (!done) {
        i = 0;
        in = 0;

        /* Determine viewport violations. */
        if (b_line[0U] < 0) {
          i = 4;
        } else {
          if (b_line[0U] > 351) {
            i = 8;
          }
        }

        if (b_line[2U] < 0) {
          in = 4;
        } else {
          if (b_line[2U] > 351) {
            in = 8;
          }
        }

        if (b_line[1U] < 0) {
          i |= 1U;
        } else {
          if (b_line[1U] > 287) {
            i |= 2U;
          }
        }

        if (b_line[3U] < 0) {
          in |= 1U;
        } else {
          if (b_line[3U] > 287) {
            in |= 2U;
          }
        }

        if (!(((unsigned int)i | in) != 0U)) {
          /* Line falls completely within bounds. */
          done = true;
          isSizeValid = true;
        } else if (((unsigned int)i & in) != 0U) {
          /* Line falls completely out of bounds. */
          done = true;
          isSizeValid = false;
        } else if ((unsigned int)i != 0U) {
          /* Clip 1st point; if it's in-bounds, clip 2nd point. */
          if (visited1) {
            b_line[0U] = row;
            b_line[1U] = line[1];
          }

          dr = b_line[2] - b_line[0];
          dc = b_line[3] - b_line[1];
          if ((dr > 1073741824) || (dr < -1073741824) || ((dc > 1073741824) ||
               (dc < -1073741824))) {
            /* Possible Inf or Nan. */
            done = true;
            isSizeValid = false;
            visited1 = true;
          } else if ((i & 4U) != 0U) {
            /* Violated RMin. */
            i = -b_line[0] * dc;
            if ((i > 1073741824) || (i < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isSizeValid = false;
            } else if (((i >= 0) && (dr >= 0)) || ((i < 0) && (dr < 0))) {
              b_line[1U] += (div_s32_floor(i << 1, dr) + 1) >> 1;
            } else {
              b_line[1U] -= (div_s32_floor(-i << 1, dr) + 1) >> 1;
            }

            b_line[0U] = 0;
            visited1 = true;
          } else if ((i & 8U) != 0U) {
            /* Violated RMax. */
            i = (351 - b_line[0]) * dc;
            if ((i > 1073741824) || (i < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isSizeValid = false;
            } else if (((i >= 0) && (dr >= 0)) || ((i < 0) && (dr < 0))) {
              b_line[1U] += (div_s32_floor(i << 1, dr) + 1) >> 1;
            } else {
              b_line[1U] -= (div_s32_floor(-i << 1, dr) + 1) >> 1;
            }

            b_line[0U] = 351;
            visited1 = true;
          } else if ((i & 1U) != 0U) {
            /* Violated CMin. */
            i = -b_line[1] * dr;
            if ((i > 1073741824) || (i < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isSizeValid = false;
            } else if (((i >= 0) && (dc >= 0)) || ((i < 0) && (dc < 0))) {
              b_line[0U] += (div_s32_floor(i << 1, dc) + 1) >> 1;
            } else {
              b_line[0U] -= (div_s32_floor(-i << 1, dc) + 1) >> 1;
            }

            b_line[1U] = 0;
            visited1 = true;
          } else {
            /* Violated CMax. */
            i = (287 - b_line[1]) * dr;
            if ((i > 1073741824) || (i < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isSizeValid = false;
            } else if (((i >= 0) && (dc >= 0)) || ((i < 0) && (dc < 0))) {
              b_line[0U] += (div_s32_floor(i << 1, dc) + 1) >> 1;
            } else {
              b_line[0U] -= (div_s32_floor(-i << 1, dc) + 1) >> 1;
            }

            b_line[1U] = 287;
            visited1 = true;
          }
        } else {
          /* Clip the 2nd point. */
          if (visited2) {
            b_line[2U] = row;
            b_line[3U] = line[3];
          }

          dr = b_line[2] - b_line[0];
          dc = b_line[3] - b_line[1];
          if ((dr > 1073741824) || (dr < -1073741824) || ((dc > 1073741824) ||
               (dc < -1073741824))) {
            /* Possible Inf or Nan. */
            done = true;
            isSizeValid = false;
            visited2 = true;
          } else if ((in & 4U) != 0U) {
            /* Violated RMin. */
            i = -b_line[2] * dc;
            if ((i > 1073741824) || (i < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isSizeValid = false;
            } else if (((i >= 0) && (dr >= 0)) || ((i < 0) && (dr < 0))) {
              b_line[3U] += (div_s32_floor(i << 1, dr) + 1) >> 1;
            } else {
              b_line[3U] -= (div_s32_floor(-i << 1, dr) + 1) >> 1;
            }

            b_line[2U] = 0;
            visited2 = true;
          } else if ((in & 8U) != 0U) {
            /* Violated RMax. */
            i = (351 - b_line[2]) * dc;
            if ((i > 1073741824) || (i < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isSizeValid = false;
            } else if (((i >= 0) && (dr >= 0)) || ((i < 0) && (dr < 0))) {
              b_line[3U] += (div_s32_floor(i << 1, dr) + 1) >> 1;
            } else {
              b_line[3U] -= (div_s32_floor(-i << 1, dr) + 1) >> 1;
            }

            b_line[2U] = 351;
            visited2 = true;
          } else if ((in & 1U) != 0U) {
            /* Violated CMin. */
            i = -b_line[3] * dr;
            if ((i > 1073741824) || (i < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isSizeValid = false;
            } else if (((i >= 0) && (dc >= 0)) || ((i < 0) && (dc < 0))) {
              b_line[2U] += (div_s32_floor(i << 1, dc) + 1) >> 1;
            } else {
              b_line[2U] -= (div_s32_floor(-i << 1, dc) + 1) >> 1;
            }

            b_line[3U] = 0;
            visited2 = true;
          } else {
            /* Violated CMax. */
            i = (287 - b_line[3]) * dr;
            if ((i > 1073741824) || (i < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isSizeValid = false;
            } else if (((i >= 0) && (dc >= 0)) || ((i < 0) && (dc < 0))) {
              b_line[2U] += (div_s32_floor(i << 1, dc) + 1) >> 1;
            } else {
              b_line[2U] -= (div_s32_floor(-i << 1, dc) + 1) >> 1;
            }

            b_line[3U] = 287;
            visited2 = true;
          }
        }
      }

      if (isSizeValid) {
        i = b_line[1] * 352 + b_line[0];
        for (in = b_line[1]; in <= b_line[3U]; in++) {
          varargin_1[i] = c_obj->P0_RTP_FILLCOLOR;
          i += 352;
        }
      }

      line[0U] = row - size;
      line[1U] = col;
      line[2U] = row + size;
      line[3U] = col;
      isSizeValid = false;

      /* Find the visible portion of a line. */
      visited1 = false;
      visited2 = false;
      done = false;
      for (i = 0; i < 4; i++) {
        b_line[i] = line[i];
      }

      while (!done) {
        i = 0;
        in = 0;

        /* Determine viewport violations. */
        if (b_line[0U] < 0) {
          i = 4;
        } else {
          if (b_line[0U] > 351) {
            i = 8;
          }
        }

        if (b_line[2U] < 0) {
          in = 4;
        } else {
          if (b_line[2U] > 351) {
            in = 8;
          }
        }

        if (b_line[1U] < 0) {
          i |= 1U;
        } else {
          if (b_line[1U] > 287) {
            i |= 2U;
          }
        }

        if (b_line[3U] < 0) {
          in |= 1U;
        } else {
          if (b_line[3U] > 287) {
            in |= 2U;
          }
        }

        if (!(((unsigned int)i | in) != 0U)) {
          /* Line falls completely within bounds. */
          done = true;
          isSizeValid = true;
        } else if (((unsigned int)i & in) != 0U) {
          /* Line falls completely out of bounds. */
          done = true;
          isSizeValid = false;
        } else if ((unsigned int)i != 0U) {
          /* Clip 1st point; if it's in-bounds, clip 2nd point. */
          if (visited1) {
            b_line[0U] = line[0];
            b_line[1U] = col;
          }

          dr = b_line[2] - b_line[0];
          dc = b_line[3] - b_line[1];
          if ((dr > 1073741824) || (dr < -1073741824) || ((dc > 1073741824) ||
               (dc < -1073741824))) {
            /* Possible Inf or Nan. */
            done = true;
            isSizeValid = false;
            visited1 = true;
          } else if ((i & 4U) != 0U) {
            /* Violated RMin. */
            i = -b_line[0] * dc;
            if ((i > 1073741824) || (i < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isSizeValid = false;
            } else if (((i >= 0) && (dr >= 0)) || ((i < 0) && (dr < 0))) {
              b_line[1U] += (div_s32_floor(i << 1, dr) + 1) >> 1;
            } else {
              b_line[1U] -= (div_s32_floor(-i << 1, dr) + 1) >> 1;
            }

            b_line[0U] = 0;
            visited1 = true;
          } else if ((i & 8U) != 0U) {
            /* Violated RMax. */
            i = (351 - b_line[0]) * dc;
            if ((i > 1073741824) || (i < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isSizeValid = false;
            } else if (((i >= 0) && (dr >= 0)) || ((i < 0) && (dr < 0))) {
              b_line[1U] += (div_s32_floor(i << 1, dr) + 1) >> 1;
            } else {
              b_line[1U] -= (div_s32_floor(-i << 1, dr) + 1) >> 1;
            }

            b_line[0U] = 351;
            visited1 = true;
          } else if ((i & 1U) != 0U) {
            /* Violated CMin. */
            i = -b_line[1] * dr;
            if ((i > 1073741824) || (i < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isSizeValid = false;
            } else if (((i >= 0) && (dc >= 0)) || ((i < 0) && (dc < 0))) {
              b_line[0U] += (div_s32_floor(i << 1, dc) + 1) >> 1;
            } else {
              b_line[0U] -= (div_s32_floor(-i << 1, dc) + 1) >> 1;
            }

            b_line[1U] = 0;
            visited1 = true;
          } else {
            /* Violated CMax. */
            i = (287 - b_line[1]) * dr;
            if ((i > 1073741824) || (i < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isSizeValid = false;
            } else if (((i >= 0) && (dc >= 0)) || ((i < 0) && (dc < 0))) {
              b_line[0U] += (div_s32_floor(i << 1, dc) + 1) >> 1;
            } else {
              b_line[0U] -= (div_s32_floor(-i << 1, dc) + 1) >> 1;
            }

            b_line[1U] = 287;
            visited1 = true;
          }
        } else {
          /* Clip the 2nd point. */
          if (visited2) {
            b_line[2U] = line[2];
            b_line[3U] = col;
          }

          dr = b_line[2] - b_line[0];
          dc = b_line[3] - b_line[1];
          if ((dr > 1073741824) || (dr < -1073741824) || ((dc > 1073741824) ||
               (dc < -1073741824))) {
            /* Possible Inf or Nan. */
            done = true;
            isSizeValid = false;
            visited2 = true;
          } else if ((in & 4U) != 0U) {
            /* Violated RMin. */
            i = -b_line[2] * dc;
            if ((i > 1073741824) || (i < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isSizeValid = false;
            } else if (((i >= 0) && (dr >= 0)) || ((i < 0) && (dr < 0))) {
              b_line[3U] += (div_s32_floor(i << 1, dr) + 1) >> 1;
            } else {
              b_line[3U] -= (div_s32_floor(-i << 1, dr) + 1) >> 1;
            }

            b_line[2U] = 0;
            visited2 = true;
          } else if ((in & 8U) != 0U) {
            /* Violated RMax. */
            i = (351 - b_line[2]) * dc;
            if ((i > 1073741824) || (i < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isSizeValid = false;
            } else if (((i >= 0) && (dr >= 0)) || ((i < 0) && (dr < 0))) {
              b_line[3U] += (div_s32_floor(i << 1, dr) + 1) >> 1;
            } else {
              b_line[3U] -= (div_s32_floor(-i << 1, dr) + 1) >> 1;
            }

            b_line[2U] = 351;
            visited2 = true;
          } else if ((in & 1U) != 0U) {
            /* Violated CMin. */
            i = -b_line[3] * dr;
            if ((i > 1073741824) || (i < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isSizeValid = false;
            } else if (((i >= 0) && (dc >= 0)) || ((i < 0) && (dc < 0))) {
              b_line[2U] += (div_s32_floor(i << 1, dc) + 1) >> 1;
            } else {
              b_line[2U] -= (div_s32_floor(-i << 1, dc) + 1) >> 1;
            }

            b_line[3U] = 0;
            visited2 = true;
          } else {
            /* Violated CMax. */
            i = (287 - b_line[3]) * dr;
            if ((i > 1073741824) || (i < -1073741824)) {
              /* Check for Inf or Nan. */
              done = true;
              isSizeValid = false;
            } else if (((i >= 0) && (dc >= 0)) || ((i < 0) && (dc < 0))) {
              b_line[2U] += (div_s32_floor(i << 1, dc) + 1) >> 1;
            } else {
              b_line[2U] -= (div_s32_floor(-i << 1, dc) + 1) >> 1;
            }

            b_line[3U] = 287;
            visited2 = true;
          }
        }
      }

      if (isSizeValid) {
        i = b_line[1] * 352 + b_line[0];
        for (in = b_line[0]; in <= b_line[2U]; in++) {
          varargin_1[i] = c_obj->P0_RTP_FILLCOLOR;
          i++;
        }
      }
    }
  }
}

/*
 * Arguments    : vision_CornerDetector_2 *obj
 *                const float varargin_1[101376]
 *                float varargout_1[101376]
 * Return Type  : void
 */
static void c_SystemCore_step(vision_CornerDetector_2 *obj, const float
  varargin_1[101376], float varargout_1[101376])
{
  vision_CornerDetector_2 *b_obj;
  int i;
  static const float fv0[10] = { 0.120078385F, 0.233880758F, 0.292081714F,
    0.233880758F, 0.120078385F, 0.120078385F, 0.233880758F, 0.292081714F,
    0.233880758F, 0.120078385F };

  static const short iv3[4] = { 0, 4, 4, 292 };

  static const short iv4[6] = { 2, 1, 0, 0, 4, 356 };

  double propValue;
  vision_private_CornerMetric_3 *c_obj;
  int j;
  if (obj->isInitialized != 1) {
    b_obj = obj;
    b_obj->isInitialized = 1;

    /* System object Constructor function: vision.private.CornerMetric */
    b_obj->cCornerMetric.S0_isInitialized = 0;
    for (i = 0; i < 10; i++) {
      b_obj->cCornerMetric.P0_FILTER_RTP[i] = fv0[i];
    }

    for (i = 0; i < 4; i++) {
      b_obj->cCornerMetric.P1_COLRANGE_RTP[i] = iv3[i];
    }

    for (i = 0; i < 6; i++) {
      b_obj->cCornerMetric.P2_ROWRANGE_RTP[i] = iv4[i];
    }

    b_obj->cCornerMetric.P3_FACTOR_RTP = 0.04F;
    propValue = b_obj->Sensitivity;
    b_obj->cCornerMetric.P3_FACTOR_RTP = (float)propValue;
    b_obj->TunablePropsChanged = false;
  }

  b_obj = obj;
  if (b_obj->TunablePropsChanged) {
    b_obj->TunablePropsChanged = false;
    propValue = b_obj->Sensitivity;
    b_obj->cCornerMetric.P3_FACTOR_RTP = (float)propValue;
  }

  b_obj = obj;
  c_obj = &b_obj->cCornerMetric;
  if (b_obj->cCornerMetric.S0_isInitialized != 1) {
    b_obj->cCornerMetric.S0_isInitialized = 1;

    /* System object Start function: vision.private.CornerMetric */
    for (i = 0; i < 4; i++) {
      c_obj->W1_DW_NEXTPADIDX[i] = i + 1;
    }

    b_obj->cCornerMetric.W1_DW_NEXTPADIDX[i] = 0;
    for (i = 0; i < 3; i++) {
      c_obj->W3_DW_ROWPADIDX[i] = 1;
    }

    for (j = 0; j < 350; j++) {
      c_obj->W3_DW_ROWPADIDX[i] = j + 1;
      i++;
    }

    for (j = 0; j < 3; j++) {
      c_obj->W3_DW_ROWPADIDX[i] = 350;
      i++;
    }

    for (i = 0; i < 3; i++) {
      c_obj->W2_DW_COLPADIDX[i] = 1;
    }

    for (j = 0; j < 286; j++) {
      c_obj->W2_DW_COLPADIDX[i] = j + 1;
      i++;
    }

    for (j = 0; j < 3; j++) {
      c_obj->W2_DW_COLPADIDX[i] = 286;
      i++;
    }
  }

  Outputs(&b_obj->cCornerMetric, varargin_1, varargout_1);
}

/*
 * Arguments    : visioncodegen_LocalMaximaFinder *obj
 *                const float varargin_1[101376]
 *                float varargin_2
 *                unsigned int varargout_1_data[]
 *                int varargout_1_size[2]
 * Return Type  : void
 */
static void d_SystemCore_step(visioncodegen_LocalMaximaFinder *obj, const float
  varargin_1[101376], float varargin_2, unsigned int varargout_1_data[], int
  varargout_1_size[2])
{
  visioncodegen_LocalMaximaFinder *b_obj;
  vision_LocalMaximaFinder_0 *c_obj;
  int countPeak;
  boolean_T done;
  int nhood_center_idx_0;
  int nhood_center_idx_1;
  int i;
  int max_idx;
  float maxValue;
  int p;
  int p1;
  int p2;
  int q2;
  unsigned int fromIdx;
  unsigned int toIdx;
  if (obj->isInitialized != 1) {
    b_obj = obj;
    b_obj->isInitialized = 1;
  }

  b_obj = obj;
  c_obj = &b_obj->cSFunObject;

  /* System object Outputs function: vision.LocalMaximaFinder */
  countPeak = 0;
  done = false;
  nhood_center_idx_0 = (int)((b_obj->cSFunObject.P0_NHOODSIZE_RTP[0] - 1U) >> 1);
  nhood_center_idx_1 = (int)((b_obj->cSFunObject.P0_NHOODSIZE_RTP[1] - 1U) >> 1);
  for (i = 0; i < 101376; i++) {
    c_obj->W0_TEMP_IN_DWORKS[i] = varargin_1[i];
  }

  memset(&varargout_1_data[0], 0, 2000U * sizeof(unsigned int));
  while (!done) {
    max_idx = 0;
    maxValue = c_obj->W0_TEMP_IN_DWORKS[0];
    for (i = 0; i < 101376; i++) {
      if (c_obj->W0_TEMP_IN_DWORKS[i] > maxValue) {
        max_idx = i;
        maxValue = c_obj->W0_TEMP_IN_DWORKS[i];
      }
    }

    p = max_idx % 352;
    i = max_idx / 352;
    if (c_obj->W0_TEMP_IN_DWORKS[max_idx] >= varargin_2) {
      varargout_1_data[countPeak] = (unsigned int)(1 + i);
      varargout_1_data[1000U + countPeak] = (unsigned int)(1 + p);
      countPeak++;
      if (countPeak == 1000) {
        done = true;
      }

      max_idx = p - nhood_center_idx_0;
      if (max_idx >= 0) {
        p1 = max_idx;
      } else {
        p1 = 0;
      }

      max_idx = p + nhood_center_idx_0;
      if (max_idx <= 351) {
        p2 = max_idx;
      } else {
        p2 = 351;
      }

      max_idx = i + nhood_center_idx_1;
      if (max_idx <= 287) {
        q2 = max_idx;
      } else {
        q2 = 287;
      }

      max_idx = i - nhood_center_idx_1;
      if (max_idx >= 0) {
      } else {
        max_idx = 0;
      }

      while (max_idx <= q2) {
        p = max_idx * 352;
        for (i = p1; i <= p2; i++) {
          c_obj->W0_TEMP_IN_DWORKS[i + p] = 0.0F;
        }

        max_idx++;
      }
    } else {
      done = true;
    }
  }

  b_obj->cSFunObject.W1_NUMPEAKS_DWORK = (unsigned int)countPeak;
  fromIdx = 1000U;
  toIdx = (unsigned int)countPeak;
  for (i = 0; i < countPeak; i++) {
    varargout_1_data[toIdx] = varargout_1_data[fromIdx];
    fromIdx++;
    toIdx++;
  }

  varargout_1_size[0] = (int)b_obj->cSFunObject.W1_NUMPEAKS_DWORK;
  varargout_1_size[1] = 2;
}

/*
 * Arguments    : int numerator
 *                int denominator
 * Return Type  : int
 */
static int div_s32_floor(int numerator, int denominator)
{
  int quotient;
  unsigned int absNumerator;
  unsigned int absDenominator;
  boolean_T quotientNeedsNegation;
  unsigned int tempAbsQuotient;
  if (denominator == 0) {
    if (numerator >= 0) {
      quotient = MAX_int32_T;
    } else {
      quotient = MIN_int32_T;
    }
  } else {
    if (numerator >= 0) {
      absNumerator = (unsigned int)numerator;
    } else {
      absNumerator = (unsigned int)-numerator;
    }

    if (denominator >= 0) {
      absDenominator = (unsigned int)denominator;
    } else {
      absDenominator = (unsigned int)-denominator;
    }

    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    tempAbsQuotient = absNumerator / absDenominator;
    if (quotientNeedsNegation) {
      absNumerator %= absDenominator;
      if (absNumerator > 0U) {
        tempAbsQuotient++;
      }
    }

    if (quotientNeedsNegation) {
      quotient = -(int)tempAbsQuotient;
    } else {
      quotient = (int)tempAbsQuotient;
    }
  }

  return quotient;
}

/*
 * Arguments    : vision_CornerDetector *obj
 *                const float varargin_1[101376]
 *                float varargout_1[101376]
 * Return Type  : void
 */
static void e_SystemCore_step(vision_CornerDetector *obj, const float
  varargin_1[101376], float varargout_1[101376])
{
  vision_CornerDetector *b_obj;
  int i;
  static const float fv1[10] = { 0.120078385F, 0.233880758F, 0.292081714F,
    0.233880758F, 0.120078385F, 0.120078385F, 0.233880758F, 0.292081714F,
    0.233880758F, 0.120078385F };

  static const short iv5[4] = { 0, 4, 4, 292 };

  static const short iv6[6] = { 2, 1, 0, 0, 4, 356 };

  vision_private_CornerMetric_4 *c_obj;
  int j;
  if (obj->isInitialized != 1) {
    b_obj = obj;
    b_obj->isInitialized = 1;

    /* System object Constructor function: vision.private.CornerMetric */
    b_obj->cCornerMetric.S0_isInitialized = 0;
    for (i = 0; i < 10; i++) {
      b_obj->cCornerMetric.P0_FILTER_RTP[i] = fv1[i];
    }

    for (i = 0; i < 4; i++) {
      b_obj->cCornerMetric.P1_COLRANGE_RTP[i] = iv5[i];
    }

    for (i = 0; i < 6; i++) {
      b_obj->cCornerMetric.P2_ROWRANGE_RTP[i] = iv6[i];
    }

    b_obj->TunablePropsChanged = false;
  }

  b_obj = obj;
  if (b_obj->TunablePropsChanged) {
    b_obj->TunablePropsChanged = false;
  }

  b_obj = obj;
  c_obj = &b_obj->cCornerMetric;
  if (b_obj->cCornerMetric.S0_isInitialized != 1) {
    b_obj->cCornerMetric.S0_isInitialized = 1;

    /* System object Start function: vision.private.CornerMetric */
    for (i = 0; i < 4; i++) {
      c_obj->W1_DW_NEXTPADIDX[i] = i + 1;
    }

    b_obj->cCornerMetric.W1_DW_NEXTPADIDX[i] = 0;
    for (i = 0; i < 3; i++) {
      c_obj->W3_DW_ROWPADIDX[i] = 1;
    }

    for (j = 0; j < 350; j++) {
      c_obj->W3_DW_ROWPADIDX[i] = j + 1;
      i++;
    }

    for (j = 0; j < 3; j++) {
      c_obj->W3_DW_ROWPADIDX[i] = 350;
      i++;
    }

    for (i = 0; i < 3; i++) {
      c_obj->W2_DW_COLPADIDX[i] = 1;
    }

    for (j = 0; j < 286; j++) {
      c_obj->W2_DW_COLPADIDX[i] = j + 1;
      i++;
    }

    for (j = 0; j < 3; j++) {
      c_obj->W2_DW_COLPADIDX[i] = 286;
      i++;
    }
  }

  b_Outputs(&b_obj->cCornerMetric, varargin_1, varargout_1);
}

/*
 * Arguments    : visioncodegen_LocalMaximaFinder *obj
 *                const float varargin_1[101376]
 *                float varargin_2
 *                unsigned int varargout_1_data[]
 *                int varargout_1_size[2]
 * Return Type  : void
 */
static void f_SystemCore_step(visioncodegen_LocalMaximaFinder *obj, const float
  varargin_1[101376], float varargin_2, unsigned int varargout_1_data[], int
  varargout_1_size[2])
{
  visioncodegen_LocalMaximaFinder *b_obj;
  vision_LocalMaximaFinder_0 *c_obj;
  int countPeak;
  boolean_T done;
  int nhood_center_idx_0;
  int nhood_center_idx_1;
  int i;
  int max_idx;
  float maxValue;
  int p;
  int p1;
  int p2;
  int q2;
  unsigned int fromIdx;
  unsigned int toIdx;
  if (obj->isInitialized != 1) {
    b_obj = obj;
    b_obj->isInitialized = 1;
  }

  b_obj = obj;
  c_obj = &b_obj->cSFunObject;

  /* System object Outputs function: vision.LocalMaximaFinder */
  countPeak = 0;
  done = false;
  nhood_center_idx_0 = (int)((b_obj->cSFunObject.P0_NHOODSIZE_RTP[0] - 1U) >> 1);
  nhood_center_idx_1 = (int)((b_obj->cSFunObject.P0_NHOODSIZE_RTP[1] - 1U) >> 1);
  for (i = 0; i < 101376; i++) {
    c_obj->W0_TEMP_IN_DWORKS[i] = varargin_1[i];
  }

  memset(&varargout_1_data[0], 0, 2000U * sizeof(unsigned int));
  while (!done) {
    max_idx = 0;
    maxValue = c_obj->W0_TEMP_IN_DWORKS[0];
    for (i = 0; i < 101376; i++) {
      if (c_obj->W0_TEMP_IN_DWORKS[i] > maxValue) {
        max_idx = i;
        maxValue = c_obj->W0_TEMP_IN_DWORKS[i];
      }
    }

    p = max_idx % 352;
    i = max_idx / 352;
    if (c_obj->W0_TEMP_IN_DWORKS[max_idx] >= varargin_2) {
      varargout_1_data[countPeak] = (unsigned int)(1 + i);
      varargout_1_data[1000U + countPeak] = (unsigned int)(1 + p);
      countPeak++;
      if (countPeak == 1000) {
        done = true;
      }

      max_idx = p - nhood_center_idx_0;
      if (max_idx >= 0) {
        p1 = max_idx;
      } else {
        p1 = 0;
      }

      max_idx = p + nhood_center_idx_0;
      if (max_idx <= 351) {
        p2 = max_idx;
      } else {
        p2 = 351;
      }

      max_idx = i + nhood_center_idx_1;
      if (max_idx <= 287) {
        q2 = max_idx;
      } else {
        q2 = 287;
      }

      max_idx = i - nhood_center_idx_1;
      if (max_idx >= 0) {
      } else {
        max_idx = 0;
      }

      while (max_idx <= q2) {
        p = max_idx * 352;
        for (i = p1; i <= p2; i++) {
          c_obj->W0_TEMP_IN_DWORKS[i + p] = 0.0F;
        }

        max_idx++;
      }
    } else {
      done = true;
    }
  }

  b_obj->cSFunObject.W1_NUMPEAKS_DWORK = (unsigned int)countPeak;
  fromIdx = 1000U;
  toIdx = (unsigned int)countPeak;
  for (i = 0; i < countPeak; i++) {
    varargout_1_data[toIdx] = varargout_1_data[fromIdx];
    fromIdx++;
    toIdx++;
  }

  varargout_1_size[0] = (int)b_obj->cSFunObject.W1_NUMPEAKS_DWORK;
  varargout_1_size[1] = 2;
}

/*
 * % Instantiate Corner Detection Objects
 * Arguments    : unsigned char R[101376]
 *                unsigned char G[101376]
 *                unsigned char B[101376]
 *                float fThresh
 *                float hThresh
 *                float mThresh
 * Return Type  : void
 */
void myCorners(unsigned char R[101376], unsigned char G[101376], unsigned char
               B[101376], float fThresh, float hThresh, float mThresh)
{
  vision_CornerDetector_2 hHarris;
  vision_CornerDetector_1 hFAST;
  vision_CornerDetector hminEigen;
  static visioncodegen_LocalMaximaFinder hFindLocalMax;
  visioncodegen_LocalMaximaFinder *obj;
  int i;
  visioncodegen_MarkerInserter hMarkerInserter;
  static float IGray[101376];
  static float metric[101376];
  int fastPoints_size[2];
  unsigned int fastPoints_data[2000];

  /* 'myCorners:4' hHarris = vision.CornerDetector('Method','Harris corner detection (Harris & Stephens)', ... */
  /* 'myCorners:5'   'MaximumCornerCount', 10000, 'CornerThreshold', eps, 'CornerLocationOutputPort', false, ... */
  /* 'myCorners:6'   'MetricMatrixOutputPort', true); */
  CornerDetector_CornerDetector(&hHarris);

  /* 'myCorners:8' hFAST = vision.CornerDetector('Method','Local intensity comparison (Rosten & Drummond)', ... */
  /* 'myCorners:9'     'MaximumCornerCount', 10000, 'CornerThreshold', eps, 'CornerLocationOutputPort', false, ... */
  /* 'myCorners:10'     'MetricMatrixOutputPort', true); */
  b_CornerDetector_CornerDetector(&hFAST);

  /* 'myCorners:12' hminEigen = vision.CornerDetector('Method','Minimum eigenvalue (Shi & Tomasi)', ... */
  /* 'myCorners:13'     'MaximumCornerCount', 10000, 'CornerThreshold', eps, 'CornerLocationOutputPort', false, ... */
  /* 'myCorners:14'     'MetricMatrixOutputPort', true); */
  c_CornerDetector_CornerDetector(&hminEigen);

  /* 'myCorners:16' hFindLocalMax = vision.LocalMaximaFinder('MaximumNumLocalMaxima', 1000, ... */
  /* 'myCorners:17'     'NeighborhoodSize', [11 11], 'ThresholdSource', 'Input port'); */
  obj = &hFindLocalMax;
  hFindLocalMax.isInitialized = 0;

  /* System object Constructor function: vision.LocalMaximaFinder */
  for (i = 0; i < 2; i++) {
    obj->cSFunObject.P0_NHOODSIZE_RTP[i] = 11U;
  }

  /* 'myCorners:19' hMarkerInserter = vision.MarkerInserter('Shape','Plus','Size',3,'BorderColor','White'); */
  MarkerInserter_MarkerInserter(&hMarkerInserter);

  /*  hGrayScaleConverter = vision.ColorSpaceConverter('Conversion', 'RGB to intensity'); */
  /* % Concatenate color planes and convert to single precision */
  /*   Then convert to grayscale */
  /*  I = single(cat(3,R,G,B)); */
  /*  IGray = step(hGrayScaleConverter, I); */
  /*  for codegen */
  /* 'myCorners:29' coef = single([0.2989360 0.5870430 0.1140209]); */
  /* 'myCorners:30' IGray = single(R)*coef(1) + single(G)*coef(2) + single(B)*coef(3); */
  for (i = 0; i < 101376; i++) {
    IGray[i] = ((float)R[i] * 0.298936F + (float)G[i] * 0.587043F) + (float)B[i]
      * 0.114020899F;
  }

  /* % FAST (Rosten and Drummond) Corners for higher performance */
  /* 'myCorners:34' minThresh = single(200); */
  /* 'myCorners:35' if (fThresh < minThresh) */
  if (fThresh < 200.0F) {
    /* 'myCorners:35' fThresh = minThresh; */
    fThresh = 200.0F;
  }

  /* 'myCorners:36' metric = step(hFAST,IGray); */
  SystemCore_step(&hFAST, IGray, metric);

  /* 'myCorners:37' fastPoints = step(hFindLocalMax, metric, fThresh); */
  b_SystemCore_step(&hFindLocalMax, metric, fThresh, fastPoints_data,
                    fastPoints_size);

  /* R = insertPlus(R,fastPoints); */
  /* 'myCorners:39' R = step(hMarkerInserter,R,fastPoints); */
  if (hMarkerInserter.isInitialized != 1) {
    hMarkerInserter.isInitialized = 1;
  }

  Nondirect_stepImpl(&hMarkerInserter, R, fastPoints_data, fastPoints_size);

  /* I = insertMarker(R, fastPoints,'+', 'Color', [255 0 0]); */
  /* % Classical Harris Corners */
  /* 'myCorners:43' minThresh = single(10000); */
  /* 'myCorners:44' if (hThresh < minThresh) */
  if (hThresh < 10000.0F) {
    /* 'myCorners:44' hThresh = minThresh; */
    hThresh = 10000.0F;
  }

  /* 'myCorners:45' metric = step(hHarris,IGray); */
  c_SystemCore_step(&hHarris, IGray, metric);

  /* 'myCorners:46' harrisPoints = step(hFindLocalMax, metric, hThresh); */
  d_SystemCore_step(&hFindLocalMax, metric, hThresh, fastPoints_data,
                    fastPoints_size);

  /*  G = insertPlus(G,harrisPoints); */
  /* 'myCorners:48' G = step(hMarkerInserter,G,harrisPoints); */
  if (hMarkerInserter.isInitialized != 1) {
    hMarkerInserter.isInitialized = 1;
  }

  b_Nondirect_stepImpl(&hMarkerInserter, G, fastPoints_data, fastPoints_size);

  /*  I2 = insertMarker(G, harrisPoints,'+', 'Color', [0 255 0]); */
  /* % Shi and Tomasi Minimum Eigenvalue Corners */
  /* 'myCorners:52' minThresh = single(1000); */
  /* 'myCorners:53' if (mThresh < minThresh) */
  if (mThresh < 1000.0F) {
    /* 'myCorners:53' mThresh = minThresh; */
    mThresh = 1000.0F;
  }

  /* 'myCorners:54' metric = step(hminEigen,IGray); */
  e_SystemCore_step(&hminEigen, IGray, metric);

  /* 'myCorners:55' minEigenPoints = step(hFindLocalMax, metric, mThresh); */
  f_SystemCore_step(&hFindLocalMax, metric, mThresh, fastPoints_data,
                    fastPoints_size);

  /*  B = insertPlus(B,minEigenPoints); */
  /* 'myCorners:57' B = step(hMarkerInserter,B,minEigenPoints); */
  if (hMarkerInserter.isInitialized != 1) {
    hMarkerInserter.isInitialized = 1;
  }

  c_Nondirect_stepImpl(&hMarkerInserter, B, fastPoints_data, fastPoints_size);

  /*  I3 = insertMarker(B, minEigenPoints,'+', 'Color', [0 0 255]); */
  /*  R = uint8(I(:,:,1)); */
  /*  G = uint8(I2(:,:,2)); */
  /*  B = uint8(I3(:,:,3)); */
  b_Destructor(&hminEigen.cCornerMetric);
  Destructor(&hHarris.cCornerMetric);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void myCorners_initialize(void)
{
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void myCorners_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for myCorners.c
 *
 * [EOF]
 */
