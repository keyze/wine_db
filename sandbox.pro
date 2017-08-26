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
    addpage.cpp \
    database/dbmanager.cpp \
    wine.cpp \
    Pages/searchpage.cpp \
    Pages/quicksearch.cpp \
    Pages/advancedsearch.cpp \
    Pages/drink.cpp \
    database/winetable.cpp \
    winebox.cpp

HEADERS += \
        mainwindow.h \
    pages.h \
    homepage.h \
    addpage.h \
    database/dbmanager.h \
    wine.h \
    Pages/searchpage.h \
    Pages/quicksearch.h \
    Pages/advancedsearch.h \
    Pages/drink.h \
    database/winetable.h \
    winebox.h

FORMS += \
        mainwindow.ui

RESOURCES += \
    resources.qrc
