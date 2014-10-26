
#include "Spiral.h"

Spiral::Spiral() {}

Spiral::Spiral(int startRadius)
{
     this->startRadius = startRadius;
}

Spiral::~Spiral(){}

void Spiral::setStartRadius(int startRadius)
{
     this->startRadius = startRadius;
}

int Spiral::getStartRadius(void)
{
     return this->startRadius;
}
