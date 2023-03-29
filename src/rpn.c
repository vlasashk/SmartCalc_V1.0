#include "stack.h"

Stack *rpn_converter(Stack *input) {
  Stack *rpn_stack = initStack();
  while (!isEmpty(input)) {
    char *peek_inside = peek(input);
    printf("%s", peek_inside);
    free(peek_inside);
  }
  printf("\n");
  return rpn_stack;
}