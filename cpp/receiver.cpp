#include "receiver.h"
#include <iostream>
using namespace std;

receiver::receiver()
{
    tx = new transmitter(this);
}
void receiver::sendData(int msgtype, const char* msg )
{
        switch(msgtype)
        {
            case 0:
              cout << msg;
                    break;
            case 1:
              cout << msg;
                    break;
        }
        this->tuwas();
    }
receiver::~receiver()
{
    delete tx;
}
void receiver::tuwas()
{
    cout << "bin schon dabei..." << endl;
}
