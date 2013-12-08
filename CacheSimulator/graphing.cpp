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

Graphing::Graphing(QVector<double> &x, QVector<double>&y , QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Graphing)
{
    ui->setupUi(this);

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);
    ui->customPlot->xAxis->setLabel("cache line size");
    ui->customPlot->yAxis->setLabel("hit ratio");
    ui->customPlot->xAxis->setRange(0, 70);
    ui->customPlot->yAxis->setRange(0.75, 0.9);
    ui->customPlot->replot();
}

Graphing::~Graphing()
{
    delete ui;
}

// QString fileNames = QFileDialog::getSaveFileName(this, tr("Save File"),"/path/to/file/",tr("PDF Files (*.pdf)"));
       //  getOpenFileNames(this, tr("Open File"),"/path/to/file/",tr("PDF Files (*.pdf)"));
//   ui->customPlot->savePdf(fileNames);
