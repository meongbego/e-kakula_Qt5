#-------------------------------------------------
#
# Project created by QtCreator 2014-04-17T22:28:42
#
#-------------------------------------------------

QT       += core gui multimedia opengl
VPATH += ../shared
INCLUDEPATH += ../shared

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = kakula
TEMPLATE = app


SOURCES += main.cpp\
        mainkakula.cpp \
    meter.cpp \
    bubble.cpp \
    glwidget.cpp

HEADERS  += mainkakula.h \
    meter.h \
    bubble.h \
    glwidget.h

FORMS    += mainkakula.ui

RESOURCES += \
    rsc.qrc

OTHER_FILES +=
