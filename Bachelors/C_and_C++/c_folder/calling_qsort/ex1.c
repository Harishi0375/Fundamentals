#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ELEMENTS 50

int my_compare(const void *va, const void *vb) {
    const int *a = (const int *)va;
    const int *b = (const int *)vb;
    if (*a < *b) return -1;
    else if (*a > *b) return 1;
    else return 0;
}

int main() {
    srand(time(NULL)); // Seed the random number generator with current time

    int arr[NUM_ELEMENTS];
    int i;

    // Fill the array with random numbers between 0 and 999
    for (i = 0; i < NUM_ELEMENTS; i++)
        arr[i] = rand() % 1000;

    // Sort the array using qsort, providing the base address, number of elements, size of each element, and the comparison function
    qsort(arr, NUM_ELEMENTS, sizeof(arr[0]), my_compare);

    // Print the sorted array
    for (i = 0; i < NUM_ELEMENTS; i++)
        printf("%d\n", arr[i]);

    return 0;
}
