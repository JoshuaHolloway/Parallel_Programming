/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * myCorners.c
 *
 * Code generation for function 'myCorners'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "myCorners.h"

/* Function Definitions */
void myCorners(uint8_T R[307200], const uint8_T G[307200], const uint8_T B
               [307200], real32_T fThresh, real32_T hThresh, real32_T mThresh)
{
  int32_T i0;
  int32_T i1;
  uint8_T u0;
  (void)G;
  (void)B;
  (void)fThresh;
  (void)hThresh;
  (void)mThresh;

  /*  Copyright 2014 - 2015 The MathWorks, Inc. */
  for (i0 = 0; i0 < 307200; i0++) {
    i1 = (int32_T)muDoubleScalarRound((real_T)R[i0] * 0.1);
    u0 = (uint8_T)i1;
    R[i0] = u0;
  }

  /*  Instantiate Corner Detection Objects */
  /* hHarris = vision.CornerDetector('Method','Harris corner detection (Harris & Stephens)', ... */
  /*   'MaximumCornerCount', 10000, 'CornerThreshold', eps, 'CornerLocationOutputPort', false, ... */
  /*   'MetricMatrixOutputPort', true); */
  /*  hFAST = vision.CornerDetector('Method','Local intensity comparison (Rosten & Drummond)', ... */
  /*      'MaximumCornerCount', 10000, 'CornerThreshold', eps, 'CornerLocationOutputPort', false, ... */
  /*      'MetricMatrixOutputPort', true); */
  /*   */
  /*  hminEigen = vision.CornerDetector('Method','Minimum eigenvalue (Shi & Tomasi)', ... */
  /*      'MaximumCornerCount', 10000, 'CornerThreshold', eps, 'CornerLocationOutputPort', false, ... */
  /*      'MetricMatrixOutputPort', true); */
  /*   */
  /*  hFindLocalMax = vision.LocalMaximaFinder('MaximumNumLocalMaxima', 1000, ... */
  /*      'NeighborhoodSize', [11 11], 'ThresholdSource', 'Input port'); */
  /*   */
  /*  hMarkerInserter = vision.MarkerInserter('Shape','Plus','Size',3,'BorderColor','White'); */
  /*     */
  /*  % hGrayScaleConverter = vision.ColorSpaceConverter('Conversion', 'RGB to intensity'); */
  /*   */
  /*  %% Concatenate color planes and convert to single precision */
  /*  %  Then convert to grayscale */
  /*  % I = single(cat(3,R,G,B)); */
  /*  % IGray = step(hGrayScaleConverter, I); */
  /*   */
  /*  % for codegen */
  /*  coef = single([0.2989360 0.5870430 0.1140209]); */
  /*  IGray = single(R)*coef(1) + single(G)*coef(2) + single(B)*coef(3); */
  /*   */
  /*   */
  /*  %% FAST (Rosten and Drummond) Corners for higher performance */
  /*  minThresh = single(200); */
  /*  if (fThresh < minThresh), fThresh = minThresh; end */
  /*  metric = step(hFAST,IGray); */
  /*  fastPoints = step(hFindLocalMax, metric, fThresh); */
  /*  %R = insertPlus(R,fastPoints); */
  /*  R = step(hMarkerInserter,R,fastPoints); */
  /*  %I = insertMarker(R, fastPoints,'+', 'Color', [255 0 0]); */
  /*   */
  /*  %% Classical Harris Corners */
  /*  minThresh = single(10000); */
  /*  if (hThresh < minThresh), hThresh = minThresh; end */
  /*  metric = step(hHarris,IGray); */
  /*  harrisPoints = step(hFindLocalMax, metric, hThresh); */
  /*  % G = insertPlus(G,harrisPoints); */
  /*  G = step(hMarkerInserter,G,harrisPoints); */
  /*  % I2 = insertMarker(G, harrisPoints,'+', 'Color', [0 255 0]); */
  /*   */
  /*  %% Shi and Tomasi Minimum Eigenvalue Corners */
  /*  minThresh = single(1000); */
  /*  if (mThresh < minThresh), mThresh = minThresh; end */
  /*  metric = step(hminEigen,IGray); */
  /*  minEigenPoints = step(hFindLocalMax, metric, mThresh); */
  /*  % B = insertPlus(B,minEigenPoints); */
  /*  B = step(hMarkerInserter,B,minEigenPoints); */
  /*  % I3 = insertMarker(B, minEigenPoints,'+', 'Color', [0 0 255]); */
  /*  R = uint8(I(:,:,1)); */
  /*  G = uint8(I2(:,:,2)); */
  /*  B = uint8(I3(:,:,3)); */
}

/* End of code generation (myCorners.c) */
