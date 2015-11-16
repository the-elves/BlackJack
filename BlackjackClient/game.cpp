#include "game.h"
#include <iostream>
#include <QHostAddress>
#include <QJsonObject>
#include <QJsonDocument>

Game::Game(QObject *parent) :
    QObject(parent)
{

}

void Game::connectToDealer(QString ip, int port, QString name)
{
    QHostAddress addr(ip);
    dealer.connectToHost(addr, port);
    connect(&dealer, SIGNAL(readyRead()), this, SLOT(readyReadDealer()));
    QJsonObject json;
    json["from"] = name;
    QJsonDocument qjd(json);
    QString str(qjd.toJson());
    dealer.write(str.toStdString().c_str());
    this->value = 0;
    this->players = 0;
}

void Game::connectToDecider(QString ip, int port)
{
    QHostAddress addr(ip);
    decider.connectToHost(addr, port);
    connect(&decider, SIGNAL(readyRead()), this, SLOT(readyReadDecider()));
}

void Game::readyReadDealer() {
    while(dealer.bytesAvailable() > 0)
    {
        QString str = dealer.readAll();
        {
            //std::cout<<str.toStdString();
            //151115-001540 68
            QJsonDocument qjd = QJsonDocument::fromJson(str.toUtf8());
            QJsonObject reply = qjd.object();
            QString check = reply["messageType"].toString();
            if(!QString::compare(check, "controlMessage", Qt::CaseInsensitive)) {
                this->players = reply["controlText"].toString().toInt();
                emit displayMsg("You are playing against: " + QString::number(players) + " players");
            }
            else {
                if(this->players == 0) {
                    this->players = reply["from"].toString().toInt();
                    emit displayMsg("You are playing against: " + QString::number(players) + " players");
                    emit changePlaying(true);
                }
                int temp = reply["value"].toString().toInt();
                this->value += temp;
                QString msg = reply["rank"].toString() + " of " + reply["suit"].toString() + "=" + reply["value"].toString() + " total: " + QString::number(value);
                emit Game::displayMsg(msg);
            }
            if(value >= 22) {
                emit changePlaying(false);
                emit displayMsg("You are busted (hand value exceeded 22)");
                stand();
                receiveResult();
            } else if(value >= 17) {
                emit changePlaying(false);
                emit displayMsg("You can't hit (hand value exceeded 17)");
                stand();
                receiveResult();
            }
        }
    }
}

void Game::readyReadDecider() {
    while(decider.bytesAvailable() > 0) {
        QString str = decider.readAll();
        emit displayMsg(str);
    }
}

void Game::sendMessageDealer(QJsonObject obj)
{
    QJsonDocument doc(obj);
    QString msgstr(doc.toJson(QJsonDocument::Compact));
    dealer.write(msgstr.toStdString().c_str());
}

void Game::sendMessageDecider(const QString& msg)
{
    const QString* msgQStr = &msg;
    std::string messageStr = msgQStr->toStdString();
    const char* messageCh = messageStr.c_str();
    decider.write(messageCh, 50);
}

void Game::setName(QString name) {
    this->name = name;
}

void Game::hit() {
    //std::cout<<"hit ";
    QJsonObject msg;
    msg["to"] = QString("Dealer");
    msg["from"] = QString(this->name);
    msg["gameMessageType"] = QString("action");
    msg["actionType"] = QString("hit");
    sendMessageDealer(msg);
}

void Game::stand() {
    QJsonObject msg;
    msg["to"] = QString("Dealer");
    msg["from"] = QString(this->name);
    msg["gameMessageType"] = QString("action");
    msg["actionType"] = QString("stand");
    sendMessageDealer(msg);
    emit changePlaying(false);
}

void Game::receiveResult() {
    connectToDecider("172.17.5.37", 8888);
    QString msg = this->name + " " + QString::number(this->players) + " " + QString::number(this->value);
    std::cout<<msg.toStdString();
    sendMessageDecider(msg.toStdString().c_str());
}
