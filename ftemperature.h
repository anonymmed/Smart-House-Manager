#ifndef FTEMPERATURE_H
#define FTEMPERATURE_H
#include "database.h"

class ftemperature
{
public:
    ftemperature();
    static QString viewtemp();
    static void changemawvalue(QString maxvalue);
    static QString viewmaxvalue();
    static QString viewfanstate();
    static void setfanstate();
};

#endif // FTEMPERATURE_H
