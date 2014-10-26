#include "transmitter.h"
#include "interface.h"

transmitter::transmitter(interface *iface)
{
    this->iface=iface;
    iface->sendData(2,"This is reality!");
}
