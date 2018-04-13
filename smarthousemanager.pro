#-------------------------------------------------
#
# Project created by QtCreator 2016-12-03T03:03:49
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = smarthousemanager
TEMPLATE = app


SOURCES += main.cpp \
    authentification.cpp \
    database.cpp \
    mainwindow.cpp \
    adminwindow.cpp \
    guestwindow.cpp \
    security.cpp \
    garage.cpp \
    fsecurity.cpp \
    flight.cpp \
    fgarage.cpp \
    ftemperature.cpp \
    ftap.cpp \
    light.cpp \
    temperature.cpp \
    tap.cpp \
    signup.cpp \
    fsignup.cpp

HEADERS  += \
    authentification.h \
    database.h \
    mainwindow.h \
    adminwindow.h \
    guestwindow.h \
    security.h \
    garage.h \
    fsecurity.h \
    flight.h \
    fgarage.h \
    ftemperature.h \
    ftap.h \
    light.h \
    temperature.h \
    tap.h \
    signup.h \
    fsignup.h

FORMS    += \
    mainwindow.ui \
    adminwindow.ui \
    guestwindow.ui \
    security.ui \
    garage.ui \
    light.ui \
    temperature.ui \
    tap.ui \
    signup.ui
