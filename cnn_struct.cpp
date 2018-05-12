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
	// 'same' 2D conv with 3D feature maps with implicit matrix slice addition
	// Zero-padding is also implicit
	//
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
//-------------------------------
FeatureMap pool_max(FeatureMap x)
{
	// downsampling factor:
	const size_t K = 2; 

	// output downsampled feature map:
	FeatureMap y(x.rows / K, x.cols / K, x.channels); // rows, cols, channels

	for (int i = 0; i < x.channels; ++i)
	{
		for (int j = 0; j < x.rows; j += K)
		{
			for (int k = 0; k < x.cols; k += K)
			{
				// Search inside the KxK block for max value
				int max = 0;
				for (int jj = j; jj < j + K; ++jj)
				{
					for (int kk = k; kk < k + K; ++kk)
					{
						if (jj == j && kk == k)
						{
							max = x.at(i,jj,kk);
						}
						else
						{
							if (x.at(i,jj,kk) > max)
								max = x.at(i,jj,kk);
						} // end if-else
					}// end for over kk
				} // end for over jj
				//y[i][j / 2][k / 2] = max;
				y.set(i, j / 2, k / 2, max);
			} // end for over k
		} // end for over j
	} // end for over i
	return y;
}
//========
FeatureMap relu(FeatureMap z)
{
	for(int i = 0; i < z.channels; ++i)
	{
		for (int j = 0; j < z.rows; ++j)
		{
			for (int k = 0; k < z.cols; ++k)
			{
				// Leaky ReLu
				if (z.at(i, j, k) < 0)
					z.set(i, j, k, 0.1*z.at(i,j,k)); 
			}
		}
	}
	return z;
}
//========
int main()
{
	// Full YOLO v1 newtork architecture:
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
	// Sections 1, 2, and 3:                          FM-1                                                    FM-2                      FM-3
	// 448×448×3  →  224×224×64  →  112×112×64  →  112×112×192  →  56×56×192  →  56×56×128  →  56×56×256  → 56×56×256  →  56×56×512 → 28×28×512 
	//         Conv(1)       Maxpool         Conv(2)         Maxpool        Conv(3)       Conv(4)       Conv(5)      Conv(6)      Maxpool
	//        Stride-2       Stride2        Stride-1         Stride2        
	//        64×3×7×7         2×2         192×64×3×3          2×2        128×192×1×1   256×128×3×3   256×256×1×1  256×512×3×3      2×2
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
	

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
	// Section 4:                                                                FM-4
	// 28×28×512  →  28×28×256  →  28×28×512  →  28×28×512  →  28×28×1024  →  14×14×1024
	//   Conv(7,9,11,13)  Conv(8,10,12,14)  Conv(15)      Conv(16)      Maxpool 
	// 256×512×1×1    512×256×3×3         512×512×1×1   1024×512×3×3      2×2 
	//      ^     [4x]     |                                           Stride-2                      
  //      | <-<-<-<-<-<-<-                   
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 


	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
	// Section 5:                                                   FM-5
	// 14×14×1024  →  14×14×512  →  14×14×1024  →  14×14×1024  →  7×7×1024
	//       Conv(17,19)    Conv(18,20)      Conv(21)      Conv(22)       
	//       512×1024×1×1   1024×512×3×3  1024×1024×3×3  1024×1024×3×3    
	//             ^     [2x]     |                        Stride-2     
	//             | <-<-<-<-<-<-<-                   
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
	// Section 6:                  FM-6
	// 7×7×1024  →  7×7×1024  →  7×7×1024 
	//       Conv(23)      Conv(24)      
	//    1024×1024×3×3  1024×1024×3×3                   
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
	// Section 7:       FM-7
	// 7×7×1024   →   7x7x256 (from darknet) 
	//          "FC"1  
	//      256×1024×1×1  (doen't say filter size - assuming 1x1 since called FC)
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
	// Section 8:       
	// 7×7×256   →   12544  →   12544  →   1715  →   × ×
	//          Vec      DropOut   "Connected" 
	//                                     "Detection-Layer"
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
	// Paper says final output should by 7x7x30
	// =========================================================================================================================================
	// =========================================================================================================================================
	// =========================================================================================================================================
	// Full YOLO v2 newtork architecture:
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
	//layer     filters    size              input                output
	//	0 conv      32  3 x 3 / 1   416 x 416 x   3   ->   416 x 416 x  32  0.299 BFLOPs
	//	1 max           2 x 2 / 2   416 x 416 x  32   ->   208 x 208 x  32
	//	2 conv      64  3 x 3 / 1   208 x 208 x  32   ->   208 x 208 x  64  1.595 BFLOPs
	//	3 max           2 x 2 / 2   208 x 208 x  64   ->   104 x 104 x  64
	//	4 conv     128  3 x 3 / 1   104 x 104 x  64   ->   104 x 104 x 128  1.595 BFLOPs
	//	5 conv      64  1 x 1 / 1   104 x 104 x 128   ->   104 x 104 x  64  0.177 BFLOPs
	//	6 conv     128  3 x 3 / 1   104 x 104 x  64   ->   104 x 104 x 128  1.595 BFLOPs
	//	7 max           2 x 2 / 2   104 x 104 x 128   ->    52 x  52 x 128
	//	8 conv     256  3 x 3 / 1    52 x  52 x 128   ->    52 x  52 x 256  1.595 BFLOPs
	//	9 conv     128  1 x 1 / 1    52 x  52 x 256   ->    52 x  52 x 128  0.177 BFLOPs
	//	10 conv    256  3 x 3 / 1    52 x  52 x 128   ->    52 x  52 x 256  1.595 BFLOPs
	//	11 max          2 x 2 / 2    52 x  52 x 256   ->    26 x  26 x 256
	//	12 conv    512  3 x 3 / 1    26 x  26 x 256   ->    26 x  26 x 512  1.595 BFLOPs
	//	13 conv    256  1 x 1 / 1    26 x  26 x 512   ->    26 x  26 x 256  0.177 BFLOPs
	//	14 conv    512  3 x 3 / 1    26 x  26 x 256   ->    26 x  26 x 512  1.595 BFLOPs
	//	15 conv    256  1 x 1 / 1    26 x  26 x 512   ->    26 x  26 x 256  0.177 BFLOPs
	//	16 conv    512  3 x 3 / 1    26 x  26 x 256   ->    26 x  26 x 512  1.595 BFLOPs
	//	17 max          2 x 2 / 2    26 x  26 x 512   ->    13 x  13 x 512
	//	18 conv   1024  3 x 3 / 1    13 x  13 x 512   ->    13 x  13 x1024  1.595 BFLOPs
	//	19 conv    512  1 x 1 / 1    13 x  13 x1024   ->    13 x  13 x 512  0.177 BFLOPs
	//	20 conv   1024  3 x 3 / 1    13 x  13 x 512   ->    13 x  13 x1024  1.595 BFLOPs
	//	21 conv    512  1 x 1 / 1    13 x  13 x1024   ->    13 x  13 x 512  0.177 BFLOPs
	//	22 conv   1024  3 x 3 / 1    13 x  13 x 512   ->    13 x  13 x1024  1.595 BFLOPs
	//	23 conv   1024  3 x 3 / 1    13 x  13 x1024   ->    13 x  13 x1024  3.190 BFLOPs
	//	24 conv   1024  3 x 3 / 1    13 x  13 x1024   ->    13 x  13 x1024  3.190 BFLOPs
	//	25 route  16
	//	26 conv     64  1 x 1 / 1    26 x  26 x 512   ->    26 x  26 x  64  0.044 BFLOPs
	//	27 reorg / 2    26 x  26 x  64   ->    13 x  13 x 256
	//	28 route  27 24
	//	29 conv   1024  3 x 3 / 1    13 x  13 x1280   ->    13 x  13 x1024  3.987 BFLOPs
	//	30 conv    425  1 x 1 / 1    13 x  13 x1024   ->    13 x  13 x 425  0.147 BFLOPs
	//	31 detection
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

	//         conv           max           conv          max           conv           conv          conv            max          conv         conv        conv          max         conv          conv         conv         conv         conv         max 
	// 416x416x3 -> 416x416x32 -> 208x208x32 -> 208x208x64 -> 104x104x64 -> 104x104x128 -> 104x104x64 ->  104x104x128 -> 52x52x128 -> 52x52x256 -> 52x52x128 -> 52x52x256 -> 26x26x256 -> 26x26x512 -> 26x26x256 -> 26x26x512 -> 26x26x256 -> 26x26x512 -> ...
	//  D[0]=3       D[1]=32        D[2]=32       D[3]=64       D[4]=64       D[5]=128       D[6]=64        D[7]=128     D[8]=128      D[9]=256    D[10]=128    D[11]=256    D[12]=256    D[13]=512    D[14]=256    D[15]=512    D[16]=256    D[17]=512

	//                                                         FEATURE-EXTRACTION   | DETECTION
	//                conv         conv          conv          conv         conv          conv          conv          route conv reorg route conv conv detection
	// ...-> 13x13x512 -> 13x13x1024 -> 13x13x512 -> 13x13x1024 -> 13x13x512 -> 13x13x1024 -> 13x13x1024 -> 13x13x1024 -> 
	//       D[18]=512    D[19]=1024    D[20]=512    D[21]=1024    D[22]=512    D[23]=1024    D[24]=1024    D[25]=1024

	// =========================================================================================================================================
	// =========================================================================================================================================

const size_t R[26] = { 416, 416, 208, 208, 104, 104, 104, 104, 52, 52, 52, 52, 26, 26, 26, 26, 26, 26,13,13,13,13,13,13,13,13 }; // Rows    in each 2D matrix slice in each 3D feature map
const size_t C[26] = { 416, 416, 208, 208, 104, 104, 104, 104, 52, 52, 52, 52, 26, 26, 26, 26, 26, 26,13,13,13,13,13,13,13,13 }; // Columns in each 2D matrix slice in each 3D feature map
	const size_t K = 3; // Filter size

	size_t D[25];
	D[0] = 3;
	D[1] = 32;
	D[2] = 32;
	D[3] = 64;
	D[4] = 64;
	D[5] = 128;
	D[6] = 64;
	D[7] = 128;
	D[8] = 128;
	D[9] = 256;
	D[10] = 128;
	D[11] = 256;
	D[12] = 256;
	D[13] = 512;
	D[14] = 256;
	D[15] = 512;
	D[16] = 256;
	D[17] = 512;
	D[18] = 512;
	D[19] = 1024;
	D[20] = 512;
	D[21] = 1024;
	D[22] = 512;
	D[23] = 1024;
	D[24] = 1024;
	D[25] = 1024;


	FeatureMap X(R[0], C[0], D[0]);     X.count();
	Tensor H1(D[1], D[0], K, K); /* */ H1.ones(); // Layer 1
	//Tensor H2(D[2], D[1], K, K); /* */ H2.ones(); // Layer 2 - Pool
	Tensor H3(D[3], D[2], K, K); /* */ H3.ones(); // Layer 3
	//Tensor H4(D[4], D[3], K, K); /* */ H4.ones(); // Layer 4 - Pool
	Tensor H5(D[5], D[4], K, K); /* */ H5.ones(); // Layer 5
	Tensor H6(D[6], D[5], K, K); /* */ H6.ones(); // Layer 6
	Tensor H7(D[7], D[6], K, K); /* */ H7.ones(); // Layer 7
	Tensor H8(D[8], D[7], K, K); /* */ H8.ones(); // Layer 8
	//Tensor H9(D[9], D[8], K, K); /* */ H9.ones(); // Layer 9 - Pool

	// Start CPU Timing
	LARGE_INTEGER start_CPU, end_CPU, frequency_CPU;
	double milliseconds_CPU, seconds_CPU, minutes_CPU;
	QueryPerformanceFrequency(&frequency_CPU);
	QueryPerformanceCounter(&start_CPU);

	// |-----------section 1-----------|--------section 2---------|------------------------section 3------------------------|
	//         conv           max           conv          max           conv           conv          conv            max          conv         conv        conv          max         conv          conv         conv         conv         conv         max 
	// 416x416x3 -> 416x416x32 -> 208x208x32 -> 208x208x64 -> 104x104x64 -> 104x104x128 -> 104x104x64 ->  104x104x128 -> 52x52x128 -> 52x52x256 -> 52x52x128 -> 52x52x256 -> 26x26x256 -> 26x26x512 -> 26x26x256 -> 26x26x512 -> 26x26x256 -> 26x26x512 -> ...
	//  D[0]=3       D[1]=32        D[2]=32       D[3]=64       D[4]=64       D[5]=128       D[6]=64        D[7]=128     D[8]=128      D[9]=256    D[10]=128    D[11]=256    D[12]=256    D[13]=512    D[14]=256    D[15]=512    D[16]=256    D[17]=512

	// -----------
	// Section 1:
	// -----------
	cout << "Section 1 - "<<R[0]<<"x"<<C[0]<<"x"<<D[0]<<" -> " << R[1] << "x" << C[1] << "x" << D[1] << " -> " << R[2] << "x" << C[2] << "x" << D[2] << "\n";
	cout << "From Darknet: 416x416x3 -> 416x416x32 -> 208x208x32 \n";
	FeatureMap A1 = pool_max(relu(conv(X, H1)));

	// -----------
	// Section 2:
	// -----------
	cout << "\nSection 2: - " << R[2] << "x" << C[2] << "x" << D[2] << " -> " << R[3] << "x" << C[3] << "x" << D[3] << " -> " << R[4] << "x" << C[4] << "x" << D[4] << "\n";
	cout << "From Darknet: 208x208x32 -> 208x208x64 -> 104x104x64 \n";
	FeatureMap A3 = pool_max(relu(conv(A1, H3)));

	// -----------
	// Section 3:
	// -----------
	cout << "\nSection 3: - " << R[4] << "x" << C[4] << "x" << D[4] << " -> " << R[5] << "x" << C[5] << "x" << D[5] << " -> " << R[6] << "x" << C[6] << "x" << D[6] 
		<< " -> " << R[7] << "x" << C[7] << "x" << D[7] << " -> " << R[8] << "x" << C[8] << "x" << D[8] << "\n";
	cout << "From Darknet: 104x104x64 -> 104x104x128 -> 104x104x64 ->  104x104x128 -> 52x52x128 \n";
	FeatureMap A5 = relu(conv(A3, H5));
	FeatureMap A6 = relu(conv(A5, H6));
	FeatureMap A7 = relu(conv(A6, H7));
	FeatureMap A8 = relu(conv(A7, H8));
	FeatureMap A9 = pool_max(A8);

	// End CPU Timing
	QueryPerformanceCounter(&end_CPU);
	milliseconds_CPU = (end_CPU.QuadPart - start_CPU.QuadPart) *
		1000.0 / frequency_CPU.QuadPart;
	seconds_CPU = milliseconds_CPU / 1000;
	minutes_CPU = seconds_CPU / 60;
	fprintf(stderr, "\nCPU Time = %.3f milliseconds", milliseconds_CPU);
	fprintf(stderr, "\nCPU Time = %.3f seconds", seconds_CPU);
	fprintf(stderr, "\nCPU Time = %.3f minutes\n\n", minutes_CPU);

	getchar();
	return 0;
}
