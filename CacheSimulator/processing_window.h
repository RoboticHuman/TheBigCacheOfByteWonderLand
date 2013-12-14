#ifndef PROCESSING_WINDOW_H
#define PROCESSING_WINDOW_H

#include <QDialog>
#include <QMovie>

namespace Ui {
class Processing_Window;
}

class Processing_Window : public QDialog
{
    Q_OBJECT

public:
    explicit Processing_Window(QWidget *parent = 0);
    ~Processing_Window();
    void ApplyTextChange();
private:
    Ui::Processing_Window *ui;
    QMovie* movie;

public slots:

};

#endif // PROCESSING_WINDOW_H
