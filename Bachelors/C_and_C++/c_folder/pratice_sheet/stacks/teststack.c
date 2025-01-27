#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stacks.h"

int main() {
  struct stack *s = malloc(sizeof(struct stack));

  createEmptyStack(s);

  push(s, 1);
  push(s, 2);
  push(s, 3);
  push(s, 4);
  push(s,5);
  push(s,6);

  sumStack(s);

  printStack(s);

  pop(s);
//   pop(s);
//   pop(s);
//   pop(s);
//   pop(s);

  printf("\nAfter popping out\n");
  printStack(s);
  free(s);
}