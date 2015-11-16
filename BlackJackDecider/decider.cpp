#include "decider.h"

Decider::Decider(QObject *parent) :
    QObject(parent)
{
    this->players = 0;
    server = new QTcpServer(this);
    connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));
    if(server->listen(QHostAddress::Any, 8888)) {
        qDebug() << "Server started";
    } else {
        qDebug() << "Server not started";
    }
}

void Decider::newConnection() {
    QTcpSocket *socket = server->nextPendingConnection();
    socket->write("Decider connected");
    socket->flush();
    socket->waitForBytesWritten(3000);
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    clients.push_back(socket);
}

void Decider::readyRead() {
    QTcpSocket *client = static_cast<QTcpSocket*>(sender());
    while(client->bytesAvailable() > 0) {
        QString str = client->readAll();
        QStringList strarr = str.split(" ");
        this->players = strarr.at(1).toInt();
        for(int i = 0; i < strarr.size(); i++) {
            qDebug() << strarr.at(i);
        }
        hands.insert(strarr[0], strarr.at(2).toInt());
        if(hands.size() == players) {
            decideAndSend();
        }
    }
}

void Decider::decideAndSend() {
    int max = 0;
    foreach( QString key, hands.keys() )
    {
        qDebug() << key << QString::number(hands.value(key)) << '\n';
        if((max < hands.value(key)) && hands.value(key) < 22)
            max = hands.value(key);
    }
    foreach( QString key, hands.keys() )
    {
        std::vector<QTcpSocket*>::iterator i;
        if(max > hands.value(key)) {
            for(i = clients.begin(); i != clients.end(); i++) {
                (*i)->write(("\n" + key + " " + QString::number(hands.value(key)) + " " + "LOST").toStdString().c_str());
            }
        }
        if(max == hands.value(key)) {
            for(i = clients.begin(); i != clients.end(); i++) {
                (*i)->write(("\n" + key + " " + QString::number(hands.value(key)) + " " + "WON").toStdString().c_str());
            }
        }
    }
    qDebug() << max;
}

