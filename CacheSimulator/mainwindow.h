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
#include "hitData.h"
class Settings;
namespace Ui
{
    class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QVector<double> x[4], QVector<double> y[4], hitdata myhits[4], QWidget *parent=NULL);
    ~MainWindow();
    QString hexadecimal(int);
    QTableWidget* table[4][4];
    QWidget *widget[4][4];
    int cacheSize, memorySize, repmethod;
    bool isFullyAssociative;
    //void Initialize_Sim();
public slots:
    //void DoWork();
private:
    Ui::MainWindow *ui;
    QVector<double> x[4];
    QVector<double> y[4];
    Graphing* mygraph;
    cacheSim* myCache;
    QScrollArea* scroll;
    QString displayCLS[4];
    QString displayType[4];

    hitdata myhits[4];

private slots:
    void on_tabWidget_currentChanged(int i);
    void on_tabWidget1_currentChanged(int index);
    void on_tabWidget2_currentChanged(int index);
    void on_tabWidget3_currentChanged(int index);
    void on_tabWidget4_currentChanged(int index);
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
