#ifndef GARAGE_H
#define GARAGE_H

#include <QMainWindow>

namespace Ui {
class garage;
}

class garage : public QMainWindow
{
    Q_OBJECT

public:
    explicit garage(QWidget *parent = 0);
    ~garage();
    void viewgarage();
    void viewgarage2();


private slots:
    void on_removegarage_clicked();

    void on_addgarage_clicked();

    void on_open_clicked();

    void on_close_clicked();

private:
    Ui::garage *ui;
};

#endif // GARAGE_H
