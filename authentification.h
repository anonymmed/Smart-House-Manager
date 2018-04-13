#ifndef AUTHENTIFICATION_H
#define AUTHENTIFICATION_H
#include <iostream>
#include <string>
#include <QString>
using namespace std;

class authentification
{
private:
    QString _username;
    QString _password;


public:
    authentification();
    authentification(QString username,QString password);
    ~authentification();
    QString getUserName();
    QString getPassword();
    bool verify();
    QString redirect();

};

#endif // AUTHENTIFICATION_H
