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
} Stack;

double algorithm(char *str, double x);
double calc_duo(double a, double b, char oper);
double calc_uno(double a, char oper);
int rpn_algorithm(char *src, char *des, int n, int *n_rpn);

int input_from_user(char *src);
int convert_input(const char *src, Stack *input);

Stack *initStack();
int isEmpty(Stack *input);
void push(Stack *input, char *value);
char *pop(Stack *input);
char *peek(Stack *input);
void freeStack(Stack *input);
void reverseStack(Stack *stack);

int check_priority(char oper);
int checkParseRes(char parse_res, int *i);
int bracketsParsing(char bracket, int *left_br, int *right_br);
int parseNumber(const char *src, char **pointer, int *i);
char parseTrigonometry(const char *src);
int expressionValidation(Stack *input);

#endif // SRC_STACK_H_
