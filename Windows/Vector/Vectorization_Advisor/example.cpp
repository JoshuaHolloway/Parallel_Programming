#include <iostream>			
#include <random>
#include <cilk/cilk.h>
#include <cilk/cilk_api.h>
#include <xmmintrin.h>  // Need this for SSE compiler intrinsics
#include <windows.h>
using namespace std;

long function(int slowDown[], long i);


//===============================
class CTimer
{
public:
	CTimer() {
		QueryPerformanceFrequency(&mqFreq);
	}
	~CTimer() {}

	void Start() {
		QueryPerformanceCounter(&mqStart);
	}
	void End() {
		QueryPerformanceCounter(&mqEnd);
	}
	double GetTimeInSeconds() {
		return (mqEnd.QuadPart - mqStart.QuadPart) / (double)mqFreq.QuadPart;
	}
	double GetTimeInMilliseconds() {
		return (1.0e3*(mqEnd.QuadPart - mqStart.QuadPart)) / mqFreq.QuadPart;
	}
	double GetTimeInMicroseconds() {
		return (1.0e6*(mqEnd.QuadPart - mqStart.QuadPart)) / mqFreq.QuadPart;
	}
	double GetTimeInNanoseconds() {
		return (1.0e9*(mqEnd.QuadPart - mqStart.QuadPart)) / mqFreq.QuadPart;
	}
private:
	LARGE_INTEGER mqStart;
	LARGE_INTEGER mqEnd;
	LARGE_INTEGER mqFreq;
};
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
int main()
{


	/*
	float arr1[2 * LENGTH] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	float arr2[2 * LENGTH] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	float arr3[2 * LENGTH] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	float arr4[2 * LENGTH] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	float arr5[2 * LENGTH] = { 1, 2, 3, 4, 5, 6, 7, 8 };

	/// Add same 4 values
	// Replicate 1.0f to all SIMD lanes
	__m128 valueA = _mm_set1_ps(1.0f); //0x3f800000
	__m128 valueB = _mm_set1_ps(2.0f); //0x40000000

	// Add the registers and store back into regular array:
	float z[LENGTH];
	__m128 sum = _mm_add_ps(valueA, valueB);
	_mm_store_ps(z, sum);
	std::cout << "Length-4 SIMD vector add: z = ";
	print(LENGTH, z);

	// SSE Length-8 Vector addition
	sse_add(2 * LENGTH, arr1, arr2);
	std::cout << "Length-8 SIMD vector add: ";
	print(2 * LENGTH, arr2);

	// SSE Length-8 SAXPY:
	saxpy_sse(2 * LENGTH, alpha, arr1, arr3);

	// SAXPY with OpenMP:
	saxpy_openmp(2 * LENGTH, alpha, arr1, arr4);

	// Serial SAXPY:
	saxpy_serial(2 * LENGTH, alpha, arr1, arr5);

	std::cout << "SIMD SAXPY: ";
	print(2 * LENGTH, arr3);

	std::cout << "OpenMP saxpy: ";
	print(2 * LENGTH, arr4);

	std::cout << "Serieal SAXPY: ";
	print(2 * LENGTH, arr5);

	// Run SAXPY on much larger array:
	const int LENGTH = 4 * LENGTH;
	float arr6[LENGTH];
	float arr7[LENGTH];
	for (int i = 0; i < LENGTH; i++)
	arr6[i] = arr7[i] = i;

	*/


	float alpha = 2.0f;
	const long LENGTH = 65536;
	float arrayA[LENGTH];
	float arrayB[LENGTH];
	double ms_serial = 0.0, ms_sse = 0.0;
	size_t TEST_NUM = 1;
	for (size_t test_num = 0; test_num < TEST_NUM; test_num++)
	{
		// Timer
		CTimer qTimer;

		// Run many times for profiler
		size_t num_itters = 100000;
		double average_time = 0.0;

		float arr5[LENGTH];
		float arr6[LENGTH];

		// SAXPY - serial 
		qTimer.Start();  // Begin timer
		for (size_t i = 0; i < num_itters; i++)
		{
			saxpy_serial(LENGTH, alpha, arr5, arr6);
		}
		qTimer.End(); // End timer
		ms_serial += qTimer.GetTimeInMilliseconds();
		//cout << qTimer.GetTimeInMilliseconds() << " milliseconds" << endl;
		//cout << qTimer.GetTimeInMicroseconds() << " microseconds" << endl;
		//cout << qTimer.GetTimeInNanoseconds() << " nanoseconds" << endl;
		//average_time = qTimer.GetTimeInMicroseconds() / num_itters;
		//cout << "average time for serial = " << average_time;
		//std::cout << "\n\n\n";

		// SAXPY - SSE
		qTimer.Start();  // Begin timer
		for (size_t i = 0; i < num_itters; i++)
		{
			saxpy_sse(LENGTH, alpha, arr5, arr6);
		}
		qTimer.End(); // End timer
		ms_sse += qTimer.GetTimeInMilliseconds();
		//cout << qTimer.GetTimeInMilliseconds() << " milliseconds" << endl;
		//cout << qTimer.GetTimeInMicroseconds() << " microseconds" << endl;
		//cout << qTimer.GetTimeInNanoseconds() << " nanoseconds" << endl;
		//average_time = qTimer.GetTimeInMicroseconds() / num_itters;
		//cout << "average time for SSE = " << average_time;
		//std::cout << "\n\n\n";

		// SAXPY - serial 
		qTimer.Start();  // Begin timer
		for (size_t i = 0; i < num_itters; i++)
		{
			saxpy_openmp(LENGTH, alpha, arr5, arr6);
		}
		qTimer.End(); // End timer
									//cout << qTimer.GetTimeInMilliseconds() << " milliseconds" << endl;
									//cout << qTimer.GetTimeInMicroseconds() << " microseconds" << endl;
									//cout << qTimer.GetTimeInNanoseconds() << " nanoseconds" << endl;
									//average_time = qTimer.GetTimeInMicroseconds() / num_itters;
									//cout << "average time for openMP = " << average_time;
									//std::cout << "\n\n\n";
	}
	double ms_serial_ave = ms_serial / TEST_NUM;
	double ms_sse_ave = ms_sse / TEST_NUM;
	std::cout << "ms_serial_ave at num_elems = " << LENGTH << " = " << ms_serial_ave << "\n";
	std::cout << "ms_sse_ave at num_elems = " << LENGTH << " = " << ms_sse_ave << "\n";



	getchar();
	return EXIT_SUCCESS;
}