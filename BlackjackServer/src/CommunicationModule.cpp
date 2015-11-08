#include "CommunicationModule.h"
#include<iostream>
CommunicationModule::CommunicationModule()
{
    getOwnIp();

}
/**
***************************Blocking Server Start Call***************************************
*******************Needs to be called from seperate thread for this*************************
***********************Loop also need to be Managed by caller*******************************

**/
void CommunicationModule::startServer(int &retSocket, string &clientIp, int &clientPort){

    sockaddr_in localhost, client;
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
    bzero(&client, sizeof(client));
    int clilen = sizeof(sockaddr_in);
    cout<<"Listening on 1234"<<endl;
    listen(servSocket, 5);
    int clisocket = accept(servSocket, (sockaddr*)&client, (socklen_t*)&clilen);
    retSocket = clisocket;
    clientIp = inet_ntoa(client.sin_addr);
    clientPort = ntohs(client.sin_port);

}

void CommunicationModule::startServer(int port, int &retSocket, string &clientIp, int &clientPort){

    sockaddr_in localhost, client;
    servSocket = socket(AF_INET,SOCK_STREAM ,0);
    bzero(&localhost,sizeof(sockaddr_in));
    localhost.sin_family = AF_INET;
    inet_aton(myIp, &(localhost.sin_addr));
    localhost.sin_port = htons(port);
    int b = bind(servSocket,(sockaddr*)&localhost,sizeof(sockaddr_in));
    if(b<0){
        exit(1);
    }
    bzero(&client, sizeof(client));
    int clilen = sizeof(sockaddr_in);
    cout<<"Listening on 1234";
    listen(servSocket, 5);
    int clisocket = accept(servSocket, (sockaddr*)&client, (socklen_t*)&clilen);
    retSocket = clisocket;
    clientIp = inet_ntoa(client.sin_addr);
    clientPort = ntohs(client.sin_port);

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
    int n = read(clisocket, rawMessage,100);
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
        messageContents["gameMessageType"] = "Action";
        switch(m.action){
            case GameMessage::REQUEST_BET:
                messageContents["actionType"] = "Requesting Bets";
            break;

            case GameMessage::REQUEST_DECISION:
                messageContents["actionType"] = "Requesting Decision";
            break;



        }
    }
    else if(m.gameMessageType == GameMessage::CARD){
        messageContents["gameMessageType"] = "card";
        messageContents["suit"] = "cardsuit";
        messageContents["rank"] = "cardrank";

    }
    string messageString = json11::Json(messageContents).dump();
    sendMessage(m.toSocket,messageString);
}

CommunicationModule::~CommunicationModule()
{
    //dtor
}
