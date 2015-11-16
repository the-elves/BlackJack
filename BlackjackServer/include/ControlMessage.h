#ifndef CONTROLMESSAGE_H
#define CONTROLMESSAGE_H

#include <Message.h>

#include<string>
using namespace std;
class ControlMessage : public Message
{
    public:
        string controlText;
        ControlMessage(int, string, string, string);
        virtual ~ControlMessage();
    protected:
    private:
};

#endif // CONTROLMESSAGE_H
