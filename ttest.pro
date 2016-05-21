#-------------------------------------------------
#
# Project created by QtCreator 2016-04-23T13:48:12
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = test
TEMPLATE = app

RC_FILE = RC.rc
SOURCES +=\
        mainwindow.cpp \
    round.cpp \
    main.cpp \
    mylistview.cpp \
    detailedwindow.cpp \
    finishdialog.cpp \
    customshadoweffect.cpp \
    uwpbutton.cpp \
    menu.cpp \
    graphwindow.cpp \
    qcustomplot.cpp \
    timeeditdelegate.cpp

HEADERS  += mainwindow.h \
    round.h \
    database.h \
    mylistview.h \
    detailedwindow.h \
    expandwidget.h \
    tempcolor.h \
    finishdialog.h \
    customshadoweffect.h \
    uwpbutton.h \
    menu.h \
    graphwindow.h \
    qcustomplot.h \
    timeeditdelegate.h

FORMS    += mainwindow.ui \
    detailedwindow.ui \
    finishdialog.ui \
    menu.ui \
    graphwindow.ui

RESOURCES += \
    resources.qrc

DISTFILES += \
    images/list.png \
    images/list_hover.png \
    images/list_rest.png
