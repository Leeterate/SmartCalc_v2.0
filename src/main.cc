#include "mainwindow.h"

//#include <QtWidgets/QApplication>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    war::MathCalculator model;
    war::Controller controller_obj(&model);
    MainWindow view(&controller_obj);
    view.setFixedSize(1100, 500);
    view.show();
    return a.exec();
}
