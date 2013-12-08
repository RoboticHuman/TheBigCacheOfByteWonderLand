#include "initialization.h"
#include "ui_initialization.h"
#include <QMovie>
Initialization::Initialization(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Initialization)
{
    ui->setupUi(this);
    QMovie* spinnerMovie = new QMovie(":/metro-loading.gif");
    ui->label_2->setMovie(spinnerMovie);
    spinnerMovie->start();
}

Initialization::~Initialization()
{
    delete ui;
}
