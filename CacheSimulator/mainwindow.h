#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include "cacheSim.h"
#include <QString>
#include "qcustomplot.h"
namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString hexadecimal(int);
private:
    Ui::MainWindow *ui;

    cacheSim* myCache;
};

#endif // MAINWINDOW_H
