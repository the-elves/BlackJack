#ifndef COMMUNICATIONMODULE_H
#define COMMUNICATIONMODULE_H
#include<sys/socket.h>
#include<netinet/in.h>
#include<iostream>
#include<arpa/inet.h>
#include<ctype.h>
#include<ifaddrs.h>
#include<string>
#include<unistd.h>
#include<strings.h>
#include<stdlib.h>
#include<string.h>
#include<json11.hpp>
#include<map>
#include"GameMessage.h"
#include"ControlMessage.h"
using namespace std;
class CommunicationModule
{
    public:
        CommunicationModule();

        void acceptConnection(int &socket, string &cilentIp, int &clientPort, string &name);

        void sendMessage(int socket, string message);
        void readMessage(int clisock, string &message);

        void sendMessage(GameMessage);
        void sendMessage(ControlMessage);

        virtual ~CommunicationModule();

        int maxfd = 0;

    protected:
    private:
        char myIp[12];
        int servSocket;
        void getOwnIp();

};

#endif // COMMUNICATIONMODULE_H
