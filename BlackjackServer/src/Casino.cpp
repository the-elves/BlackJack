#include "Casino.h"
#include "GameMessage.h"
#include <sstream>

Casino::Casino()
{

    int socket, clientPort;
    string clientIp, message, name;
    int i = 0;
    thread a(&Casino::readMgt, this);
    while(1){
        comm.acceptConnection(socket, clientIp, clientPort, name);
        Player p(socket, clientPort, clientIp, name);
        startDealer(p);
        if(i == 0)
            dealer.cardsInit();
        i++;
        //comm.readMessage(socket, message);
        //cout<<message;
        /*GameMessage gm ;
        gm.to = "todd";
        gm.from = "frdd";
        gm.toSocket=socket;
        gm.gameMessageType = GameMessage::ACTION;
        gm.action=GameMessage::HIT;
        comm.sendMessage(gm);*/
    }
    a.join();
}

Casino::~Casino()
{
    //dtor
}

void Casino::readMgt() {
    string msg;
    vector<Player>::iterator i;
    fd_set readset;
    FD_ZERO(&readset);
    int count = 0;
    cout<<"readmgt "<<endl;
    while((dealer.players.empty())||(dealer.players.size() <= 1)) {
    }
    cout<<"starting Dealing"<<endl;
    startDealing();
    cout<<"starting Dealing finished"<<endl;
    for(i = dealer.players.begin(); i!= dealer.players.end(); i++) {
    //i = dealer.players.begin();
        do{
            /*FD_SET(i->getSocket(), &readset);
            int r=select(i->getSocket(), &readset, NULL, NULL, NULL);
            if(r > 0) {*/
            cout<<"Waiting for Player one"<<endl;
            comm.readMessage(i->getSocket(), msg);
            //}
            cout<<msg;
            string err;
            json11::Json a = json11::Json::parse(msg.c_str(), err);
            msg = a["actionType"].dump();
            if(msg.size() > 0) {
                msg.erase(0, 1);
                msg.erase(msg.find('"'));
            }
            if(!strcmp(msg.c_str(), "hit")) {
                cout<<"hit clicked"<<endl;
                Card c = dealer.dealCard();
                cout<<"value: "<<c.getCardValue()<<endl;
                GameMessage gm(i->getSocket(), string("Dealer"), i->getName(), Message::GameMessageType::CARD, Message::ActionType::NONE, c);
                comm.sendMessage(gm);
            }
            else if(!strcmp(msg.c_str(), "stand")) {
                cout<<"stand clicked";
                i->setStand(true);
            }
        } while(!i->getStand());
    }
}

/*void Casino::writeMgt(string msg) {
    json11::Json a = json11::Json::parse(str.c_str(), err);
    string name = a["action"].dump();
    if(name.compare("HIT")) {

    }
}*/

void Casino::startDealer(Player p) {
    dealer.addPlayer(p);
    dealer.shuffle();
}

void Casino::startDealing() {
    cout<<"Dealing"<<endl;
    vector<Player>::iterator i;
    int playersCount = dealer.players.size();
    for(i = dealer.players.begin(); i != dealer.players.end(); i++) {
        std::stringstream ss;
        ss << playersCount;
        Card c = dealer.dealCard();
        cout<<"value: "<<c.getCardValue()<<endl;
        GameMessage gm(i->getSocket(), ss.str(), i->getName(), Message::GameMessageType::CARD, Message::ActionType::NONE, c);
        comm.sendMessage(gm);
    }
    for(i = dealer.players.begin(); i != dealer.players.end(); i++) {
        Card c = dealer.dealCard();
        cout<<"value: "<<c.getCardValue()<<endl;
        GameMessage gm(i->getSocket(), string("Dealer"), i->getName(), Message::GameMessageType::CARD, Message::ActionType::NONE, c);
        comm.sendMessage(gm);
    }
}

