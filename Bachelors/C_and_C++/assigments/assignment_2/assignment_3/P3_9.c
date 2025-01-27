/*
  CH-230-A
  a3_p9.c
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <stdio.h>

double sum25(double v[], int n) {
    if (n > 5) {
        return v[2] + v[5];
    } else {
        printf("One or both positions are invalid\n");
        return -111;
    }
}

int main() {
    int n;

    // enter the input
    scanf("%d", &n);

    // Check if n is within valid range
    if (n < 1 || n > 20) {
        printf("One or both positions are invalid\n");
        return 1; // Return error code
    }

    double v[20]; 

    // Read the elements into the array
    for (int i = 0; i < n; i++) {
        scanf("%lf", &v[i]);
    }

    // Calculate sum of elements at positions 2 and 5
    double result = sum25(v, n);

    if (result != -111) {
        printf("sum=%f\n", result);
    }

    return 0;
}