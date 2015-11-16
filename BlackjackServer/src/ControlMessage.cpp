#include "ControlMessage.h"

ControlMessage::ControlMessage(int sock, string from, string to, string text)
{
    this->toSocket = sock;
    this->from = from;
    this->to = to;
    messageType = CONTROL_MESSAGE;
    this->controlText = text;
    //ctor
}

ControlMessage::~ControlMessage()
{
    //dtor
}
