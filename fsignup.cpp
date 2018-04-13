#include "fsignup.h"

fsignup::fsignup()
{

}

bool fsignup::checkuser(QString username)
{
    bool check=false;
 QSqlQuery query;
 query.prepare("select * from users where username= ?");
 query.addBindValue(username);
 query.exec();
 query.next();
 if (query.value(0).toString()=="" || query.value(0).toString()== " ")
 {
     check= true;
 }
 else
 {
     check= false;
 }
 return check;
}

bool fsignup::adminsignup(QLineEdit* id,QLineEdit *username, QLineEdit *password,QComboBox *type)
{
    bool check;
    QSqlQuery query;
query.prepare("select id from users where username =?");
query.addBindValue(username->text());
query.exec();
query.next();
if (query.value(0).toString()=="" || query.value(0).toString()==" ")
{
    query.prepare("insert into users values(?,?,?,'admin')");
    query.addBindValue(id->text());
    query.addBindValue(username->text());
    query.addBindValue(password->text());
    query.addBindValue(type->currentText());
    if (query.exec())
    {
        check=true;
    }
    else
    {
        check=false;
    }
}
else
{
    check=false;
    qDebug()<<"username already in database";
}
return check;
}

bool fsignup::guestsignup(QLineEdit* id,QLineEdit *username, QLineEdit *password)
{
    bool check;
    QSqlQuery query;
    query.prepare("select id from users where username =?");
    query.addBindValue(username->text());
    query.exec();
    query.next();
    if (query.value(0).toString()=="" || query.value(0).toString()==" ")
    {

    query.prepare("insert into users values(?,?,?,'guest')");
    query.addBindValue(id->text());
    query.addBindValue(username->text());
    query.addBindValue(password->text());
    if(query.exec())
    {
        check=true;
    }
    else
    {
        check=false;
    }
    }
        else
        {
        check=false;
            qDebug()<<"username already in database";
        }
return check;
}

bool fsignup::checkexistance()
{
    bool check = false;
    QSqlQuery query;
    query.prepare("select * from users where type=?");
    query.addBindValue("admin");
    query.exec();
    query.next();
    if (query.value(0).toString()=="" || query.value(0)==" ")
    {
        check=false;
    }
    else
    {
        check=true;
    }
    return check;
}
