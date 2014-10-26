#include <at89x51.h>

#define False 0
#define True 1
typedef unsigned char BYTE;

void toggle_LED (void)
{
     P1_0 = ~P1_0;
}


void HW_delay(unsigned char t)
{
     unsigned int i;
     if (t==0) return;
     while(t--)for (i=0;i<774;i++);
     return;
}


int main(){
     BYTE xdata * p = 0x00 ;
     int i;
     P1_0 = True;
     for(i = 0; i<0x1FFF; i++){
	  *p = 0xFF;
	  HW_delay(2);
	  if (*p != 0xFF){
	       toggle_LED();
	       return 0;
	  }
	  p++;
     }
     return 0;
}
