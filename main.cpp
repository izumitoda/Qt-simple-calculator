#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.setWindowTitle("Calculator");
    //w.setWindowIcon(QIcon(":/new/prefix1/image/calculator.ico"));
    w.show();

    return a.exec();
}
