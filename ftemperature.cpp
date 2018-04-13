#include "ftemperature.h"

ftemperature::ftemperature()
{

}

QString ftemperature::viewtemp()
{
    QString tempvalue;
 QSqlQuery query;
 query.prepare("select current_temperature from temperature where id=?");
 query.addBindValue(1);
 query.exec();
 query.next();
 tempvalue=query.value(0).toString();
 qDebug()<<"temperature "+tempvalue;
 return tempvalue;
}
void ftemperature::changemawvalue(QString maxvalue)
{
    QSqlQuery query;
    query.prepare("update temperature set TEMP_MAX_VALUE=? where id =?");
    query.addBindValue(maxvalue);
    query.addBindValue(1);
    query.exec();
    qDebug()<<query.value(2).toString();
    viewmaxvalue();
}

QString ftemperature::viewmaxvalue()
{
 QString tempmaxvalue;
 QSqlQuery query;
 query.prepare("select TEMP_MAX_VALUE from temperature where id=?");
 query.addBindValue(1);
 query.exec();
 query.next();
 tempmaxvalue=query.value(0).toString();
 qDebug()<<"temperature "+tempmaxvalue;
 return tempmaxvalue;
}
QString ftemperature::viewfanstate()
{
    setfanstate();
    QString fanstate;
    QSqlQuery query;
    query.prepare("select fan_state from temperature where id=?");
    query.addBindValue(1);
    query.exec();
    query.next();
    fanstate=query.value(0).toString();
    qDebug()<<"temperature "+fanstate;
    return fanstate;
}

void ftemperature::setfanstate()
{
    QSqlQuery query;
    query.prepare("select CURRENT_TEMPERATURE,TEMP_MAX_VALUE from temperature where id=?");
    query.addBindValue(1);
    query.exec();
    query.next();
int max=query.value(1).toInt();
int current=query.value(0).toInt();
qDebug()<<max<<" "<<current;
    if (current>= max)
    {
        qDebug()<<"depassed maximum !!!! ";
        query.prepare("update temperature set fan_state=? where id= ?");
        query.addBindValue("on");
        query.addBindValue(1);
        query.exec();
    }
    else
    {
        QSqlQuery fanquery;
        query.prepare("update temperature set fan_state=? where id= ?");
        query.addBindValue("off");
        query.addBindValue(1);
        query.exec();

    }
}
