#include "signup.h"
#include "ui_signup.h"
#include "fsignup.h"
signup::signup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
    if(fsignup::checkexistance())
    {
        ui->type->hide();
    }
    else
    {
        ui->type->show();
    }
}

signup::~signup()
{
    delete ui;
}

void signup::on_pushButton_clicked()
{
if (fsignup::checkexistance())
{
    if(fsignup::guestsignup(ui->id,ui->username,ui->password))
    {
        this->close();
        this->parentWidget()->show();
    }
    else
    {
        QMessageBox::information(this,"error","error creating user ! ");
    }
}
else
{
    if(fsignup::adminsignup(ui->id,ui->username,ui->password,ui->type))
    {
        this->close();
        this->parentWidget()->show();
    }
    else
    {
        QMessageBox::information(this,"error","error creating user ! ");
    }

    }
}
