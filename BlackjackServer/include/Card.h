#ifndef CARD_H
#define CARD_H
#include <iostream>
using namespace std;

enum Rank { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, RankFirst = ACE, RankLast = KING};
enum Suit { SPADES, HEARTS, DIAMONDS, CLUBS, SuitFirst = SPADES, SuitLast = CLUBS };

class Card
{
    public:
        //constructor, destructor
        Card();
        Card(Suit s, Rank r);
        virtual ~Card();

        //getter, setter
        void setRank(Rank r);
        Rank getRank();
        void setSuit(Suit s);
        Suit getSuit();

        //rest methods
        void printCard();
        string getCardRank();
        string getCardSuit();
        int getCardValue();

    protected:
    private:
        Rank r;
        Suit s;
        int value;
};

#endif // CARD_H
