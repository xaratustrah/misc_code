#include <8051.h>
#define False 0
#define True 1

main()
{
	int i;
	TMOD=0x20;		/* timer 1 mode 2 (auto reload) */
	TH1=-3;			/* 9600 Baud rate*/
	SCON=0x50;		/* 8-bit, 1 stop, receive enabled */
	IE=0x90;		/* Enable serial Interrupt*/
	TR1=True;		/* start timer 1 */

	P3_5=True;			/*strobe neg.*/
	P3_6=P3_7=False;	/*Make input*/

	while (True){
		P1_0=True;
		SBUF='5';while(TI);TI=False;
		for (i=0;i<700000;i++);
		P1_0=False;
		for (i=0;i<700000;i++);
	}
}


void ser_hand (void) interrupt 4
{
	int i;
	char n;

	if (TI){
		TI=False;
	}
	if (RI){
		n=SBUF;
		RI=False;
		for (i=0;i<200;i++);
		SBUF=n;
		TI=False;
		P2=n;
		P3_5=False;
		while(P3_6);
		P3_5=True;
	}
}
