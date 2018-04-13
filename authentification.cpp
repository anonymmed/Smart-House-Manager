#include "authentification.h"
#include "database.h"
#include <iostream>
#include <QString>

using namespace std;
authentification::authentification()
{
}
authentification::~authentification()
{
}

authentification::authentification(QString username, QString password)
{
  _username=username;
  _password=password;
}

bool authentification::verify()
{

    QSqlQuery query;
    return query.exec("select * from users where username='"+_username+"' and password ='"+_password+"'");

}

QString authentification::getUserName()
{
    return _username;
}
QString authentification::getPassword()

{
    return _password;
}
QString authentification::redirect()
{
        QSqlQuery query;
        query.exec("select * from users where username='"+_username+"'and password = '"+_password+"'");
        query.next();
        QString testType=query.value(3).toString();
                if (testType == "admin")
                {

                return "admin";
                }
                else if (testType == "guest")
                {

                return "guest";


                }
    else
    {
        QMessageBox::critical(0, QObject::tr("error !"), "user can not be found in the database!!");
        return "null";
    }
}
