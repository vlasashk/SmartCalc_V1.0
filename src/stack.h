#ifndef SRC_STACK_H_
#define SRC_STACK_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIMIT 1024
#define DIGITS "0123456789x."
#define SIGNS "*-+/^"
#define TRIGONMETRY "scltma"
#define OPERATIONS "SsCcTtRlL"
#define VALIDATION "*-+/^%~"

typedef struct input_node {
  char *lexema;
  struct input_node *next;
} InputNode;

typedef struct {
  InputNode *top;
  int x_status;
  char *x_value;
} Stack;

int calculation(Stack *rpn, double *result);
double calcUno(double a, char oper, int *calc_err);
double calcDuo(double a, double b, char oper, int *calc_err);
int checkUnoDuo(char oper);

int inputFromUser(char *src);
int convertInput(const char *src, Stack *input);

Stack *initStack();
int isEmpty(Stack *input);
void push(Stack *input, char *value);
char *pop(Stack *input);
char *peek(Stack *input);
void freeStack(Stack *input);
void reverseStack(Stack *stack);

int checkParseRes(char parse_res, int *i);
int bracketsParsing(char bracket, int *left_br, int *right_br);
int parseNumber(const char *src, char **pointer, int *i, Stack *input);
char parseTrigonometry(const char *src);
int expressionValidation(Stack *input);
int inputX(Stack *input);

Stack *rpnConverter(Stack *input);
void operationHandler(Stack *rpn_stack, Stack *temp_stack, char *pop_value);
int priorityValidation(Stack *temp_stack, int peek_priority, int pop_priority);
int checkPriority(char oper);

#endif // SRC_STACK_H_
