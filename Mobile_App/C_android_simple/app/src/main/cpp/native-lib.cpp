#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring

JNICALL
Java_com_example_josh_c_1android_1simple_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
//==================================================================================================
void vecAdd(float* arr3, float* arr1, float* arr2, int n)
{
    for (int i = 0; i < n; i++)
        arr3[i] = arr1[i] + arr2[i];
}
//==================================================================================================
extern "C"
JNIEXPORT jfloatArray JNICALL
Java_com_example_josh_c_1android_1simple_MainActivity_test(JNIEnv *env, jobject instance,
                                                           jfloatArray fltarray1,
                                                           jfloatArray fltarray2) {
    jfloatArray result;
    result = env->NewFloatArray(3);
    if (result == NULL) {
        return NULL; /* out of memory error thrown */
    }

    jfloat array1[3];
    jfloat* flt1 = env->GetFloatArrayElements( fltarray1,0);
    jfloat* flt2 = env->GetFloatArrayElements( fltarray2,0);


    const int LEN = 3;
    float vecRtrn[LEN] = {0, 0, 0};
    vecAdd(vecRtrn, flt1, flt2, LEN);

    array1[0] = vecRtrn[0];
    array1[1] = vecRtrn[1];
    array1[2] = vecRtrn[2];

    env->ReleaseFloatArrayElements(fltarray1, flt1, 0);
    env->ReleaseFloatArrayElements(fltarray2, flt2, 0);
    env->SetFloatArrayRegion(result, 0, 3, array1);
    return result;
}