#include "database.h"
#include "mainwindow.h"
#include "authentification.h"
#include <QApplication>
#include <QMessageBox>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    database db("projet","HR","HR");

    return a.exec();
}
