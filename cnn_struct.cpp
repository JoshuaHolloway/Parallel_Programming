#include <iostream>
#include <string>
using std::cout;
using std::string;
//===================
#include <windows.h>
#include <iostream> 
#include <fstream>
#include <stdio.h>
//-----------
struct Vector
{
	float* val = nullptr;
	size_t length;
	Vector(size_t length)
	{
		val = new float[length];
		this->length = length;
	}
};
//-----------------------------
Vector conv(Vector x, Vector h)
{
	Vector y(x.length);
	for (int i = 0; i < x.length; ++i)
	{
		float Pvalue = 0.0f;
		int N_start_point = i - h.length / 2;
		for (int j = 0; j < h.length; j++)
		{
			if (N_start_point + j >= 0 && N_start_point + j < x.length)
				Pvalue += x.val[N_start_point + j] * h.val[j];
		}
		y.val[i] = Pvalue;
	}
	return y;
}
//===========
struct Matrix
{
	float* val = nullptr;
	size_t rows;
	size_t cols;
	size_t length;

	Matrix(size_t rows, size_t cols)
	{
		
		length = rows * cols;
		this->rows = rows;
		this->cols = cols;
		val = new float[length];
	}
	
	void set(size_t i, size_t j, float val)
	{
		this->val[i * cols + j] = val;
	}

	float at(size_t i, size_t j)
	{
		return val[i * cols + j];
	}

	void ones()
	{
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				this->val[i * cols + j] = 1;
			}
		}
	}

	void zeros()
	{
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				this->val[i * cols + j] = 0;
			}
		}
	}

	void count()
	{
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				this->val[i * cols + j] = i * cols + j;
			}
		}
	}
};
//-----------------------------
Matrix conv(Matrix x, Matrix h)
{
	

	Matrix y(x.rows, x.cols);
	for (int idy = 0; idy < x.rows; ++idy)
	{
		
		for (int idx = 0; idx < x.cols; ++idx)
		{
			
			float Pvalue = 0.0f;

			int M_start_point = idx - h.rows / 2;
			int N_start_point = idy - h.cols / 2;
			for (int i = 0; i < h.rows; ++i)
			{
				
				for (int j = 0; j < h.cols; ++j)
				{
					

					if ((M_start_point + i >= 0 && M_start_point + i < x.rows)
						&& (N_start_point + j >= 0 && N_start_point + j < x.cols))
					{
						Pvalue += x.at(M_start_point + i, N_start_point + j) * h.at(i,j);
					}
				}
				
			}
			y.set(idx, idy, Pvalue);
			//cout << y.at(idx, idy) << " ";
			//getchar();
		}
		//cout << "\n";
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


	/// 1D:
	const size_t width = 3, mask_width = 3;
	Vector x(3), h(3);
	x.val[0] = 1;	x.val[1] = 2;	x.val[2] = 3;
	h.val[0] = 1;	h.val[1] = 1;	h.val[2] = 1;
	
	Vector y = conv(x, h);

	for (int i = 0; i < y.length; i++)
		cout << y.val[i] << " ";
	cout << "\n\n 1D complete \n\n Start 2D: \n\n";

	/// 2D:
	Matrix X(3, 3);
	X.count();

	Matrix H(3, 3);
	H.ones();

	Matrix Y = conv(X, H);

	for (int i = 0; i < Y.rows; ++i)
	{
		for (int j = 0; j < Y.cols; ++j)
		{
			cout << Y.at(i, j) << " ";
		}
		cout << "\n";
	}

	getchar();
	return 0;
}
