#include "CommunicationModule.h"
#include<iostream>
#include <sstream>
CommunicationModule::CommunicationModule()
{
    getOwnIp();
    sockaddr_in localhost;
    servSocket = socket(AF_INET,SOCK_STREAM ,0);
    bzero(&localhost,sizeof(sockaddr_in));
    localhost.sin_family = AF_INET;
    inet_aton(myIp, &(localhost.sin_addr));
    localhost.sin_port = htons(1234);
    int b = bind(servSocket,(sockaddr*)&localhost,sizeof(sockaddr_in));
    if(b<0){
        cout<<"Couldnt Bind"<<endl;
        exit(1);
    }

}
/**
***************************Blocking Server Start Call***************************************
*******************Needs to be called from seperate thread for this*************************
***********************Loop also need to be Managed by caller*******************************

**/
void CommunicationModule::acceptConnection(int &retSocket, string &clientIp, int &clientPort, string &name){

    sockaddr_in client;
    bzero(&client, sizeof(client));
    int clilen = sizeof(sockaddr_in);
    cout<<endl<<"Listening on 1234"<<endl;
    listen(servSocket, 5);
    int clisocket = accept(servSocket, (sockaddr*)&client, (socklen_t*)&clilen);
    retSocket = clisocket;
    clientIp = inet_ntoa(client.sin_addr);
    clientPort = ntohs(client.sin_port);
    string str, err;
    readMessage(retSocket, str);
    json11::Json a = json11::Json::parse(str.c_str(), err);
    name = a["from"].dump();
    if(name.size() > 0) {
        name.erase(0, 1);
        name.erase(name.find('"'));
    }
    cout<<name<<" joined"<<endl;

}
/*char cliName [100];
    int n = read(clisocket, cliName,100);
    cliName[n] = '\0';
    firstMessage cliName;*/

void CommunicationModule::getOwnIp(){
    char *addr;
    struct ifaddrs *ifap, *ifa;
    sockaddr_in *sa;
    getifaddrs(&ifap);
    for (ifa = ifap; ifa; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr->sa_family==AF_INET) {
            sa = (struct sockaddr_in *) ifa->ifa_addr;
            addr = inet_ntoa(sa->sin_addr);
            if(strcmp(ifa->ifa_name,"eth0") == 0)
                strcpy(myIp, addr);
        }
    }
    freeifaddrs(ifap);

}


void CommunicationModule::sendMessage(int socket, string message){
    int len = message.length();
    int sentbytes = write(socket, message.c_str(), len);
    cout<<message<<":sent"<<sentbytes<<endl;
}

/**
blocking Read call
*/
void CommunicationModule::readMessage(int clisocket, string &message){
    char rawMessage[100];
    int n = 0;
    //do {
        n = read(clisocket, rawMessage,100);
    //} while(n > 0);
    rawMessage[n] = '\0';
    message = string(rawMessage);
}

void CommunicationModule::sendMessage(ControlMessage m){
    map<string,string> messageContents;
    messageContents["from"] = m.from;
    messageContents["to"] = m.to;
    messageContents["messageType"] = "controlMessage";
    messageContents["controlText"]= m.controlText;
    json11::Json a(messageContents);
    string msgString = a.dump().c_str();
    sendMessage(m.toSocket,msgString);
}

void CommunicationModule::sendMessage(GameMessage m){
    map<string,string> messageContents;
    messageContents["from"] = m.from;
    messageContents["to"] = m.to;
    messageContents["messageType"] = "gameMessage";
    if(m.gameMessageType == GameMessage::ACTION){
        messageContents["gameMessageType"] = "action";
        switch(m.action){
            case GameMessage::HIT:
                messageContents["actionType"] = "Hit";
            break;

            case GameMessage::STAND:
                messageContents["actionType"] = "Stand";
            break;

        }
    }
    else if(m.gameMessageType == GameMessage::CARD){
        messageContents["gameMessageType"] = "card";
        switch(m.action){
            case GameMessage::NONE:
                messageContents["actionType"] = "None";
            break;

        }
        messageContents["suit"] = m.getCard().getCardSuit();
        messageContents["rank"] = m.getCard().getCardRank();
        std::stringstream ss;
        ss << m.getCard().getCardValue();
        messageContents["value"] = ss.str();

    }
    string messageString = json11::Json(messageContents).dump();
    sendMessage(m.toSocket,messageString);
}

CommunicationModule::~CommunicationModule()
{
    //dtor
}
