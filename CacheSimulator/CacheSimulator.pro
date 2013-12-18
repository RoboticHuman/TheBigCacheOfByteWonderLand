#-------------------------------------------------
#
# Project created by QtCreator 2013-12-07T16:10:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++11

TARGET = CacheSimulator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cacheSim.cpp \
    qcustomplot.cpp \
    graphing.cpp \
    settings.cpp \
    processing_window.cpp \
    initialize.cpp \
    nightcharts.cpp \
    mywidget.cpp \
    processingthedata.cpp

HEADERS  += mainwindow.h \
    cacheSim.h \
    cacheline.h \
    qcustomplot.h \
    graphing.h \
    settings.h \
    processing_window.h \
    initialize.h \
    nightcharts.h \
    mywidget.h \
    hitData.h \
    processingthedata.h

FORMS    += mainwindow.ui \
    graphing.ui \
    settings.ui \
    processing_window.ui \
    initialize.ui \
    piepainter.ui

RESOURCES += \
    images.qrc

win32:RC_FILE += CacheSimulator.rc
