#include "ui_graphing.h"
#include "graphing.h"
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

Graphing::Graphing(QVector<double> x[], QVector<double> y[] , QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Graphing)
{
    ui->setupUi(this);



    ui->customPlot->xAxis->setLabel("cache line size");
    ui->customPlot->yAxis->setLabel("hit ratio");
    ui->customPlot->xAxis->setRange(0, 70);
    ui->customPlot->yAxis->setRange(0.4, 1.0);
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables | QCP::iMultiSelect);

    Qt::GlobalColor theColor[4] = { Qt::blue , Qt::red , Qt::green , Qt::black };
    for(int i=0 ; i<4 ; i++)
    {
        ui->customPlot->addGraph();
        ui->customPlot->graph(i)->setData(x[i], y[i]);
        /*std::cout<<x[i][0]<<" "<<y[i][0]<<std::endl;
        std::cout<<x[i][1]<<" "<<y[i][1]<<std::endl;
        std::cout<<x[i][2]<<" "<<y[i][2]<<std::endl;
        std::cout<<x[i][3]<<" "<<y[i][3]<<std::endl<<std::endl;
        */
        ui->customPlot->graph(i)->setPen(QPen(theColor[i]));
        ui->customPlot->replot();
    }
}

Graphing::~Graphing()
{
    delete ui;
}


void Graphing::on_pushButton_clicked()
{
    QString fileNames = QFileDialog::getSaveFileName(this, tr("Save File"),"/path/to/file/",tr("JPEG Files (*.jpg)"));
    //getOpenFileNames(this, tr("Open File"),"/path/to/file/",tr("PDF Files (*.jpg)"));
    ui->customPlot->saveJpg(fileNames);
}

void Graphing::on_pushButton_2_clicked()
{
    QString fileNames = QFileDialog::getSaveFileName(this, tr("Save File"),"/path/to/file/",tr("PDF Files (*.pdf)"));
    //getOpenFileNames(this, tr("Open File"),"/path/to/file/",tr("PDF Files (*.pdf)"));
    ui->customPlot->savePdf(fileNames);
}
