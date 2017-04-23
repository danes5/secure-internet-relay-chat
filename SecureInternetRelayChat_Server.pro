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
    clientinfo.cpp \
    gcmutils.cpp \
    securityfunctions.cpp \
    libs/aes.c \
    libs/aesni.c \
    libs/gcm.c \
    libs/sha512.c \
    libs/cipher.c \
    libs/ccm.c \
    libs/cmac.c \
    libs/cipher_wrap.c \
    libs/arc4.c \
    libs/camellia.c \
    libs/blowfish.c \
    libs/des.c \
    buffer.cpp \
    parser.cpp


HEADERS += \
    Connection.h \
    clientinfo.h \
    catch.hpp \
    gcmutils.h \
    securityfunctions.h \
    libs/cipher_internal.h \
    libs/aes.h \
    libs/aesni.h \
    libs/gcm.h \
    libs/sha512.h \
    libs/check_config.h \
    libs/cipher.h \
    libs/config.h \
    libs/padlock.h \
    libs/platform.h \
    libs/platform_time.h \
    libs/target_config.h \
    catch.hpp \
    libs/ccm.h \
    libs/cmac.h \
    libs/arc4.h \
    libs/camellia.h \
    libs/blowfish.h \
    libs/des.h \
    buffer.h \
    parser.h \
    Client.h \
    Server.h


