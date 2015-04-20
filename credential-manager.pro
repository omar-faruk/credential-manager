#-------------------------------------------------
#
# Project created by QtCreator 2015-04-19T23:26:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = credential-manager
TEMPLATE = app

SOURCES +=\
        loginwindow.cpp \
    main.cpp \
    credentialwindow.cpp

HEADERS  += loginwindow.h \
    crypto.h \
    credentialwindow.h

FORMS    += loginwindow.ui \
    credentialwindow.ui

CONFIG +=console

OTHER_FILES += \
    up.db
