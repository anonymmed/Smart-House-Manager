#ifndef LIGHT_H
#define LIGHT_H

#include <QDialog>
#include "flight.h"
namespace Ui {
class light;
}

class light : public QDialog
{
    Q_OBJECT

public:
    explicit light(QWidget *parent = 0);
    ~light();

private slots:
    void on_pushButton_clicked();

    void on_turnon_clicked();

    void on_turnoff_clicked();

    void on_addlight_clicked();

    void on_deletelight_clicked();

private:
    Ui::light *ui;
};

#endif // LIGHT_H
