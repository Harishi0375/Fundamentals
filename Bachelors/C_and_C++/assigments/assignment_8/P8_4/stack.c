/*
CH-230-A
a8 p4.c 
Harishi Velavan
hvelavan@jacobs-university.de
*/

#include "stack.h"
#include <stdio.h>

void push(struct stack *s, unsigned int num) {
    if (s->count < 12) {
        s->array[s->count++] = num;
    } else {
        printf("Stack Overflow\n");
    }
}

int pop(struct stack *s) {
    if (s->count > 0) {
        return s->array[--s->count];
    } else {
        printf("Stack Underflow\n");
        return -1; // Return a sentinel value indicating underflow
    }
}

void empty(struct stack *s) {
    while (s->count > 0) {
        printf("%d ", pop(s));
    }
    printf("\n");
}

int isEmpty(const struct stack *s) {
    return s->count == 0;
}
