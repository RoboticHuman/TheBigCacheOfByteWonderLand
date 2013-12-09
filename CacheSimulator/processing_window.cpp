#include "processing_window.h"
#include "ui_processing_window.h"
#include "settings.h"
Processing_Window::Processing_Window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Processing_Window)
{
    ui->setupUi(this);
    movie = new QMovie(":/images/294.GIF");
    ui->label_2->setMovie(movie);
    movie->start();
}

Processing_Window::~Processing_Window()
{
    delete ui;
    delete movie;
}


