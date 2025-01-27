#include <stdio.h>

int main() {
    // Declare an array of integers with a fixed size of 5
    int numbers[5];

    // Initialize the array with values
    numbers[0] = 10;
    numbers[1] = 20;
    numbers[2] = 30;
    numbers[3] = 40;
    numbers[4] = 50;

    // Print the values in the array
    printf("Array elements:\n");
    for (int i = 0; i < 5; i++) {
        printf("numbers[%d] = %d\n", i, numbers[i]);
    }

    return 0;
}
