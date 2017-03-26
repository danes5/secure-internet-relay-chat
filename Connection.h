#ifndef TCPCONNECTION_H
#define TCPCONNECTION_H

#include <QObject>
#include <QDebug>
#include <QTcpSocket>

/**
 * @brief The Connection class
 * represents communication between client and server
 * contains socket through which server will receive requests from client and send replies
 *
 * not yet implemented
 */
class Connection : public QObject{
        Q_OBJECT

private:
    void processGetRequest();




    public:
        //explicit Connection(QObject *parent = 0);
        //~Connection();

        virtual void setSocket(QTcpSocket *socket);

    protected:
        QTcpSocket *m_socket;
        QTcpSocket *getSocket();

    signals:

    public slots:
        virtual void connected();
        virtual void disconnected();
        virtual void readyRead();
        virtual void bytesWritten(qint64 bytes);
        virtual void stateChanged(QAbstractSocket::SocketState socketState);
        virtual void error(QAbstractSocket::SocketError socketError);

};

#endif // TCPCONNECTION_H
