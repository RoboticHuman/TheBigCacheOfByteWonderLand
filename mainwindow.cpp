#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QtGui>
#include <QApplication>
#include <QDesktopWidget>
#include <QtCore/QCoreApplication>
#include <QHeaderView>
#include <QMessageBox>

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
      m_pTableWidget(NULL)
{
    m_pTableWidget = new QTableWidget(this);
    m_pTableWidget->setRowCount(10);
    m_pTableWidget->setColumnCount(3);
    m_TableHeader<<"Address"<<"Validity"<<"Tag";
    m_pTableWidget->setHorizontalHeaderLabels(m_TableHeader);
    m_pTableWidget->verticalHeader()->setVisible(false);
    m_pTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_pTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_pTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    m_pTableWidget->setShowGrid(false);
    m_pTableWidget->setStyleSheet("QTableView {selection-background-color: blue;}");
    m_pTableWidget->setGeometry(QApplication::desktop()->screenGeometry());

    //insert data
    for(int i=0 ; i<10 ; i++)
    m_pTableWidget->setItem(i, 0, new QTableWidgetItem("Hello"));

    connect( m_pTableWidget, SIGNAL( cellDoubleClicked (int, int) ),
             this, SLOT( cellSelected( int, int ) ) );
}

MainWindow::~MainWindow()
{
}

void MainWindow::cellSelected(int nRow, int nCol)
{
    QMessageBox::information(this, "",
                            "Cell at row "+QString::number(nRow)+
                             " column "+QString::number(nCol)+
                             " was double clicked.");
}
