#include "processingthedata.h"
#include <QLabel>
#include <QtGui>
#include <QApplication>
#include <QDesktopWidget>
#include <QtCore/QCoreApplication>
#include <QHeaderView>
#include <QMessageBox>
#include "qcustomplot.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include "settings.h"
#include "mywidget.h"
#include <QTableWidget>
#include <QScrollArea>
#include <QString>
#include <QVector>
#include <sstream>
#include <string>

ProcessingTheData::ProcessingTheData()
{
}

ProcessingTheData::~ProcessingTheData()
{

}

void ProcessingTheData::run()
{
    this->Initialize_Sim();
    emit DoneThread();
}

void ProcessingTheData::Initialize_Sim()
{

    for(int i=0 ; i<4 ; i++)
    {
        x[i].resize(4);
        y[i].resize(4);
    }


    for (int i=0; i<4; ++i)
    {
       for( int j=0 ; j<4 ; j++)
           x[j][i] = pow(2,i+3);
       cacheSim q( int(x[0][i]) , cacheSize , memorySize , isFullyAssociative , repmethod);
      for( int j=0 ; j<4 ; j++)
      {
          myhits[i].hitC[j]=q.Hits[j];
          myhits[i].missC[j]=100000 - q.Hits[j];
          myhits[i].hitR[j]=q.Ratio[j];
          y[j][i]=q.Ratio[j];
      }
    }
}


