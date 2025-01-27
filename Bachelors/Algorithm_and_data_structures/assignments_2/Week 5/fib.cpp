#include "fib.h"
#include <cmath>

long long int naiv_fib(int n) {
    if (n == 1 || n == 0)
        return n;

    return naiv_fib(n-1) + naiv_fib(n-2);
}

long long int bottom_up_fib(int n) {
    if (n == 0 || n == 1)
        return n;

    int fib[n+1];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    return fib[n];
}

long long int closed_fib(int n) {
    double phi = (1.0 + std::sqrt(5)) / 2.0;
    return std::round(std::pow(phi, n) / std::sqrt(5)); 
}


// I took this algorithm from the following source:
// https://www.geeksforgeeks.org/matrix-exponentiation/
// please done kill
void multiply(long long int a[3][3], long long int b[3][3]) {
	// Creating an auxiliary matrix to store elements 
	// of the multiplication matrix
	long long int mul[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			mul[i][j] = 0;
			for (int k = 0; k < 3; k++)
				mul[i][j] += a[i][k]*b[k][j];
		}
	}

	// storing the multiplication result in a[][]
	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
			a[i][j] = mul[i][j]; // Updating our matrix
}

// Function to compute F raise to power n-2.
long long int power(long long int F[3][3], long long int n) {
	long long int M[3][3] = {{1,1,0}, {1,0,0}, {0,1,0}};

	// Multiply it with initial values i.e with
	// F(0) = 0, F(1) = 1, F(2) = 1
	if (n==1)
		return F[0][0] + F[0][1];

	power(F, n/2);

	multiply(F, F);

	if (n%2 != 0)
		multiply(F, M);

	// Multiply it with initial values i.e with
	// F(0) = 0, F(1) = 1, F(2) = 1
	return F[0][0] + F[0][1] ;
}

long long int matrix_fib(int n) {

	long long int F[3][3] = {{1,1,0}, {1,0,0}, {0,1,0}} ;

	//Base cases
	if(n==0)
		return 0;
	if(n==1 || n==2)
		return 1;

	return power(F, n-2);
}

