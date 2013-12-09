#include "mainwindow.h"
#include <QApplication>
#include "settings.h"
#include "initialize.h"
#include <QTimer>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Settings s;
    Initialize init;
    init.show();
    QTimer::singleShot(4000,&s, SLOT(show()));
    QTimer::singleShot(4000,&init, SLOT(hide()));
    return a.exec();
}
