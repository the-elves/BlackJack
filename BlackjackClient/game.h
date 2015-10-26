#ifndef GAME_H
#define GAME_H

#include <QObject>
#include "player.h"

class Game : public QObject
{
    Q_OBJECT
    explicit Game(QObject *parent = 0);
    void connectToDealer(QString ip, int port);
    void receiveCards();
    void calculateMoney();
    void decideMove();
    void hit();
    void stand();
    void receiveResult();

private:
    Player p;

signals:

public slots:

};

#endif // GAME_H
