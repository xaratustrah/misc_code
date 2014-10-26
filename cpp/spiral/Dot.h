
#include "Coordinates.h"

#ifndef __DOT_H__
#define __DOT_H__

class Dot {

private:

     Coordinates * xyCoordinates;
     int traceWidth;

public:

     Dot();
     Dot (int traceWidth, Coordinates * xyCoordinates);
     ~Dot ();
     void setTraceWidth(int width);
     void setCoordinates(Coordinates * xyCoordinates);
     int getTraceWidth(void);
     Coordinates * getCoordinates(void);
};


#endif
