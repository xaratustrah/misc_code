#include <at89x51.h>
#define True 1
#define False 0

main()
{
	int i;
	TMOD=0x20;		/* timer 1 mode 2 (auto reload) */
	TH1=-3;			/* 9600 Baud rate for 11.0592 Xtal*/
	SCON=0x50;		/* 8-bit, 1 stop, receive enabled */
	IE=0x90;		/* Enable serial Interrupt*/
	//IT0=True;		/*External interrupt 0 set to edge-triggered.*/
	TR1=True;		/* start timer 1 for serial communicaiton */

	for (i=0; i<300000; i++); /* give the processor some time*/
	SBUF='?';while(TI);TI=False;

	for(;;){
		P1_0=1;
		for (i=0; i<300000; i++);
		P1_0=0;
		for (i=0; i<300000; i++);
	}

}

void ser_hand (void) interrupt 4
{
	char n;
	int count=200;
	int i;

	if (TI){
		TI=False;
	}
	if (RI){
		n=SBUF;
		RI=False;

		/* LED on */

		if (n=='Q'|| n=='q') P2_5 = ~P2_5;

		}

	}
}

void ext_hand (void) interrupt 0
{
	int i;
	P1_2=1;P1_1=0;
	for (i=0; i<200000; i++);
	P1_2=0;P1_1=0;
}


