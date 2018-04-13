#include "flight.h"
#include "database.h"
flight::flight()
{

}

void flight::viewlight(QTableWidget *Tab)
{
    QSqlQuery query;
    query.exec("select * from light");
    int count=0;
    while(query.next())
    {
        count++;
    }


    Tab->setRowCount(count);
    Tab->setColumnCount(3);
    count=0;

    query.exec("select light.id as Light_Id ,light.state as Light_State,piece.name as Piece_Name from light inner join piece on (light.piece_id=piece.id);");

    while(query.next())
    {
        Tab->setItem(count,0,new QTableWidgetItem(query.value(0).toString()));
        Tab->setItem(count,1,new QTableWidgetItem(query.value(1).toString()));
        Tab->setItem(count,2,new QTableWidgetItem(query.value(2).toString()));

        count++;
    }
}


void flight::activatelight(QTableWidget *Tab1, QTableWidget *Tab2)
{

    if (Tab1->currentRow()==-1)
    {
        QMessageBox error;
        error.setText("error");
        error.setInformativeText("Please Select A Row To activate");
        error.exec();

    }
    else
    {
        QString selectedid=Tab1->item(Tab1->currentRow(),0)->text();
         if(Tab1->item(Tab1->currentRow(),1)->text()=="0")
         {
             QSqlQuery query;
             query.prepare("update light set state=1 where id='"+selectedid+"'");
              query.exec();
         }
         viewlight(Tab1);
         viewlight(Tab2);
    }

}

void flight::desactivatelight(QTableWidget *Tab1, QTableWidget *Tab2)
{

    if (Tab1->currentRow()==-1)
    {
        QMessageBox error;
        error.setText("error");
        error.setInformativeText("Please Select A Row To desactivate");
        error.exec();

    }
    else
    {
        QString selectedid=Tab1->item(Tab1->currentRow(),0)->text();

         if (Tab1->item(Tab1->currentRow(),1)->text()=="1")
            {
             QSqlQuery query;
             query.prepare("update light set state=0 where id='"+selectedid+"'");
              query.exec();
            }
         viewlight(Tab1);
         viewlight(Tab2);

    }

    }

void flight::addlight(QTableWidget *Tab1, QTableWidget *Tab2, QString Id, QString State, QString nompiece)
{
    QSqlQuery query,searchquery;
    if(searchquery.exec("select id from piece where name='"+nompiece+"'"))
    {
       searchquery.next();
        query.exec("insert into light values('"+Id+"','"+State+"','"+searchquery.value(0).toString()+"')");


    }

    viewlight(Tab1);
    viewlight(Tab2);
}

void flight::removelight(QTableWidget *Tab1, QTableWidget *Tab2)
{
    if (Tab2->currentRow()==-1)
    {
        QMessageBox error;
        error.setText("error");
        error.setInformativeText("Please Select A Row To desactivate");
        error.exec();

    }
    else
    {
        QString selectedid=Tab2->item(Tab2->currentRow(),0)->text();

        QSqlQuery query;
        query.prepare("delete from light where id='"+selectedid+"' ");
        query.exec();
        viewlight(Tab1);
        viewlight(Tab2);

    }
    }
