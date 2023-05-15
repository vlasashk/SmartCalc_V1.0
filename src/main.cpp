#include <QApplication>
#include <QFontMetrics>
#include <QMenuBar>

#include "front/headers/creditcalc.h"
#include "front/headers/mainwindow.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    QMenuBar* menuBar = new QMenuBar();
    QMenu* modeMenu = menuBar->addMenu("View mode");
    QAction* basicModeAction = modeMenu->addAction("Basic");
    QAction* creditModeAction = modeMenu->addAction("Credit");

    QWidget* calculator = new MainWindow();
    QObject::connect(basicModeAction, &QAction::triggered, [&]() {
        if (calculator) {
            delete calculator;
        }
        calculator = new MainWindow();
        calculator->show();
    });
    QObject::connect(creditModeAction, &QAction::triggered, [&]() {
        if (calculator) {
            delete calculator;
        }
        calculator = new CreditCalc();
        calculator->show();
    });
    calculator->show();
    int result = a.exec();
    if (calculator) {
        delete calculator;
    }
    delete menuBar;

    return result;
}
