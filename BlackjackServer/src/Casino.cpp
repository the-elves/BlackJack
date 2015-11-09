#include "Casino.h"
#include "GameMessage.h"
Casino::Casino()
{
    int socket, clientPort;
    string clientIp, message;
    while(1){
    comm.startServer(socket, clientIp, clientPort);
    comm.readMessage(socket, message);
    cout<<message;
    GameMessage gm ;
    gm.to = "todd";
    gm.from = "frdd";
    gm.toSocket=socket;
    gm.gameMessageType = GameMessage::ACTION;
    gm.action=GameMessage::REQUEST_BET;
    comm.sendMessage(gm);
    }

}

Casino::~Casino()
{
    //dtor
}
