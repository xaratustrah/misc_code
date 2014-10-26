
/* A program to calculate the e number */

/* compile with: */
/* $ gcc -Wall -g3 -lm -o e e.c */

/* 15.JUN.2006/sh */

#include <stdio.h>
#include <math.h>

int main (void)
{

//     int K = 10;
     double n = 1, z;
     fprintf(stdout, "pi = %.10f\n", 4 * atan(1.0));
     while(1)
//     for ( n = 1; n <= K ; n++)
     {
	  z = pow ((1+(1/n)) , n );
	  fprintf(stdout, "e = %.500f\n", z );
	  n++;
     } 
     return 0;
}
