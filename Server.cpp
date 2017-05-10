#include "Server.h"


Server::Server(QObject *parent) : QTcpServer(parent)
{
    qDebug() <<  this << "created on" << QThread::currentThread();
    if (! listen(QHostAddress::Any, 5000)){
        qDebug() << "could not start server";
    }
    int ret;
    if ((ret = rsa.initialize()) != 0 ){
        qDebug() << "initialization failed: " << ret;
        return;
    }
    if ((ret = rsa.setMyKeyFromFile(serverKeysPath)) != 0){
        qDebug() << "could not set key from file: " << ret;
    }
}

QList<QString> Server::getRegisteredClients()
{
    QList<QString> clients;
    for (auto con : activeConnections){
        if (con->isReady())
            clients.push_back(con->getName());
    }
    return clients;
}

QJsonObject Server::getRegisteredClientsInJson()
{
    QJsonObject data;

    QJsonArray names;

    for (auto& it : getRegisteredClients()){
        qDebug() << it;
        names.append(it);
    }
    data["names"] = names;
    return data;

}

void Server::sendChannelRequest(QString destName, QJsonObject json) {
    qDebug() << "sending connection request to: " << destName;
    auto con = findConnection(destName);
    if (con == nullptr){
        qDebug() << "requested user does not exist";
        return;
    }
    con->sendChannelRequest(json);



}

void Server::sendChannelReply(QString destName, QJsonObject json)
{
    qDebug() << "sending channel reply to client: " << destName;
    auto con = findConnection(destName);
    if (con == nullptr){
        qDebug() << "requested user does not exist";
        return;
    }
    con->sendChannelReply(json);
}

bool Server::clientExists(QString clientName)
{
    auto cl = getRegisteredClients();

    return cl.contains(clientName);
}

void Server::removeClient(Connection *connection)
{
    qDebug() << "remove client";
    activeConnections.removeAll(connection);
}


void Server::incomingConnection(qintptr socketDescriptor)
{
    qDebug() << "new Incoming connection" << socketDescriptor;
    Connection* connection = new Connection(socketDescriptor, rsa, this);
    connect(connection, SIGNAL(onRegistrationRequest(ClientInfo)), this, SLOT(processRegistrationRequest(ClientInfo)) );
    connect(connection, SIGNAL(onCreateChannelRequest(QString, QJsonObject)), this, SLOT(sendChannelRequest(QString, QJsonObject)));
    connect(connection, SIGNAL(onCreateChannelReply(QString, QJsonObject)), this, SLOT(sendChannelReply(QString, QJsonObject)));
    connect(connection, SIGNAL(onQuit(Connection*)), this, SLOT(removeClient(Connection*)));
    activeConnections.push_back(connection);

}

Connection *Server::findConnection(QString name)
{
    for (auto it : activeConnections){
        if (it->isRegistered()){
            if (it->getName() == name)
                return &(*it);

        }
    }
    return nullptr;
}

void Server::processRegistrationRequest(ClientInfo clInfo)
{
    //qDebug() << "process registration request on server was called name: " << name;
    Connection* con = static_cast<Connection*>(QObject::sender());
    if (findConnection(clInfo.name) == nullptr){
        con->processRegistrationRequest(clInfo, true);
       qDebug() << "registration accepted ";
    } else{
        con->processRegistrationRequest(clInfo, false);
        qDebug() << "registration rejected ";
    }
}
