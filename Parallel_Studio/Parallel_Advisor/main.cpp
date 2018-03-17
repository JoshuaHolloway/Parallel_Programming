#include <iostream>
#include <cilk/cilk.h>
#include <advisor-annotate.h>
//==================
using namespace std;
//=====================
#define NUMBER  1000000
//========
int main()
{
    float *a = new float[NUMBER];
    float *b = new float[NUMBER];

    ANNOTATE_SITE_BEGIN(solve)
    // not explicity using cilk_for
    for (int i =0; i < NUMBER; i++) {
        a[i] = i + 2.0f;
    }
    cout << "A \n";
    ANNOTATE_TASK_BEGIN(setQueen)

    for (int i = 0; i < NUMBER; i++) {
        b[i] = a[i] * 2.0f;
    }
    cout << "B \n";
    ANNOTATE_TASK_END(setQueen)

    for (int i = 0; i < NUMBER; i++) {
        b[i] = a[i] * 2.0f + 2.0f;
    }
    cout << "C \n";
    ANNOTATE_SITE_END(solve)

    /*
    cilk_for (int i =0; i < NUMBER; i++) {
        a[i] = i + 2.0f;
    }

    cout << "A \n";

    cilk_for (int i = 0; i < NUMBER; i++) {
        b[i] = a[i] * 2.0f;
    }

    cout << "B \n";

    cilk_for (int i = 0; i < NUMBER; i++) {
        b[i] = a[i] * 2.0f + 2.0f;
    }
    */

    return 0;
}