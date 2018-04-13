#ifndef TAP_H
#define TAP_H

#include <QDialog>

namespace Ui {
class tap;
}

class tap : public QDialog
{
    Q_OBJECT

public:
    explicit tap(QWidget *parent = 0);
    ~tap();

private slots:
    void on_addtap_clicked();

    void on_deletetap_clicked();

private:
    Ui::tap *ui;
};

#endif // TAP_H
