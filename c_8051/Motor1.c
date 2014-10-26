#include <at89x51.h>
#define True 1
#define False 0

main()
{
	int i;
	TMOD=0x20;		/* timer 1 mode 2 (auto reload) */
	TH1=-3;			/* 9600 Baud rate*/
	SCON=0x50;		/* 8-bit, 1 stop, receive enabled */
	IE=0x91;		/* Enable serial and external 0 Interrupt*/
	IT0=True;		/*External interrupt 0 set to edge-triggered.*/
	TR1=True;		/* start timer 1 */

	SBUF='L';while(TI);TI=False;
	SBUF='/';while(TI);TI=False;
	SBUF='R';while(TI);TI=False;
	SBUF='?';while(TI);TI=False;
	P1_1=True;

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
	int count=100;
	int i;

	if (TI){
		TI=False;
	}
	if (RI){
		n=SBUF;
		RI=False;
		if (n=='L'){P1_2=1;P1_3=0;}
		if (n=='R'){P1_2=0;P1_3=1;}

		if (n=='S'){
			while(count!=0){
				P1_2=0;P1_3=1;
				for (i=0; i<count; i++);
				count--;
				P1_2=1;P1_3=0;
				for (i=0; i<count; i++);
				count--;
			}
			P1_2=0;P1_3=0;
		}

	}
}

void ext_hand (void) interrupt 0
{
	int i;
	P1_2=1;P1_3=0;
	for (i=0; i<200000; i++);
	P1_2=0;P1_3=0;
}

