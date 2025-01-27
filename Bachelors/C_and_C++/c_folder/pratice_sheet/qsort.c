#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compareIntegers(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int numbers[] = {5, 2, 8, 1, 3, 7, 4, 6};
    size_t size = sizeof(numbers) / sizeof(numbers[0]);

    printf("Original array: ");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // Using qsort to sort the array
    qsort(numbers, size, sizeof(int), compareIntegers);

    printf("Sorted array: ");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}
