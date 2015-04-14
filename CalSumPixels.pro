#-------------------------------------------------
#
# Project created by QtCreator 2015-04-13T12:06:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CalSumPixels
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    workspace.cpp \
    setcircledialog.cpp

HEADERS  += mainwindow.h \
    workspace.h \
    setcircledialog.h

FORMS    += mainwindow.ui \
    setcircledialog.ui
