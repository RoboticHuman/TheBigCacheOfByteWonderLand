#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cacheSim.h"
#include <QString>
#include <QTableWidget>
#include "qcustomplot.h"
#include "graphing.h"
#include <QAbstractSlider>
#include <QScrollBar>
#include "graphing.h"
#include <QVector>
#include <QWidget>
class Settings;
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
    int cacheSize, memorySize, repmethod;
    bool isFullyAssociative;
    void Initialize_Sim();
public slots:
    void DoWork();
private:
    Ui::MainWindow *ui;
    QVector<double> x;
    QVector<double> y;
    Graphing* mygraph;
    cacheSim* myCache;
    QTableWidget* table1,*table2,*table3,*table4;
    QWidget *widget1,*widget2,*widget3,*widget4;
    int dude;
    QScrollArea* scroll;
    struct hitdata
    {
        int hitC;
        int missC;
        double hitR;
    };
    hitdata myhits[4];

private slots:
    void on_tabWidget_currentChanged(int index);
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
