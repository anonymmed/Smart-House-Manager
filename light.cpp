#include "light.h"
#include "ui_light.h"
#include <QString>
#include <string>

light::light(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::light)
{
    ui->setupUi(this);
    ui->viewtable->setStyleSheet("background:transparent;border:0px solid transparent;");
    ui->viewtable_light->setStyleSheet("background:transparent;border:0px solid transparent;");

    flight::viewlight(ui->viewtable);
    flight::viewlight(ui->viewtable_light);
    QStringList Headers;
    Headers<<"LIGHT_ID"<<"LIGHT_STATE"<<"PIECE_NAME";
    ui->viewtable_light->setHorizontalHeaderLabels(Headers);
    ui->viewtable_light->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->viewtable_light->verticalHeader()->hide();

    ui->viewtable->setHorizontalHeaderLabels(Headers);
    ui->viewtable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->viewtable->verticalHeader()->hide();

    ui->label_light->setStyleSheet("background-image:url('C:/Users/apple/Desktop/root/trunk/med/fin/smarthousemanager/gfx/Finalcons/light.png')");
    ui->label_light_2->setStyleSheet("background-image:url('C:/Users/apple/Desktop/root/trunk/med/fin/smarthousemanager/gfx/Finalcons/light.png')");
    ui->label_light_3->setStyleSheet("background-image:url('C:/Users/apple/Desktop/root/trunk/med/fin/smarthousemanager/gfx/Finalcons/light.png')");
    ui->AddBackground->setStyleSheet("background-image:url('C:/Users/apple/Desktop/root/trunk/med/fin/smarthousemanager/gfx/padlock.png')");
    ui->RemoveBackground->setStyleSheet("background-image:url('C:/Users/apple/Desktop/root/trunk/med/fin/smarthousemanager/gfx/tap.png')");
    ui->ViewBackground->setStyleSheet("background-image:url('C:/Users/apple/Desktop/root/trunk/med/fin/smarthousemanager/gfx/light.png')");

}

light::~light()
{
    delete ui;
}

void light::on_pushButton_clicked()
{
    this->parentWidget()->show();
    this->close();
}

void light::on_turnon_clicked()
{
    flight::activatelight(ui->viewtable,ui->viewtable_light);
}

void light::on_turnoff_clicked()
{
flight::desactivatelight(ui->viewtable,ui->viewtable_light);
}

void light::on_addlight_clicked()
{
flight::addlight(ui->viewtable,ui->viewtable_light,ui->addid->text(),ui->addstate->text(),ui->addpiece->text());
}

void light::on_deletelight_clicked()
{
flight::removelight(ui->viewtable,ui->viewtable_light);
}
