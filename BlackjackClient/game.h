#ifndef GAME_H
#define GAME_H

#include <QObject>
#include "player.h"
#include <QTcpSocket>

class Game : public QObject
{
    Q_OBJECT

public:
    explicit Game(QObject *parent = 0);
    void connectToDealer(QString ip, int port,QString);
    void connectToDecider(QString ip, int port);
    void sendMessageDealer(QJsonObject obj);
    void sendMessageDecider(const QString &obj);
    void hit();
    void stand();
    void receiveResult();
    void setName(QString name);

private:
    Player p;
    QTcpSocket dealer;
    QTcpSocket decider;
    QString name;
    int players;
    int value;

signals:
    void displayMsg(QString msg);
    void changePlaying(bool value);

public slots:
    void readyReadDealer();
    void readyReadDecider();

};

#endif // GAME_H
