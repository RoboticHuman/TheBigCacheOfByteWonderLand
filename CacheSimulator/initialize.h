#ifndef INITIALIZE_H
#define INITIALIZE_H

#include <QDialog>
#include <QMovie>
namespace Ui {
class Initialize;
}

class Initialize : public QDialog
{
    Q_OBJECT

public:
    explicit Initialize(QWidget *parent = 0);
    ~Initialize();

private:
    Ui::Initialize *ui;
    QMovie* movie;
};

#endif // INITIALIZE_H
