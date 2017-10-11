TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    vagao.cpp \
    passageiro.cpp \
    trem.cpp \
    registropassageiros.cpp \
    controller.cpp

HEADERS += \
    vagao.h \
    passageiro.h \
    trem.h \
    registropassageiros.h \
    split.h \
    controller.h

