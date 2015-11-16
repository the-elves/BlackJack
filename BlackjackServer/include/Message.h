#ifndef MESSAGE_H
#define MESSAGE_H
#include<iostream>
#include<string>
using namespace std;
class Message
{
    public:
        enum MessageType{GAME_MESSAGE, CONTROL_MESSAGE};
        enum GameMessageType{ACTION,CARD};
        enum ActionType{HIT,STAND,NONE};


        Message();
        virtual ~Message();

        string from,to;
        int toSocket;
        MessageType messageType;

    protected:
    private:


};

#endif // MESSAGE_H
