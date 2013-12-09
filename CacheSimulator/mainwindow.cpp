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

MainWindow::MainWindow(QWidget *parent,Settings* set)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //
    // Get the data
    //
    //connect(set, SIGNAL(blablabla()), this, SLOT(DoWork()));
}

void MainWindow::Initialize_Sim()
{
    QVector<double> x(4), y(4);
    QVector<int> hello;
     for (int i=0; i<4; ++i)
     {
       x[i] = pow(2,i+3);
       cacheSim q( int(x[i]) , cacheSize , memorySize , isFullyAssociative , repmethod);
       y[i] = q.getHitRatio();
       hello.push_back(q.numberOfCachelines);
       myhits[i].hitC=q.getHits();
       myhits[i].missC=q.getMisses();
       myhits[i].hitR=q.getHitRatio();
     }
     //     table1->addScrollBarWidget(ui->verticalScrollBar1,Qt::AlignRight);
         QStringList m_Table1Header;
         table1 = new QTableWidget(ui->widget1);
         table1->setRowCount(hello[0]);
         table1->setColumnCount(2);
         table1->verticalHeader()->setDefaultSectionSize( 15 );
         table1->horizontalHeader()->setDefaultSectionSize( 180 );
         m_Table1Header<<"Address"<<"State";
         table1->setHorizontalHeaderLabels(m_Table1Header);
         table1->verticalHeader()->setVisible(false);
         table1->setEditTriggers(QAbstractItemView::NoEditTriggers);
         table1->setSelectionBehavior(QAbstractItemView::SelectRows);
         table1->setSelectionMode(QAbstractItemView::SingleSelection);
         table1->setShowGrid(false);
         table1->setStyleSheet("QTableView {selection-background-color: blue; background-color: #ffffff; color: #004080;}");
         table1->setGeometry(QApplication::desktop()->screenGeometry());



         ifstream in;
         stringstream tsstr;
         tsstr<<"data"<<x[0]<<".dtt";
         in.open((tsstr.str()).c_str());
         string tstr;
         int k=0;
         while(getline(in,tstr))
         {
             string s1=tstr.substr(0,tstr.find(" "));
             string s2=tstr.substr(tstr.find(" ")+1,tstr.size());
              QString fileline1 = QString::fromStdString(s1);
              QString fileline2 = QString::fromStdString(s2);

                table1->setItem(k, 0, new QTableWidgetItem(fileline1));
                table1->setItem(k, 1, new QTableWidgetItem(fileline2));
                 k++;
         }
         in.close();


         table2 = new QTableWidget(ui->widget2);
         table2->setRowCount(hello[1]);
         table2->setColumnCount(2);
         table2->verticalHeader()->setDefaultSectionSize( 15 );
         table2->horizontalHeader()->setDefaultSectionSize( 180 );
         table2->setHorizontalHeaderLabels(m_Table1Header);
         table2->verticalHeader()->setVisible(false);
         table2->setEditTriggers(QAbstractItemView::NoEditTriggers);
         table2->setSelectionBehavior(QAbstractItemView::SelectRows);
         table2->setSelectionMode(QAbstractItemView::SingleSelection);
         table2->setShowGrid(false);
         table2->setStyleSheet("QTableView {selection-background-color: blue; background-color: #ffffff; color: #004080;}");
         table2->setGeometry(QApplication::desktop()->screenGeometry());



         stringstream tsstr2;
         tsstr2<<"data"<<x[1]<<".dtt";
         in.open((tsstr2.str()).c_str());
         k=0;
         while(getline(in,tstr))
         {
             string s1=tstr.substr(0,tstr.find(" "));
             string s2=tstr.substr(tstr.find(" ")+1,tstr.size());
              QString fileline1 = QString::fromStdString(s1);
              QString fileline2 = QString::fromStdString(s2);

                table2->setItem(k, 0, new QTableWidgetItem(fileline1));
                table2->setItem(k, 1, new QTableWidgetItem(fileline2));
                 k++;
         }
         in.close();




         table3 = new QTableWidget(ui->widget3);
         table3->setRowCount(hello[2]);
         table3->setColumnCount(2);
         table3->verticalHeader()->setDefaultSectionSize( 15 );
         table3->horizontalHeader()->setDefaultSectionSize( 180 );
         table3->setHorizontalHeaderLabels(m_Table1Header);
         table3->verticalHeader()->setVisible(false);
         table3->setEditTriggers(QAbstractItemView::NoEditTriggers);
         table3->setSelectionBehavior(QAbstractItemView::SelectRows);
         table3->setSelectionMode(QAbstractItemView::SingleSelection);
         table3->setShowGrid(false);
         table3->setStyleSheet("QTableView {selection-background-color: blue; background-color: #ffffff; color: #004080;}");
         table3->setGeometry(QApplication::desktop()->screenGeometry());



         stringstream tsstr3;
         tsstr3<<"data"<<x[2]<<".dtt";
         in.open((tsstr3.str()).c_str());

         k=0;
         while(getline(in,tstr))
         {
             string s1=tstr.substr(0,tstr.find(" "));
             string s2=tstr.substr(tstr.find(" ")+1,tstr.size());
              QString fileline1 = QString::fromStdString(s1);
              QString fileline2 = QString::fromStdString(s2);

                table3->setItem(k, 0, new QTableWidgetItem(fileline1));
                table3->setItem(k, 1, new QTableWidgetItem(fileline2));
                 k++;
         }
         in.close();





         table4 = new QTableWidget(ui->widget4);
         table4->setRowCount(hello[3]);
         table4->setColumnCount(2);
         table4->verticalHeader()->setDefaultSectionSize( 15 );
         table4->horizontalHeader()->setDefaultSectionSize( 180 );
         table4->setHorizontalHeaderLabels(m_Table1Header);
         table4->verticalHeader()->setVisible(false);
         table4->setEditTriggers(QAbstractItemView::NoEditTriggers);
         table4->setSelectionBehavior(QAbstractItemView::SelectRows);
         table4->setSelectionMode(QAbstractItemView::SingleSelection);
         table4->setShowGrid(false);
         table4->setStyleSheet("QTableView {selection-background-color: blue; background-color: #ffffff; color: #004080;}");
         table4->setGeometry(QApplication::desktop()->screenGeometry());



         stringstream tsstr4;
         tsstr4<<"data"<<x[3]<<".dtt";
         in.open((tsstr4.str()).c_str());
         k=0;
         while(getline(in,tstr))
         {
             string s1=tstr.substr(0,tstr.find(" "));
             string s2=tstr.substr(tstr.find(" ")+1,tstr.size());
              QString fileline1 = QString::fromStdString(s1);
              QString fileline2 = QString::fromStdString(s2);

                table4->setItem(k, 0, new QTableWidgetItem(fileline1));
                table4->setItem(k, 1, new QTableWidgetItem(fileline2));
                 k++;
         }
         in.close();


     //ui->textEdit1->addScrollBarWidget(ui->verticalScrollBar1,right);

         //connect(this, SIGNAL(on_clicked()), this, SLOT(on_tabWidget_currentChanged(int)) );


     //mygraph = new Graphing(x,y);
}

MainWindow::~MainWindow()
{
    //delete mygraph;
    delete table1;
    delete table2;
    delete table3;
    delete table4;
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


void MainWindow::on_tabWidget_currentChanged(int index)
{
    stringstream tstr[3];
    tstr[0]<<myhits[index].hitC;
    tstr[1]<<myhits[index].missC;
    tstr[2]<<myhits[index].hitR;
    ui->label_6->setText( QString::fromStdString(tstr[0].str()));
    ui->label_7->setText( QString::fromStdString(tstr[1].str()));
    ui->label_8->setText( QString::fromStdString(tstr[2].str()));
}

void MainWindow::DoWork()
{
    this->Initialize_Sim();
    this->show();
}
