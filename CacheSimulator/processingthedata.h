#ifndef PROCESSINGTHEDATA_H
#define PROCESSINGTHEDATA_H


#include "cacheSim.h"
#include <QString>
#include <QTableWidget>
#include <QAbstractSlider>
#include <QScrollBar>
#include <QVector>
#include <QWidget>
#include "hitData.h"
#include "mainwindow.h"
#include <QtCore>
class ProcessingTheData :public QThread
{
    Q_OBJECT
public:
    ProcessingTheData();
    ~ProcessingTheData();
    int cacheSize, memorySize, repmethod;
    bool isFullyAssociative;
    void Initialize_Sim();
    void run();
    QVector<double> x[4];
    QVector<double> y[4];
    cacheSim* myCache;

    hitdata myhits[4];
    MainWindow* myMain;
    bool bDone;
signals:
    void DoneThread();
};

#endif // PROCESSINGTHEDATA_H
