#ifndef CASINO_H
#define CASINO_H
#include<vector>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<ctype.h>
#include<thread>
#include<string.h>
#include<string>
#include "CommunicationModule.h"
#include "Dealer.h"
#include "Player.h"
using namespace std;
class Casino
{
    public:
        Casino();
        virtual ~Casino();

        void startDealer(Player p);
        void readMgt();
        void startDealing();
        void read();

    protected:
    private:
        Dealer dealer;
        vector<int> currentTables;
        CommunicationModule comm;
};

#endif // CASINO_H
