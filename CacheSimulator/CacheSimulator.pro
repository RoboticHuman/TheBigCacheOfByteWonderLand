#-------------------------------------------------
#
# Project created by QtCreator 2013-12-07T16:10:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = CacheSimulator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cacheSim.cpp \
    qcustomplot.cpp \
    graphing.cpp \
    settings.cpp \
    nightcharts.cpp \
    mywidget.cpp

HEADERS  += mainwindow.h \
    cacheSim.h \
    cacheline.h \
    qcustomplot.h \
    graphing.h \
    settings.h \
    nightcharts.h \
    mywidget.h

FORMS    += mainwindow.ui \
    graphing.ui \
    settings.ui
