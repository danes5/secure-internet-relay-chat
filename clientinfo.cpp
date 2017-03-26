#include "clientinfo.h"

ClientInfo::ClientInfo()
{

}

void ClientInfo::write(QJsonObject &json) const
{
    // temporary implementation
    json["address"] = clientAddress.toString();

}

void ClientInfo::read(const QJsonObject &json)
{
    // temporary implementation
    clientAddress.setAddress(json["address"].toString());
}

