#include "Connection.h"
#include "parser.h"

void Connection::processGetRequest()
{

}

Connection::Connection(quintptr descriptor, QObject *parent) : QObject(parent), encrypted(true), registered(false), server(static_cast<Server*> (parent))
{
    initialize();
    unsigned char key[32] = { 'o', 'a', 'b', 's', 'w', 'o', 'e', 'd', 'v', 'h', 'q', 'm', 'z', 'g', 'a', 'u','y','q','g','l','5','`','1','Z','q','H','7','F','f','b','n',' '};
    setkey(key);
    socket = new QTcpSocket();
    socket->setSocketDescriptor(descriptor);
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    qDebug() << "connection initialized";

}

void Connection::initialize(){
    gcm.initialize();
}

unsigned char* Connection::generateGcmKey()
{
    return gcm.generateGcmKey();
}

void Connection::setkey(unsigned char * newKey)
{
    gcm.setKey(newKey);

}

void Connection::processRegistrationRequest(QString name, bool result)
{
    if (registered || !result)
        return;
    registered = result;
    clientName = name;
    sendRegistrationReply(name, result);

}

/*Connection::Connection(QObject *parent)
{
    //qDebug() << "created connection on:" << socketDescriptor();
    //qDebug() << isValid();
}*/

/*const ClientInfo &Connection::getClientInfo()
{
    return clientInfo;

}*/

bool Connection::isReady()
{
   return registered && encrypted;

}

Connection::~Connection()
{

}

QByteArray Connection::encryptAndTag(QJsonObject json)
{
    QJsonDocument jsonDoc(json);
    QByteArray array(jsonDoc.toBinaryData());
    return gcm.encryptAndTag(array);

}

QByteArray Connection::encryptGetRegisteredClientsReply()
{
    QJsonObject result;
    QJsonObject jsonClients = server->getRegisteredClientsInJson();
    result["data"] = jsonClients;
    result["type"] = "ret_cli";
    return encryptAndTag(result);

}

QByteArray Connection::encryptChannelRequest(QJsonObject data)
{
    QJsonObject result;
    result["type"] = "req_cre";
    result["name"] = data["name"];
    return encryptAndTag(result);
}

QByteArray Connection::encryptChannelReply(QJsonObject data)
{
    QJsonObject result;
    result["type"] = "req_rep";
    result["name"] = data["name"];
    result["result"] = data["result"];
    return encryptAndTag(result);
}

QByteArray Connection::encryptSendClientInfo(QJsonObject data)
{
    QJsonObject result;
    result["type"] = "cli_info";
    result["info"] = data["info"];
    return encryptAndTag(result);
}

QByteArray Connection::encryptRegistrationReply(QString name, bool result)
{
    QJsonObject json;
    json["type"] = "reg_rep";
    json["name"] = name;
    json["result"] = result ? "acc" : "rej";
    return encryptAndTag(json);
}

void Connection::sendRegisteredClients()
{
    QByteArray array = encryptGetRegisteredClientsReply();
    socket->write(array);
    if (!socket->waitForBytesWritten())
        qDebug() << "cant write bytes";
}

void Connection::sendRegistrationReply(QString name, bool result)
{
    qDebug() << "sending registration reply to name: " << name << "with result: " << result;
    QByteArray array = encryptRegistrationReply(name, result);
    socket->write(array);
    if (!socket->waitForBytesWritten())
        qDebug() << "cant write bytes";
}

bool Connection::isRegistered()
{
    return registered;
}

QString Connection::getName()
{
    return clientName;
}

void Connection::sendChannelRequest(QJsonObject data){
    QByteArray array = encryptChannelRequest(data);
    socket->write(array);
    if (!socket->waitForBytesWritten())
        qDebug() << "cant write bytes";
}

void Connection::sendChannelReply(QJsonObject data){
    QByteArray array = encryptChannelReply(data);
    socket->write(array);
    if (!socket->waitForBytesWritten())
        qDebug() << "cant write bytes";
}





void Connection::connected()
{
    //write("ahoj", 4);


}

void Connection::disconnected()
{

}

void Connection::readyRead()
{
    qDebug() << "ready read !!!";
   buffer.append(socket->readAll());
   if (buffer.fullMessageRead()){
       QByteArray data = buffer.getData();
        Parser parser;
       if (encrypted){
           parser = Parser(gcm.decryptAndAuthorizeFull(data));
           if (! parser.verifyId(nextId)){
               // ids do not match so just discard this message
               return;
           }
           QString type = parser.get("type");
           if (type == "get_cli"){
                qDebug() << "get active clients request";
                sendRegisteredClients();
           } else
           if (type == "reg_req"){
               QString name = parser.get("client");
               emit onRegistrationRequest(name);
               qDebug() << "registration request received from client: " << name;
           } else
           if (type == "req_cre"){
               QString name = parser.get("client");
               qDebug() << "received communication request to client: " << name;
               emit onCreateChannelRequest(clientName, name);
           } else
           if (type == "req_rep"){
               QString name = parser.get("client");
               QString res = parser.get("result");
               qDebug() << "received communication reply to client: " << name << " with result: " << res;
           }



       } else{
           qDebug() << "read data: " << data;
           QJsonDocument doc;
           parser = Parser(QJsonDocument::fromBinaryData(data));
       }
       if (! parser.verifyId(nextId)){
           // ids do not match so just discard this message
           return;
       }





   }
   buffer.reset();


}

void Connection::bytesWritten(qint64 bytes)
{

}

void Connection::stateChanged(QAbstractSocket::SocketState socketState)
{

}

void Connection::error(QAbstractSocket::SocketError socketError)
{

}

