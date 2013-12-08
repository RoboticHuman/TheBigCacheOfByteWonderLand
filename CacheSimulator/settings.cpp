#include "settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(pressed()),SLOT(hide()));
}

Settings::~Settings()
{
    delete ui;
    delete win;
}

void Settings::on_pushButton_pressed()
{
    win=new MainWindow();
    if(ui->comboBox->currentText()=="1 MB")
        win->memorySize=1024*1024;
    else if(ui->comboBox->currentText()=="2 MB")
        win->memorySize=2*(1024*1024);
    else if(ui->comboBox->currentText()=="3 MB")
        win->memorySize=3*(1024*1024);
    else if(ui->comboBox->currentText()=="4 MB")
        win->memorySize=4*(1024*1024);

    if(ui->comboBox_2->currentText()=="16 KB")
        win->cacheSize=16*1024;
    else if(ui->comboBox_2->currentText()=="8 KB")
        win->cacheSize=8*1024;
    else if(ui->comboBox_2->currentText()=="32 KB")
        win->cacheSize=32*1024;

    if(ui->comboBox_3->currentText()=="Direct-Mapped")
        win->isFullyAssociative=0;
    else
        win->isFullyAssociative=1;

    if(ui->comboBox_4->currentText()=="Random Replacement")
        win->repmethod=0;
    else if(ui->comboBox_4->currentText()=="First In First Out")
        win->repmethod=1;
    else if(ui->comboBox_4->currentText()=="Least Frequently Used")
        win->repmethod=2;
    win->Initialize_Sim();
    win->show();
}
