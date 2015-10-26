#include "ControlMessage.h"

ControlMessage::ControlMessage(string text)
{
    messageType = CONTROL_MESSAGE;
    controlText = text;
    //ctor
}

ControlMessage::~ControlMessage()
{
    //dtor
}
