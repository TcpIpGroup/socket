#-------------------------------------------------
#
# Project created by QtCreator 2016-05-08T11:03:49
#
#-------------------------------------------------

QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = socket
TEMPLATE = app


SOURCES += main.cpp\
    server.cpp \
    client.cpp \
    util.cpp \
    group.cpp \
    globle.cpp \
    peer.cpp

HEADERS  += \
    server.h \
    client.h \
    util.h \
    enum.h \
    group.h \
    globle.h \
    peer.h

FORMS    += \
    group.ui \
    peer.ui

RESOURCES += \
    qdarkstyle/style.qrc
