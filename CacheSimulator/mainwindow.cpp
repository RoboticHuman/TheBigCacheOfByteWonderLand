#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QTableWidget>
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
#include <fstream>
#include <sstream>
#include "settings.h"
#include "mywidget.h"
#include <QScrollArea>

MainWindow::MainWindow(QVector<double> x[4], QVector<double> y[4], hitdata myhits[4], bool cacheType
, int lineReplacement, QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    QString cacheT[2] = {"Direct Mapped Cache","Fully Associative Cache"};
    QString lineR[3] = {"Random Replacement","FIFO Replacement","LFU Replacement"};
    ui->setupUi(this);
    //
    // Get the data
    //
    //connect(set, SIGNAL(blablabla()), this, SLOT(DoWork()));

    ui->label_16->setText(cacheT[cacheType]);
    if(cacheType)
        ui->label_17->setText(lineR[lineReplacement]);
    for(int i=0 ; i<4 ; i++)
    {
        this->x[i].resize(4);
        this->y[i].resize(4);
    }

    for(int i=0 ; i<4 ; i++)
        for(int j=0 ; j<4 ; j++)
        {
            this->myhits[i].hitC[j]=myhits[i].hitC[j];
            this->myhits[i].missC[j]=myhits[i].missC[j];
            this->myhits[i].hitR[j]=myhits[i].hitR[j];
            this->x[j][i]=x[j][i];
            this->y[j][i]=y[j][i];
        }

    displayCLS[0]="8 Bytes";
    displayCLS[1]="16 Bytes";
    displayCLS[2]="32 Bytes";
    displayCLS[3]="64 Bytes";

    displayType[0]="Random";
    displayType[1]="Sequential";
    displayType[2]="Small-Range Loop";
    displayType[3]="Wide-Range Loop";



    for(int i=0 ; i<4 ; i++)
        for( int j=0 ; j<4 ; j++)
       {
        widget[i][j] = new QWidget;
        QStringList m_Table1Header;
        table[i][j] = new QTableWidget(widget[i][j]);
        table[i][j]->setRowCount(100000);
        table[i][j]->setColumnCount(2);
        table[i][j]->verticalHeader()->setDefaultSectionSize( 15 );
        table[i][j]->horizontalHeader()->setDefaultSectionSize( 180 );
        m_Table1Header<<"Address"<<"State";
        table[i][j]->setHorizontalHeaderLabels(m_Table1Header);
        table[i][j]->verticalHeader()->setVisible(false);
        table[i][j]->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table[i][j]->setSelectionBehavior(QAbstractItemView::SelectRows);
        table[i][j]->setSelectionMode(QAbstractItemView::SingleSelection);
        table[i][j]->setShowGrid(false);
        table[i][j]->setStyleSheet("QTableView {selection-background-color: blue; background-color: #ffffff; color: #004080;}");
        table[i][j]->setGeometry(QApplication::desktop()->screenGeometry());
   }


        ifstream in;
        stringstream* tsstr;

        tsstr= new stringstream;
        *(tsstr)<<"data"<<x[0][0]<<".dtt";
        in.open((tsstr->str()).c_str());
        for(int j=0 ; j<4 ; j++)
        {
           for(int i=0 ; i<100000 ; i++)
           {
               string s1,s2;
               in>> s1 >>s2;
               QString fileline1 = QString::fromStdString(s1);
               QString fileline2 = QString::fromStdString(s2);

               table[0][j]->setItem(i, 0, new QTableWidgetItem(fileline1));
               table[0][j]->setItem(i, 1, new QTableWidgetItem(fileline2));

           }
        }
        in.close();
        delete tsstr;



       //******************************************************************************************

        tsstr= new stringstream;
        *tsstr<<"data"<<x[1][0]<<".dtt";
        in.open((tsstr->str()).c_str());
        for(int j=0 ; j<4 ; j++)
        {
            for(int i=0 ; i<100000 ; i++)
            {
                string s1,s2;
                in>> s1 >>s2;
                QString fileline1 = QString::fromStdString(s1);
                QString fileline2 = QString::fromStdString(s2);

                table[1][j]->setItem(i, 0, new QTableWidgetItem(fileline1));
                table[1][j]->setItem(i, 1, new QTableWidgetItem(fileline2));

            }
        }
        in.close();
        delete tsstr;



        //******************************************************************************************

        tsstr= new stringstream;
        *tsstr<<"data"<<x[2][0]<<".dtt";
        in.open((tsstr->str()).c_str());
        for(int j=0 ; j<4 ; j++)
        {
            for(int i=0 ; i<100000 ; i++)
            {
                string s1,s2;
                in>> s1 >>s2;
                QString fileline1 = QString::fromStdString(s1);
                QString fileline2 = QString::fromStdString(s2);

                table[2][j]->setItem(i, 0, new QTableWidgetItem(fileline1));
                table[2][j]->setItem(i, 1, new QTableWidgetItem(fileline2));

            }
        }
        in.close();
        delete tsstr;


        //******************************************************************************************

        tsstr= new stringstream;
        *tsstr<<"data"<<x[3][0]<<".dtt";
        in.open((tsstr->str()).c_str());
        for(int j=0 ; j<4 ; j++)
        {
            for(int i=0 ; i<100000 ; i++)
            {
                string s1,s2;
                in>> s1 >>s2;
                QString fileline1 = QString::fromStdString(s1);
                QString fileline2 = QString::fromStdString(s2);

                table[3][j]->setItem(i, 0, new QTableWidgetItem(fileline1));
                table[3][j]->setItem(i, 1, new QTableWidgetItem(fileline2));

            }
        }
        in.close();
        delete tsstr;






         ui->scrollArea_1->setGeometry(table[0][0]->geometry());
         ui->scrollArea_1->setWidget(table[0][0]);
         ui->scrollArea_2->setGeometry(table[0][1]->geometry());
         ui->scrollArea_2->setWidget(table[0][1]);
         ui->scrollArea_3->setGeometry(table[0][2]->geometry());
         ui->scrollArea_3->setWidget(table[0][2]);
         ui->scrollArea_4->setGeometry(table[0][3]->geometry());
         ui->scrollArea_4->setWidget(table[0][3]);
         ui->scrollArea_5->setGeometry(table[1][0]->geometry());
         ui->scrollArea_5->setWidget(table[1][0]);
         ui->scrollArea_6->setGeometry(table[1][1]->geometry());
         ui->scrollArea_6->setWidget(table[1][1]);
         ui->scrollArea_7->setGeometry(table[1][2]->geometry());
         ui->scrollArea_7->setWidget(table[1][2]);
         ui->scrollArea_8->setGeometry(table[1][3]->geometry());
         ui->scrollArea_8->setWidget(table[1][3]);
         ui->scrollArea_9->setGeometry(table[2][0]->geometry());
         ui->scrollArea_9->setWidget(table[2][0]);
         ui->scrollArea_10->setGeometry(table[2][1]->geometry());
         ui->scrollArea_10->setWidget(table[2][1]);
         ui->scrollArea_11->setGeometry(table[2][2]->geometry());
         ui->scrollArea_11->setWidget(table[2][2]);
         ui->scrollArea_12->setGeometry(table[2][3]->geometry());
         ui->scrollArea_12->setWidget(table[2][3]);
         ui->scrollArea_13->setGeometry(table[3][0]->geometry());
         ui->scrollArea_13->setWidget(table[3][0]);
         ui->scrollArea_14->setGeometry(table[3][1]->geometry());
         ui->scrollArea_14->setWidget(table[3][1]);
         ui->scrollArea_15->setGeometry(table[3][2]->geometry());
         ui->scrollArea_15->setWidget(table[3][2]);
         ui->scrollArea_16->setGeometry(table[3][3]->geometry());
         ui->scrollArea_16->setWidget(table[3][3]);


         stringstream tstr[3];
         tstr[0]<<myhits[0].hitC[0];
         tstr[1]<<myhits[0].missC[0];
         tstr[2]<<myhits[0].hitR[0];
         ui->label_6->setText( QString::fromStdString(tstr[0].str()));
         ui->label_7->setText( QString::fromStdString(tstr[1].str()));
         ui->label_8->setText( QString::fromStdString(tstr[2].str()));
         ui->label_10->setText(displayCLS[0]);
         ui->label_12->setText(displayType[0]);
         ui->PlotRegion->hits=myhits[0].hitR[0]*100.0;
         ui->PlotRegion->update();

         this->show();

}

//void MainWindow::Initialize_Sim()
//{
//
//
//}

MainWindow::~MainWindow()
{
    delete mygraph;
//    for(int i=0 ; i<4 ; i++)
//        for(int j=0 ; j<4 ; j++)
//        {
//            delete widget[i][j];
//            delete table[i][j];
//        }
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


void MainWindow::on_tabWidget_currentChanged(int i)
{
    int j=0;
    switch(i)
    {
    case 0:
        if(ui->tab1_1->isVisible())
            j=0;
        else if(ui->tab1_2->isVisible())
            j=1;
        else if(ui->tab1_3->isVisible())
            j=2;
        else if(ui->tab1_4->isVisible())
            j=3;
        on_tabWidget1_currentChanged(j);
        break;
    case 1:
        if(ui->tab2_1->isVisible())
            j=0;
        else if(ui->tab2_2->isVisible())
            j=1;
        else if(ui->tab2_3->isVisible())
            j=2;
        else if(ui->tab2_4->isVisible())
            j=3;
        on_tabWidget2_currentChanged(j);
        break;
    case 2:
        if(ui->tab3_1->isVisible())
            j=0;
        else if(ui->tab3_2->isVisible())
            j=1;
        else if(ui->tab3_3->isVisible())
            j=2;
        else if(ui->tab3_4->isVisible())
            j=3;
        on_tabWidget3_currentChanged(j);
        break;
    case 3:
        if(ui->tab4_1->isVisible())
            j=0;
        else if(ui->tab4_2->isVisible())
            j=1;
        else if(ui->tab4_3->isVisible())
            j=2;
        else if(ui->tab4_4->isVisible())
            j=3;
        on_tabWidget4_currentChanged(j);
    }
}

void MainWindow::on_tabWidget1_currentChanged(int j)
{
    stringstream tstr[3];
    tstr[0]<<myhits[0].hitC[j];
    tstr[1]<<myhits[0].missC[j];
    tstr[2]<<myhits[0].hitR[j];
    ui->label_6->setText( QString::fromStdString(tstr[0].str()));
    ui->label_7->setText( QString::fromStdString(tstr[1].str()));
    ui->label_8->setText( QString::fromStdString(tstr[2].str()));
    ui->label_10->setText(displayCLS[0]);
    ui->label_12->setText(displayType[j]);
    ui->PlotRegion->hits=myhits[0].hitR[j]*100.0;
    ui->PlotRegion->update();
}

void MainWindow::on_tabWidget2_currentChanged(int j)
{
    stringstream tstr[3];
    tstr[0]<<myhits[1].hitC[j];
    tstr[1]<<myhits[1].missC[j];
    tstr[2]<<myhits[1].hitR[j];
    ui->label_6->setText( QString::fromStdString(tstr[0].str()));
    ui->label_7->setText( QString::fromStdString(tstr[1].str()));
    ui->label_8->setText( QString::fromStdString(tstr[2].str()));
    ui->label_10->setText(displayCLS[1]);
    ui->label_12->setText(displayType[j]);
    ui->PlotRegion->hits=myhits[1].hitR[j]*100.0;
    ui->PlotRegion->update();
}

void MainWindow::on_tabWidget3_currentChanged(int j)
{
    stringstream tstr[3];
    tstr[0]<<myhits[2].hitC[j];
    tstr[1]<<myhits[2].missC[j];
    tstr[2]<<myhits[2].hitR[j];
    ui->label_6->setText( QString::fromStdString(tstr[0].str()));
    ui->label_7->setText( QString::fromStdString(tstr[1].str()));
    ui->label_8->setText( QString::fromStdString(tstr[2].str()));
    ui->label_10->setText(displayCLS[2]);
    ui->label_12->setText(displayType[j]);
    ui->PlotRegion->hits=myhits[2].hitR[j]*100.0;
    ui->PlotRegion->update();
}

void MainWindow::on_tabWidget4_currentChanged(int j)
{
    stringstream tstr[3];
    tstr[0]<<myhits[3].hitC[j];
    tstr[1]<<myhits[3].missC[j];
    tstr[2]<<myhits[3].hitR[j];
    ui->label_6->setText( QString::fromStdString(tstr[0].str()));
    ui->label_7->setText( QString::fromStdString(tstr[1].str()));
    ui->label_8->setText( QString::fromStdString(tstr[2].str()));
    ui->label_10->setText(displayCLS[3]);
    ui->label_12->setText(displayType[j]);
    ui->PlotRegion->hits=myhits[3].hitR[j]*100.0;
    ui->PlotRegion->update();

}

//void MainWindow::DoWork()
//{
//    this->Initialize_Sim();
//    this->show();
//}

void MainWindow::on_pushButton_clicked()
{
    mygraph=new Graphing(x,y);
    mygraph->show();
}
