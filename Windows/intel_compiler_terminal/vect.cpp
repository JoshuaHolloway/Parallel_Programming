
/*
int main() {
    const int n = 1024;
    int A[n] __attribute__((aligned(64)));
    int B[n] __attribute__((aligned(64)));

    for (int i = 0; i < n; i++)
        A[i] = B[i] = i;

    //This loop will be auto-vectorized
    for(int i = 0; i < n; i++)
        A[i] = A[i] + B[i];

    for(int i = 0; i < n; i++)
        printf("%2d %2d %2d\n", i, A[i], B[i]);
    return 0;
}
*/
#include <iostream>
#include <cilk/cilk.h>

using namespace std;

int main() {

	float *a = new float[128];
	float *b = new float[128];
	float *c = new float[128];
	for (int i = 0; i < 128; i++)
	{
		a[i] = i / 10.0f;
		b[i] = i / 20.0f;
		c[i] = 0;
	}

	for (int i = 0; i < 128; i++)
	{	
		c[i] = a[i] + b[i];
	}

	for (int i = 0; i < 128; i++)
	{
		cout << c[i] << endl;
	}

	std::cout << "DEBUG - AFTER MOD\n\n\n";

	return 0;
}