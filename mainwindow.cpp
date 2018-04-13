#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "authentification.h"
#include "guestwindow.h"
#include "adminwindow.h"
#include "signup.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/apple/Desktop/root/trunk/med/fin/smarthousemanager/gfx/b.png");
    ui->background->setPixmap(pix);
}


MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_login_clicked()
{
    authentification login(ui->username->text(),ui->password->text());
    if (login.verify())
    {
        if(login.redirect()=="admin")
        {
            adminwindow* a=new adminwindow(this);
            this->close();
            a->show();
        }
        else if (login.redirect()=="guest")
        {
                  GuestWindow* g=new GuestWindow(this);
                  this->close();
                  g->show();

        }
        else
        {
            //exit
        }
    }
}

void MainWindow::on_checkBox_clicked()
{
    if (ui->checkBox->checkState()==Qt::Checked)
    {
    ui->password->setEchoMode(QLineEdit::Normal);

    }
    else if (ui->checkBox->checkState()== Qt::Unchecked)
    {
        ui->password->setEchoMode(QLineEdit::Password);

    }

}

void MainWindow::on_signup_clicked()
{
    this->close();
    signup* s=new signup(this);
    s->show();
}
