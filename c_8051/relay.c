
#include <at89x51.h>

#define False 0
#define True 1

void _delay(unsigned char t)
{
     unsigned int i;
     if (t==0) return;
     while(t--)for (i=0;i<774;i++);
     return;
     
}

/************************ main ***********************************/

void main (void)
{
     TMOD=0x20;		/* timer 1 mode 2 (auto reload) */
     TH1=-3;			/* 9600 Baud rate for 11.0592 Xtal*/
     SCON=0x50;		/* 8-bit, 1 stop, receive enabled */
     IE = 0x90;		/* enable serial interrupt */
     TR1=True;		/* start timer 1 for serial communicaiton */


     _delay(300);

     _delay(5);

     SBUF='?';while(TI);TI=False;

     for (;;){
	  _delay(5);
     }
     
}

void ser_hand (void) interrupt 4
{
     char n;

     if (TI){
	  TI=False;
     }
     if (RI){
	  n=SBUF;
	  RI=False;

	  /* LED on */

	  if (n == 'Q'|| n == 'q') P1_0 = ~P1_0;
	  _delay(5);
	  
     }

}
