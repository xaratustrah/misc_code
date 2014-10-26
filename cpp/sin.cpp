// IEA 1996
// Example program - Section 16.3
// Tabulates sine function for x = 0(5)90

#include <iostream.h>
#include <iomanip.h>
#include <math.h>      // because we are going to use
                       // a mathematical function

int main()
{
  const float degtorad = M_PI/180;  // convert degrees
                                    // to radians
  int degree = 0;      // initialise degrees to zero

   // Set output to fixed with decimal point shown and
   // six places printed after the decimal point

  cout << setiosflags(ios::fixed | ios::showpoint)
       << setprecision(6); 

  float radian;        // radian equivalent of degree
      // Output headings
  cout << endl << "degrees" << "   sin(degrees)"
       << endl;
      // Now loop
  while (degree <= 90)
    {
      radian = degree * degtorad;  // convert degrees to
                                   // radians
      cout << endl << setw(5) << degree 
           << setw(15) << sin(radian);
      degree = degree + 5;  // increment degrees
    }
  cout << endl;
  return 0;
}

