#include "stack.h"
// 3+(-4)*sin(3+5)*2/(1-5)^2^3
// 15/(7-(1+1))*3-(2+(1+1))*15/(7-(200+1))*3-(2+(1+1))*(15/(7-(1+1))*3-(2+(1+1))+15/(7-(1+1))*3-(2+(1+1)))
int main() {
  Stack *input = initStack();
  char user_input[MAX_LIMIT];
  int read_success = inputFromUser(user_input);
  if (read_success && convertInput(user_input, input)) {
    Stack *rpn = rpnConverter(input);
    reverseStack(rpn);
    // while (!isEmpty(rpn)) {
    //   char *peeks = pop(rpn);
    //   printf("%s ", peeks);
    //   free(peeks);
    // }
    double result = 0.0;
    if (calculation(rpn, &result)) {
      printf("%lf\n", result);
    } else {
      printf("Error\n");
    }
    freeStack(rpn);
    if (input->x_status == 1) {
      free(input->x_value);
    }
  } else {
    printf("Invalid input\n");
  }
  freeStack(input);
  return 0;
}
