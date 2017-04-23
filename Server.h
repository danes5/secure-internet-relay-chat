#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QThread>
#include "Connection.h"
#include <map>
#include <string>
#include "Client.h"

#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>

/**
 * @brief The Server class
 * represents server that is responsible for communicating with clients and creating connections between them
 */
class Connection;
class Server : public QTcpServer
{
    Q_OBJECT
public:
    Server(QObject *parent = nullptr);
    /**
     * @brief getRegisteredClients
     * @return map of all registered clients
     */
    QList<QString> getRegisteredClients();
    QList<Connection*> activeConnections;

    QJsonObject getRegisteredClientsInJson();

    /**
     * @brief registerNewClient attempts to register client and add him into map, returns true if insertion into map was successful, false otherwise
     * @param clientName name of the new client
     * @param connection pointer to connection on which client communicates with the server
     * @return
     */
    bool registerNewClient(QString clientName, Connection* connection);

    /**
     * @brief sendConnectionAccept called on server by accepting client to send request accept to the sender
     * @param callerName name of the accepting client
     * @param destName name of the original sender of the request
     */
    void sendConnectionAccept(QString callerName, QString destName);

    /**
     * @brief sendConnectionDecline called on server by declining client to send request decline to the request sender
     * @param callerName name of the declining client
     * @param destName name of the original sender of the request
     */
    void sendConnectionDecline(QString callerName, QString destName);

    /**
     * @brief sendClientInfo send client info over network about client to another client, only after connectiom between them was accepted
     * @param clientName name of the client to send info about
     * @param destName name of the client to send info to
     */
    void sendClientInfo(QString clientName, QString destName);

    /**
     * @brief clientExists checks for existence of a client by name
     * @param clientName name of the client
     * @return true if client is in the map, false otherwise
     */
    bool clientExists(QString clientName);

    /**
     * @brief getClientInfo get info about client
     * @param clientName name of the client
     */
    const ClientInfo& getClientInfo(QString clientName);

    /**
     * @brief clientInfoToJSON get client info in JSON form
     * @param clientInfo client info to format
     * @return clientInfo in JSON format
     */
    QJsonObject getclientInfoInJSON(QString clientName);

    /**
     * @brief removeClient remove client from server, also remove all ongoing communications
     * @param clientName name of the client to remove
     */
    void removeClient(QString clientName);

protected:
    void incomingConnection(qintptr socketDescriptor) override;
    Connection* findConnection(QString name);

public slots:
    void processRegistrationRequest(QString name);
    /**
     * @brief sendConnectionRequest method called by client to initialize connection with another client
     * @param callerName name of the sender of the request
     * @param destName name of the destination client of the request
     */
    void sendConnectionRequest(QString callerName, QString destName);

};

#endif // SERVER_H
