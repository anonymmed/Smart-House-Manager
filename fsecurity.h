#ifndef FSECURITY_H
#define FSECURITY_H
#include "authentification.h"
#include "database.h"
#include <QMainWindow>
#include <QTableWidget>
class fsecurity
{
public:
    fsecurity();
  static void viewalarms(QTableWidget*);
 static void activatealarm(QTableWidget* Tab1 ,QTableWidget* Tab2);
  static void desactivatealarm(QTableWidget* Tab1, QTableWidget* Tab2);
 static void addalarm(QTableWidget* Tab1,QTableWidget* Tab2,QString Id,QString State,QString nompiece);
 static void removealarm(QTableWidget* Tab1,QTableWidget* Tab2);
};

#endif // FSECURITY_H
