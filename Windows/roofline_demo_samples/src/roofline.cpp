#include <iostream>
#include <random>
#include <cstdio>
#include <cassert>
#include <cilk/cilk.h>
#include <cilk/cilk_api.h>
#include <tbb\parallel_for.h>
#include <xmmintrin.h>  // Need this for SSE compiler intrinsics
#include <stdio.h>
using namespace std;
#define REPEAT	(300000000)
#define SIZE	(8)
typedef vector<double> dynamic_array;
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
void saxpy_sse( // THIS HAS EXAMPLE CODE FROM THE VIDEO GAME GUY
	size_t n,
	float alpha,
	const float x[],
	float* y)
{
	assert(0 == n % 4); // n must be a multiple of 4
	__m128 res, prd, mx, my, m_alpha;
	for (size_t i = 0; i < n; i += 4) {
		mx = _mm_loadu_ps(&x[i]); // load 4 elements from a
		my = _mm_loadu_ps(&y[i]); // load 4 elements from b

		m_alpha = _mm_set1_ps(alpha); // replicate 1.0 to all 4 SIMD lanes

		prd = _mm_mul_ps(m_alpha, mx);	// multiply 4 values elementwise  (alpha * x)
		res = _mm_add_ps(prd, my); // y = alpha * x + y
	}
	//_mm_store_ss(&y, res);  - HOW TO STORE INTO ARRAY y?
}
//===============================
void saxpy_openmp(
	int n,
	float a,
	const float x[],
	float y[]
) {
#pragma omp parallel for
	for (int i = 0; i < n; i++) {
		y[i] = a * x[i] + y[i];
	}
}
//===============================
void saxpy_tbb(
	int n,
	float a,
	const float x[],
	float y[]
) {
	tbb::parallel_for(
		tbb::blocked_range<int>(0, n),
		[&](tbb::blocked_range<int> r) {
			for (size_t i = r.begin(); i != r.end(); ++i)
				y[i] = a * x[i] + y[i];
		} // end lambda
	); // end par-for
}
//===============================
//===============================
//===============================
//===============================
float sprod(
	size_t n,
	const float a[],
	const float b[]
)	{
	float res = 0.0f;
	for (size_t i = 0; i < n; i++) {
		res += a[i] * b[i];
	}
	return res;
}
//===============================
float sse_prod(
	size_t n,
	const float a[],
	const float b[])
{
	assert(0 == n % 4); // n must be a multiple of 4
	__m128 res, prd, ma, mb;
	for (size_t i = 0; i < n; i += 4) {
		ma = _mm_loadu_ps(&a[i]); // load 4 elements from a
		mb = _mm_loadu_ps(&b[i]); // load 4 elements from b
		prd = _mm_mul_ps(ma, mb);	// multiply 4 values elementwise 
		res = _mm_add_ps(prd, res); // accumulate partial sum over 4-tuples
	}
	prd = _mm_setzero_ps();
	res = _mm_hadd_ps(res, prd); // horizontal addition
	res = _mm_hadd_ps(res, prd); // horizontal addition
	float tmp;
	_mm_store_ss(&tmp, res);
	return tmp;
}
//===============================
//===============================
//===============================
//===============================

/*******************************/
/*        Control Panel        */
/*******************************/
//#define GROUP_1
#ifdef GROUP_1
    //#define G1_AOS_SCALAR
    #define G1_SOA_SCALAR
    //#define G1_SOA_VECTOR
#endif /************************/
//#define GROUP_2
#ifdef GROUP_2
    //#define G2_AOS_SCALAR
    //#define G2_SOA_SCALAR
    #define G2_SOA_VECTOR
#endif /************************/
//#define GROUP_3
#ifdef GROUP_3
    #define G3_AOS_SCALAR
    //#define G3_SOA_SCALAR
    //#define G3_AOS_VECTOR
    //#define G3_SOA_VECTOR
    //#define G3_SOA_VECTOR_FMAS
#endif /************************/
//#define GROUP_4
#ifdef GROUP_4
    #define G4_SOA
    //#define G4_AOSOA
#endif /************************/

#define MAXVALUE 1000000
#define ARRAY_SIZE_1 1328
#define REPEAT_1 10000000
#define ARRAY_SIZE_2 2000
#define REPEAT_2 30000000
#define UNROLL_COUNT 2

void setupArrays();

/********** Data Set 1 **********/
// Array of Structures
typedef struct S1_AoS
{
    double a;
    double b;
    double pad1;
    double pad2;
} S1_AoS;
double AoS1_X[ARRAY_SIZE_1];
S1_AoS AoS1_Y[ARRAY_SIZE_1];
// Structure of Arrays
typedef struct S1_SoA
{
    double a[ARRAY_SIZE_1];
    double b[ARRAY_SIZE_1];
    double pad1[ARRAY_SIZE_1];
    double pad2[ARRAY_SIZE_1];
} S1_SoA;
double SoA1_X[ARRAY_SIZE_1];
S1_SoA SoA1_Y;
/********** Data Set 2 **********/
// Structure of Arrays
typedef struct S2_SoA
{
    double a[ARRAY_SIZE_2];
    double b[ARRAY_SIZE_2];
} S2_SoA;
double SoA2_X[ARRAY_SIZE_2];
S2_SoA SoA2_Y;
// Array of Structure of Arrays
typedef struct AoSoA
{
    double a[ARRAY_SIZE_2 / 2];
    double b[ARRAY_SIZE_2 / 2];
} AoSoA;
double AoSoA_X[ARRAY_SIZE_2];
AoSoA AoSoA_Y[2]; 

int main()
{
	float x_sp[SIZE], y_sp[SIZE], alpha_sp = 2.0f;
	double x_dp[SIZE], y_dp[SIZE], alpha_dp = 2.0;
	dynamic_array x_dyn(SIZE), y_dyn(SIZE);
	double error = 0;
	
	// Initialize
	for (int i = 0; i < SIZE; i++)
	{
		x_dyn[i] = x_dp[i] = (rand() % 5000) + 1.0;
		y_dyn[i] = y_dp[i] = (rand() % 5000) + 1.0;
		x_sp[i] = i * 1.0f;// (rand() % 5000) + 1.0f;
		y_sp[i] = i * 1.0f;//(rand() % 5000) + 1.0f;
	}
	cout << "array 1: ";
	print(SIZE, x_sp);
	cout << "array 2: ";
	print(SIZE, y_sp);

	// ------- SAXPY -------
	// ------- SAXPY -------
	// ------- SAXPY -------

	// Run SERIAL-SAXPY
	float y_sp_gold[SIZE];
	//for (int r = 0; r < REPEAT; r++)
	saxpy_serial(SIZE, alpha_sp, x_sp, y_sp_gold);
	
	cout << "Golden ref:\n";
	print(SIZE, y_sp_gold);

	// Run SSE-SAXPY
	//for (int r = 0; r < REPEAT; r++)
		saxpy_sse(SIZE, alpha_sp, x_sp, y_sp);
	error = L1_error(SIZE, y_sp, y_sp_gold);
	// << "Error of SSE-SAXPY: " << error << "\n";
	
	// Run Open-MP-SAXPY
	//for (int r = 0; r < REPEAT; r++)
		saxpy_openmp(SIZE, alpha_sp, x_sp, y_sp);
	error = L1_error(SIZE, y_sp, y_sp_gold);
	cout << "Error of OpenMP-SAXPY: " << error << "\n";

	// Run TBB-SAXPY


	// Run Cilk-SAXPY
	

	// Run Cilk-SAXPY (with array notation)


	// Compare results:
	

	// ------- Dot-Product -------
	// ------- Dot-Product -------
	// ------- Dot-Product -------

	// pause
	getchar();

    //setupArrays();
    //cout << "Setup complete.\n";

    //############################## Group 1 ##############################//
    // Group 1 is a low arithmetic intensity algorithm intended to display
    // roofline behavior which may initially seem counter-intuitive.
    #ifdef GROUP_1
    cout << "####################### Group 1 #######################\n"
         << "    Algorithm: X = Ya + Yb\n    Data Set 1: " << ARRAY_SIZE_1 
         << " doubles/array.\n";
    #endif
    /******************** AOS - Unvectorized ********************/
    #ifdef G1_AOS_SCALAR
    for (int r = 0; r < REPEAT_1; r++)
    {
        #pragma unroll (UNROLL_COUNT)
        #pragma novector
        for (int i = 0; i < ARRAY_SIZE_1; i++)
        {
            AoS1_X[i] = AoS1_Y[i].a + AoS1_Y[i].b;
        }
    }
    cout << "Unvectorized AOS loop complete.\n";
    #endif
    /******************** SOA - Unvectorized ********************/
    #ifdef G1_SOA_SCALAR
    for (int r = 0; r < REPEAT_1; r++)
    {
        #pragma unroll (UNROLL_COUNT)
        #pragma novector
        for (int i = 0; i < ARRAY_SIZE_1; i++)
        {
            SoA1_X[i] = SoA1_Y.a[i] + SoA1_Y.b[i];
        }
    }
    cout << "Unvectorized SOA loop complete.\n";
    #endif
    /********************* SOA - Vectorized *********************/
    #ifdef G1_SOA_VECTOR
    for (int r = 0; r < REPEAT_1; r++)
    {
        #pragma unroll (UNROLL_COUNT)
        #pragma simd vectorlengthfor(double)
        for (int i = 0; i < ARRAY_SIZE_1; i++)
        {
            SoA1_X[i] = SoA1_Y.a[i] + SoA1_Y.b[i];
        }
    }
    cout << "Vectorized SOA loop complete.\n";
    #endif

    //############################## Group 2 ##############################//
    // Group 2 is not explored in the tutorial video, but it's here if you
    // wish to experiment with it. It has an AI between Groups 1 and 3.
    #ifdef GROUP_2
    cout << "####################### Group 2 #######################\n"
         << "    Algorithm: X = Ya + Yb + Yb\n    Data Set 1: " << ARRAY_SIZE_1
         << " doubles/array.\n";
    #endif
    /******************** AOS - Unvectorized ********************/
    #ifdef G2_AOS_SCALAR
    for (int r = 0; r < REPEAT_1; r++)
    {
        #pragma unroll (UNROLL_COUNT)
        #pragma novector
        for (int i = 0; i < ARRAY_SIZE_1; i++)
        {
            AoS1_X[i] = AoS1_Y[i].a + AoS1_Y[i].b + AoS1_Y[i].b;
        }
    }
    cout << "Unvectorized AOS loop complete.\n";
    #endif
    /******************** SOA - Unvectorized ********************/
    #ifdef G2_SOA_SCALAR
    for (int r = 0; r < REPEAT_1; r++)
    {
        #pragma unroll (UNROLL_COUNT)
        #pragma novector
        for (int i = 0; i < ARRAY_SIZE_1; i++)
        {
            SoA1_X[i] = SoA1_Y.a[i] + SoA1_Y.b[i] + SoA1_Y.b[i];
        }
    }
    cout << "Unvectorized SOA loop complete.\n";
    #endif
    /********************* SOA - Vectorized *********************/
    #ifdef G2_SOA_VECTOR
    for (int r = 0; r < REPEAT_1; r++)
    {
        #pragma unroll (UNROLL_COUNT)
        #pragma simd vectorlengthfor(double)
        for (int i = 0; i < ARRAY_SIZE_1; i++)
        {
            SoA1_X[i] = SoA1_Y.a[i] + SoA1_Y.b[i] + SoA1_Y.b[i];
        }
    }
    cout << "Vectorized SOA loop complete.\n";
    #endif

    //############################## Group 3 ##############################//
    // Group 3 is a high arithmetic intensity algorithm that is intended
    // to demonstrate compute binding and compiler-induced AI changes.
    #ifdef GROUP_3
    cout << "####################### Group 3 #######################\n"
         << "    Algorithm: X = Ya + Ya + Yb + Yb + Yb\n    Data Set 1: " << ARRAY_SIZE_1
         << " doubles/array.\n";
    #endif
    /******************** AOS - Unvectorized ********************/
    #ifdef G3_AOS_SCALAR
    for (int r = 0; r < REPEAT_1; r++)
    {
        #pragma unroll (UNROLL_COUNT)
        #pragma novector
        for (int i = 0; i < ARRAY_SIZE_1; i++)
        {
            AoS1_X[i] = AoS1_Y[i].a + AoS1_Y[i].a + AoS1_Y[i].b + AoS1_Y[i].b + AoS1_Y[i].b;
        }
    }
    cout << "Unvectorized AOS loop complete.\n";
    #endif
    /******************** SOA - Unvectorized ********************/
    #ifdef G3_SOA_SCALAR
    for (int r = 0; r < REPEAT_1; r++)
    {
        #pragma unroll (UNROLL_COUNT)
        #pragma novector
        for (int i = 0; i < ARRAY_SIZE_1; i++)
        {
            SoA1_X[i] = SoA1_Y.a[i] + SoA1_Y.a[i] + SoA1_Y.b[i] + SoA1_Y.b[i] + SoA1_Y.b[i];
        }
    }
    cout << "Unvectorized SOA loop complete.\n";
    #endif
    /********************* AOS - Vectorized *********************/
    #ifdef G3_AOS_VECTOR
    for (int r = 0; r < REPEAT_1; r++)
    {
        #pragma unroll (UNROLL_COUNT)
        #pragma simd vectorlengthfor(double)
        for (int i = 0; i < ARRAY_SIZE_1; i++)
        {
            AoS1_X[i] = AoS1_Y[i].a + AoS1_Y[i].a + AoS1_Y[i].b + AoS1_Y[i].b + AoS1_Y[i].b;
        }
    }
    cout << "Vectorized AOS loop complete.\n";
    #endif
    /********************* SOA - Vectorized *********************/
    #ifdef G3_SOA_VECTOR
    for (int r = 0; r < REPEAT_1; r++)
    {
        #pragma unroll (UNROLL_COUNT)
        #pragma simd vectorlengthfor(double)
        for (int i = 0; i < ARRAY_SIZE_1; i++)
        {
            SoA1_X[i] = SoA1_Y.a[i] + SoA1_Y.a[i] + SoA1_Y.b[i] + SoA1_Y.b[i] + SoA1_Y.b[i];
        }
    }
    cout << "Vectorized SOA loop complete.\n";
    #endif
    /**************** SOA - Vectorized with FMAs ****************/
    #ifdef G3_SOA_VECTOR_FMAS
    for (int r = 0; r < REPEAT_1; r++)
    {
        #pragma unroll (UNROLL_COUNT)
        #pragma simd vectorlengthfor(double)
        for (int i = 0; i < ARRAY_SIZE_1; i++)
        {
            SoA1_X[i] = (2.0 * SoA1_Y.b[i] + SoA1_Y.b[i]) + SoA1_Y.a[i] * 2.0;
        }
    }
    cout << "Vectorized SOA with FMAs loop complete.\n";
    #endif

    //############################## Group 4 ##############################//
    // Group 4 uses a different data set than the other Groups, and has
    // a medium AI. It is intended to demonstrate cache bandwidth binding.
    #ifdef GROUP_4
    cout << "####################### Group 4 #######################\n"
         << "    Algorithm: X = Ya + Ya + Yb + Yb\n    Data Set 2: " << ARRAY_SIZE_2
         << " doubles/array.\n";
    #endif
    /**************************** SOA ***************************/
    #ifdef G4_SOA
    for (int r = 0; r < REPEAT_2; r++)
    {
        #pragma nounroll
        #pragma simd vectorlengthfor(double)
        for (int i = 0; i < ARRAY_SIZE_2; i++)
        {
            SoA2_X[i] = SoA2_Y.a[i] + SoA2_Y.a[i] + SoA2_Y.b[i] + SoA2_Y.b[i];
        }
    }
    cout << "SOA loop complete.\n";
    #endif
    /*************************** AOSOA **************************/
    #ifdef G4_AOSOA
    for (int r = 0; r < REPEAT_2; r++)
    {
        for (int j = 0; j < 2; j++)
        {
            #pragma nounroll
            #pragma simd vectorlengthfor(double)
            for (int i = 0; i < ARRAY_SIZE_2 / 2; i++)
            {
                AoSoA_X[(j * (ARRAY_SIZE_2 / 2)) + i] = AoSoA_Y[j].a[i] + AoSoA_Y[j].a[i] 
                                                        + AoSoA_Y[j].b[i] + AoSoA_Y[j].b[i];
            }
        }
    }
    cout << "AOSOA loop complete.\n";
    #endif

    return EXIT_SUCCESS;
}

void setupArrays()
{
    for (int i = 0; i < ARRAY_SIZE_1; i++)
    {
        SoA1_Y.a[i] = ((rand() % MAXVALUE) + 1) / 3;
        SoA1_Y.b[i] = ((rand() % MAXVALUE) + 1) / 3;
        AoS1_Y[i].a = SoA1_Y.a[i];
        AoS1_Y[i].b = SoA1_Y.b[i];
    }
    for (int i = 0; i < ARRAY_SIZE_2; i++)
    {
        SoA2_Y.a[i] = ((rand() % MAXVALUE) + 1) / 3;
        SoA2_Y.b[i] = ((rand() % MAXVALUE) + 1) / 3;
    }
    for (int i = 0; i < ARRAY_SIZE_2 / 2; i++)
    {
        AoSoA_Y[0].a[i] = SoA2_Y.a[i];
        AoSoA_Y[1].a[i] = SoA2_Y.a[i + (ARRAY_SIZE_2 / 2)];
        AoSoA_Y[0].b[i] = SoA2_Y.b[i];
        AoSoA_Y[1].b[i] = SoA2_Y.b[i + (ARRAY_SIZE_2 / 2)];
    }
}