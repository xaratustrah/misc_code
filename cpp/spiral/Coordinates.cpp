
#include "Coordinates.h"

//Coordinates::Coordinates() {}

Coordinates::Coordinates(int x_value,  int y_value)
{
     this->x_value = x_value;
     this->y_value = y_value;
}

//Coordinates::~Coordinates(){}

void Coordinates::setXValue(int x_value)
{
     this->x_value = x_value;
}

void Coordinates::setYValue(int y_value)
{
     this->y_value = y_value;
}

int Coordinates::getXValue(void)
{
     return this -> x_value;
}

int Coordinates::getYValue(void)
{
     return this -> y_value;
}
