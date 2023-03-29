#include "stack.h"

struct char_stack *root_c = NULL;
// 3+(-4)*sin(3+5)*2/(1-5)^2^3
int main() {
  Stack *input = initStack();
  char user_input[MAX_LIMIT];
  int read_success = input_from_user(user_input);
  if (read_success && convert_input(user_input, input)) {
    while (!isEmpty(input)) {
      char *peeks = pop(input);
      printf("%s", peeks);
      free(peeks);
    }
    printf("\n");
  } else {
    printf("Invalid input\n");
  }
  freeStack(input);
  return 0;
}

int check_priority(char oper) {
  int out;
  if (oper == '(' || oper == ')') {
    out = 5;
  } else if (strchr("~^", oper) != NULL) {
    out = 4;
  } else if (strchr(OPERATIONS, oper) != NULL) {
    out = 3;
  } else if (strchr("*/%", oper) != NULL) {
    out = 2;
  } else if (strchr("+-", oper) != NULL) {
    out = 1;
  } else {
    out = 0;
  }
  return out;
}
