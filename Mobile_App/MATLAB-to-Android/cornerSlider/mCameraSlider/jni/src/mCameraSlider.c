/*
 * File: mCameraSlider.c
 */

#define MY_CORNERS

#include "mCameraSlider.h"
#include "driver_android_slider.h"
#ifdef MY_CORNERS
#include "myCorners.h"
#endif

#define SLIDER_MAX              (1.0)
#define SLIDER_MIN              (0.0)
#define SLIDER_VAL              (0.5)

/* image frame */
rgbImage_T rgbImage;

real_T updateSlider(int id, real_T scale)
{
	  real_T slider;
	  slider = getSliderValue(id, SLIDER_MIN, SLIDER_MAX, 10.0);
	  slider *= scale;
	  dispSliderValue(id, slider);
	  return(slider);
}

void applyGains(uint8_T *r, uint8_T *g, uint8_T *b,
		        real_T gainR, real_T gainG, real_T gainB)
{
	  int32_T i;
	  real_T pixel;

	  for (i=0; i<CAM_RES; i++)
	  {
		  pixel = (real_T)(*r) * gainR;
		  *r++ = (uint8_T)pixel;

		  pixel = (real_T)(*g) * gainG;
		  *g++ = (uint8_T)pixel;

		  pixel = (real_T)(*b) * gainB;
		  *b++ = (uint8_T)pixel;
	  }
}


/* Model output function */
void mCameraSlider_output(void)
{
	  real_T rSlider, gSlider, bSlider;
	  uint8_T *r = rgbImage.rPlane;
	  uint8_T *g = rgbImage.gPlane;
	  uint8_T *b = rgbImage.bPlane;

	  /* grab frame */
	  getCameraData(r,g,b);


#ifdef MY_CORNERS
      /* read and display sliders */
	  rSlider = updateSlider(1.0, 4000);    /* FAST */
      gSlider = updateSlider(2.0, 1000000);  /* Harris */
      bSlider = updateSlider(3.0, 5000);  /* Shi & Tomasi */

	  myCorners(r,g,b,rSlider,gSlider,bSlider);
#else
      /* read and display sliders */
	  rSlider = updateSlider(1.0, 1);
      gSlider = updateSlider(2.0, 1);
      bSlider = updateSlider(3.0, 1);

	  /* apply slider gains */
	  applyGains(r,g,b,rSlider,gSlider,bSlider);
#endif

	  /* display frame */
	  putDisplayData(r,g,b);
}

void mCameraSlider_initialize(void)
{
  /* init sliders */
  initSlider(1.0, SLIDER_MIN, SLIDER_VAL, SLIDER_MAX, 10.0);
  initSlider(2.0, SLIDER_MIN, SLIDER_VAL, SLIDER_MAX, 10.0);
  initSlider(3.0, SLIDER_MIN, SLIDER_VAL, SLIDER_MAX, 10.0);

  initCamera(0.1, 2U, CAM_WIDTH, CAM_HEIGHT);
  initDisplay(CAM_WIDTH, CAM_HEIGHT);

#ifdef MY_CORNERS
  myCorners_initialize();
#endif
}

/* Model terminate function */
void mCameraSlider_terminate(void)
{
#ifdef MY_CORNERS
  myCorners_terminate();
#endif
  terminateCamera();
  terminateDisplay();
}
