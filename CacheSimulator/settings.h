#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include "mainwindow.h"
#include "processing_window.h"

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
private slots:
    void on_pushButton_pressed();



private:
    Ui::Settings *ui;
    MainWindow* win;
    Processing_Window* processing;
};

#endif // SETTINGS_H
