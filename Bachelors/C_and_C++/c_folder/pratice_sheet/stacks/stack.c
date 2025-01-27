#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stacks.h"

int count = 0;

void createEmptyStack(struct stack *s) {
  s->top = -1;
}

// Check if the stack is full
int isfull(struct stack *s) {
  if (s->top == 5)
    return 1;
  else
    return 0;
}

// Check if the stack is empty
int isempty(struct stack *s) {
  if (s->top == -1)
    return 1;
  else
    return 0;
}

// Add elements into stack
void push(struct stack *s, char newitem) {
  if (isfull(s)) {
    printf("STACK FULL");
  } else {
    s->top++;
    s->items[s->top] = newitem;
  }
  count++;
}

// Remove element from stack
void pop(struct stack *s) {
  if (isempty(s)) {
    printf("\n STACK EMPTY \n");
  } else {
    printf("Item popped= %d", s->items[s->top]);
    s->top--;
  }
  count--;
  printf("\n");
}

// Print elements of stack
void printStack(struct stack *s) {
  printf("Stack: ");
  for (int i = 0; i < count; i++) {
    printf("%d ", s->items[i]);
  }
  printf("\n");
}

void sumStack(struct stack *s)
{
  int sum = 0;
  for (int i = 0; i < count; i++)
  {
    sum = sum + s->items[i];
  }
  printf("the sum = %d\n",sum);  
}