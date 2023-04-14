#ifndef SRC_HEADERS_STACK_H_
#define SRC_HEADERS_STACK_H_

#include "includes.h"

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

Stack *initStack();
int isEmpty(Stack *input);
void push(Stack *input, char *value);
char *pop(Stack *input);
char *peek(Stack *input);
void freeStack(Stack *input);
void reverseStack(Stack *stack);

Stack *rpnConverter(Stack *input);
void operationHandler(Stack *rpn_stack, Stack *temp_stack, char *pop_value);
int priorityValidation(Stack *temp_stack, int peek_priority, int pop_priority);
int checkPriority(char oper);

#endif  // SRC_HEADERS_STACK_H_
