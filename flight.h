#ifndef FLIGHT_H
#define FLIGHT_H
#include <QTableWidget>

class flight
{
public:
    flight();
    static void viewlight(QTableWidget*);
   static void activatelight(QTableWidget* Tab1 ,QTableWidget* Tab2);
    static void desactivatelight(QTableWidget* Tab1, QTableWidget* Tab2);
   static void addlight(QTableWidget* Tab1,QTableWidget* Tab2,QString Id,QString State,QString nompiece);
   static void removelight(QTableWidget* Tab1,QTableWidget* Tab2);

};

#endif // FLIGHT_H
