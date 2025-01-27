#include <stdio.h>

char *intToBinary(int n, char *binstr) {
    // int maxbit = sizeof(int) * 8;
    int limit = 8;  // Limit the binary representation to 8 characters

    for (int i = 0; i < limit; i++) {
        if (n & (1 << i)) {
            binstr[limit - i - 1] = '1';
        } else {
            binstr[limit - i - 1] = '0';
        }
    }

    binstr[limit] = '\0';  // Null-terminate the string
    return binstr;
}

int main() {
    int number;
    char binaryString[9];  // 8 characters for binary + 1 for null-terminator

    printf("Enter an integer: ");
    scanf("%d", &number);

    printf("Binary representation: %s\n", intToBinary(number, binaryString));

    return 0;
}

