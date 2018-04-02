/*
 * driver_android_slider.c
 *
 * Driver code
 *
 * Copyright 2013-2014 The MathWorks, Inc.
 */
#include <jni.h>
#include <stdlib.h>
#include "driver_android_slider2.h"


extern JavaVM *cachedJvm;
extern jobject cachedActivityObj;
extern jclass cachedMainActivityCls;
static jmethodID sgGetSliderID, sgSetSliderID, sgRegSliderID,sgDispSliderID;



void initSlider(int id, float min, float value, float max, int steps)
{
    JNIEnv *pEnv;
    (*cachedJvm)->AttachCurrentThread(cachedJvm, &pEnv, NULL);
    sgGetSliderID   = (*pEnv)->GetMethodID(pEnv, cachedMainActivityCls, "getSliderValue","(I)F");
    sgSetSliderID   = (*pEnv)->GetMethodID(pEnv, cachedMainActivityCls, "setSliderValue","(IFI)V");    
    sgRegSliderID   = (*pEnv)->GetMethodID(pEnv, cachedMainActivityCls, "registerSlider","(I)V");    
    sgDispSliderID  = (*pEnv)->GetMethodID(pEnv, cachedMainActivityCls, "dispSliderValue","(IF)V");    
    
    /* Initialize slider value */
    if (sgSetSliderID != NULL)
    {
        (*pEnv)->CallVoidMethod(pEnv, cachedActivityObj, sgSetSliderID, id, steps*(value-min)/(max-min),steps);       
        if ((*pEnv)->ExceptionCheck(pEnv)) return;
    }

    /*Display initial value */
    if (sgDispSliderID != NULL)
    {
        (*pEnv)->CallVoidMethod(pEnv, cachedActivityObj, sgDispSliderID, id, value);       
        if ((*pEnv)->ExceptionCheck(pEnv)) return;
    }
    
    /* Register Slider onChangeListener */
    if (sgRegSliderID != NULL)
    { 
        (*pEnv)->CallVoidMethod(pEnv, cachedActivityObj, sgRegSliderID, id);       
        if ((*pEnv)->ExceptionCheck(pEnv)) return;
    }
    
    
}

float getSliderValue(int id,float min, float max, int steps)
{
	jfloat value = 0;
    JNIEnv *pEnv;

    /* Read current slider progress */
    if (sgGetSliderID != NULL)
    {
        (*cachedJvm)->AttachCurrentThread(cachedJvm, &pEnv, NULL);
        value = (jfloat)(*pEnv)->CallFloatMethod(pEnv, cachedActivityObj, sgGetSliderID,id);       
        value = ((max-min)*(value)/steps)+min;
        
        if ((*pEnv)->ExceptionCheck(pEnv)) value = 0;
    }

    return value;
}

void dispSliderValue(int id, float value)
{
    /* Display slider values */
    if (sgDispSliderID != NULL)
    {
        JNIEnv *pEnv;
        
        (*cachedJvm)->AttachCurrentThread(cachedJvm, &pEnv, NULL);
        (*pEnv)->CallVoidMethod(pEnv, cachedActivityObj, sgDispSliderID, id, value);       
        if ((*pEnv)->ExceptionCheck(pEnv)) return;
    }     
}

void terminateSlider()
{
}
