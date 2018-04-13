#include "adminwindow.h"
#include "ui_adminwindow.h"
#include "database.h"
#include "security.h"
#include "garage.h"
#include "light.h"
#include  "tap.h"
#include "temperature.h"
adminwindow::adminwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminwindow)
{
    ui->setupUi(this);
    ui->label_tap->setStyleSheet("background-image:url('C:/Users/apple/Desktop/root/trunk/med/fin/smarthousemanager/gfx/Finalcons/tap.png')");
    ui->label_security->setStyleSheet("background-image:url('C:/Users/apple/Desktop/root/trunk/med/fin/smarthousemanager/gfx/Finalcons/padlock.png')");
    ui->label_garage->setStyleSheet("background-image:url('C:/Users/apple/Desktop/root/trunk/med/fin/smarthousemanager/gfx/Finalcons/garage.png')");
    ui->label_light->setStyleSheet("background-image:url('C:/Users/apple/Desktop/root/trunk/med/fin/smarthousemanager/gfx/Finalcons/light.png')");
    ui->label_temperature->setStyleSheet("background-image:url('C:/Users/apple/Desktop/root/trunk/med/fin/smarthousemanager/gfx/Finalcons/thermometer.png')");
    ui->label_user->setStyleSheet("background-image:url('C:/Users/apple/Desktop/root/trunk/med/fin/smarthousemanager/gfx/Finalcons/man.png')");
    ui->background->setStyleSheet("background-image:url('C:/Users/apple/Desktop/root/trunk/med/fin/smarthousemanager/gfx/c.png')");

}


adminwindow::~adminwindow()
{
    delete ui;
}

void adminwindow::on_pushButton_secutiry_clicked()
{
    security* s=new security(this);
    this->hide();
    s->show();

}

void adminwindow::on_pushButton_garage_clicked()
{
    this->close();
    garage* g=new garage(this);
    g->show();
}

void adminwindow::on_pushButton_clicked()
{
    this->parentWidget()->show();
    this->close();
}

void adminwindow::on_pushButton_light_clicked()
{
    light* l=new light(this);
    this->close();
    l->show();

}

void adminwindow::on_pushButton_tap_clicked()
{
    tap *t = new tap(this);
    this->close();
    t->show();
}

void adminwindow::on_pushButton_temperature_clicked()
{
    temperature* t=new temperature(this);
    this->close();
    t->show();
}

void adminwindow::on_pushButton_user_clicked()
{

}
