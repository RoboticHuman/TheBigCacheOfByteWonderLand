#include "mywidget.h"

mywidget::mywidget(double hits, QWidget *parent) :
    QWidget(parent)
{
    this->hits=hits;
}

void mywidget::paintEvent(QPaintEvent* e)
{
QWidget::paintEvent(e);
QPainter painter;
painter.begin(this);
Nightcharts PieChart;
PieChart.setType(Nightcharts::Dpie);//{Histogramm,Pie,DPie};
PieChart.setLegendType(Nightcharts::Round);//{Round,Vertical}
PieChart.setCords(150,50,this->width()/3.0,this->height()/3.0);
PieChart.addPiece("Hits",Qt::green,hits);
PieChart.addPiece("Misses",Qt::red,100-hits);

PieChart.draw(&painter);
PieChart.drawLegend(&painter);
}
