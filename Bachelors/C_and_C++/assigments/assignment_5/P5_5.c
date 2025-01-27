/*
  CH-230-A
  a5_p5.c
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    double *v, *w;
    double scalar_product, product;
    double smallest1, smallest2, largest1, largest2;
    int position_smallest1, position_smallest2, position_largest1, position_largest2;

    scanf("%d", &n);
    v = (double *)malloc(n * sizeof(double)); //dynamic memory for v
    w = (double *)malloc(n * sizeof(double)); //dynamic memory for w

    for (int i = 0; i < n; i++) {
        scanf("%lf", &v[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%lf", &w[i]);
    }

    scalar_product = 0;
    for (int i = 0; i < n; i++) {
        product = v[i] * w[i];
        scalar_product = scalar_product + product;
    }

    smallest1 = v[0];
    smallest2 = w[0];
    largest1 = v[0];
    largest2 = w[0];
    position_smallest1 = 0;
    position_smallest2 = 0;
    position_largest1 = 0;
    position_largest2 = 0;

    for (int i = 0; i < n; i++) {
        if (smallest1 > v[i]) {
            smallest1 = v[i];
            position_smallest1 = i;
        }
        if (smallest2 > w[i]) {
            smallest2 = w[i];
            position_smallest2 = i;
        }
        if (largest1 < v[i]) {
            largest1 = v[i];
            position_largest1 = i;
        }
        if (largest2 < w[i]) {
            largest2 = w[i];
            position_largest2 = i;
        }
    }

    printf("Scalar product=%lf\n", scalar_product);
    printf("The smallest = %lf\n", smallest1);
    printf("Position of smallest = %d\n", position_smallest1);
    printf("The largest = %lf\n", largest1);
    printf("Position of largest = %d\n", position_largest1);
    printf("The smallest = %lf\n", smallest2);
    printf("Position of smallest = %d\n", position_smallest2);
    printf("The largest = %lf\n", largest2);
    printf("Position of largest = %d\n", position_largest2);

    free(v); //deallocation of v
    free(w); //deallocation of w

    return 0;
}
