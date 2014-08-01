#-------------------------------------------------
#
# Project created by QtCreator 2014-06-07T16:25:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Pacman
TEMPLATE = app


SOURCES += main.cpp\
        pacman.cpp \
    gamemap.cpp \
    creature.cpp \
    pacman_creature.cpp \
    monster_creature.cpp

HEADERS  += pacman.h \
    gamemap.h \
    creature.h \
    pacman_creature.h \
    monster_creature.h \
    ThreadPool.h

FORMS    += pacman.ui

RESOURCES += \
    Source_files.qrc
CONFIG += c++11
OTHER_FILES +=

