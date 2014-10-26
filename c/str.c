#include <stdio.h>
#include <stdlib.h>

int main()
{
     char* ch = "0.123";
     double d = 1;

     d =  strtod(ch, NULL);

     printf("%f\n", d);

     return (0);
}
