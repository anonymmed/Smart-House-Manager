#include "fsecurity.h"
#include <QLineEdit>
#include <QMessageBox>
fsecurity::fsecurity()
{

}


void fsecurity::viewalarms(QTableWidget* Tab)
{
    QSqlQuery query;
    query.exec("select * from alarm");
    int count=0;
    while(query.next())
    {
        count++;
    }


    Tab->setRowCount(count);
    Tab->setColumnCount(3);
    count=0;

    query.exec("select alarm.id as Alarm_Id ,alarm.state as Alarm_State,piece.name as Piece_Name from alarm inner join piece on (alarm.piece_id=piece.id);");

    while(query.next())
    {
        Tab->setItem(count,0,new QTableWidgetItem(query.value(0).toString()));
        Tab->setItem(count,1,new QTableWidgetItem(query.value(1).toString()));
        Tab->setItem(count,2,new QTableWidgetItem(query.value(2).toString()));

        count++;
    }
}

void fsecurity::activatealarm(QTableWidget *Tab1, QTableWidget *Tab2)
{
    if (Tab1->currentRow()==-1)
    {
        QMessageBox error;
        error.setText("error");
        error.setInformativeText("Please Select A Row To Remove");
        error.exec();

    }
    else
    {
        QString selectedid=Tab1->item(Tab1->currentRow(),0)->text();
         if(Tab1->item(Tab1->currentRow(),1)->text()=="0")
         {
             QSqlQuery query;
             query.prepare("update alarm set state=1 where id='"+selectedid+"'");
              query.exec();
         }
         viewalarms(Tab1);
         viewalarms(Tab2);
         }
    }
void fsecurity::desactivatealarm(QTableWidget *Tab1, QTableWidget *Tab2)
{
    if (Tab1->currentRow()==-1)
    {
        QMessageBox error;
        error.setText("error");
        error.setInformativeText("Please Select A Row To Remove");
        error.exec();

    }
    else
    {
        QString selectedid=Tab1->item(Tab1->currentRow(),0)->text();

         if (Tab1->item(Tab1->currentRow(),1)->text()=="1")
            {
             QSqlQuery query;
             query.prepare("update alarm set state=0 where id='"+selectedid+"'");
              query.exec();
            }
         viewalarms(Tab1);
         viewalarms(Tab2);
    }


}
void fsecurity::addalarm(QTableWidget* Tab1,QTableWidget* Tab2,QString Id,QString State,QString nompiece)
{
    QSqlQuery query,searchquery;
    if(searchquery.exec("select id from piece where name='"+nompiece+"'"))
    {
       searchquery.next();
        query.exec("insert into alarm values('"+Id+"','"+State+"','"+searchquery.value(0).toString()+"')");


    }

    viewalarms(Tab1);
    viewalarms(Tab2);
}
void fsecurity::removealarm(QTableWidget *Tab1, QTableWidget *Tab2)
{
    if (Tab2->currentRow()==-1)
    {
        QMessageBox error;
        error.setText("error");
        error.setInformativeText("Please Select A Row To Remove");
        error.exec();

    }
        else
       {
        QString selectedid=Tab2->item(Tab2->currentRow(),0)->text();

        QSqlQuery query;
        query.prepare("delete from alarm where id='"+selectedid+"' ");
        query.exec();
        viewalarms(Tab1);
        viewalarms(Tab2);

        }
}


