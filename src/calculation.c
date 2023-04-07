#include "stack.h"

int calculation(Stack *rpn, double *result) {
  int calc_err = 0;
  Stack *temp_stack = initStack();
  if (rpn->x_status == 0) {
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
          temp_calc = calcDuo(atof(second), atof(first), pop_val[0], &calc_err);
          free(second);
        } else {
          temp_calc = calcUno(atof(first), pop_val[0], &calc_err);
        }
        snprintf(buffer, 32, "%lf", temp_calc);
        push(temp_stack, buffer);
        free(first);
      }
      free(pop_val);
    }
  }
  char *res = pop(temp_stack);
  *result = atof(res);
  free(res);
  freeStack(temp_stack);
  return !calc_err;
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
  switch (oper) {
  case '~':
    res = -a;
    break;
  case 's':
    res = sin(a);
    break;
  case 'S':
    if (a >= -1.0f && a <= 1.0f) {
      res = asin(a);
    } else {
      *calc_err = 1;
    }
    break;
  case 'c':
    res = cos(a);
    break;
  case 'C':
    if (a >= -1.0f && a <= 1.0f) {
      res = acos(a);
    } else {
      *calc_err = 1;
    }
    break;
  case 't':
    if (cos(a) == 0.0f) {
      *calc_err = 1;
    } else {
      res = tan(a);
    }
    break;
  case 'T':
    res = atan(a);
    break;
  case 'R':
    if (a >= 0.0f) {
      res = sqrt(a);
    } else {
      *calc_err = 1;
    }
    break;
  case 'L':
    if (a > 0.0f) {
      res = log10(a);
    } else {
      *calc_err = 1;
    }
    break;
  case 'l':
    if (a > 0.0f) {
      res = log(a);
    } else {
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
      res = (double)a / b;
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