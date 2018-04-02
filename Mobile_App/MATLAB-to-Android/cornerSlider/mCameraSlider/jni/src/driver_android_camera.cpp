/*
 * driver_android_camera.cpp
 *
 * Driver code
 *
 * Copyright 2013-2014 The MathWorks, Inc.
 */
#include <jni.h>
#include <stdlib.h>
#include <android/log.h>
#include <opencv2/core/core.hpp>

extern JavaVM *cachedJvm;
extern jobject cachedActivityObj;
extern jclass cachedMainActivityCls;

typedef struct _CameraContext
{
    jmethodID CameraGetInputBufferID;
    jmethodID InitCameraID;    
    
    int Width;
	int Height;
    int Location;
    
    cv::Mat Temp;
    cv::Mat Repo;
} CameraContext;
static CameraContext sgCameraContext;

extern "C" 
void initCamera(double sampleTime, int location, int width, int height )
{
    JNIEnv *pEnv;
    (cachedJvm)->AttachCurrentThread(&pEnv, NULL);
    sgCameraContext.CameraGetInputBufferID = (pEnv)->GetMethodID( cachedMainActivityCls, "getCameraInputBuffer",
    "()J");
    sgCameraContext.InitCameraID = (pEnv)->GetMethodID(cachedMainActivityCls, "initCamera",
    "(DIII)I");
    sgCameraContext.Width = width;
    sgCameraContext.Height = height;
    sgCameraContext.Location = location;
    if (sgCameraContext.InitCameraID != NULL)
    {
        JNIEnv *pEnv;
        jint ret;
        
        (cachedJvm)->AttachCurrentThread(&pEnv, NULL);
         //__android_log_print(ANDROID_LOG_INFO, "CAMERAINPUT", "sample: %g, loc: %d, width: %d, height: %d", 
         //        sampleTime, location, width, height);
        ret = (jint)((pEnv)->CallIntMethod(cachedActivityObj, sgCameraContext.InitCameraID, sampleTime, location, width, height));       
        if (ret != 1)
        {
            /* set the error condition */
        }
    }
}

inline void repoChannel(cv::Mat& input, cv::Mat& output)
{
    int InputLeft = 0;
    int OutputLeft = 0;
    int Width = output.cols;
    if (output.cols > input.cols)
    {
        OutputLeft = (output.cols  - input.cols) >> 1;
        Width = input.cols;
    }
    else
    {
        InputLeft = (input.cols - output.cols)  >> 1;
    }
    int InputTop = 0;
    int OutputTop = 0;
    int Height = output.rows;
    if (output.rows > input.rows)
    {
        OutputTop = (output.rows  - input.rows) >> 1;
        Height = input.rows;
    }
    else
    {
        InputTop = (input.rows - output.rows)  >> 1;
    }
    cv::Mat OutputRoi(output, cv::Rect(OutputLeft,OutputTop,Width, Height));
    cv::Mat InputRoi(input, cv::Rect(InputLeft,InputTop,Width,Height));
    InputRoi.copyTo(OutputRoi);
    //__android_log_print(ANDROID_LOG_INFO, "CAMERAINPUT", "(%d, %d) -> (%d, %d), %d, %d", 
    //    OutputLeft,OutputTop,InputLeft,InputTop,Width,Height);

}

inline void extractChannelFromInput(cv::Mat& input, uint8_t* outCh, int chIdx)
{
     cv::Mat  JustChMat = cv::Mat(sgCameraContext.Height, sgCameraContext.Width, CV_8UC1, outCh);
     //if location is front, then we need to flip
     if (sgCameraContext.Location == 1)
     {
         extractChannel(input, sgCameraContext.Temp, chIdx);
         if ((sgCameraContext.Width != input.cols) || (sgCameraContext.Height != input.rows))
         {  
             cv::flip(sgCameraContext.Temp,sgCameraContext.Repo,1);
             repoChannel(sgCameraContext.Repo, JustChMat);
         }
         else
            cv::flip(sgCameraContext.Temp,JustChMat,1);
     }
     else
     {
         if ((sgCameraContext.Width != input.cols) || (sgCameraContext.Height != input.rows))
         {
              extractChannel(input, sgCameraContext.Repo, chIdx);
              repoChannel(sgCameraContext.Repo, JustChMat);
         }
         else
             extractChannel(input, JustChMat, chIdx);
     }
}

extern "C" 
void getCameraData(uint8_t *outCh1, uint8_t *outCh2, uint8_t *outCh3)
{
    if (sgCameraContext.CameraGetInputBufferID != NULL)
    {
        JNIEnv *pEnv;
         jlong  ret;
        
         (cachedJvm)->AttachCurrentThread(&pEnv, NULL);
         ret = (jlong)pEnv->CallLongMethod(cachedActivityObj, sgCameraContext.CameraGetInputBufferID);       
         if (ret != 0)
        {
             cv::Mat&   input = *(cv::Mat *)ret;
             //__android_log_print(ANDROID_LOG_INFO, "CAMERAINPUT", "type: %d, rows: %d, cols: %d, Req: %d, %d", 
             //        input.type(), input.rows, input.cols, sgCameraContext.Width, sgCameraContext.Height);
             extractChannelFromInput(input, outCh1, 0);
             extractChannelFromInput(input, outCh2, 1);
             extractChannelFromInput(input, outCh3, 2);
             //__android_log_print(ANDROID_LOG_INFO, "CAMERAINPUT", "%d, %d, %d", 
             //        *outCh1, *outCh2, *outCh3);
        }
    }
}

extern "C" 
void terminateCamera()
{
}
/* LocalWords:  DIII CAMERAINPUT
 */
