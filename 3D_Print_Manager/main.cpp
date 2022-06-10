#include "mainwindow.h"
#include "Database/data_test.cpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //data_test();
    return a.exec();
}
