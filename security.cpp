#include "security.h"
#include "ui_security.h"
#include <iostream>
#include <QString>
#include <QMessageBox>
#include "database.h"
#include <string>
#include <QDebug>
#include "fsecurity.h"
security::security(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::security)
{
    ui->setupUi(this);
    this->setStyleSheet("background-image:url('C:/Users/game/Documents/med/smarthousemanager/gfx/bpadlock.png');");
    ui->viewtable->setStyleSheet("background:transparent;border:0px solid transparent;");
    ui->viewtable2->setStyleSheet("background:transparent;border:0px solid transparent;");

    fsecurity::viewalarms(ui->viewtable);
    fsecurity::viewalarms(ui->viewtable2);

    QStringList Headers;
    Headers<<"ALARM_ID"<<"ALARM_STATE"<<"PIECE_NAME";
    ui->viewtable2->setHorizontalHeaderLabels(Headers);
    ui->viewtable2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->viewtable2->verticalHeader()->hide();

    ui->viewtable->setHorizontalHeaderLabels(Headers);
    ui->viewtable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->viewtable->verticalHeader()->hide();

    ui->label->setStyleSheet("background-image:url('C:/Users/apple/Desktop/root/trunk/med/fin/smarthousemanager/gfx/Finalcons/padlock.png')");
    ui->label_4->setStyleSheet("background-image:url('C:/Users/apple/Desktop/root/trunk/med/fin/smarthousemanager/gfx/Finalcons/padlock.png')");
    ui->label_3->setStyleSheet("background-image:url('C:/Users/apple/Desktop/root/trunk/med/fin/smarthousemanager/gfx/Finalcons/padlock.png')");
    ui->AddBackground->setStyleSheet("background-image:url('C:/Users/apple/Desktop/root/trunk/med/fin/smarthousemanager/gfx/padlock.png')");
    ui->RemoveBackground->setStyleSheet("background-image:url('C:/Users/apple/Desktop/root/trunk/med/fin/smarthousemanager/gfx/tap.png')");
    ui->ViewBackground->setStyleSheet("background-image:url('C:/Users/apple/Desktop/root/trunk/med/fin/smarthousemanager/gfx/light.png')");
}

security::~security()
{
    delete ui;
}

void security::on_activate_clicked()
{
fsecurity::activatealarm(ui->viewtable,ui->viewtable2);
}

void security::on_desactivate_clicked()
{
fsecurity::desactivatealarm(ui->viewtable,ui->viewtable2);
}

void security::on_addalarm_clicked()
{
fsecurity::addalarm(ui->viewtable,ui->viewtable2,ui->addid->text(),ui->addstate->text(),ui->addpiece->text());
}

void security::on_deletealarm_clicked()
{
    fsecurity::removealarm(ui->viewtable,ui->viewtable2);
}

void security::on_pushButton_clicked()
{
    this->parentWidget()->show();
    this->close();
}
