#include <8051.h>
#define False 0
#define True 1

main()
{
	int i;
	unsigned char *n="H";
	TMOD=0x20;		/* timer 1 mode 2 (auto reload) */
	TH1=-3;			/* 9600 Baud rate*/
	SCON=0x50;		/* 8-bit, 1 stop, receive enabled */
	IE=0x90;		/* Enable serial Interrupt*/
	TR1=True;		/* start timer 1 */
	while (True){
		P1_0=True;
		/* SBUF='5';while(TI);TI=False;*/
		ser_putc(n);
		for (i=0;i<700000;i++);
		P1_0=False;
		for (i=0;i<700000;i++);
	}
}

void ser_putc (unsigned char c)
{
	SBUF=c;
	while(TI);
	TI=False;
}

unsigned char ser_getc (void)
{
	 unsigned char c;

	 while(RI);
	 c=SBUF;
	 RI=False;
	 return(c);
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
		for (i=0;i<200;i++);
		SBUF=n;
		TI=False;
	}
}


