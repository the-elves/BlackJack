#include "Card.h"
#include <iostream>
using namespace std;

Card::Card(Suit suit, Rank rnk)
{
    //ctor
    this->s = suit;
    this->r = rnk;
}


Card::~Card()
{
    //dtor
}

Card::Card()
{
    //ctor
}


Rank Card::getRank() {
    return this->r;
}

Suit Card::getSuit() {
    return this->s;
}

void Card::setRank(Rank rnk) {
    this->r = rnk;
}

void Card::setSuit(Suit suit) {
    this->s = suit;
}

string Card::getCardSuit() {
    switch(s) {
        case SPADES:
            return "SPADES";
            break;
        case HEARTS:
            return "HEARTS";
            break;
        case DIAMONDS:
            return "DIAMONDS";
            break;
        case CLUBS:
            return "CLUBS";
            break;
        default:
            return "";
    };
}

string Card::getCardRank() {
    switch(r) {
        case ACE:
            return "ACE";
            break;
        case TWO:
            return "TWO";
            break;
        case THREE:
            return "THREE";
            break;
        case FOUR:
            return "FOUR";
            break;
        case FIVE:
            return "FIVE";
            break;
        case SIX:
            return "SIX";
            break;
        case SEVEN:
            return "SEVEN";
            break;
        case EIGHT:
            return "EIGHT";
            break;
        case NINE:
            return "NINE";
            break;
        case TEN:
            return "TEN";
            break;
        case JACK:
            return "JACK";
            break;
        case QUEEN:
            return "QUEEN";
            break;
        case KING:
            return "KING";
            break;
        default:
            return "";
    };
}


void Card::printCard() {
    cout<<"\t";
    cout<<getCardRank();
    cout << " of ";
    cout<<getCardSuit();
}

int Card::getCardValue() {
    int val = this->r;
    val++;
    if(val > 10)
        val = 10;
    this->value = val;
    return val;
}





