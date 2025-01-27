/*
CH-230-A
a8 p4.c 
Harishi Velavan
hvelavan@jacobs-university.de
*/

#include "stack.h"
#include <stdio.h>

int main() {
    struct stack s;
    unsigned int num;

    s.count = 0;

    scanf("%d", &num);

    // Storing the remainder in the stack
    while (num > 0) {
        push(&s, num % 2);
        num = num / 2;
    }

    // Printing the binary representation
    printf("The binary representation of %d is ",num);
    while (!isEmpty(&s)) {
        printf("%d", pop(&s));
    }
    printf("\n");

    return 0;
}
