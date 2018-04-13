#ifndef FTAP_H
#define FTAP_H
#include "database.h"
#include <QTableWidget>

class ftap
{
public:
    ftap();
    static void viewtap(QTableWidget* Tab1);
    static void addtap(QTableWidget* Tab1,QTableWidget* Tab2,QString addid,QString nompiece);
    static void removetap(QTableWidget* Tab1,QTableWidget* Tab2);
};

#endif // FTAP_H
