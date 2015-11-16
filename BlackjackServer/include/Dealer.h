#ifndef DEALER_H
#define DEALER_H

#include "Card.h"
#include <json11.hpp>
#include <vector>
#include "Player.h"
using namespace std;
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
        void shuffle();
        void cardsInit();
        void addPlayer(Player p);
        Card dealCard();
        vector<Player> players;

    protected:

    private:
        int port;
        int myHand;

        vector<Card> cardsAvailable, cardsDealt;
};

#endif // DEALER_H
