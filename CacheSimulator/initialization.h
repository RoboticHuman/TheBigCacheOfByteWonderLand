#ifndef INITIALIZATION_H
#define INITIALIZATION_H

#include <QDialog>

namespace Ui {
class Initialization;
}

class Initialization : public QDialog
{
    Q_OBJECT

public:
    explicit Initialization(QWidget *parent = 0);
    ~Initialization();

private:
    Ui::Initialization *ui;
};

#endif // INITIALIZATION_H
