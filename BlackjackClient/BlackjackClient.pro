#-------------------------------------------------
#
# Project created by QtCreator 2015-10-24T11:36:50
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BlackjackClient
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    player.cpp \
    card.cpp \
    game.cpp

HEADERS  += mainwindow.h \
    player.h \
    card.h \
    game.h

FORMS    += mainwindow.ui
