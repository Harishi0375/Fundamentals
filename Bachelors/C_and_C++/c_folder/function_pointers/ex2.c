#include <stdio.h>

// Function to display a message
void output(void) {
    printf("Please enter a number:");
}

// Function to calculate the sum of two integers
int sum(int a, int b) {
    return (a + b);
}

int main() {
    int x, y;
    
    // Declare function pointers
    void (*fptr1)(void);
    int (*fptr2)(int, int);
    
    // Assign function addresses to function pointers
    fptr1 = output;
    fptr2 = sum;
    
    // Call the function using function pointer directly
    fptr1();
    
    // Read input
    scanf("%d", &x);
    
    // Call the function using function pointer inside parentheses
    (fptr1)();
    
    // Call the function using function pointer with complete syntax
    // (*fptr1)();
    
    // Read another input
    scanf("%d", &y);
    
    // Call the sum function using function pointer and print the result
    printf("The sum is %d.\n", fptr2(x, y));

    return 0;
}

