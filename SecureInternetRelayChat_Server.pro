QT += core
QT -= gui
QT += network

QMAKE_CXXFLAGS += -std=c++14

TARGET = SecureInternetRelayChat_Server
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Server.cpp \
    Client.cpp \
    Connection.cpp \
    clientinfo.cpp

HEADERS += \
    Server.hpp \
    Client.hpp \
    Connection.h \
    clientinfo.h \
    catch.hpp


