#include "stack.h"

Stack *initStack() {
  Stack *temp = (Stack *)malloc(sizeof(Stack));
  temp->top = NULL;
  temp->x_status = 0;
  temp->x_value = NULL;
  return temp;
}

int isEmpty(Stack *s) { return s->top == NULL; }

void push(Stack *input, char *value) {
  InputNode *newNode = (InputNode *)malloc(sizeof(InputNode));
  newNode->lexema = (char *)calloc(strlen(value) + 1, sizeof(char));
  strcpy(newNode->lexema, value);
  newNode->next = input->top;
  input->top = newNode;
}

char *pop(Stack *input) {
  if (isEmpty(input)) {
    printf("Error: Stack is empty\n");
    return NULL;
  }
  char *value = input->top->lexema;
  InputNode *temp = input->top;
  input->top = input->top->next;
  free(temp);
  return value;
}

char *peek(Stack *input) {
  if (isEmpty(input)) {
    return NULL;
  }
  return input->top->lexema;
}

void reverseStack(Stack *stack) {
  InputNode *prev = NULL;
  InputNode *current = stack->top;
  InputNode *next = NULL;
  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  stack->top = prev;
}

void freeStack(Stack *input) {
  while (!isEmpty(input)) {
    InputNode *temp = input->top;
    input->top = input->top->next;
    free(temp->lexema);
    free(temp);
  }
  if (input->x_value != NULL) {
    free(input->x_value);
  }
  free(input);
}
