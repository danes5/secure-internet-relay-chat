#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QThread>
#include "Connection.h"
#include <map>
#include <string>

#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>
#include "rsautils.h"

/**
 * @brief The Server class
 * represents server that is responsible for communicating with clients and creating connections between them
 */
class Connection;
class Server : public QTcpServer
{
    Q_OBJECT

private:
    QList<Connection*> activeConnections;
    rsautils rsa;
public:
    Server(QObject *parent = nullptr);

    const QString serverKeysPath = "rsa_priv.txt";

    /**
     * @brief getRegisteredClients
     * @return map of all registered clients
     */
    QList<QString> getRegisteredClients();


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


protected:
    void incomingConnection(qintptr socketDescriptor) override;
    Connection* findConnection(QString name);

public slots:
    void processRegistrationRequest(ClientInfo clInfo);
    /**
     * @brief sendConnectionRequest method called by client to initialize connection with another client
     * @param callerName name of the sender of the request
     * @param destName name of the destination client of the request
     */
    void sendChannelRequest(QString destName, QJsonObject json);
    void sendChannelReply(QString destName, QJsonObject json);

    /**
     * @brief removeClient remove client from server
     * @param clientName name of the client to remove
     */
    void removeClient(Connection* connection);


};

#endif // SERVER_H
