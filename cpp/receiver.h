#ifndef RECEIVER_H
#define RECEIVER_H

#include "interface.h"
#include "transmitter.h"

class receiver : public interface
{
public:
    receiver();
    ~receiver();
    transmitter * tx;
    virtual void sendData(int , const char* );

private:
    void tuwas();
};

#endif // RECEIVER_H
