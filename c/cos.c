
#include <math.h>
#include <stdio.h>

int main(void)
{
  const float degtorad = M_PI/180;  // convert degrees
                                    // to radians
  float x_in_radians, result;
  int degree = 60;      // initialise degrees to zero
  x_in_radians = degree  * degtorad;
//  result = sin(x_in_radians * 3) + 3 * (cos (x_in_radians));
  result = log10(tan(x_in_radians) * 1423);
  printf ("%d\n",(int) result);
  return 0;
}
