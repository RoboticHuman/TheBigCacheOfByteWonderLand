#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void cellSelected(int nRow, int nCol);

private:
    Ui::MainWindow *ui;
    QTableWidget* m_pTableWidget;

    QStringList m_TableHeader;


};

#endif // MAINWINDOW_H
