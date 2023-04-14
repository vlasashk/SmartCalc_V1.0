#include "Headers/calculator.h"
#include "Headers/credit.h"
// 3+(-4)*sin(3+5)*2/(1-5)^2^3
// 15/(7-(1+1))*3-(2+(1+1))*15/(7-(200+1))*3-(2+(1+1))*(15/(7-(1+1))*3-(2+(1+1))+15/(7-(1+1))*3-(2+(1+1)))

// int main() {
//   char calc_out[128] = {0};
//   calculator(calc_out);
//   printf("%s\n", calc_out);
//   return 0;
// }

int main() {
  CreditOutput out = creditCalculator();
  printf("%lf - %lf\n", out.min_monthly, out.max_monthly);
  printf("%lf\n", out.overpay);
  printf("%lf\n", out.total_credit);
  return 0;
}
