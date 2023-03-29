#include "stack.h"

// double algorithm(char *str, double x) {
//   char *p;
//   char temp[100] = " ";
//   strcpy(temp, str);
//   p = strtok(temp, " ");

//   while (p != NULL) {
//     int flag = 1;
//     int length = strlen(p);
//     for (int i = 0; i < length; i++) {
//       if ((p[i] < '0' || p[i] > '9') && p[i] != '.') {
//         flag = 0;
//         if (p[i] == '+' || p[i] == '-' || p[i] == '*' || p[i] == '/') {
//           double var2 = pop_d();
//           double var1 = pop_d();
//           push_d(calc_duo(var1, var2, p[i]));
//         } else if (p[i] == '~' || p[i] == 's' || p[i] == 'c' || p[i] == 't'
//         ||
//                    p[i] == 'C' || p[i] == 'R' || p[i] == 'L') {
//           double var = pop_d();
//           push_d(calc_uno(var, p[i]));
//         } else if (p[i] == 'x' || p[i] == 'X') {
//           printf("gblh %lf\n", x);
//           push_d(x);
//         }
//       }
//     }
//     char *temp_pointer = p;
//     if (flag != 0) {
//       push_d(atof(temp_pointer));
//     }
//     p = strtok(NULL, " ");
//   }
//   // display_d();
//   destroy_d();
//   return pop_d();
// }

// double calc_uno(double a, char oper) {
//   double res = 0.0;
//   switch (oper) {
//   case '~':
//     res = -a;
//     break;
//   case 's':
//     res = sin(a);
//     break;
//   case 'c':
//     res = cos(a);
//     break;
//   case 't':
//     res = tan(a);
//     break;
//   case 'C':
//     res = 1 / tan(a);
//     break;
//   case 'R':
//     res = sqrt(a);
//     break;
//   case 'L':
//     res = log(a);
//     break;
//   default:
//     break;
//   }
//   return res;
// }

// double calc_duo(double a, double b, char oper) {
//   double res = 0.0;
//   switch (oper) {
//   case '+':
//     res = (double)a + b;
//     break;
//   case '-':
//     res = (double)a - b;
//     break;
//   case '*':
//     res = (double)a * b;
//     break;
//   case '/':
//     if (b == 0) {
//       printf("Division by zero\n");
//       break;
//     }
//     res = (double)a / b;
//     break;
//   default:
//     break;
//   }
//   return res;
// }

Stack *initStack() {
  Stack *temp = (Stack *)malloc(sizeof(Stack));
  temp->top = NULL;
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
  free(input);
}
