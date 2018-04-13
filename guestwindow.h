#ifndef GUESTWINDOW_H
#define GUESTWINDOW_H
#include "database.h"
#include <QDialog>

namespace Ui {
class GuestWindow;
}

class GuestWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GuestWindow(QWidget *parent = 0);
    ~GuestWindow();
    void consult();
private:
    Ui::GuestWindow *ui;
};

#endif // GUESTWINDOW_H
