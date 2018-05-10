#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
//===================
#include <windows.h>
#include <iostream> 
#include <fstream>
#include <stdio.h>
//----------
struct Array
{
	float* arr = nullptr;
	size_t length;
	Array(size_t size)
	{
		arr = new float[size];
		this->length = size;
	}
};
//--------------------------
Array conv(Array x, Array h)
{
	Array y(x.length);
	for (int i = 0; i < x.length; ++i)
	{
		float Pvalue = 0.0f;
		int N_start_point = i - h.length / 2;
		for (int j = 0; j < h.length; j++)
		{
			if (N_start_point + j >= 0 && N_start_point + j < x.length)
				Pvalue += x.arr[N_start_point + j] * h.arr[j];
		}
		y.arr[i] = Pvalue;
	}
	return y;
}
//========
int main()
{
	//     conv      pool
	// 4x4x1 -> 4x4x2 -> 2x2x2
	const size_t R[3] = { 4, 4, 2 };
	const size_t C[3] = { 4, 4, 2 };
	const size_t D[3] = { 1, 2, 2 };

	const size_t width = 3, mask_width = 3;
	Array x(3), h(3);
	x.arr[0] = 1;	x.arr[1] = 2;	x.arr[2] = 3;
	h.arr[0] = 1;	h.arr[1] = 1;	h.arr[2] = 1;
	
	Array y = conv(x, h);

	for (int i = 0; i < y.length; i++)
		cout << y.arr[i] << " ";
	cout << "\n";
	
	getchar();
	return 0;
}
