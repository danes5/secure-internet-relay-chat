#ifndef TCPCONNECTION_H
#define TCPCONNECTION_H

#include <QObject>
#include <QDebug>
#include <QTcpSocket>
#include <QSslSocket>
#include <QFile>
#include "clientinfo.h"
#include "gcmutils.h"
#include "buffer.h"
#include "parser.h"
#include "Server.h"
#include "rsautils.h"
/**
 * @brief The Connection class
 * represents communication between client and server
 * contains socket through which server will receive requests from client and send replies
 */



class Server;
class Connection : public QObject {
        Q_OBJECT

private:
    QSslSocket* socket;
    rsautils& rsa;

    public:
        explicit Connection(quintptr descriptor, rsautils& rsa, QObject *parent = 0);
    const ClientInfo& getClientInfo();
    bool isReady();
        ~Connection();
    void sendChannelRequest(QJsonObject data);
    void sendChannelReply(QJsonObject data);
    void sendRegisteredClients();
    void sendRegistrationReply(QString clientName, bool result);
    bool isRegistered();
    QString getName();
private:
    bool encrypted;
    GcmUtils gcm;
    Buffer buffer;
    quint64 nextId;
    Server* server;
    QByteArray encryptAndTag(QJsonObject json);
    bool registered;

    // info about the client
    ClientInfo clientInfo;

    QByteArray encryptGetRegisteredClientsReply();
    QByteArray encryptChannelRequest(QJsonObject data);
    QByteArray encryptChannelReply(QJsonObject data);
    QByteArray encryptSendClientInfo(QJsonObject data);
    QByteArray encryptRegistrationReply(QString clientName, bool result);


    void initialize();
    unsigned char * generateGcmKey();
    void setkey(unsigned char * newKey);




    signals:
        void onRegistrationRequest(ClientInfo clInfo);
        void onCreateChannelReply(QString dest, QJsonObject data);
        void onCreateChannelRequest(QString destination,  QJsonObject json);
        void onQuit(Connection* connection);

    public slots:
        void processRegistrationRequest(ClientInfo clInfo, bool result);
        void connected();
        void disconnected();
        void readyRead();
        void bytesWritten(qint64 bytes);
        void stateChanged(QAbstractSocket::SocketState socketState);
        void sslError(QList<QSslError> errors);
        void socketError(QAbstractSocket::SocketError error);


};

#endif // TCPCONNECTION_H
