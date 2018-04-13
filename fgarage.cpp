#include "fgarage.h"
#include "database.h"
fgarage::fgarage()
{

}

fgarage::~fgarage()
{

}

void fgarage::viewgarage(QTableWidget *Tab1)
{
    QSqlQuery query;
    query.exec("select * from garage");
    int count=0;
    while(query.next())
    {
        count++;
    }
    Tab1->setRowCount(count);
    Tab1->setColumnCount(2);
    count=0;

    query.exec("select * from garage");

    while(query.next())
    {
        Tab1->setItem(count,0,new QTableWidgetItem(query.value(0).toString()));
        Tab1->setItem(count,1,new QTableWidgetItem(query.value(1).toString()));
        count++;
    }

}

void fgarage::addgarage(QTableWidget *Tab1, QTableWidget *Tab2, QString addid)
{
    QSqlQuery query;
    query.prepare("insert into garage values('"+addid+"','closed')");
    query.exec();
    viewgarage(Tab1);
    viewgarage(Tab2);
}
void fgarage::removegarage(QTableWidget *Tab1,QTableWidget *Tab2)
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
              query.prepare("delete from garage where id='"+selectedid+"' ");
              query.exec();
               viewgarage(Tab1);
              viewgarage(Tab2);
    }
}

void fgarage::opengarage(QTableWidget *Tab1, QTableWidget *Tab2)
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
         if(Tab1->item(Tab1->currentRow(),1)->text()=="closed")
         {
             QSqlQuery query;
             query.prepare("update garage set state='opened' where id='"+selectedid+"'");
              query.exec();
         }
            viewgarage(Tab1);
            viewgarage(Tab2);
    }

}

void fgarage::closegarage(QTableWidget *Tab1, QTableWidget *Tab2)
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
         if(Tab1->item(Tab1->currentRow(),1)->text()=="opened")
         {
             QSqlQuery query;
             query.prepare("update garage set state='closed' where id='"+selectedid+"'");
              query.exec();
         }
            viewgarage(Tab1);
            viewgarage(Tab2);

    }

}
