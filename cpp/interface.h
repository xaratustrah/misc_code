#ifndef INTERFACE_H
#define INTERFACE_H

class interface
{
public:
    interface();
    virtual void sendData(int, const char*)=0;
};

#endif // INTERFACE_H
