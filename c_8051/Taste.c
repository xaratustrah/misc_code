#include <8051.h>
#define False 0
#define True 1

main()
{
	int i;
	bit n;
	//P1=0x00;
	TMOD=0x20;		/* timer 1 mode 2 (auto reload) */
	TH1=-3;			/* 9600 Baud rate*/
	SCON=0x50;		/* 8-bit, 1 stop, receive enabled */
	TR1=True;		/* start timer 1 */

	i=0;

	P1_1=P1_5=P1_7=True;	/*Make input */
	do
	P1_2=P1_3=P1_4=P1_6=False;
	while(!P1_1|!P1_5|!P1_7);
	for (i=0;i<200;i++);

	P1_3=True;

	while(True){
		n=P1_7;
		for (i=0;i<2000;i++);
		if (n) {SBUF='5';while(TI);TI=False;}
		for (i=0;i<2000;i++);

		}
}
