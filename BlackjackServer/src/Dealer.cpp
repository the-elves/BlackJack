#include "Dealer.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <algorithm>
#include <iterator>
using namespace std;

Dealer::Dealer()
{
    //ctor
}

Dealer::~Dealer()
{
    //dtor
}

void Dealer::addPlayer(Player p) {
    this->players.push_back(p);
}

void Dealer::cardsInit() {
    for(int i = SuitFirst; i <= SuitLast; i++) {
        for(int j = RankFirst; j <= RankLast; j++) {
            Card c((Suit)i, (Rank)j);
            this->cardsAvailable.push_back(c);
        }
    }
}

void Dealer::shuffle() {
    random_shuffle(cardsAvailable.begin(), cardsAvailable.end());
    vector<Card>::iterator i;
    for(i = cardsAvailable.begin(); i != cardsAvailable.end(); i++) {
        i->printCard();
    }
}

Card Dealer::dealCard() {
    int randomIndex = rand() % cardsAvailable.size();
    Card c = cardsAvailable.at(randomIndex);
    cardsDealt.push_back(c);
    int count = -1;
    vector<Card>::iterator i;
    for(i = cardsAvailable.begin(); i != cardsAvailable.end(); i++) {
        count++;
        if(count == randomIndex) {
            cout<<"Card selected: ";
            i->printCard();
            cardsAvailable.erase(i);
        }
    }
    return c;
}
