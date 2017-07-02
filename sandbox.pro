#-------------------------------------------------
#
# Project created by QtCreator 2017-06-19T13:36:19
#
#-------------------------------------------------

QT       += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sandbox
TEMPLATE = app
RCC_DIR = pictures
# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    pages.cpp \
    homepage.cpp \
    borderlayout.cpp \
    addpage.cpp \
    stuff.cpp \
    database/dbmanager.cpp \
    wine.cpp \
    Pages/searchpage.cpp

HEADERS += \
        mainwindow.h \
    pages.h \
    homepage.h \
    borderlayout.h \
    addpage.h \
    stuff.h \
    database/dbmanager.h \
    wine.h \
    Pages/searchpage.h

FORMS += \
        mainwindow.ui

RESOURCES += \
    resources.qrc
