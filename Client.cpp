#include "Client.hpp"

//Client::Client(QObject *parent) : QObject(parent) {}

Client::Client(QObject *parent) : QObject(parent){}

const ClientInfo& Client::getClientInfo(){
    return clientInfo;
}
