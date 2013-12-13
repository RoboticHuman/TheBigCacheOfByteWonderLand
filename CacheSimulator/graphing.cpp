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
    Qt::GlobalColor theColor[5] = { Qt::blue , Qt::red , Qt::green , Qt::black , Qt::cyan};

    //*****************************************************************\\
    ui->customPlot->xAxis->setLabel("cache line size");
    ui->customPlot->yAxis->setLabel("hit ratio");
    ui->customPlot->xAxis->setRange(0, 70);
    ui->customPlot->yAxis->setRange(0, 1.2);
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables | QCP::iMultiSelect);

    for(int i=0 ; i<4 ; i++)
    {
        ui->customPlot->addGraph();
        ui->customPlot->graph(i)->setData(x[i], y[i]);
        ui->customPlot->graph(i)->setPen(QPen(theColor[i]));
        ui->customPlot->replot();
    }
    //*****************************************************************\\

    QVector<double> dude;
    dude.push_back(8);
    dude.push_back(20);
    dude.push_back(32);
    dude.push_back(44);

    QVector<QString> displayType;
    displayType.resize(4);
    displayType[0]="8 Bytes";
    displayType[1]="16 Bytes";
    displayType[2]="32 Bytes";
    displayType[3]="64 Bytes";

    ui->customPlot_2->xAxis->setLabel("Cache Line Size");
    ui->customPlot_2->yAxis->setLabel("hit ratio");
    ui->customPlot_2->xAxis->setRange(0, 52);
    ui->customPlot_2->yAxis->setRange(0, 1.2);
    ui->customPlot_2->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables | QCP::iMultiSelect);
    ui->customPlot_2->xAxis->setAutoTickLabels(false);
    ui->customPlot_2->xAxis->setAutoTicks(false);
    ui->customPlot_2->xAxis->setAutoTickStep(false);
    ui->customPlot_2->xAxis->setTickVector(dude);
    ui->customPlot_2->xAxis->setTickVectorLabels(displayType);

    for(int i=0 ; i<4 ; i++)
        for(int j=0 ; j<4 ; j++)
            x[i][j]=8+(12*j)-3+(2*i);
    for(int i=0 ; i<4 ; i++)
    {
        myBars[i]= new QCPBars(ui->customPlot_2->xAxis, ui->customPlot_2->yAxis);
        ui->customPlot_2->addPlottable(myBars[i]);
        myBars[i]->setWidth(2);
        myBars[i]->setData(x[i],y[i]);
        myBars[i]->setBrush(theColor[i]);

        //ui->customPlot_2->graph(i)->setData(x[i], y[i]);
        //ui->customPlot_2->graph(i)->setPen(QPen(theColor[i]));
        //ui->customPlot_2->rescaleAxes();
        ui->customPlot_2->replot();
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

void Graphing::on_pushButton_3_clicked()
{
    QString fileNames = QFileDialog::getSaveFileName(this, tr("Save File"),"/path/to/file/",tr("PDF Files (*.pdf)"));
    //getOpenFileNames(this, tr("Open File"),"/path/to/file/",tr("PNG Files (*.png)"));
    ui->customPlot->savePng(fileNames);
}

void Graphing::on_pushButton_4_clicked()
{
    QString fileNames = QFileDialog::getSaveFileName(this, tr("Save File"),"/path/to/file/",tr("PDF Files (*.pdf)"));
    //getOpenFileNames(this, tr("Open File"),"/path/to/file/",tr("BMP Files (*.bmp)"));
    ui->customPlot->saveBmp(fileNames);
}
