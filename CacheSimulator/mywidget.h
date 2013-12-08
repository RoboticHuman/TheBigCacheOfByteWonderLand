#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include "nightcharts.h"
class mywidget : public QWidget
{
    Q_OBJECT
public:
    explicit mywidget(double hits, QWidget *parent = 0);
     void paintEvent(QPaintEvent* );
     double hits;
signals:

public slots:

};

#endif // MYWIDGET_H
