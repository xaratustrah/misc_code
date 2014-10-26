#ifndef TRANSMITTER_H
#define TRANSMITTER_H

#include "interface.h"

class transmitter// : public interface
{
public:
    transmitter(interface* iface);
    interface *iface;
};

#endif // TRANSMITTER_H
