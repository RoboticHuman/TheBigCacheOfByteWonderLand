#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cacheSim.h"
#include <QString>
#include <QTableWidget>
#include "qcustomplot.h"
#include "graphing.h"
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
    Graphing* mygraph;
    cacheSim* myCache;
    QTableWidget* table1,*table2,*table3,*table4;
};

#endif // MAINWINDOW_H
