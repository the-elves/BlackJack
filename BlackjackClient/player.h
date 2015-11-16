#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include "card.h"



class Player : public QObject
{
    Q_OBJECT
public:
    explicit Player(QObject *parent = 0);

    //getter, setter
    void setName();
    QString getName();    
    void setIp();
    QString getOwnIp();
    void setHand(int hand);
    int getHand();
    void setBet(int bet);
    int getBet();
    void setMoney(int money);
    int getMoney();
    void setStand(bool stand);
    bool getStand();


protected:


private:
    QString name, OwnIp;
    int hand, bet, money;
    bool stand;
    std::vector<Card> cards;

signals:

public slots:

};

#endif // PLAYER_H
