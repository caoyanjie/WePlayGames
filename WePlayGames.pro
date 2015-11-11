#-------------------------------------------------
#
# Project created by QtCreator 2015-11-04T13:26:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WePlayGames
TEMPLATE = app


SOURCES += main.cpp\
        weplaygames.cpp \
    windowtools.cpp \
    gamearea.cpp \
    spidercard.cpp \
    card.cpp

HEADERS  += weplaygames.h \
    windowtools.h \
    gamearea.h \
    spidercard.h \
    card.h

RESOURCES += \
    pix.qrc
