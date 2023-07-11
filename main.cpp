#include <QCoreApplication>
#include "n2chserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    N2ChServer server;
    server.StartServer();
    return a.exec();
}
