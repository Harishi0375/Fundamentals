#include <stdio.h>

int main() {
    unsigned int binaryNumber;

    // Get binary input from the user
    printf("Enter a binary number: ");
    if (scanf("%d", &binaryNumber) != 1) {
        printf("Invalid input. Please enter a valid unsigned integer.\n");
        return 1;
    }

    // Perform bitwise left shift (<<) and right shift (>>)
    unsigned int resultLeftShift = binaryNumber << 2;   // Shift left by 2 bits
    unsigned int resultRightShift = binaryNumber >> 1;  // Shift right by 1 bit

    // Display results
    printf("Original binary number: %d\n", binaryNumber);
    printf("After left shift by 2: %d\n", resultLeftShift);
    printf("After right shift by 1: %d\n", resultRightShift);

    return 0;
}
