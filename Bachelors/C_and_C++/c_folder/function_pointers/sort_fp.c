#include <stdio.h>
#include <stdlib.h>

int numcmp(const char *s1, const char *s2) {
    double num1 = atof(s1); // Convert the first string to a double
    double num2 = atof(s2); // Convert the second string to a double

    if (num1 < num2) {
        return -1; // s1 is numerically less than s2
    } else if (num1 > num2) {
        return 1; // s1 is numerically greater than s2
    } else {
        return 0; // s1 and s2 are numerically equal
    }
}

int main() {
    char *str1 = "hello world";
    char *str2 = "dance";

    int result = numcmp(str1, str2);

    if (result < 0) {
        printf("%s is numerically less than %s\n", str1, str2);
    } else if (result > 0) {
        printf("%s is numerically greater than %s\n", str1, str2);
    } else {
        printf("%s and %s are numerically equal\n", str1, str2);
    }

    return 0;
}
