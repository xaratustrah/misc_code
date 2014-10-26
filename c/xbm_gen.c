
/* XBM Generator! */

#include <stdio.h>

int main(){
     int i=1, width = 10000, height = 10000;
     printf("#define test_width %d\n", width);
     printf("#define test_height %d\n", height);
     printf("static unsigned char test_bits[] = {\n");

/*     for (j=1 ; j<width ; j++){
	  for (i=k; i<=8*k ; i*=2){
	       printf("0x%d,\n",i);
	  }	  
	  k=k*10;
     }
*/
     for (i=1; i<width-1; i*=10){
	  printf("0x%d,",i*10);
	  printf("0x%d,",i*20);
	  printf("0x%d,",i*40);
	  printf("0x%d,",i*80);
     }

     printf("0x%d",i);
     printf("};\n");
     return 0;
}
