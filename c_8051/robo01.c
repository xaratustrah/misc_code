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

	P1_3=True; /*enabel top motor */
	P1_5=True; /* enable side motor */

	for(;;){
		P1_0=1;
		for (i=0; i<300000; i++);
		P1_0=0;
		for (i=0; i<300000; i++);
	}

	/********* test routine for the self controll*/

	/* side motor alone */

	P1_6=1;P1_7=0; /* left */
	for (i=0; i<20000000; i++);
	P1_6=0;P1_7=1; /* right */
	for (i=0; i<20000000; i++);
	P1_6=0;P1_7=0; /* stop */

	/* top motor alone */

	P1_2=1;P1_1=0; /* Left */
	for (i=0; i<20000000; i++);
	P1_2=0;P1_1=1; /* right */
	for (i=0; i<20000000; i++);
	P1_2=0;P1_1=0; /*stop*/


	P1_6=0;P1_7=1;P1_2=0;P1_1=1;/* side right, top right */
	for (i=0; i<20000000; i++);
	P1_6=0;P1_7=1;P1_2=1;P1_1=0;/* side right, top left */
	for (i=0; i<20000000; i++);
	P1_6=1;P1_7=0;P1_2=0;P1_1=1;/* side left, top right */
	for (i=0; i<20000000; i++);
	P1_6=1;P1_7=0;P1_2=1;P1_1=0; /* side left, top left */
	for (i=0; i<20000000; i++);
	P1_6=0;P1_7=0;P1_2=0;P1_1=0; /*stop all*/


	P1_4=False;		/* peeeeeeebs! */
	for (i=0; i<50000; i++);
	P1_4=True;
	*/
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

		/* Sound controller */

		if (n=='Q'|| n=='q')P1_4=False; /* start buzzer (active low) */
		if (n=='E'|| n=='e')P1_4=True;
		if (n=='W'|| n=='w')
		{
					P1_4=False;
					for (i=0; i<100000; i++);
					P1_4=True;
		}

		/*TOP motor */

		if (n=='D'|| n=='d'){P1_2=1;P1_1=0;}
		if (n=='A'|| n=='a'){P1_2=0;P1_1=1;}
		if (n=='S'|| n=='s'){
			while(count!=0){
				P1_2=0;P1_1=1;
				for (i=0; i<count; i++);
				count--;
				P1_2=1;P1_1=0;
				for (i=0; i<count; i++);
				count--;
			}
			P1_2=0;P1_1=0;
		}

		/* Side motor */

		if (n=='J'|| n=='j'){P1_6=1;P1_7=0;}
		if (n=='L'|| n=='l'){P1_6=0;P1_7=1;}
		if (n=='K'|| n=='k'){
			while(count!=0){
				P1_6=0;P1_7=1;
				for (i=0; i<count; i++);
				count--;
				P1_6=1;P1_7=0;
				for (i=0; i<count; i++);
				count--;
			}
			P1_6=0;P1_7=0;
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

