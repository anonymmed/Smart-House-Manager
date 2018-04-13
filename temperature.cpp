#include "temperature.h"
#include "ui_temperature.h"
#include "ftemperature.h"
temperature::temperature(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::temperature)
{
    ui->setupUi(this);
    ui->tempvalue->setText(ftemperature::viewtemp());
    ui->tempmaxvalue->setText(ftemperature::viewmaxvalue());
    ui->fanstate->setText(ftemperature::viewfanstate());

    ui->EditBackground->setStyleSheet("background-image:url('C:/Users/apple/Desktop/root/trunk/med/fin/smarthousemanager/gfx/padlock.png')");
    ui->ViewBackground->setStyleSheet("background-image:url('C:/Users/apple/Desktop/root/trunk/med/fin/smarthousemanager/gfx/tap.png')");
    ui->label_5->setStyleSheet("background-image:url('C:/Users/apple/Desktop/root/trunk/med/fin/smarthousemanager/gfx/Finalcons/thermometer.png')");
    ui->label_4->setStyleSheet("background-image:url('C:/Users/apple/Desktop/root/trunk/med/fin/smarthousemanager/gfx/Finalcons/thermometer.png')");
}

temperature::~temperature()
{
    delete ui;
}

void temperature::on_pushButton_clicked()
{
if(ui->edittemp->text()!="" || ui->edittemp->text()!=" ")
{
    ftemperature::changemawvalue(ui->edittemp->text());
}
ui->tempmaxvalue->setText(ftemperature::viewmaxvalue());
ui->fanstate->setText(ftemperature::viewfanstate());

}
