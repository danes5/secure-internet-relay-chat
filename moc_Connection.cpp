/****************************************************************************
** Meta object code from reading C++ file 'Connection.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Connection.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Connection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Connection_t {
    QByteArrayData data[30];
    char stringdata0[373];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Connection_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Connection_t qt_meta_stringdata_Connection = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Connection"
QT_MOC_LITERAL(1, 11, 21), // "onRegistrationRequest"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 10), // "ClientInfo"
QT_MOC_LITERAL(4, 45, 6), // "clInfo"
QT_MOC_LITERAL(5, 52, 20), // "onCreateChannelReply"
QT_MOC_LITERAL(6, 73, 4), // "dest"
QT_MOC_LITERAL(7, 78, 4), // "data"
QT_MOC_LITERAL(8, 83, 22), // "onCreateChannelRequest"
QT_MOC_LITERAL(9, 106, 11), // "destination"
QT_MOC_LITERAL(10, 118, 4), // "json"
QT_MOC_LITERAL(11, 123, 6), // "onQuit"
QT_MOC_LITERAL(12, 130, 11), // "Connection*"
QT_MOC_LITERAL(13, 142, 10), // "connection"
QT_MOC_LITERAL(14, 153, 26), // "processRegistrationRequest"
QT_MOC_LITERAL(15, 180, 6), // "result"
QT_MOC_LITERAL(16, 187, 9), // "connected"
QT_MOC_LITERAL(17, 197, 12), // "disconnected"
QT_MOC_LITERAL(18, 210, 9), // "readyRead"
QT_MOC_LITERAL(19, 220, 12), // "bytesWritten"
QT_MOC_LITERAL(20, 233, 5), // "bytes"
QT_MOC_LITERAL(21, 239, 12), // "stateChanged"
QT_MOC_LITERAL(22, 252, 28), // "QAbstractSocket::SocketState"
QT_MOC_LITERAL(23, 281, 11), // "socketState"
QT_MOC_LITERAL(24, 293, 8), // "sslError"
QT_MOC_LITERAL(25, 302, 16), // "QList<QSslError>"
QT_MOC_LITERAL(26, 319, 6), // "errors"
QT_MOC_LITERAL(27, 326, 11), // "socketError"
QT_MOC_LITERAL(28, 338, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(29, 367, 5) // "error"

    },
    "Connection\0onRegistrationRequest\0\0"
    "ClientInfo\0clInfo\0onCreateChannelReply\0"
    "dest\0data\0onCreateChannelRequest\0"
    "destination\0json\0onQuit\0Connection*\0"
    "connection\0processRegistrationRequest\0"
    "result\0connected\0disconnected\0readyRead\0"
    "bytesWritten\0bytes\0stateChanged\0"
    "QAbstractSocket::SocketState\0socketState\0"
    "sslError\0QList<QSslError>\0errors\0"
    "socketError\0QAbstractSocket::SocketError\0"
    "error"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Connection[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       5,    2,   77,    2, 0x06 /* Public */,
       8,    2,   82,    2, 0x06 /* Public */,
      11,    1,   87,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    2,   90,    2, 0x0a /* Public */,
      16,    0,   95,    2, 0x0a /* Public */,
      17,    0,   96,    2, 0x0a /* Public */,
      18,    0,   97,    2, 0x0a /* Public */,
      19,    1,   98,    2, 0x0a /* Public */,
      21,    1,  101,    2, 0x0a /* Public */,
      24,    1,  104,    2, 0x0a /* Public */,
      27,    1,  107,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QJsonObject,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QJsonObject,    9,   10,
    QMetaType::Void, 0x80000000 | 12,   13,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    4,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,   20,
    QMetaType::Void, 0x80000000 | 22,   23,
    QMetaType::Void, 0x80000000 | 25,   26,
    QMetaType::Void, 0x80000000 | 28,   29,

       0        // eod
};

void Connection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Connection *_t = static_cast<Connection *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onRegistrationRequest((*reinterpret_cast< ClientInfo(*)>(_a[1]))); break;
        case 1: _t->onCreateChannelReply((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QJsonObject(*)>(_a[2]))); break;
        case 2: _t->onCreateChannelRequest((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QJsonObject(*)>(_a[2]))); break;
        case 3: _t->onQuit((*reinterpret_cast< Connection*(*)>(_a[1]))); break;
        case 4: _t->processRegistrationRequest((*reinterpret_cast< ClientInfo(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 5: _t->connected(); break;
        case 6: _t->disconnected(); break;
        case 7: _t->readyRead(); break;
        case 8: _t->bytesWritten((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 9: _t->stateChanged((*reinterpret_cast< QAbstractSocket::SocketState(*)>(_a[1]))); break;
        case 10: _t->sslError((*reinterpret_cast< QList<QSslError>(*)>(_a[1]))); break;
        case 11: _t->socketError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Connection* >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketState >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QSslError> >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Connection::*_t)(ClientInfo );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Connection::onRegistrationRequest)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Connection::*_t)(QString , QJsonObject );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Connection::onCreateChannelReply)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Connection::*_t)(QString , QJsonObject );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Connection::onCreateChannelRequest)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Connection::*_t)(Connection * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Connection::onQuit)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject Connection::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Connection.data,
      qt_meta_data_Connection,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Connection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Connection::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Connection.stringdata0))
        return static_cast<void*>(const_cast< Connection*>(this));
    return QObject::qt_metacast(_clname);
}

int Connection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void Connection::onRegistrationRequest(ClientInfo _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Connection::onCreateChannelReply(QString _t1, QJsonObject _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Connection::onCreateChannelRequest(QString _t1, QJsonObject _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Connection::onQuit(Connection * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
