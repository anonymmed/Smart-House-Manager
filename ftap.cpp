#include "ftap.h"

ftap::ftap()
{

}
void ftap::viewtap(QTableWidget *Tab1)
{
    QSqlQuery query;
    query.exec("select * from tap");
    int count=0;
    while(query.next())
    {
        count++;
    }


    Tab1->setRowCount(count);
    Tab1->setColumnCount(3);
    count=0;

    query.exec("select tap.id as Tap_Id ,tap.state as Tap_State,piece.name as Piece_Name from tap inner join piece on (tap.piece_id=piece.id);");

    while(query.next())
    {
        Tab1->setItem(count,0,new QTableWidgetItem(query.value(0).toString()));
        Tab1->setItem(count,1,new QTableWidgetItem(query.value(1).toString()));
        Tab1->setItem(count,2,new QTableWidgetItem(query.value(2).toString()));

        count++;
    }

}
void ftap::addtap(QTableWidget *Tab1, QTableWidget *Tab2, QString addid,QString nompiece)
{
    QSqlQuery query,searchquery;
    if(searchquery.exec("select id from piece where name='"+nompiece+"'"))
    {
       searchquery.next();
        query.exec("insert into tap values('"+addid+"',0,'"+searchquery.value(0).toString()+"')");


    }

    viewtap(Tab1);
    viewtap(Tab2);

}
void ftap::removetap(QTableWidget *Tab1, QTableWidget *Tab2)
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
        query.prepare("delete from tap where id='"+selectedid+"' ");
        query.exec();
        viewtap(Tab1);
        viewtap(Tab2);

        }

}
