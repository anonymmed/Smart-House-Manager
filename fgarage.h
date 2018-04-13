#ifndef FGARAGE_H
#define FGARAGE_H
#include <QTableWidget>
#include <QLineEdit>
class fgarage
{
public:
    fgarage();
    virtual ~fgarage();
    static void viewgarage(QTableWidget* Tab1);
    static void addgarage(QTableWidget* Tab1,QTableWidget* Tab2,QString addid);
    static void removegarage(QTableWidget* Tab1,QTableWidget *Tab2);
    static void opengarage(QTableWidget* Tab1,QTableWidget* Tab2);
    static void closegarage(QTableWidget* Tab1,QTableWidget* Tab2);

};

#endif // FGARAGE_H
