
#ifndef __SPIRAL_H__
#define __SPIRAL_H__

//#include <math.h>

class Spiral {

private:

//     const float degToRad = M_PI/180;
     int startRadius;

public:

     Spiral();
     Spiral (int startRadius);
     ~Spiral ();
     int getStartRadius(void);
     void setStartRadius(int radius);

};


#endif
