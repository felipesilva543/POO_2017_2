TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Tweett.cpp \
    User.cpp \
    Repository.cpp

HEADERS += \
    User.h \
    Repository.h \
    split.h \
    Tweet.h
