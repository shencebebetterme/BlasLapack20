#include <iostream>
#include "cblas_inc.h"

int main()
{
	float alpha = 2.0;                 // scalar value
	int n = 4;                         // length of vectors
	float x[] = { 1.0, 2.0, 3.0, 4.0 };  // input vector x
	float y[] = { 2.0, 4.0, 6.0, 8.0 };  // input/output vector y
	int incx = 1;
	int incy = 1;

	//saxpy_(&n, &alpha, x, &incx, y, &incy); // perform y = alpha*x + y
	cblas_saxpy(n, alpha, x, incx, y, incy); // perform y = alpha*x + y

	// print result
	printf("Result vector y: ");
	for (int i = 0; i < n; i++) {
		printf("%f ", y[i]);
	}
	printf("\n");

	return 0;
}
