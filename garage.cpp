#include "garage.h"
#include "ui_garage.h"
#include "database.h"
#include "fgarage.h"
garage::garage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::garage)
{
    ui->setupUi(this);
    ui->viewgarage->setStyleSheet("background:transparent;border:0px solid transparent;");
    ui->viewgarage2->setStyleSheet("background:transparent;border:0px solid transparent;");


    fgarage::viewgarage(ui->viewgarage);
    fgarage::viewgarage(ui->viewgarage2);

    QStringList Headers;
    Headers<<"ID"<<"STATE";
    ui->viewgarage2->setHorizontalHeaderLabels(Headers);
    ui->viewgarage2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->viewgarage2->verticalHeader()->hide();

    ui->viewgarage->setHorizontalHeaderLabels(Headers);
    ui->viewgarage->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->viewgarage->verticalHeader()->hide();
    ui->viewgarage->setStyleSheet("text-align:center;");

    ui->label->setStyleSheet("background-image:url('C:/Users/apple/Desktop/root/trunk/med/fin/smarthousemanager/gfx/Finalcons/garage.png')");
    ui->AddBackground->setStyleSheet("background-image:url('C:/Users/apple/Desktop/root/trunk/med/fin/smarthousemanager/gfx/padlock.png')");
    ui->RemoveBackground->setStyleSheet("background-image:url('C:/Users/apple/Desktop/root/trunk/med/fin/smarthousemanager/gfx/tap.png')");
    ui->ViewBackground->setStyleSheet("background-image:url('C:/Users/apple/Desktop/root/trunk/med/fin/smarthousemanager/gfx/light.png')");
}

garage::~garage()
{
    delete ui;
}



void garage::on_removegarage_clicked()
{
fgarage::removegarage(ui->viewgarage,ui->viewgarage2);
}

void garage::on_addgarage_clicked()
{
    fgarage::addgarage(ui->viewgarage,ui->viewgarage2,ui->addid->text());
}


void garage::on_open_clicked()
{
    fgarage::opengarage(ui->viewgarage,ui->viewgarage2);
}


void garage::on_close_clicked()
{
    fgarage::closegarage(ui->viewgarage,ui->viewgarage2);
}
