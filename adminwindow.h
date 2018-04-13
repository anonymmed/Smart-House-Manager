#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QDialog>

namespace Ui {
class adminwindow;
}

class adminwindow : public QDialog
{
    Q_OBJECT

public:
    explicit adminwindow(QWidget *parent = 0);
    ~adminwindow();

private slots:
    void on_pushButton_secutiry_clicked();

    void on_pushButton_garage_clicked();

    void on_pushButton_clicked();

    void on_pushButton_light_clicked();

    void on_pushButton_tap_clicked();

    void on_pushButton_temperature_clicked();

private:
    Ui::adminwindow *ui;
};

#endif // ADMINWINDOW_H
