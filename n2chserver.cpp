#include "n2chserver.h"

N2ChServer::N2ChServer(QObject *parent) : QTcpServer(parent)
{
}

void N2ChServer::StartServer()
{
    if(this->listen(QHostAddress::Any, 60535))
    {
        qDebug() << "Server started";
    }
    else
    {
        qDebug() << "Server did not start!";
    }
}

void N2ChServer::incomingConnection(int socketDescriptor)
{
    qDebug() << socketDescriptor << " Connecting...";
    N2Thread *thread = new N2Thread(socketDescriptor, this);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
}

void N2ChServer::NewConnection()
{
    QTcpSocket *socket = server->nextPendingConnection();
    socket->write("hello client\r\n");
    socket->flush();
    socket->waitForBytesWritten(3000);
    socket->close();
}
