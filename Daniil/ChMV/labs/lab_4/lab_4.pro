#-------------------------------------------------
#
# Project created by QtCreator 2018-09-25T20:57:14
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lab_4
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    secondwindow.cpp \
    adminwindow.cpp

HEADERS  += mainwindow.h \
    secondwindow.h \
    adminwindow.h

FORMS    += mainwindow.ui \
    secondwindow.ui \
    adminwindow.ui

RESOURCES += \
    source.qrc
