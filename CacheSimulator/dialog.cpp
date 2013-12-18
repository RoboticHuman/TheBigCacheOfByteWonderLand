#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    a = QDir(QCoreApplication::applicationDirPath()).absoluteFilePath("report/report.txt");
    getTextFile();
}

void statistics_easy::getTextFile()
{
    QFile myfile(a);
    myfile.open(QIODevice::ReadOnly);
    QTextStream textStream(&myfile);
    QString line = textStream.readAll();
    myfile.close();
    ui->plainTextEdit->setPlainText(line);
}

Dialog::~Dialog()
{
    delete ui;
}
