#include "Server.hpp"


Server::Server(QObject *parent) : QTcpServer(parent)
{
    qDebug() <<  this << "created on" << QThread::currentThread();
}

QList<QString> Server::getRegisteredClients()
{
    return registeredClients.keys();
}

QJsonObject Server::getRegisteredClientsInJson()
{
    QJsonObject data;

    QJsonArray names;

    for (auto& it : registeredClients.keys()){
        names.append(it);
    }
    data["names"] = names;
    return data;

}

bool Server::registerNewClient(QString clientName, Connection* connection){
    if (registeredClients.find(clientName) != registeredClients.end())
        return false;
    Client *client = new Client;
    registeredClients.insert(clientName, client);
    return true;
}

void Server::sendConnectionRequest(QString callerName, QString destName){
    // not yet implemented
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
    return registeredClients.find(clientName) != registeredClients.end();
}

const ClientInfo&  Server::getClientInfo(QString clientName){
    auto it = registeredClients.find(clientName);
    return it.value()->getClientInfo();
}

QJsonObject Server::getclientInfoInJSON(QString clientName){
    QJsonObject clientInfoJson;
    auto it = registeredClients.find(clientName);
    it.value()->getClientInfo().write(clientInfoJson);
    return clientInfoJson;

}

void Server::removeClient(QString clientName){
    auto client = registeredClients.find(clientName);
    client.value()->deleteLater();

    registeredClients.remove(clientName);
}
