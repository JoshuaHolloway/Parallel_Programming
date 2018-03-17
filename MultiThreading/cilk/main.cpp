#include <iostream>
#include <cilk/cilk.h>
//==================
using namespace std;
//=====================
#define NUMBER  1000000
//========
int main()
{
    float *a = new float[NUMBER];
    float *b = new float[NUMBER];


    // not explicity using cilk_for
    for (int i =0; i < NUMBER; i++) {
        a[i] = i + 2.0f;
    }
    cout << "A \n";

    for (int i = 0; i < NUMBER; i++) {
        b[i] = a[i] * 2.0f;
    }
    cout << "B \n";

    for (int i = 0; i < NUMBER; i++) {
        b[i] = a[i] * 2.0f + 2.0f;
    }
    cout << "C \n";

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