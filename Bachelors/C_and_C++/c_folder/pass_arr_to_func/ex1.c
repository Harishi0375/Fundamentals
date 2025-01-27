#include <stdio.h>
#include <stdlib.h>

void strange_function(int v[], int dim) {
    int i;
    for (i = 0; i < dim; i++)
        v[i] = 287;
    // v = (int *) malloc(sizeof(int) * 1000);
}

int main() {
    int array[] = {1, 2, 9, 16};
    int *p = &array[0];
    strange_function(array, 4);
    printf("%d %p %p\n", array[0], (void *)p, (void *)array);
    return 0;
}