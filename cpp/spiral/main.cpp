#include <iostream>
using namespace std;

#include "Spiral.h"
#include "Dot.h"
#include "Coordinates.h"

int main(void)
{
     Spiral mySpiral(15);
     Coordinates * myCo = new Coordinates(5,6);
     Dot *myDot = new Dot(12, myCo);
     cout << "Hello World\n" ;
     return 0;
}
