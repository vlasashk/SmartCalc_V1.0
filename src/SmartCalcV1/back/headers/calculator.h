#ifndef SRC_SMARTCALCV1_BACK_HEADERS_CALCULATOR_H_
#define SRC_SMARTCALCV1_BACK_HEADERS_CALCULATOR_H_

#include "parser.h"
#include "stack.h"
void calculator(char *user_input, char *x_input, char *calc_out);
void convert_output(char *calc_out);
int calculation(Stack *rpn, double *result);
double calcUno(double a, char oper, int *calc_err);
double calcDuo(double a, double b, char oper, int *calc_err);
int checkUnoDuo(char oper);
int unoValidation(double a, char oper, int *calc_err);
double myAtof(char *val, Stack *rpn);

#endif  // SRC_SMARTCALCV1_BACK_HEADERS_CALCULATOR_H_
