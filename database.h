#ifndef DATABASE_H
#define DATABASE_H
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QMessageBox>
#include <QDebug>

class database
{
public:
    database();
    database(QString dbName,QString dbUsername,QString dbPassword);
     ~database();

private:
    QSqlDatabase db;
    QString dbName;
    QString dbUsername;
    QString dbPassword;

};

#endif // DATABASE_H
