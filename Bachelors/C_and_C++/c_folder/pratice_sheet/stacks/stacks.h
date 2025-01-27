#ifndef STACK_H
#define STACK_H

struct stack {
  int items[20];
  int top;
};


void createEmptyStack(struct stack *s);
int isfull(struct stack *s);
int isempty(struct stack *s);
void push(struct stack *s, char newitem) ;
void pop(struct stack *s);
void printStack(struct stack *s);
void sumStack(struct stack *s);


#endif 