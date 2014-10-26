
#ifndef __COORDINATES_H__
#define __COORDINATES_H__

class Coordinates {

private:

     int x_value, y_value;

public:

     Coordinates();
     Coordinates (int x_value, int y_value);
     ~Coordinates ();
     void setXValue(int x_value);
     void setYValue(int y_value);
     int getXValue(void);
     int getYValue(void);

};

#endif
