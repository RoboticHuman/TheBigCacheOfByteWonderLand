#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QtGui>
#include <QApplication>
#include <QDesktopWidget>
#include <QtCore/QCoreApplication>
#include <QHeaderView>
#include <QMessageBox>
#include <QString>
#include <QVector>
#include <string>
#include "qcustomplot.h"
#include <cmath>
#include <iostream>
/*
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//  QLabel *w = new QLabel(this);
//  w->setFrameStyle(QFrame::Panel | QFrame::Sunken);
//  QMovie *movie = new QMovie("D:/Images/coin.gif");
//  w->setMovie (movie);
//  movie->start ();


}

MainWindow::~MainWindow()
{
    delete ui;
}
*/
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //
    // Get the data
    //
   int cacheSize=16*1024, memorySize=1024*1024 , repmethod=0;
    bool isFullyAssociative=1;

   QVector<double> x(4), y(4);
    for (int i=0; i<4; ++i)
    {
      x[i] = pow(2,i+3);
      cacheSim q( int(x[i]) , cacheSize , memorySize , isFullyAssociative , repmethod);
      y[i] = q.getHitRatio();
      //y[i]=x[i];
      cout<<y[i];
    }

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);
    ui->customPlot->xAxis->setLabel("cache line size");
    ui->customPlot->yAxis->setLabel("hit ratio");
    ui->customPlot->xAxis->setRange(0, 70);
    ui->customPlot->yAxis->setRange(0.75, 0.9);
    ui->customPlot->replot();

    ui->customPlot->savePdf("graph.pdf");
}

MainWindow::~MainWindow()
{
}



QString MainWindow::hexadecimal(int m)
{
    string C[16]={"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
    string s;
    for(int i=0 ; i<8 ; i++)
    {
        s.insert(0,C[m%16]);
         m=m/16;
    }
    s.insert(0,"0x");
    QString qstr = QString::fromStdString(s);
    return qstr;
}
