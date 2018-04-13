#ifndef FSIGNUP_H
#define FSIGNUP_H
#include "database.h"
#include <QLineEdit>
#include <QComboBox>
#include <QLabel>
class fsignup
{
private:
public:
    fsignup();
    static bool checkuser(QString username);
    static bool adminsignup(QLineEdit* id,QLineEdit* username,QLineEdit* password,QComboBox* type);
    static bool guestsignup(QLineEdit* id,QLineEdit* username,QLineEdit* password);
    static bool checkexistance();
    static QString checktype(QString type);
};

#endif // FSIGNUP_H
