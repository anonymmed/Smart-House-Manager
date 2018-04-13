#ifndef SECURITY_H
#define SECURITY_H
#include <QMainWindow>

namespace Ui {
class security;
}

class security : public QMainWindow
{
    Q_OBJECT

public:
    explicit security(QWidget *parent = 0);
    ~security();
private slots:


    void on_activate_clicked();
    void on_desactivate_clicked();
    void on_addalarm_clicked();
    void on_deletealarm_clicked();
    void on_pushButton_clicked();

private:
    Ui::security *ui;
};

#endif // SECURITY_H
