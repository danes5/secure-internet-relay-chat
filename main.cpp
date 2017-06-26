#include "Server.h"
#include <QCoreApplication>
#include <QDebug>

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);

  Server server;
  return a.exec();
}
