
#include "Dot.h"
#include "Coordinates.h"

Dot::Dot() {}

Dot::Dot(int traceWidth,  Coordinates * xyCoordinates)
{
     this->traceWidth = traceWidth;
     this->xyCoordinates = xyCoordinates;
}

Dot::~Dot(){}

void Dot::setTraceWidth(int traceWidth)
{
     this->traceWidth = traceWidth;
}

void Dot::setCoordinates(Coordinates * xyCoordinates)
{
     this-> xyCoordinates =  xyCoordinates;
}

int Dot::getTraceWidth(void)
{
     return this -> traceWidth;
}

Coordinates * Dot::getCoordinates(void)
{
     return this -> xyCoordinates;
}

