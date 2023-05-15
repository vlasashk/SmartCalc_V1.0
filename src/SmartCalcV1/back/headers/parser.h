#ifndef SRC_SMARTCALCV1_BACK_HEADERS_PARSER_H_
#define SRC_SMARTCALCV1_BACK_HEADERS_PARSER_H_

#include "stack.h"

int convertInput(const char *src, Stack *input);
int inputX(char *x_input, Stack *input);
int validateX(const char *src);

int checkParseRes(char parse_res, int *i);
int bracketsParsing(char bracket, int *left_br, int *right_br);
int parseNumber(const char *src, char **pointer, int *i, Stack *input);
char parseTrigonometry(const char *src);
int expressionValidation(Stack *input);

#endif  // SRC_SMARTCALCV1_BACK_HEADERS_PARSER_H_
