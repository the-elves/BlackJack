#ifndef GAMEMESSAGE_H
#define GAMEMESSAGE_H

#include <Message.h>
#include <Card.h>

class GameMessage : public Message
{
    public:
        GameMessageType gameMessageType;
        ActionType action;
        //Card c;
        GameMessage();
        GameMessage(int sock, string from, string to, GameMessageType gm, ActionType a, Card card);
        Card getCard();

        virtual ~GameMessage();
    protected:
    private:
        Card c;
};

#endif // GAMEMESSAGE_H
