#ifndef CASINO_H
#define CASINO_H
#include<vector>
#include "CommunicationModule.h"
using namespace std;
class Casino
{
    public:
        Casino();
        virtual ~Casino();
    protected:
    private:
        vector<int> currentTables;
        CommunicationModule comm;
};

#endif // CASINO_H
