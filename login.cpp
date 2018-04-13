#include "login.h"
#include "ui_login.h"
#include <QString>
login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    this->setFixedSize(811,533);
    QString path="c:/Users/game/Desktop/";
   this->setStyleSheet("background-image:url('"+path+"/b.png');");
}

login::~login()
{
    delete ui;
}
