#ifndef N2CHSERVER_H
#define N2CHSERVER_H

#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>

#include "n2thread.h"


class N2ChServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit N2ChServer(QObject *parent = nullptr);
    void StartServer();
private:
    QTcpServer *server;
protected:
    void incomingConnection(int socketDescriptor);
public slots:
    void NewConnection();
signals:

};

#endif // N2CHSERVER_H
