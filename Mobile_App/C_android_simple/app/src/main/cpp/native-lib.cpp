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
void mat_mult(float* arr3, float* arr1, float* arr2, int n)
{
    //for (int i = 0; i < n; i++)
    //    arr3[i] = arr1[i] + arr2[i];

    for (int i = 0; i < 2; i++) { // Only works for n = 4

        for (int j = 0; j < 2; j++) {
            float temp = 0.0f;
            for (int k = 0; k < 2; k++) {
                temp += arr1[i + k * 2] * arr2[j * 2 + k];
            }
            arr3[i * 2 + j] = temp;
        }
    }
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


    float vecRtrn[N];
    mat_mult(vecRtrn, flt1, flt2, N);

    for (int i = 0; i < N; i++)
        array1[i] = vecRtrn[i];

    env->ReleaseFloatArrayElements(fltarray1, flt1, 0);
    env->ReleaseFloatArrayElements(fltarray2, flt2, 0);
    env->SetFloatArrayRegion(result, 0, N, array1); // Range: [0,N]
    return result;
}