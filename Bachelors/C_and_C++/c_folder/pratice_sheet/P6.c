#include <stdio.h>

// Function to calculate factorial
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1; // 0! and 1! are both 1
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int num;
    scanf("%d",&num);
    printf("%d",factorial(num));

    return 0;
}
