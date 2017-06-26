#ifndef TCPCONNECTION_H
#define TCPCONNECTION_H

#include "Server.h"
#include "buffer.h"
#include "clientinfo.h"
#include "gcmutils.h"
#include "parser.h"
#include "rsautils.h"
#include <QDebug>
#include <QFile>
#include <QObject>
#include <QSslSocket>
#include <QTcpSocket>
/**
 * @brief The Connection class
 * represents communication between client and server
 * contains socket through which server will receive requests from client and
 * send replies
 */

class Server;
class Connection : public QObject {
  Q_OBJECT

public:
  explicit Connection(quintptr descriptor, rsautils &rsa, QObject *parent = 0);
  const ClientInfo &getClientInfo();
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
  bool registered;
  Server *server;

  // info about the client
  ClientInfo clientInfo;
  QSslSocket *socket;
  rsautils &rsa;

  QByteArray encryptAndTag(QJsonObject json);
  QByteArray encryptGetRegisteredClientsReply();
  QByteArray encryptChannelRequest(QJsonObject data);
  QByteArray encryptChannelReply(QJsonObject data);
  QByteArray encryptSendClientInfo(QJsonObject data);
  QByteArray encryptRegistrationReply(QString clientName, bool result);

  void initialize();
  unsigned char *generateGcmKey();
  void setkey(unsigned char *newKey);

signals:
  void onRegistrationRequest(ClientInfo clInfo);
  void onCreateChannelReply(QString dest, QJsonObject data);
  void onCreateChannelRequest(QString destination, QJsonObject json);
  void onQuit(Connection *connection);

public slots:
  void processRegistrationRequest(ClientInfo clInfo, bool result);
  void connected();
  void disconnected();
  void readyRead();
  void stateChanged(QAbstractSocket::SocketState socketState);
  void sslError(QList<QSslError> errors);
  void socketError(QAbstractSocket::SocketError error);
};

#endif // TCPCONNECTION_H
