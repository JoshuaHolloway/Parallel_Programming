#include <iostream>			
#include <random>
#include <cilk/cilk.h>
#include <cilk/cilk_api.h>
#include <xmmintrin.h>  // Need this for SSE compiler intrinsics
using namespace std;

long function (int slowDown[], long i);

const long SIZE = 4;
const long SLOWDOWNSIZE = 256;

int slowdown[SIZE][SLOWDOWNSIZE];

float arrayA[SIZE];
float arrayB[SIZE];
//===============================
double L1_error(size_t n, const float x[], const float y[]) {
	double sum = 0.0;
	for (int i = 0; i < n; i++)
		sum += std::abs(x[i] - y[i]);
	return sum;
}
//===============================
void print(
	size_t n,
	const float x[])
{
	for (size_t i = 0; i < n; ++i)
		cout << x[i] << " ";
	cout << "\n";
}
//===============================
// Serial SAXPY
void saxpy_serial(
	size_t n,
	float a,
	const float x[],
	float y[])
{
	for (size_t i = 0; i < n; ++i)
		y[i] = a * x[i] + y[i];
}
//===============================
void saxpy_openmp(
	int n,
	float a,
	const float x[],
	float y[]
) {
#pragma omp parallel for
	for (size_t i = 0; i < n; i++) {
		y[i] = a * x[i] + y[i];
	}
}
//===============================
void saxpy_sse(
	const size_t n,
	float alpha,
	const float x[],
	float* y)
{
	assert(0 == n % 4); // n must be a multiple of 4
	__m128 vec1, vec2, alpha_vec, sum, product;
	for (size_t i = 0; i < n; i += 4) {
		vec1 = _mm_loadu_ps(&x[i]); // load 4 elements from a
		vec2 = _mm_loadu_ps(&y[i]); // load 4 elements from b

		alpha_vec = _mm_set1_ps(alpha); // replicate alpha to all 4 SIMD lanes

		product = _mm_mul_ps(alpha_vec, vec1);	// multiply 4 values elementwise  (alpha * x)
		sum = _mm_add_ps(product, vec2);
		_mm_store_ps(&y[i], sum);
	}
}
//===============================
void sse_add(
	const size_t n,
	const float x[],
	float* y)
{
	assert(0 == n % 4); // n must be a multiple of 4
	__m128 vec1, vec2, sum;
	
	// Currently only works on 4 elements 
	for (size_t i = 0; i < n; i += 4) {
		vec1 = _mm_loadu_ps(&x[i]); // load 4 elements from a
		vec2 = _mm_loadu_ps(&y[i]); // load 4 elements from b
		
		sum = _mm_add_ps(vec1, vec2);
		_mm_store_ps(&y[i], sum);
	}
}
//===============================
int main ()
{
#include <Windows.h>
#include <time.h>
#include <ctime>
#include <windows.h>
	typedef unsigned long long LARGE_INTEGER;
	typedef unsigned long DWORD;
	typedef long HRESULT;
	LARGE_INTEGER StartingTime, EndingTime, ElapsedMicroseconds;
	LARGE_INTEGER Frequency;

	QueryPerformanceFrequency(&Frequency);
	QueryPerformanceCounter(&StartingTime);

	// Activity to be timed

	QueryPerformanceCounter(&EndingTime);
	ElapsedMicroseconds.QuadPart = EndingTime.QuadPart - StartingTime.QuadPart;


	//
	// We now have the elapsed number of ticks, along with the
	// number of ticks-per-second. We use these values
	// to convert to the number of elapsed microseconds.
	// To guard against loss-of-precision, we convert
	// to microseconds *before* dividing by ticks-per-second.
	//

	ElapsedMicroseconds.QuadPart *= 1000000;
	ElapsedMicroseconds.QuadPart /= Frequency.QuadPart;



	float alpha = 2.0f;
	float arr1[2 * SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	float arr2[2 * SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	float arr3[2 * SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	float arr4[2 * SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	float arr5[2 * SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8 };

	/// Add same 4 values 
	// Replicate 1.0f to all SIMD lanes 
	__m128 valueA = _mm_set1_ps(1.0f); //0x3f800000
	__m128 valueB = _mm_set1_ps(2.0f); //0x40000000

	// Add the registers and store back into regular array:
	float z[SIZE];
	__m128 sum = _mm_add_ps(valueA, valueB);
	_mm_store_ps(z, sum);
	std::cout << "Length-4 SIMD vector add: z = ";
	print(SIZE, z);
		
	// SSE Length-8 Vector addition
	sse_add(2 * SIZE, arr1, arr2);
	std::cout << "Length-8 SIMD vector add: ";
	print(2 * SIZE, arr2);


	// SSE Length-8 SAXPY:
	saxpy_sse(2 * SIZE, alpha, arr1, arr3);

	// SAXPY with OpenMP:
	saxpy_openmp(2 * SIZE, alpha, arr1, arr4);

	// Serial SAXPY:
	saxpy_serial(2 * SIZE, alpha, arr1, arr5);
		
	std::cout << "SIMD SAXPY: ";
	print(2 * SIZE, arr3);

	std::cout << "OpenMP saxpy: ";
	print(2 * SIZE, arr4);

	std::cout << "Serieal SAXPY: ";
	print(2 * SIZE, arr5);

	// Run SAXPY on much larger array:
	const int largeArraySize = 1000 * SIZE;
	float arr6[largeArraySize];
	float arr7[largeArraySize];
	for (int i = 0; i < largeArraySize; i++)
		arr6[i] = arr7[i] = i;

	// Run many times for profiler
	for (size_t i = 0; i < 100000; i++)
	{
		saxpy_sse(largeArraySize, alpha, arr5, arr6);

		saxpy_openmp(largeArraySize, alpha, arr5, arr6);

		saxpy_serial(largeArraySize, alpha, arr5, arr6);
	}

	//getchar();
	return EXIT_SUCCESS;
}