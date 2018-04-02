LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)
# Need to update the following line to point to your own OpenCV.mk
#include C:\MATLAB\SupportPackages\R2015a\OpenCV-2.4.9-android-sdk\sdk\native\jni\OpenCV.mk
include /home/josh/OpenCV-2.4.9-android-sdk/sdk/native/jni/OpenCV.mk

LOCAL_MODULE := mCameraSlider
                
LOCAL_SRC_FILES := src/driver_android_slider.c    \
                   src/driver_android_camera.cpp  \
                   src/driver_android_display.cpp \
                   src/main.c                     \
                   src/mCameraSlider.c            \
                   src/corner/myCorners.c         \
                   
LOCAL_C_INCLUDES += $(LOCAL_PATH)\src\include \
                    $(LOCAL_PATH)\src\corner  \

LOCAL_LDLIBS  +=  -llog -ldl
include $(BUILD_SHARED_LIBRARY)
