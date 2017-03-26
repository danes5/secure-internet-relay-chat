#include <QCoreApplication>
#include "Server.hpp"
#include <QDebug>

#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>

// Tell CATCH to define its main function here
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

/*int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    Server server;
    //server.startServer();
    return a.exec();
}*/

TEST_CASE("test adding client"){

    Server server;

    REQUIRE(server.registerNewClient("123", nullptr));
    REQUIRE(server.registerNewClient("124", nullptr));
    REQUIRE(server.registerNewClient("125", nullptr));
    REQUIRE(server.registerNewClient("126", nullptr));
    REQUIRE(server.registerNewClient("127", nullptr));
    REQUIRE(! server.registerNewClient("123", nullptr));
    REQUIRE(! server.registerNewClient("124", nullptr));
    REQUIRE(! server.registerNewClient("125", nullptr));
    REQUIRE(! server.registerNewClient("126", nullptr));
    REQUIRE(! server.registerNewClient("127", nullptr));

    auto clients = server.getRegisteredClients();
    REQUIRE(clients.contains("123"));
    REQUIRE(clients.contains("124"));
    REQUIRE(clients.contains("125"));
    REQUIRE(clients.contains("126"));
    REQUIRE(clients.contains("127"));
    REQUIRE(clients.size() == 5);
}

TEST_CASE("Removing clients"){
    Server server;
    server.registerNewClient("123", nullptr);
    server.registerNewClient("124", nullptr);
    server.registerNewClient("125", nullptr);
    server.registerNewClient("126", nullptr);
    server.registerNewClient("127", nullptr);
    server.removeClient("123");
    REQUIRE(server.getRegisteredClients().size() == 4);
    server.removeClient("124");
    REQUIRE(server.getRegisteredClients().size() == 3);
    server.removeClient("125");
    REQUIRE(server.getRegisteredClients().size() == 2);
    server.removeClient("126");
    REQUIRE(server.getRegisteredClients().size() == 1);
    server.removeClient("127");
    REQUIRE(server.getRegisteredClients().size() == 0);
}

TEST_CASE("Get clients name JSON"){
    Server server;
    server.registerNewClient("123", nullptr);
    server.registerNewClient("124", nullptr);
    server.registerNewClient("125", nullptr);
    server.registerNewClient("126", nullptr);
    server.registerNewClient("127", nullptr);
    QJsonObject json = server.getRegisteredClientsInJson();

    QJsonArray names = json["names"].toArray();

   REQUIRE(names[0].toString() == "123");
   REQUIRE(names[1].toString() == "124");
   REQUIRE(names[2].toString() == "125");
   REQUIRE(names[3].toString() == "126");
   REQUIRE(names[4].toString() == "127");
}






