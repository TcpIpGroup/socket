#-------------------------------------------------
#
# Project created by QtCreator 2016-05-08T11:03:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = socket
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    server.cpp \
    client.cpp

HEADERS  += mainwindow.h \
    server.h \
    client.h

FORMS    += mainwindow.ui

RESOURCES += \
    qdarkstyle/style.qrc
