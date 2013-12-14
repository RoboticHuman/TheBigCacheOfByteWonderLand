#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include "mainwindow.h"
#include "processing_window.h"
#include "processingthedata.h"
#include <QTableWidget>
#include <QWidget>
namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = 0);
    ~Settings();

    void emitsignal();
signals:
    void blablabla();
    void ChangeText();
private slots:
    void on_pushButton_pressed();

public slots:
    void onDoneThread();

private:
    Ui::Settings *ui;
    ProcessingTheData* win;
    Processing_Window* processing;
    MainWindow* myMain;
};

#endif // SETTINGS_H
