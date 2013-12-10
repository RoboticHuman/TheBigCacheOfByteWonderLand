#ifndef GRAPHING_H
#define GRAPHING_H

#include <QDialog>
#include <QString>
#include "qcustomplot.h"

namespace Ui {
class Graphing;
}

class Graphing : public QDialog
{
    Q_OBJECT

public:
    explicit Graphing( QVector<double> &, QVector<double> &, QWidget *parent = 0);
    ~Graphing();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Graphing *ui;
};

#endif // GRAPHING_H
