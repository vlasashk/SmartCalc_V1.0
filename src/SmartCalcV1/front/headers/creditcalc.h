#ifndef SRC_SMARTCALCV1_FRONT_HEADERS_CREDITCALC_H_
#define SRC_SMARTCALCV1_FRONT_HEADERS_CREDITCALC_H_

#ifdef __cplusplus
extern "C" {
#endif
#include "../../back/headers/credit.h"
#ifdef __cplusplus
}
#endif

#include <QAbstractItemView>
#include <QMainWindow>

#include "QtWidgets"

namespace Ui {
class CreditCalc;
}

class CreditCalc : public QMainWindow {
  Q_OBJECT

 public:
  explicit CreditCalc(QWidget* parent = nullptr);
  ~CreditCalc();

 private:
  Ui::CreditCalc* ui;
 private slots:
  void setSelectComboBoxStyle(QComboBox* comboBox);
  void calculateResults();
  CreditInput initInput();
  int payTypeParse();
  int monthParse();
  int termTypeParse();
  void adjustFont(QLabel* label);
};

#endif  // SRC_SMARTCALCV1_FRONT_HEADERS_CREDITCALC_H_
