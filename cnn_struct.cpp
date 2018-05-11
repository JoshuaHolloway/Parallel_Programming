#include <iostream>
#include <string>
#include <vector>
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

	void print()
	{
		for (int i = 0; i < channels; ++i)
		{
			cout << "\n ----------------- \n";
			cout << "Slice " << i << " \n";
			for (int j = 0; j < rows; ++j)
			{
				for (int k = 0; k < cols; ++k)
				{
					cout << val[i * rows * cols + j * cols + k] << " ";
				}
				cout << "\n";
			}
		}
	}
};
//---------------
class Tensor
{
private:
	size_t dim1;
	size_t dim2;
	size_t dim3;
	size_t dim4;
public:
	// pixel data
	float* val = nullptr;

	// (filters, channels, rows, cols)
	size_t filters;		// dim 1
	size_t channels;	// dim 2
	size_t rows;			// dim 3
	size_t cols;			// dim 4

										// total number of pixels
	size_t length;


	// Vector of feature maps - tensor = set of feature maps:
	std::vector<FeatureMap> tensor;

	// Constructor and destructor
	Tensor(size_t filters, size_t channels, size_t rows, size_t cols)
	{
		length = rows * cols * channels * filters;

		val = new float[length];

		this->filters = filters;			this->dim1 = filters;
		this->channels = channels;		this->dim2 = channels;
		this->rows = rows;						this->dim3 = rows;
		this->cols = cols;						this->dim4 = cols;
	}
	~Tensor() { delete[] val; }

	// Easier indexing is achieved with (output_channel, input_channel, row, col)
	void set(size_t i, size_t j, size_t k, size_t l, float val)
	{
		// i: dim1 - filters
		// j: dim2 - channels
		// k: dim3 - rows
		// l: dim4 - cols

		// 3D linear index: i * rows * cols + j * cols + k
		// i * cols * rows + j * cols + k
		// (i * dim3 * dim2) + (j * dim3) + k

		// 4D linear index:
		// (i * dim4 * dim3 * dim2) + (j * dim4 * dim3) + (k * dim4) + l

		this->val[(i * dim4 * dim3 * dim2) + (j * dim4 * dim3) + (k * dim4) + l] = val;
	}

	float at(size_t i, size_t j, size_t k, size_t l) //(filters, channel, row, col)
	{
		return val[(i * dim4 * dim3 * dim2) + (j * dim4 * dim3) + (k * dim4) + l];
	}

	void ones()
	{
		for (int i = 0; i < dim1; ++i)
		{
			for (int j = 0; j < dim2; ++j)
			{
				for (int k = 0; k < dim3; ++k)
				{
					for (int l = 0; l < dim4; ++l)
						this->val[(i * dim4 * dim3 * dim2) + (j * dim4 * dim3) + (k * dim4) + l] = 1;
				}
			}
		}
	}

	void zeros()
	{
		for (int i = 0; i < dim1; ++i)
		{
			for (int j = 0; j < dim2; ++j)
			{
				for (int k = 0; k < dim3; ++k)
				{
					for (int l = 0; l < dim4; ++l)
						this->val[(i * dim4 * dim3 * dim2) + (j * dim4 * dim3) + (k * dim4) + l] = 0;
				}
			}
		}
	}

	void count()
	{
		for (int i = 0; i < dim1; ++i)
		{
			for (int j = 0; j < dim2; ++j)
			{
				for (int k = 0; k < dim3; ++k)
				{
					for (int l = 0; l < dim4; ++l)
					{
						this->val[(i * dim4 * dim3 * dim2) + (j * dim4 * dim3) + (k * dim4) + l]
							= (i * dim4 * dim3 * dim2) + (j * dim4 * dim3) + (k * dim4) + l;

					}
				}
			}
		}
	};

	void print()
	{
		for (int i = 0; i < filters; ++i)
		{
			cout << "\n ----------------- \n";
			cout << "Volume " << i << " \n";
			for (int j = 0; j < channels; ++j)
			{
				cout << "\n ----------------- \n";
				cout << "Slice " << i << " \n";
				for (int k = 0; k < rows; ++k)
				{
					for (int l = 0; l < cols; ++l)
					{
						cout << val[(i * dim4 * dim3 * dim2) + (j * dim4 * dim3) + (k * dim4) + l] << " ";
					}
					cout << "\n";
				}
			}
		}
	}
};
//===============================
FeatureMap collapse(FeatureMap x)
{
	// add together the matrix slices in a feature map
	FeatureMap y(x.rows, x.cols, 1);
	for (int idy = 0; idy < x.rows; ++idy)
	{
		for (int idx = 0; idx < x.cols; ++idx)
		{
			float Pvalue = 0.0f;
			for (int idz = 0; idz < x.channels; ++idz)
			{
				// Sum pixels in the z-dimension
				Pvalue += x.at(idz, idy, idx);
			}
			// Store into the zeroth index of output feature map - i.e. matrix
			y.set(0, idy, idx, Pvalue);
		}
	}
	return y;
}
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
						Pvalue += x.at(M_start_point + i, N_start_point + j) * h.at(i, j);
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
	// 2D conv with 3D feature maps with implicit matrix slice addition
	// Input: Two 3D tensors
	// Output: One 2D Matrix
	FeatureMap y(x.rows, x.cols, 1);
	// for (int idq = 0; idq < h.filters; ++idq) // out_channels
	for (int idy = 0; idy < x.rows; ++idy) // out_rows
	{
		for (int idx = 0; idx < x.cols; ++idx) // out_cols
		{
			float Pvalue = 0.0f;
			for (int idz = 0; idz < x.channels; ++idz) // input_channels
			{

				int M_start_point = idy - h.rows / 2;
				int N_start_point = idx - h.cols / 2;
				for (int i = 0; i < h.rows; ++i) // filter_rows
				{
					for (int j = 0; j < h.cols; ++j) // filter_cols
					{
						if ((M_start_point + i >= 0 && M_start_point + i < x.rows)
							&& (N_start_point + j >= 0 && N_start_point + j < x.cols))
						{
							Pvalue += x.at(idz, M_start_point + i, N_start_point + j) * h.at(idz, i, j);
						}
					}
				}
				y.set(0, idy, idx, Pvalue);
			}
		}
	}
	//return collapse(y);
	return y;
}
//-------------------------------------
FeatureMap conv(FeatureMap x, Tensor h)
{

	// 2D conv with 3D feature maps with implicit matrix slice addition
	// Input: One 3D feature map and one 4D tensor (set of filters)
	// Output: One 3D feature map
	FeatureMap y(x.rows, x.cols, h.filters);
	for (int idq = 0; idq < h.filters; ++idq) // out_channels
	{
		for (int idy = 0; idy < x.rows; ++idy) // out_rows
		{
			for (int idx = 0; idx < x.cols; ++idx) // out_cols
			{
				float Pvalue = 0.0f;
				for (int idz = 0; idz < x.channels; ++idz) // input_channels
				{

					int M_start_point = idy - h.rows / 2;
					int N_start_point = idx - h.cols / 2;
					for (int i = 0; i < h.rows; ++i) // filter_rows
					{
						for (int j = 0; j < h.cols; ++j) // filter_cols
						{
							if ((M_start_point + i >= 0 && M_start_point + i < x.rows)
								&& (N_start_point + j >= 0 && N_start_point + j < x.cols))
							{
								Pvalue += x.at(idz, M_start_point + i, N_start_point + j) * h.at(idq, idz, i, j);
							}
						}
					}
					y.set(idq, idy, idx, Pvalue);
				}
			}
		}
	}
	return y;
}
//===========================
FeatureMap pool_ave(FeatureMap x)
{
	const size_t H = x.rows;
	const size_t W = x.cols;
	const size_t M = x.channels;
	const size_t K = 2; // downsampling factor

	FeatureMap S(H / K, W / K, x.channels); // rows, cols, channels

	for (int m = 0; m < M; ++m)  // channels
	{
		for (int h = 0; h < H / K; ++h) // rows
		{
			for (int w = 0; w < W / K; ++w)
			{
				float temp = 0.0f;
				for (int p = 0; p < K; ++p)
				{
					for (int q = 0; q < K; ++q)
					{
						temp += x.at(m, K*h + p, K*w + q) / float(K*K);
					}
				}
				S.set(m, h, w, temp);
			}
		}
	}

	return S;
}
//========
int main()
{
	//     conv      pool
	// 4x4x1 -> 4x4x2 -> 2x2x2
	const size_t R[3] = { 4, 4 };
	const size_t C[3] = { 4, 4 };
	const size_t D[3] = { 1, 2 };
	const size_t K[1] = { 3 }; // filter sizes

														 /// 4D:
	FeatureMap X4(R[0], C[0], D[0]);			X4.count();
	Tensor H4(D[1], D[0], K[0], K[0]);		H4.ones();

	cout << "\n\nX4: \n";
	X4.print();



	FeatureMap Y4 = conv(X4, H4);
	cout << "\n\nY4.rows = " << Y4.rows << "\n";
	cout << "Y4.cols = " << Y4.cols << "\n";
	cout << "Y4.channel = " << Y4.channels << "\n";


	cout << "\n\nY4: \n";
	Y4.print();

	FeatureMap Z4 = pool_ave(Y4);
	cout << "\n\nZ4: \n";
	Z4.print();

	getchar();
	return 0;
}
