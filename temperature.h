#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <QDialog>

namespace Ui {
class temperature;
}

class temperature : public QDialog
{
    Q_OBJECT

public:
    explicit temperature(QWidget *parent = 0);
    ~temperature();

private slots:
    void on_pushButton_clicked();

private:
    Ui::temperature *ui;
};

#endif // TEMPERATURE_H
