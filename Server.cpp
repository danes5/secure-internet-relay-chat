#include "Server.h"


Server::Server(QObject *parent) : QTcpServer(parent)
{
    qDebug() <<  this << "created on" << QThread::currentThread();
    if (! listen(QHostAddress::Any, 5000)){
        qDebug() << "could not start server";
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

/*bool Server::registerNewClient(QString clientName, Connection* connection){
    if (getRegisteredClients.find(clientName) != registeredClients.end())
        return false;
    Client *client = new Client;
    registeredClients.insert(clientName, client);
    return true;
}*/

void Server::sendConnectionRequest(QString callerName, QString destName) {
    auto con = findConnection(callerName);
    if (con == nullptr){
        qDebug() << "requested user does not exist";
        return;


}
}

void Server::sendConnectionAccept(QString callerName, QString destName){
    // not yet implemented
}

void Server::sendConnectionDecline(QString callerName, QString destName){
    // not yet implemented
}

void Server::sendClientInfo(QString clientName, QString destName){
    // not yet implemented
}

bool Server::clientExists(QString clientName)
{
    auto cl = getRegisteredClients();

    return cl.contains(clientName);
}

/*const ClientInfo&  Server::getClientInfo(QString clientName){
    for (auto it : activeConnections){
        if (it->getClientInfo().name == clientName)
            return it->getClientInfo();
    }

}*/

/*QJsonObject Server::getclientInfoInJSON(QString clientName){
    QJsonObject clientInfoJson;
    ClientInfo cInfo = getClientInfo(clientName);
    cInfo.write(clientInfoJson);
    return clientInfoJson;

}*/

/*void Server::removeClient(QString clientName){
    auto client = registeredClients.find(clientName);
    client.value()->deleteLater();

    registeredClients.remove(clientName);
}*/

void Server::incomingConnection(qintptr socketDescriptor)
{
    qDebug() << "new Incoming connection" << socketDescriptor;
    Connection* connection = new Connection(socketDescriptor, this);
    connect(connection, SIGNAL(onRegistrationRequest(QString)), this, SLOT(processRegistrationRequest(QString)) );
    //bool b = connection->setSocketDescriptor(socketDescriptor);

    activeConnections.push_back(connection);
    //qDebug() << "connection has descriptor: " << connection->socketDescriptor();
    //emit connection->connected();
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

void Server::processRegistrationRequest(QString name)
{
    qDebug() << "process registration request on server was called name: " << name;
    Connection* con = static_cast<Connection*>(QObject::sender());
    if (findConnection(con->getName()) == nullptr){
        con->processRegistrationRequest(name, true);
    } else{
        con->processRegistrationRequest(name, false);
    }
}
