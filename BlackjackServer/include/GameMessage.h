#ifndef GAMEMESSAGE_H
#define GAMEMESSAGE_H

#include <Message.h>
#include <Card.h>

class GameMessage : public Message
{
    public:
        GameMessageType gameMessageType;
        ActionType action;
        ResultType result;
        Card c;
        GameMessage();

        virtual ~GameMessage();
    protected:
    private:
};

#endif // GAMEMESSAGE_H
