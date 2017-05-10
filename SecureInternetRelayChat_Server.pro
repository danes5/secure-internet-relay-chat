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
    libs/threading.c \
    libs/entropy_poll.c \
    libs/ctr_drbg.c \
    libs/timing.c \
    libs/havege.c \
    libs/entropy.c \
    libs/bignum.c \
    libs/ripemd160.c \
    libs/sha1.c \
    libs/sha256.c \
    libs/md2.c \
    libs/md4.c \
    libs/md5.c \
    libs/md_wrap.c \
    libs/asn1parse.c \
    libs/md.c \
    libs/oid.c \
    libs/rsa.c \
    rsautils.cpp \
    buffer.cpp \
    parser.cpp \


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
    libs/threading.h \
    libs/entropy_poll.h \
    libs/ctr_drbg.h \
    libs/timing.h \
    libs/havege.h \
    libs/entropy.h \
    libs/bignum.h \
    libs/ripemd160.h \
    libs/sha1.h \
    libs/sha256.h \
    libs/md2.h \
    libs/md4.h \
    libs/md5.h \
    libs/md_internal.h \
    libs/asn1.h \
    libs/md.h \
    libs/oid.h \
    libs/rsa.h \
    rsautils.h \
    buffer.h \
    parser.h \
    Server.h \


