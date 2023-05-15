#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#ifdef __cplusplus
extern "C" {
    #endif
        #include "../../back/headers/calculator.h"
    #ifdef __cplusplus
}
#endif

#include <QMainWindow>
#include "QtWidgets"
#include <QTimer>
#include <QPalette>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

   public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


   private:
    Ui::MainWindow *ui;
    QLabel *inputLabel;
    QTimer *blinkTimer;
    QTimer *blinkDurationTimer;
    QColor backgroundColor; // Transparent
    QColor axisColor; // White
    QColor graphLineColor; // Orange
    bool resultDisplayed;
    bool switchField;
    double xMinBound;
    double xMaxBound;
    double yMinBound;
    double yMaxBound;
    double yMinTemp;
    double yMaxTemp;
    double calcForGraph(double x, Stack *input);
    QVector<double> calculateXValues(double xMin, double xMax);
    QVector<double> calculateYValues(QVector<double> xValues, Stack *input);
    void updateBoundsY(QVector<double>  y);
   private slots:
    void basicInputLineUI();
    void trigonometryInputLineUI();
    void clearInputLine();
    void backspaceInputLine();
    void adjustLabelFontSize(QLabel* label);
    void sendToCalculate();
    bool simpleOperationCheck(QString button);
    void switchInputField();
    void toggleLabelVisibility();
    void stopBlinking();
    bool inputLimitationX(QString button);
    void stylizePlotWindow();
    void plotGraph(QVector<double> xValues, QVector<double> yValues);
    void callPlotModule();
};
#endif  // MAINWINDOW_H
