/* driver_android_slider.h
 *
 * Copyright 2013-2014 The MathWorks, Inc.
 */
 
#if ( defined(MATLAB_MEX_FILE) || defined(RSIM_PARAMETER_LOADING) ||  defined(RSIM_WITH_SL_SOLVER) )
/* This will be run in Rapid Accelerator Mode */

#define SLIDER_INIT(id,min,value,max,steps) (0)
#define SLIDER_GETVAL(id,min,max,steps) (0)
#define SLIDER_DISPVAL(id,value) (0)
#define SLIDER_TERMINATE() (0)

#else

/* This will be called in Normal/External modes */

void initSlider(int,float,float,float,int);
float getSliderValue(int,float,float,int);
void dispSliderValue(int,float);
void terminateSlider();

#define SLIDER_INIT(id,min,value,max,steps) initSlider(id,min,value,max,steps)
#define SLIDER_GETVAL(id,min,max,steps) getSliderValue(id,min,max,steps)
#define SLIDER_DISPVAL(id,value) dispSliderValue(id,value) 
#define SLIDER_TERMINATE() terminateSlider()

#endif 
