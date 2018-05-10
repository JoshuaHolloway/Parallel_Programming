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
	size_t get_rows()
	{
		return Tensor<T>::rows;
	}
	T at(size_t idx)
	{
		return tensor[idx];
	}

	// y = h.conv(x);
	Vector conv(Vector x) // Probably should be Vector&
	{
		// Input:  Vector x of length M
		// Output: Vector y of length N
		// Operation performed: y = conv(x, h) of length M + N - 1
		//	where h is the filter kernel stored 
		//	in the internal state of the object 
		//	that is the instantiation of this class

		// Grab sizes of input arrays
		const size_t M = x.get_rows();
		const size_t N = rows;  // length of fitler kernel

		// Allocate memory for output
		//T* y = new T[M + N - 1]; // Column vector
		Vector y(M + N - 1, "ones");

		T tempx1 = x.at(0);
		T temph1 = tensor[0];
		cout << "x.at(0) = " << tempx1 << " and tensor[0] = " << temph1 << "\n";

		return y;
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
	size_t get_chs() { return chs; }
	size_t get_filts() { return filts; }

private:
	size_t rows{ 0 }; // dim 1
	size_t cols{ 0 }; // dim 2
	size_t chs{ 0 };	// dim 3
	size_t filts{ 0 };// dim 4
	T* fm = nullptr;
};
//===================
template <typename T>
Vector<T> conv(Vector<T> x, Vector<T> h)
{
	auto M = x.get_rows();
	auto N = h.get_rows();
	Vector<T> y(M + N - 1);
	//for (int i = 0; i < M; ++i)
		
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

	// THIS IS WHAT WE WANT:
	// y = h.conv(x);

	Vector<float> y;
	//y = h.conv(x);

	const int width = 3;
	const int mask_width = 3;
	int xarr[width] = { 1, 2, 3 };
	int harr[mask_width] = { 1, 1, 1 };
	int yarr[width];

	for (int i = 0; i < width; ++i)
	{
		float Pvalue = 0.0f;
		int N_start_point = i - mask_width / 2;
		for (int j = 0; j < mask_width; j++)
		{
			if(N_start_point + j >= 0 && N_start_point + j < width)
			{
				Pvalue += xarr[N_start_point + j] * harr[j];
			}
		}
		yarr[i] = Pvalue;
	}

	for (int i = 0; i < width; i++)
		cout << yarr[i] << " ";
	cout << "\n";
	
	getchar();
	return 0;
}
