#include "initialize.h"
#include "ui_initialize.h"

Initialize::Initialize(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Initialize)
{
    ui->setupUi(this);
    movie = new QMovie(":/images/294.GIF");
    ui->label_2->setMovie(movie);
    movie->start();
}

Initialize::~Initialize()
{
    delete ui;
    delete movie;
}
