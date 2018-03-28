#include <iostream>
#include <random>
#include <cilk/cilk.h>
#include <cilk/cilk_api.h>
#include <xmmintrin.h>  // Need this for SSE compiler intrinsics
//#include <windows.h>
using namespace std;

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
void saxpy_tbb(
	int n,
	float a,
	const float x[],
	const float y[],
	float z[])
{

	for (size_t i = 0; i < n; i++) {
		y[i] = a * x[i] + y[i];
	}
}
//===============================
// Serial add
void serial_add(
	size_t n,
	const float x[],
	float y[])
{
	for (size_t i = 0; i < n; ++i)
		y[i] = x[i] + y[i];
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
	float alpha = 2.0f;
	const int LENGTH = 8;

	float arr1[LENGTH] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	float arr2[LENGTH] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	float arr3[LENGTH] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	float arr4[LENGTH] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	float arr5[LENGTH] = { 1, 2, 3, 4, 5, 6, 7, 8 };

	/// Add same 4 values
	// Replicate 1.0f to all SIMD lanes
	__m128 valueA = _mm_set1_ps(1.0f); //0x3f800000
	__m128 valueB = _mm_set1_ps(2.0f); //0x40000000

	// Add the registers and store back into regular array:
	float z[LENGTH];

	// SSE Length-8 Vector addition
	sse_add(LENGTH, arr1, arr2);
	std::cout << "Length-8 SIMD vector add: ";
	print(LENGTH, arr2);

	// SSE Length-8 SAXPY:
	saxpy_sse(LENGTH, alpha, arr1, arr3);

	// SAXPY with OpenMP:
	saxpy_openmp(LENGTH, alpha, arr1, arr4);

	// Serial SAXPY:
	saxpy_serial(LENGTH, alpha, arr1, arr5);

	std::cout << "SIMD SAXPY: ";
	print(LENGTH, arr3);

	std::cout << "OpenMP saxpy: ";
	print(LENGTH, arr4);

	std::cout << "Serieal SAXPY: ";
	print(LENGTH, arr5);

	return EXIT_SUCCESS;
}
