#ifndef SRC_HEADERS_CREDIT_H_
#define SRC_HEADERS_CREDIT_H_

#include "includes.h"

typedef struct {
  int annuity;
  double min_monthly;
  double max_monthly;
  double overpay;
  double total_credit;
} CreditOutput;

typedef struct {
  int annuity;
  int total_loan;
  int term;
  int yearly;
  double interest;
  int curr_year;
  int curr_month;
} CreditInput;

// Credit module
int leapYear(int year);
void countDays(int year, int month, int *days_month, int *days_year);
void annuityCalc(CreditInput input, CreditOutput *output);
void diffCalc(CreditInput input, CreditOutput *output);
CreditOutput initCreditOutput();
CreditOutput creditCalculator(CreditInput input);

#endif  // SRC_HEADERS_CREDIT_H_