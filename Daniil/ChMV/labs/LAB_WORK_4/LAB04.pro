#-------------------------------------------------
#
# Project created by QtCreator 2018-09-25T20:14:56
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LAB04
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    basecontents.cpp

HEADERS  += mainwindow.h \
    basecontents.h

FORMS    += mainwindow.ui \
    basecontents.ui

RESOURCES += \
    logo.qrc
