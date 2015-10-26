#ifndef MESSAGE_H
#define MESSAGE_H
#include<iostream>
#include<string>
using namespace std;
class Message
{
    public:
        enum MessageType{GAME_MESSAGE, CONTROL_MESSAGE};
        enum GameMessageType{ACTION,CARD,RESULT};
        enum ActionType{HIT,STAND,FOLD,REQUEST_BET,PLACE_BET,REQUEST_DECISION};
        enum ResultType{WIN,LOOSE};
        string from,to;
        int toSocket;
        MessageType messageType;
        Message();
        virtual ~Message();
    protected:
    private:
};

#endif // MESSAGE_H
