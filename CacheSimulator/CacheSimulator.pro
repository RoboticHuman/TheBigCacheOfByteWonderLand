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
    qcustomplot.cpp

HEADERS  += mainwindow.h \
    cacheSim.h \
    cacheline.h \
    qcustomplot.h

FORMS    += mainwindow.ui
