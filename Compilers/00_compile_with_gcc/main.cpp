#include <iostream>
//#include <cilk/cilk.h>
#include "Class.h"

using namespace std;

int main() 
{
	// Test out the usage of the Class class:
	Class obj; // Instantiate an object of type Class

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

	return 0;
}
