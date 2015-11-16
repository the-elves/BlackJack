#include "GameMessage.h"

GameMessage::GameMessage(int sock, string from, string to, GameMessageType gm, ActionType a, Card card) {

    this->toSocket = sock;
    this->from = from;
    this->to = to;
    this->gameMessageType = gm;
    this->action = a;
    this->messageType = GAME_MESSAGE;
    this->c.setRank(card.getRank());
    this->c.setSuit(card.getSuit());
    this->c.getCardValue();
}
GameMessage::GameMessage() {
    //ctor
}

GameMessage::~GameMessage()
{
    //dtor
}

Card GameMessage::getCard()
{
    return this->c;
}


