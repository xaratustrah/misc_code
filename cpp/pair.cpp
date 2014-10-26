#include <utility>
#include <iostream>
#include <math.h>

std::pair<double, double> cart2pol(double real, double imag)
{
     std::pair<double, double> result;
     result = std::make_pair(sqrt(pow(real, 2)+pow(imag, 2)), atan(imag/real));
     return result;
}

int main()
{
     std::cout << "Mag: " << cart2pol(1, 1).first << std::endl << "Phase: " <<  cart2pol(1, 1).second << std::endl;
}
