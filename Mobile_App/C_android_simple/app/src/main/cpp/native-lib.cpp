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
//--------------------------------------------------------------------------------------------------
extern "C"
JNIEXPORT jfloatArray JNICALL
Java_com_example_josh_c_1android_1simple_MainActivity_test(JNIEnv *env, jobject instance,
                                                           jfloatArray fltarray1,
                                                           jfloatArray fltarray2) {
    const int N = 4;

    jfloatArray result;
    result = env->NewFloatArray(N);
    if (result == NULL) {
        return NULL; /* out of memory error thrown */
    }

    // increase to len-4
    jfloat array1[N];
    jfloat* flt1 = env->GetFloatArrayElements( fltarray1,0);
    jfloat* flt2 = env->GetFloatArrayElements( fltarray2,0);


    const int LEN = N;
    float vecRtrn[LEN];
    vecAdd(vecRtrn, flt1, flt2, LEN);

    for (int i = 0; i < N; i++)
        array1[i] = vecRtrn[i];

    env->ReleaseFloatArrayElements(fltarray1, flt1, 0);
    env->ReleaseFloatArrayElements(fltarray2, flt2, 0);
    env->SetFloatArrayRegion(result, 0, N, array1); // Range: [0,N]
    return result;
}
//==================================================================================================
void matlab_func(float* z, const float* x, const float* y, int n)
{
    int i0; int i1;  int i2;
    for (i0 = 0; i0 < n; i0++) {
        for (i1 = 0; i1 < n; i1++) {
            z[i0 + (i1 << 1)] = 0.0;
            for (i2 = 0; i2 < n; i2++) {
                z[i0 + (i1 << 1)] += x[i0 + (i2 << 1)] * y[i2 + (i1 << 1)];
            }
        }
    }
}
//--------------------------------------------------------------------------------------------------
extern "C"
JNIEXPORT jfloatArray JNICALL
Java_com_example_josh_c_1android_1simple_MainActivity_test_1matlab(JNIEnv *env, jobject instance,
                                                                   jfloatArray fltarray1,
                                                                   jfloatArray fltarray2) {
    jfloatArray result;
    result = env->NewFloatArray(4);
    if (result == NULL) {
        return NULL; /* out of memory error thrown */
    }

    jfloat array1[3];
    jfloat* flt1 = env->GetFloatArrayElements( fltarray1,0);
    jfloat* flt2 = env->GetFloatArrayElements( fltarray2,0);


    const int LEN = 2;
    float vecRtrn[LEN*LEN] = {0, 0, 0, 0};
    matlab_func(vecRtrn, flt1, flt2, LEN);

    array1[0] = vecRtrn[0];
    array1[1] = vecRtrn[1];
    array1[2] = vecRtrn[2];
    array1[3] = vecRtrn[3];

    env->ReleaseFloatArrayElements(fltarray1, flt1, 0);
    env->ReleaseFloatArrayElements(fltarray2, flt2, 0);
    env->SetFloatArrayRegion(result, 0, 3, array1);
    return result;
}