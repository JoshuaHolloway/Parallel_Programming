#ifndef M_CAMERA_SLIDER_H
#define M_CAMERA_SLIDER_H

#include <math.h>
#include <stddef.h>
#include <string.h>
#include "rtwtypes.h"
#include "driver_android_slider.h"
#include "driver_android_camera.h"
#include "driver_android_display.h"

#define CAM_WIDTH (352)
#define CAM_HEIGHT (288)
#define CAM_RES (CAM_WIDTH*CAM_HEIGHT)

/* Block signals (auto storage) */
typedef struct {
  uint8_T rPlane[CAM_RES];
  uint8_T gPlane[CAM_RES];
  uint8_T bPlane[CAM_RES];
} rgbImage_T;

/* functions */
extern void mCameraSlider_initialize(void);
extern void mCameraSlider_output(void);
extern void mCameraSlider_terminate(void);

#endif /* M_CAMERA_SLIDER_H */
