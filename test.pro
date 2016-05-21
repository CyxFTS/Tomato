#-------------------------------------------------
#
# Project created by QtCreator 2016-04-23T13:48:12
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test
TEMPLATE = app


SOURCES +=\
        mainwindow.cpp \
    round.cpp \
    DetailedWindow.cpp \
    per.cpp \
    main.cpp \
    mylistview.cpp \
    checkboxdelegate.cpp

HEADERS  += mainwindow.h \
    round.h \
    DetailedWindow.h \
    database.h \
    per.h \
    mylistview.h \
    checkboxdelegate.h

FORMS    += mainwindow.ui \
    DetailedWindow.ui

RESOURCES += \
    resources.qrc
