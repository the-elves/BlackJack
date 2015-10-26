#ifndef CARD_H
#define CARD_H

enum Rank { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
enum Suit { SPADES, HEARTS, DIAMONDS, CLUBS };

class Card
{
    public:
        //constructor, destructor
        Card();
        virtual ~Card();

        //getter, setter
        void setRank(Rank r);
        int getRank();
        void setSuit(Suit s);
        int getSuit();

        //rest methods
        int getCardValue();

    protected:
    private:
        Rank r;
        Suit s;
};

#endif // CARD_H
