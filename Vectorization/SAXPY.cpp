#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <cilk/cilk.h>
#include <cilk/cilk_api.h>
#include <xmmintrin.h>  // Need this for SSE compiler intrinsics
#include <omp.h>	// Open-MP

using std::cout;

/* Consider adjusting LOOP_COUNT based on the performance of your computer */
/* to make sure that total run time is at least 1 second */
#define LOOP_COUNT 10
//===============================
void saxpy_serial(
	size_t n,
	float a,
	const float x[],
	const float y[],
	float z[])
{
	for (size_t i = 0; i < n; ++i)
		z[i] = a * x[i] + y[i];
}
//===============================
void saxpy_openmp(
	size_t n,
	float a,
	const float x[],
	const float y[],
	float z[])
 {
#pragma omp parallel for
	for (size_t i = 0; i < n; i++) {
		z[i] = a * x[i] + y[i];
	}
}
//===============================
void saxpy_sse(
	const size_t n,
	float alpha,
	const float x[],
	const float y[],
	float z[])
{
	assert(0 == n % 4); // n must be a multiple of 4
	__m128 vec1, vec2, alpha_vec, sum, product;
	for (size_t i = 0; i < n; i += 4) {
		vec1 = _mm_loadu_ps(&x[i]); // load 4 elements from a
		vec2 = _mm_loadu_ps(&y[i]); // load 4 elements from b

		alpha_vec = _mm_set1_ps(alpha); // replicate alpha to all 4 SIMD lanes

		product = _mm_mul_ps(alpha_vec, vec1);	// multiply 4 values elementwise  (alpha * x)
		sum = _mm_add_ps(product, vec2);
		_mm_store_ps(&z[i], sum);
	}
}
//===============================
void saxpy_cilk(
	int n,
	float a,
	const float x[],
	const float y[],
	float z[])
{
	z[0:n] = a * x[0:n] + y[0:n];
}
//===============================
/*
void saxpy_tbb( // tiled - see page 126
	int n,
	float a,
	const float x[],
	const float y[],
	float z[])
{
	using tbb::parallel_for;
	using tbb::blocked_range;
	parallel_for(
		blocked_range<int>(0, n),
		[&](blocked_range)<int> r)
		{
			for(size_t i = r.begin(); i != r.end(); i++)
				z[i] = a * x[i] + y[i];
		}
	);
}
*/
//===============================
//===============================
float dot_serial(
	size_t n,
	const float x[],
	const float y[])
{
	float sum = 0.0f;
	for (size_t i = 0; i < n; ++i)
		sum += x[i] * y[i];
	return sum;
}
//===============================
float dot_sse(
	const size_t n,
	const float x[],
	const float y[])
{
	assert(0 == n % 4); // n must be a multiple of 4
	__m128 accumulate, product, vec1, vec2;
	accumulate = _mm_setzero_ps();


	// In each iteration:
	// a1  a2  a3  a4             }
	// *   *   *   *   _mm_add_ps } Loop
	// b1  b2  b3  b4             } over
	// =   =   =   =              } this
	// c1  c2  c3  c4             } part
	// +   +   +   +   _mm_add_ps }
	// s1  s2  s3  s4
	//  \ /     \ /
	//   t1      t2
	//    \     /
	//     result
	for (size_t i = 0; i < n; i += 4) {
		vec1 = _mm_loadu_ps(&x[i]); // load 4 elements from x
		vec2 = _mm_loadu_ps(&y[i]); // load 4 elements from y

		product = _mm_mul_ps(vec1, vec2);	// x * y
		accumulate = _mm_add_ps(accumulate, product); // s += x*y
	}
	product = _mm_setzero_ps();  // [0 0 0 0]
	accumulate = _mm_hadd_ps(accumulate, product); // [(s1+s2), (s3+s4), (0+0), (0+0)]
	accumulate = _mm_hadd_ps(accumulate, product); // [(s1+s2)+(s3+s4), 0, 0, 0]

	float result;
	_mm_store_ss(&result, accumulate);  // Extract left most element of accumulate

	return result;
}
//===============================
float dot_openmp(
	size_t n,
	const float x[],
	const float y[])
{
	float sum = 0.0f;
#pragma omp parallel for reduction(+:sum)
	for (size_t i = 0; i < n; ++i)
		sum += x[i] * y[i];
	return sum;
}
//===============================
float stencil_serial(
		size_t n,
		const float x[],
		float y[])
{
  // Filter kernel:
  float k00=-1, k01=-1, k02=-1;
  float k10=-1, k11= 8, k12=-1;
  float k20=-1, k21=-1, k22=-1;

  for (size_t i = 1; i < n-1; i++)
  {
    for (size_t j = 1; j < n-1; j++)
    {
      y[i * n + j] =
        k00*x[(i-1)*n + j-1] + k01*x[(i-1)*n + j] + k02*x[(i-1)*n + j+1] +
        k10*x[(i  )*n + j-1] + k11*x[(i  )*n + j] + k12*x[(i  )*n + j+1] +
        k20*x[(i+1)*n + j-1] + k21*x[(i+1)*n + j] + k22*x[(i+1)*n + j+1];
    }
  }
}
//===============================


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
int main()
{
	float alpha = 2.0f;
	const int LENGTH = 8;

	float arr1[LENGTH] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	float arr2[LENGTH] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	float arr3[LENGTH];

    struct timeval start, end;
    long total_time, seconds, useconds;

    gettimeofday(&start, NULL);

    saxpy_serial(LENGTH, alpha, arr1, arr2, arr3);
	cout << "Length-8 serial SAXPY: ";
	print(LENGTH, arr3);

	saxpy_openmp(LENGTH, alpha, arr1, arr2, arr3);
	cout << "Length-8 OpenMP SAXPY: ";
	print(LENGTH, arr3);

	saxpy_sse(LENGTH, alpha, arr1, arr2, arr3);
	cout << "Length-8 SSE SAXPY: ";
	print(LENGTH, arr3);

	saxpy_cilk(LENGTH, alpha, arr1, arr2, arr3);
	cout << "Length-8 Cilk SAXPY: ";
	print(LENGTH, arr3);


	// - - - - - - - - - - - - - - - - - - -
    float dot;
	dot = dot_serial(LENGTH, arr1, arr2);
	cout << "Serial dot-product: dot = " << dot << "\n";

	dot = dot_sse(LENGTH, arr1, arr2);
	cout << "SSE dot-product: dot = " << dot << "\n";

	dot = dot_openmp(LENGTH, arr1, arr2);
	cout << "OpenMP dot-product: dot = " << dot << "\n";

    gettimeofday(&end, NULL);

    seconds = end.tv_sec - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec ;
    total_time = ((seconds)*1000 + useconds/1000.0) + 0.5;

    printf("======Matrix multiplication using Intel(R) C++ Compiler is completed=====\n"
    		"==============at %ld milliseconds==========\n\n", total_time/LOOP_COUNT);
    printf("======Matrix multiplication using Intel(R) C++ Compiler is completed=====\n"
    		"==============at %ld milliseconds==========\n\n", total_time/LOOP_COUNT);


	#pragma omp parallel
    {
		cout << "omp_get_thread_num = " << omp_get_thread_num() << std::endl;
	}

    printf (" Example completed . \n\n");
    return 0;
}
