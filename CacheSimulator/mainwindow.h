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
    QVector<double> x[4];
    QVector<double> y[4];
    Graphing* mygraph;
    cacheSim* myCache;
    QTableWidget* table[4][4];
    QWidget *widget[4][4];
    QScrollArea* scroll;
    QString displayCLS[4];
    QString displayType[4];
    struct hitdata
    {
        int hitC[4];
        int missC[4];
        double hitR[4];
    };
    hitdata myhits[4];

private slots:
    void on_tabWidget1_currentChanged(int index);
    void on_tabWidget2_currentChanged(int index);
    void on_tabWidget3_currentChanged(int index);
    void on_tabWidget4_currentChanged(int index);
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
