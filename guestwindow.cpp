#include "guestwindow.h"
#include "ui_guestwindow.h"
#include <QDebug>
GuestWindow::GuestWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GuestWindow)
{
    ui->setupUi(this);
    ui->TapLogo->setStyleSheet("background-image:url('C:/Users/apple/Desktop/root/trunk/med/fin/smarthousemanager/gfx/Finalcons/tap.png')");
    ui->SecurityLogo->setStyleSheet("background-image:url('C:/Users/apple/Desktop/root/trunk/med/fin/smarthousemanager/gfx/Finalcons/padlock.png')");
    ui->GarageLogo->setStyleSheet("background-image:url('C:/Users/apple/Desktop/root/trunk/med/fin/smarthousemanager/gfx/Finalcons/garage.png')");
    ui->LightLogo->setStyleSheet("background-image:url('C:/Users/apple/Desktop/root/trunk/med/fin/smarthousemanager/gfx/Finalcons/light.png')");
    ui->TemperatureLogo->setStyleSheet("background-image:url('C:/Users/apple/Desktop/root/trunk/med/fin/smarthousemanager/gfx/Finalcons/thermometer.png')");

    ui->TapBackground->setStyleSheet("background-image:url('C:/Users/apple/Desktop/root/trunk/med/fin/smarthousemanager/gfx/tap.png')");
    ui->SecurityBackground->setStyleSheet("background-image:url('C:/Users/apple/Desktop/root/trunk/med/fin/smarthousemanager/gfx/padlock.png')");
    ui->GarageBackground->setStyleSheet("background-image:url('C:/Users/apple/Desktop/root/trunk/med/fin/smarthousemanager/gfx/garage.png')");
    ui->LightBackground->setStyleSheet("background-image:url('C:/Users/apple/Desktop/root/trunk/med/fin/smarthousemanager/gfx/light.png')");
    ui->TemperatureBackground->setStyleSheet("background-image:url('C:/Users/apple/Desktop/root/trunk/med/fin/smarthousemanager/gfx/thermometer.png')");


}

GuestWindow::~GuestWindow()
{
    delete ui;
}

void GuestWindow::consult()
{
    QSqlQuery query;
    query.exec("select state from alarm;");
    query.next();
    QString state=query.value(0).toString();
    if(state=="0")
    {
        ui->textEdit_Security->setText("VOTRE MAISON EST SECURISEE");
    }else
        ui->textEdit_Security->setText("VOTRE MAISON N'EST PAS SECURISEE");

    QSqlQuery query1;
    query1.exec("select degree from temperature;");
    query1.next();
    QString degree=query1.value(0).toString();

        ui->textEdit_Temperature->setText(degree);
}

