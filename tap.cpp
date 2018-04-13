#include "tap.h"
#include "ui_tap.h"
#include "ftap.h"
tap::tap(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tap)
{
    ui->setupUi(this);

    ui->viewtable->setStyleSheet("background:transparent;border:0px solid transparent;");
    ui->viewtable2->setStyleSheet("background:transparent;border:0px solid transparent;");

    ftap::viewtap(ui->viewtable);
    ftap::viewtap(ui->viewtable2);

    QStringList Headers;
    Headers<<"TAP_ID"<<"TAP_STATE"<<"PIECE_NAME";
    ui->viewtable2->setHorizontalHeaderLabels(Headers);
    ui->viewtable2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->viewtable2->verticalHeader()->hide();

    ui->viewtable->setHorizontalHeaderLabels(Headers);
    ui->viewtable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->viewtable->verticalHeader()->hide();
    ui->AddBackground->setStyleSheet("background-image:url('C:/Users/apple/Desktop/root/trunk/med/fin/smarthousemanager/gfx/padlock.png')");
    ui->RemoveBackground->setStyleSheet("background-image:url('C:/Users/apple/Desktop/root/trunk/med/fin/smarthousemanager/gfx/tap.png')");
    ui->ViewBackground->setStyleSheet("background-image:url('C:/Users/apple/Desktop/root/trunk/med/fin/smarthousemanager/gfx/light.png')");
    ui->label->setStyleSheet("background-image:url('C:/Users/apple/Desktop/root/trunk/med/fin/smarthousemanager/gfx/Finalcons/tap.png')");
    ui->label_1->setStyleSheet("background-image:url('C:/Users/apple/Desktop/root/trunk/med/fin/smarthousemanager/gfx/Finalcons/tap.png')");
    ui->label_2->setStyleSheet("background-image:url('C:/Users/apple/Desktop/root/trunk/med/fin/smarthousemanager/gfx/Finalcons/tap.png')");
}

tap::~tap()
{
    delete ui;
}

void tap::on_addtap_clicked()
{
    ftap::addtap(ui->viewtable,ui->viewtable2,ui->addid->text(),ui->addpiece->text());
}

void tap::on_deletetap_clicked()
{
    ftap::removetap(ui->viewtable,ui->viewtable2);
}
