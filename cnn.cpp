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
//-------------------------------------------------------------------
#define ROWS               5 // Height of 3D Feature Map
#define COLS               5 // Width of 3D Feature Map
#define N0                 3 // Number of input feature map channels
#define N1                 2 // Number of output feature map channels
#define P                  1 // Zero pad size
#define K                  (2 * P + 1) // Height and Width of square filter kernel
#define S  1 // Stride
#define ROWS_ZP            (ROWS + 2 * P)
#define COLS_ZP            (COLS + 2 * P)

#define BYTES_2D_IMAGE     (sizeof(float) * COLS * ROWS)
#define BYTES_3D_FM0       (sizeof(float) * COLS * ROWS * N0)
#define BYTES_3D_FM1       (sizeof(float) * COLS * ROWS * N1)
#define BYTES_4D_KERNEL    (sizeof(float) * K * K * N0 * N1)
#define ZP_AREA            (ZERO_PADDED_WIDTH * ZERO_PADDED_HEIGHT)
#define ZP_VOLUME          (N0 * (ROWS + 2 * P) * (COLS + 2 * P))
#define BYTES_3D_FM0_ZP (sizeof(float) * ZP_VOLUME)
//===================
template <typename T>
class Tensor
{
public:
protected:
	T * tensor = nullptr;
	size_t rows{ 0 };
private:
};
//-------------------
template <typename T>
class Vector : Tensor<T> {
public:
	using Tensor<T>::tensor;

	Vector() = default;
	Vector(size_t rows)
		: rows(rows) {
		tensor = new T[rows];
		for (size_t i = 0; i < rows; ++i) {
			tensor[i] = i;
		}
	} 
	Vector(size_t rows, string ones) : rows(rows) {
		tensor = new T[rows];
		for (int i = 0; i < rows; ++i)
		{
			tensor[i] = 1;
		}
	}
	~Vector() {
		delete[] tensor;
	}
	void print()
	{
		for (int i = 0; i < rows; ++i)
		{
			cout << tensor[i] << " ";
		}
		cout << "\n";
	}
private:
	size_t rows{ 0 };
};
//-------------------
template <typename T>
class FeatureMap {
public:
	FeatureMap() {}
	FeatureMap(size_t rows, size_t cols, size_t chs)
		: rows(rows), cols(cols), chs(chs) {
		fm = new T[rows * cols * chs];
		for (size_t i = 0; i < rows; ++i) {
			for (size_t j = 0; j < cols; ++j) {
				for (size_t k = 0; k < chs; ++k) {
					fm[i * cols * chs + j * chs + k] = i * cols * chs + j * chs + k;
				}
			}
		}
	}
	~FeatureMap() {
		delete[] fm;
	}
	float at(size_t x, size_t y, size_t z) {
		return fm[x * cols * chs + y * chs + z];
	}
	void print() {
	}
	size_t get_rows() { return rows; }
	size_t get_cols() { return cols; }
	size_t get_chs()	{ return chs; }
	size_t get_filts(){ return filts; }

private:
	size_t rows{ 0 }; // dim 1
	size_t cols{ 0 }; // dim 2
	size_t chs{ 0 };	// dim 3
	size_t filts{ 0 };// dim 4
	T* fm = nullptr;
};
//===================
template <typename T>
class A
{
protected:
	int a{0};
};
//-------------------
template <typename T>
class B : A<T>
{
public:
	int get_a()
	{
		return A<T>::a;
	}
};
//==========================================
// Functions for creating synthetic tensors:
template <class T, size_t dim1, size_t dim2>
void create_synthetic_tensor_rank2(T(&arr_rank2)[dim1][dim2])
{
	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; ++j) {
			arr_rank2[i][j] = (i * COLS + j);
		}
	}
}
//=======================================================
template <class T, size_t dim1, size_t dim2, size_t dim3>
void create_synthetic_tensor_3D(T(&arr_3D)[dim1][dim2][dim3])
{
	for (int i = 0; i < N0; ++i) {
		for (int j = 0; j < ROWS; ++j) {
			for (int k = 0; k < COLS; ++k) {
				arr_3D[i][j][k] = ((i * COLS * ROWS) + (j * COLS) + k);
			}
		}
	}
}
//====================================================================
template <class T, size_t dim1, size_t dim2, size_t dim3, size_t dim4>
void create_synthetic_tensor_rank4(T(&arr_rank4)[dim1][dim2][dim3][dim4])
{
	for (int i = 0; i < N1; ++i) {
		for (int j = 0; j < N0; ++j) {
			for (int k = 0; k < K; ++k) {
				for (int l = 0; l < K; ++l) {
					arr_rank4[i][j][k][l]
						= ((i * K * K * N0)
							+ (j * K * K)
							+ (k * K) + l);
				}
			}
		}
	}
}
//====================================
// Function to create a 3D box-filter:
template <class T, size_t dim1, size_t dim2, size_t dim3, size_t dim4>
void create_4D_box_filter(T(&arr_rank4)[dim1][dim2][dim3][dim4])
{
	for (int i = 0; i < N1; ++i) {
		for (int j = 0; j < N0; ++j) {
			for (int k = 0; k < K; ++k) {
				for (int l = 0; l < K; ++l) {
					arr_rank4[i][j][k][l] = 1;
				}
			}
		}
	}
}
//=========================================================================
// Function for complete working single layer naive conv net:
template <class T, size_t image_dim1, size_t image_dim2, size_t image_dim3>
void single_layer_conv_net_naive_test(T(&output_fm)[image_dim1][image_dim2][image_dim3]) // Golden reference (NEED TO DOUBLE CHECK THIS IS CORRECT!!!)
{
	// The indexing formula is given by the multiplication of any given dimension 
	//	value with the product of all the previous dimensions.

	// Index = xn(D1 * ... * D{ n - 1 }) + x{ n - 1 } (D1 * ... * D{ n - 2 }) + ... + x2 * D1 + x1
	// So for 4D:
	//	index = x + y * D1 + z * D1 * D2 + t * D1 * D2 * D3;

	// x = Index % D1;
	// y = ((Index - x) / D1) % D2;
	// z = ((Index - y * D1 - x) / (D1 * D2)) % D3;
	// t = ((Index - z * D2 * D1 - y * D1 - x) / (D1 * D2 * D3)) % D4;
	/* Technically the last modulus is not required,
	since that division SHOULD be bounded by D4 anyways... */

	//The general formula being of the form
	//	xn = ((Index - Index(x1, ..., x{ n - 1 })) / Product(D1, ..., D{ N - 1 })) % Dn

	// Input Feature Map - Rank 3 Tensor (3x5x5)																									 
	const int input_fm[N0][ROWS][COLS] =
	{
		{
			{ 0,  1,  2,  3,  4 },
			{ 5,  6,  7,  8,  9 },
			{ 10, 11, 12, 13, 14 },
			{ 15, 16, 17, 18, 19 },
			{ 20, 21, 22, 23, 24 }
		},
		{
			{ 25, 26, 27, 28, 29 },
			{ 30, 31, 32, 33, 34 },
			{ 35, 36, 37, 38, 39 },
			{ 40, 41, 42, 43, 44 },
			{ 45, 46, 47, 48, 49 }
		},
		{
			{ 50, 51, 52, 53, 54 },
			{ 55, 56, 57, 58, 59 },
			{ 60, 61, 62, 63, 64 },
			{ 65, 66, 67, 68, 69 },
			{ 70, 71, 72, 73, 74 }
		}
	};

	// Initiailize Zero Padded Input Feature Map - Rank 3 Tensor (3x7x7)
	int zp_input_fm[N0][ROWS_ZP][COLS_ZP];
	for (int i = 0; i < N0; i++)
		for (int j = 0; j < ROWS_ZP; j++)
			for (int k = 0; k < COLS_ZP; k++)
				zp_input_fm[i][j][k] = 0;

	// Zero Pad Input Feature Map - Rank 3 Tensor (3x7x7)
	for (int i = 0; i < N0; i++)
		for (int j = P; j < ROWS + P; j++)
			for (int k = P; k < COLS + P; k++)
				zp_input_fm[i][j][k] = input_fm[i][j - P][k - P];

	// Initialize kernel - Rank-4 Tensor (2x3x3x3)
	const int weights[N1][N0][K][K] =
	{
		{
			{
				{ 0, 1, 2 },
				{ 3, 4, 5 },
				{ 6, 7, 8 }
			},
			{
				{ 9, 10, 11 },
				{ 12, 13, 14 },
				{ 15, 16, 17 }
			},
			{
				{ 18, 19, 20 },
				{ 21, 22, 23 },
				{ 24, 25, 26 }
			}
		},
		{
			{
				{ 27, 28, 29 },
				{ 30, 31, 32 },
				{ 33, 34, 35 }
			},
			{
				{ 36, 37, 38 },
				{ 39, 40, 41 },
				{ 42, 43, 44 }
			},
			{
				{ 45, 46, 47 },
				{ 48, 49, 50 },
				{ 51, 52, 53 }
			}
		}
	};

	// Allocate and Initialize Output Feature Map - Rank 3 Tensor (2x5x5)
	for (int i = 0; i < N1; i++)
		for (int j = 0; j < ROWS; j++)
			for (int k = 0; k < COLS; k++)
				output_fm[i][j][k] = 0;

	// Bias:
	const int B[N1] = { 0, 0 };

	// Do Convolution
	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLS; col++) {
			for (int to = 0; to < N1; to++) {
				for (int ti = 0; ti < N0; ti++) {
					for (int i = 0; i < K; i++) {
						for (int j = 0; j < K; j++) {
							output_fm[to][row][col] += weights[to][ti][i][j] * zp_input_fm[ti][S*row + i][S*col + j];
						} // End loop over j
					} // End loop over i
				} // End loop over ti
				output_fm[to][row][col] += B[to]; // Add Bias:
				if (output_fm[to][row][col] < 0) // ReLu Activation function:
					output_fm[to][row][col] = 0;
			} // End loop over to
		} // End loop over col
	} // End loop over row

		// Print output feature map
	for (int i = 0; i < N1; i++) {
		std::cout << "Output Feature Map " << i << ":\n\n";
		for (int j = 0; j < ROWS; j++) {
			for (int k = 0; k < COLS; k++)
				std::cout << output_fm[i][j][k] << " ";
			printf("\n");
		}
		printf("\n\n");
	}
}
//========
int main()
{
	//     conv      pool
	// 4x4x1 -> 4x4x2 -> 2x2x2
	const size_t R[3] = { 4, 4, 2 };
	const size_t C[3] = { 4, 4, 2 };
	const size_t D[3] = { 1, 2, 2 };

	FeatureMap<float> fm(R[0], C[0], D[0]);
	
	for (size_t i = 0; i < fm.get_rows(); ++i) {
		for (size_t j = 0; j < fm.get_cols(); ++j) {
			for (size_t k = 0; k < fm.get_chs(); ++k) {
				cout << fm.at(i, j, k) << " ";
			}
		}
		cout << endl;
	}


	Vector<float> x(3);
	x.print();

	Vector<float> h(3, "ones");
	h.print();

	getchar();
	return 0;
}
