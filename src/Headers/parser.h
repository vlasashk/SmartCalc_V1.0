#ifndef SRC_HEADERS_PARSER_H_
#define SRC_HEADERS_PARSER_H_

#include "stack.h"

int inputFromUser(char *src);
int convertInput(const char *src, Stack *input);
int inputX(Stack *input);

int checkParseRes(char parse_res, int *i);
int bracketsParsing(char bracket, int *left_br, int *right_br);
int parseNumber(const char *src, char **pointer, int *i, Stack *input);
char parseTrigonometry(const char *src);
int expressionValidation(Stack *input);

#endif  // SRC_HEADERS_PARSER_H_
