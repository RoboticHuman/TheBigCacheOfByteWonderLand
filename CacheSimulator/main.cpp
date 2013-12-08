#include "mainwindow.h"
#include <QApplication>
#include "settings.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Settings s;
    s.show();
    return a.exec();
}
