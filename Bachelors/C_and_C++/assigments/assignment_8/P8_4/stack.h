/*
CH-230-A
a8 p4.c 
Harishi Velavan
hvelavan@jacobs-university.de
*/

#ifndef STACK_H
#define STACK_H

struct stack {
    unsigned int count;
    int array[12]; // Container
};

void push(struct stack *s,unsigned int num);
int pop(struct stack *s);
void empty(struct stack *s);
int isEmpty(const struct stack *s);

#endif /* STACK_H */
