
/* This routine generates a sine lookup table for use with programmable logic */
/* and DDS algorithm. */
/* compile with: */
/* gcc -lm -Wall -g3 -o sine_table sine_table.c */
//
/* xaratustrah, 08.10.2006 */
//
/* n is the resolution of the DAC */
/* each phase increment is (i * (2*pi) / pow (2,n)) */
/* the sine value of that, should be divided into 1/(2^(n-1)) */
/* n-1 because sine value go plus and minus. */
/* for streight binary, offset could be set. */

#include<stdio.h>
#include<math.h>

int  main(void)
{


     int n = 14;
     double pi = 3.14159;
     int i, val, j = 0;

     for(i = 0; i < (pow(2,n)); i++)
     {


	  val = (int) pow(2,n) / 2 + (int) floor( pow (2, (n-1)) * sin (i * (2*pi) / pow (2,n)));

//	  printf("%d-> 0x%X,", i , val);

	  printf("0x%X,", val);

//	  printf("x\"%X\",", val);

	  if(j == 10) {
	       printf("\n");
	       j = 0;
	  }
	  else j++;
     }
     return 0;
}
