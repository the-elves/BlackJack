#ifndef CARD_H
#define CARD_H

#include <QObject>

enum Rank {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
enum Suit {SPADES, HEARTS, DIAMONDS, CLUBS};

class Card : public QObject
{
    Q_OBJECT
public:
    //constructor, destructor
    explicit Card(QObject *parent = 0, QString name, QString ip, int sock, int port);

    //getter, setter
    void setRank(Rank r);
    int getRank();
    void setSuit(Suit s);
    int getSuit();

    //rest methods
    int getCardValue();

signals:

public slots:

private:
    Rank r;
    Suit s;
};

#endif // CARD_H
