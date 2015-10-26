#ifndef DEALER_H
#define DEALER_H

#include "card.h"
#include "player.h"

class Dealer
{
    public:
        //constructor, destructor
        Dealer();
        virtual ~Dealer();

        //getter, setter
        void setPort(int port);
        int getPort();

        //rest methods
        void Connect();
        void addPlayer(Player p);
        void dealCards(int num);
        void readPlayerMoves();
        void writeToPlayers();
        void play(); //adds cards and calculates myHand
        void decider();


    protected:

    private:
        int port;
        int myHand;
        vector<Player> players;
        vector<Card> cards;
};

#endif // DEALER_H
