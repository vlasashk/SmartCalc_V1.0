#include "Headers/calculator.h"

void calculator(char *calc_out) {
  Stack *input = initStack();
  double result = 0.0f;
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
    if (inputX(rpn) && calculation(rpn, &result)) {
      sprintf(calc_out, "%.12lf", result);
      convert_output(calc_out);
    } else {
      sprintf(calc_out, "Error");
    }
    freeStack(rpn);
    if (input->x_status == 1) {
      free(input->x_value);
    }
  } else {
    sprintf(calc_out, "Invalid input");
  }
  freeStack(input);
}

void convert_output(char *calc_out) {
  int len = strlen(calc_out) - 1;
  if (calc_out[len] == '0') {
    int terminate = len;
    for (size_t i = len; calc_out[i] == '0' || calc_out[i] == '.'; i--) {
      terminate = i;
    }
    calc_out[terminate] = '\0';
  }
}

int calculation(Stack *rpn, double *result) {
  int calc_err = 0;
  Stack *temp_stack = initStack();
  while (!isEmpty(rpn) && calc_err == 0) {
    char *pop_val = pop(rpn);
    int oper_type = checkUnoDuo(pop_val[0]);
    if (oper_type == 0) {
      push(temp_stack, pop_val);
    } else {
      char *first = pop(temp_stack);
      char buffer[32] = {0};
      double temp_calc = 0.0;
      if (oper_type == 2) {
        char *second = pop(temp_stack);
        temp_calc = calcDuo(myAtof(second, rpn), myAtof(first, rpn), pop_val[0],
                            &calc_err);
        free(second);
      } else {
        temp_calc = calcUno(myAtof(first, rpn), pop_val[0], &calc_err);
      }
      snprintf(buffer, 32, "%.20lf", temp_calc);
      push(temp_stack, buffer);
      free(first);
    }
    free(pop_val);
  }
  char *res = pop(temp_stack);
  *result = atof(res);
  free(res);
  freeStack(temp_stack);
  return !calc_err;
}

double myAtof(char *val, Stack *rpn) {
  double res = 0.0f;
  if (val[0] != 'x') {
    res = atof(val);
  } else {
    res = atof(rpn->x_value);
  }
  return res;
}

int checkUnoDuo(char oper) {
  int out;
  char uno[] = "SsCcTtRlL~";
  char duo[] = "+-*/%^";
  if (strchr(duo, oper) != NULL) {
    out = 2;
  } else if (strchr(uno, oper) != NULL) {
    out = 1;
  } else {
    out = 0;
  }
  return out;
}

double calcUno(double a, char oper, int *calc_err) {
  double res = 0.0;
  if (unoValidation(a, oper, calc_err)) {
    switch (oper) {
    case '~':
      res = -a;
      break;
    case 's':
      res = sin(a);
      break;
    case 'S':
      res = asin(a);
      break;
    case 'c':
      res = cos(a);
      break;
    case 'C':
      res = acos(a);
      break;
    case 't':
      res = tan(a);
      break;
    case 'T':
      res = atan(a);
      break;
    case 'R':
      res = sqrt(a);
      break;
    case 'L':
      res = log10(a);
      break;
    case 'l':
      res = log(a);
      break;
    default:
      break;
    }
  }
  return res;
}

int unoValidation(double a, char oper, int *calc_err) {
  int res = 1;
  switch (oper) {
  case 'S':
  case 'C':
    if (a < -1.0f || a > 1.0f) {
      res = 0;
      *calc_err = 1;
    }
    break;
  case 't':
    if (cos(a) == 0.0f) {
      res = 0;
      *calc_err = 1;
    }
    break;
  case 'R':
    if (a < 0.0f) {
      res = 0;
      *calc_err = 1;
    }
    break;
  case 'L':
  case 'l':
    if (a <= 0.0f) {
      res = 0;
      *calc_err = 1;
    }
    break;
  default:
    break;
  }
  return res;
}

double calcDuo(double a, double b, char oper, int *calc_err) {
  double res = 0.0;
  switch (oper) {
  case '^':
    res = pow(a, b);
    break;
  case '+':
    res = (double)a + b;
    break;
  case '-':
    res = (double)a - b;
    break;
  case '*':
    res = (double)a * b;
    break;
  case '/':
    if (b == 0) {
      *calc_err = 1;
    } else {
      res = a / b;
    }
    break;
  case '%':
    if (b == 0) {
      *calc_err = 1;
    } else {
      res = fmod(a, b);
    }
    break;
  default:
    break;
  }
  return res;
}