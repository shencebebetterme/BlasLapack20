#include <iostream>
#include "cblas_inc.h"

#define LAPACK_ROW_MAJOR               101

extern "C"
{
	void sgerqf(
		const int* m, const int * n,
		float* A, const int* lda,
		float* tau,
		float* work, const int* lwork,
		int* info);

	int LAPACKE_sgerqf(int matrix_layout, int m, int n,
		float* a, int lda, float* tau);

	void saxpy_(int* n, float* alpha, float* x, int* incx, float* y, int* incy);
}

int main()
{
	float alpha = 2.0;                 // scalar value
	int len = 4;                         // length of vectors
	float x[] = { 1.0, 2.0, 3.0, 4.0 };  // input vector x
	float y[] = { 2.0, 4.0, 6.0, 8.0 };  // input/output vector y
	int incx = 1;
	int incy = 1;

	//saxpy_(&n, &alpha, x, &incx, y, &incy); // perform y = alpha*x + y
	cblas_saxpy(len, alpha, x, incx, y, incy); // perform y = alpha*x + y

	// print result
	printf("Result vector y: ");
	for (int i = 0; i < len; i++) {
		printf("%f ", y[i]);
	}
	printf("\n");


	//constexpr int M = 4;
	//constexpr int N = 3;
	//constexpr int LDA = N;

	//float A[M * N] = { 1, 2, 3,
	//				 4, 5, 6,
	//				 7, 8, 9,
	//				 10, 11, 12 };
	//float tau[N];
	//float work[M];
	//int info, lwork = M;

	// Compute the RQ factorization of A
	//sgerqf(&M, &N, A, &LDA, tau, work, &lwork, &info);
	// 
	// Define the input matrix A
	float A[] = { 1.0f, 2.0f, 3.0f,
				  4.0f, 5.0f, 6.0f,
				  7.0f, 8.0f, 9.0f,
				 10.0f,11.0f,12.0f };

	// Dimensions and leading dimension of A
	int m = 4, n = 3, lda = n;

	// Allocate workspace
	float work[4];
	int lwork = 4;

	// Allocate workspace for computed Householder scalars
	float tau[3];

	// Compute the RQ factorization of A
	int info = LAPACKE_sgerqf(LAPACK_ROW_MAJOR, m, n, A, lda, tau);


	return 0;
}

