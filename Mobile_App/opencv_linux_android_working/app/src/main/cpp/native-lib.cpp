#include <jni.h>
#include <string>
#include <opencv2/core.hpp>

extern "C" JNIEXPORT jstring

JNICALL
Java_com_example_root_opencv_1linux_1android_1working_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_root_opencv_1linux_1android_1working_MainActivity_validate(JNIEnv *env,
                                                                            jobject instance,
                                                                            jlong matAddrGr,
                                                                            jlong matAddrRgba) {
    //cv::Rect();
    cv::Mat testMat;
    std::string hello2 = "Hello from validate()";

    return env->NewStringUTF(hello2.c_str());
}