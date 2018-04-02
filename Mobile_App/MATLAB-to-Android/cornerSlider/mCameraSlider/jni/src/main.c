/*
 * main.c - for shared object (.so) in an Android application
 */

#include <android/log.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <jni.h>
#include <android/log.h>
#include "mCameraSlider.h"
#include "rtwtypes.h"

#define LOGMESSAGE(message)            __android_log_print(ANDROID_LOG_INFO, "mCameraSlider",message)
#define LOGMESSAGE_ARG1(message, arg1) __android_log_print(ANDROID_LOG_INFO, "mCameraSlider",message, arg1)

/* Used for JNI calls */
JavaVM *cachedJvm;
jobject cachedActivityObj;
jclass cachedMainActivityCls;
jmethodID flashMessageID;

void detachCurrentThreadFromJVM()
{
  if (cachedJvm != NULL) {
    (*cachedJvm)->DetachCurrentThread(cachedJvm);
  }
}

void flashMessage(const char* inMessage)
{
  if (flashMessageID != NULL) {
    JNIEnv *pEnv;
    jstring jMessage;
    (*cachedJvm)->AttachCurrentThread(cachedJvm, &pEnv, NULL);
    jMessage = (*pEnv)->NewStringUTF(pEnv, inMessage);
    (*pEnv)->CallVoidMethod(pEnv, cachedActivityObj, flashMessageID, jMessage);
    (*pEnv)->DeleteLocalRef(pEnv, jMessage);
  }
}

jint JNICALL naMain(JNIEnv *pEnv, jobject pObj, jobjectArray pArgv, jobject
                    pMainActivity)
{
  int ret;

  (*pEnv)->GetJavaVM(pEnv, &cachedJvm);
  cachedMainActivityCls = (*pEnv)->NewGlobalRef(pEnv, (*pEnv)->GetObjectClass
    (pEnv, pMainActivity));
  cachedActivityObj = (*pEnv)->NewGlobalRef(pEnv, pMainActivity);
  flashMessageID = (*pEnv)->GetMethodID(pEnv, cachedMainActivityCls,
    "flashMessage", "(Ljava/lang/String;)V");

  /* Flash a message in the main activity */
  flashMessage("Starting the model");

  mCameraSlider_initialize();

  /* find more elegant way of exiting this loop */
  while(1)
  {

    mCameraSlider_output();
  }

  /* Received stop signal */
  LOGMESSAGE("**stopping the model**\n");

  /* Terminate model */
  mCameraSlider_terminate();

  /* Remove all global references */
  (*pEnv)->DeleteGlobalRef(pEnv, cachedMainActivityCls);
  (*pEnv)->DeleteGlobalRef(pEnv, cachedActivityObj);
  detachCurrentThreadFromJVM();
  return 0;
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* pVm, void *reserved)
{
  JNIEnv* env;
  if ((*pVm)->GetEnv(pVm, (void **)&env, JNI_VERSION_1_6) != JNI_OK)
  {
    LOGMESSAGE_ARG1("Not version %d; Exiting", JNI_VERSION_1_6);
    return -1;
  }

  JNINativeMethod nm[1];
  nm[0].name = "naMain";
  nm[0].signature =
    "([Ljava/lang/String;Lcom/example/mCameraSlider/mCameraSlider;)I";
  nm[0].fnPtr = (void*)naMain;
  jclass cls = (*env)->FindClass(env, "com/example/mCameraSlider/mCameraSlider");

  //Register methods with env->RegisterNatives.
  (*env)->RegisterNatives(env, cls, nm, 1);
  return JNI_VERSION_1_6;
}

