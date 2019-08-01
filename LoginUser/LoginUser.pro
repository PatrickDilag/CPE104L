#-------------------------------------------------
#
# Project created by QtCreator 2019-07-30T23:41:28
#
#-------------------------------------------------

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LoginUser
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        Player.cpp \
        bullet.cpp \
        enemy.cpp \
        game.cpp \
        health.cpp \
        main.cpp \
        mainwindow.cpp \
        score.cpp

HEADERS += \
        Player.h \
        bullet.h \
        enemy.h \
        game.h \
        health.h \
        mainwindow.h \
        score.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    bullet.mp3

RESOURCES += \
    res.qrc
