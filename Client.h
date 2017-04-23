#ifndef PB173_TEST_CLIENT_H
#define PB173_TEST_CLIENT_H
/*

#include <QObject>
#include <QTcpSocket>
#include <QThreadPool>
#include "Connection.h"
#include "clientinfo.h"

/**
 * @brief The Client class
 * abstraction of client, has info about client and facilitates calling methods by server on Connection object for that client
 * will contain signals that are connected slots to Connection object upon instantiation


class Client : public QObject {
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);

    const ClientInfo& getClientInfo();

    // class will contain some signals and slots for communication with Connection, which will run on a separate thread
    signals:

    public slots:

private:
    // connection is responsible for communication over network with client
    Connection* connection;
    // info about this client
    ClientInfo clientInfo;

};
*/

#endif //PB173_TEST_CLIENT_H
