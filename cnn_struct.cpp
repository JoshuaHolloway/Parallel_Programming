#include <iostream>
#include <string>
using std::cout;
using std::string;
//===========
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
//-----------
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
//-----------
struct FeatureMap
{
	float* val = nullptr;
	size_t rows;
	size_t cols;
	size_t channels;
	size_t length;

	FeatureMap(size_t rows, size_t cols, size_t channels)
	{
		length = rows * cols * channels;
		this->rows = rows;
		this->cols = cols;
		this->channels = channels;
		val = new float[length];
	}


	// Easier indexing is achieved with (channel, row, col)
	void set(size_t i, size_t j, size_t k, float val)
	{
		this->val[i * rows * cols + j * cols + k] = val;
	}

	float at(size_t i, size_t j, size_t k) //(channel, row, col)
	{
		return val[i * rows * cols + j * cols + k];
	}

	void ones()
	{
		for (int i = 0; i < channels; ++i)
		{
			for (int j = 0; j < rows; ++j)
			{
				for (int k = 0; k < cols; ++k)
				{
					this->val[i * rows * cols + j * cols + k] = 1;
				}
			}
		}
	}

	void zeros()
	{
		for (int i = 0; i < channels; ++i)
		{
			for (int j = 0; j < rows; ++j)
			{
				for (int k = 0; k < cols; ++k)
				{
					this->val[i * rows * cols + j * cols + k] = 0;
				}
			}
		}
	}

	void count()
	{
		for (int i = 0; i < channels; ++i)
		{
			for (int j = 0; j < rows; ++j)
			{
				for (int k = 0; k < cols; ++k)
				{
					this->val[i * rows * cols + j * cols + k] = i * rows * cols + j * cols + k;
				}
			}
		}
	}
};
//=============================
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
		}
	}
	return y;
}
//-----------------------------
FeatureMap conv(FeatureMap x, FeatureMap h)
{
	FeatureMap y(x.rows, x.cols, x.channels);
	for (int idz = 0; idz < x.channels; ++idz)
	{
		for (int idy = 0; idy < x.rows; ++idy)
		{
			for (int idx = 0; idx < x.cols; ++idx)
			{
				// Perform 2D convolution over each channel

				float Pvalue = 0.0f;

				int M_start_point = idy - h.rows / 2;
				int N_start_point = idx - h.cols / 2;
				for (int i = 0; i < h.rows; ++i)
				{

					for (int j = 0; j < h.cols; ++j)
					{
						if ((M_start_point + i >= 0 && M_start_point + i < x.rows)
							&& (N_start_point + j >= 0 && N_start_point + j < x.cols))
						{
							Pvalue += x.at(idz, M_start_point + i, N_start_point + j) * h.at(idz, i, j);
						}
					}

				}
				y.set(idz, idy, idx, Pvalue);
			}
		}
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

	/// 3D:
	FeatureMap X3(3, 3, 2);
	X3.count();

	FeatureMap H3(3, 3, 2);
	H3.ones();

	FeatureMap Y3 = conv(X3, H3);


	cout << "X3.rows = " << X3.rows << "\n";
	cout << "X3.cols = " << X3.cols << "\n";
	cout << "X3.channel = " << X3.channels << "\n";

	cout << "\n\nX3: \n";
	for (int i = 0; i < X3.channels; ++i)
	{
		for (int j = 0; j < X3.rows; ++j)
		{
			for (int k = 0; k < X3.cols; ++k)
			{
				cout << X3.at(i, j, k) << " ";
			}
			cout << "\n";
		}
		cout << "\n ----------------- \n";
	}



	for (int i = 0; i < X3.channels; ++i)
	{
		for (int j = 0; j < X3.rows; ++j)
		{
			for (int k = 0; k < X3.cols; ++k)
			{
				cout << Y3.at(i, j, k) << " ";
			}
			cout << "\n";
		}
		cout << "\n ----------------- \n";
	}
	

	getchar();
	return 0;
}
