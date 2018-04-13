#include "database.h"
database::database()
{
    this->dbName="projet";
    this->dbUsername="HR";
    this->dbPassword="HR";
    db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName(this->dbName);
    db.setUserName(this->dbUsername);
    db.setPassword(this->dbPassword);
    bool dbCheck=db.open();
    if(!dbCheck)
    {
        QMessageBox::critical(0, QObject::tr("error !"),db.lastError().text());

    }

}
database::database(QString dbName, QString dbUsername, QString dbPassword)
{
    this->dbName=dbName;
    this->dbUsername=dbUsername;
    this->dbPassword=dbPassword;
    db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName(this->dbName);
    db.setUserName(this->dbUsername);
    db.setPassword(this->dbPassword);
    bool dbCheck=db.open();
    if(!dbCheck)
    {
        QMessageBox::critical(0, QObject::tr("error !"),db.lastError().text());

    }
}
database::~database()
{
    db.close();

}
