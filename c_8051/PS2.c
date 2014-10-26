#include <at89x51.h>

#define True 1
#define False 0
#define CLK P2_0
#define DAT P2_1

void lcd_init(void);
void lcd_putcursor(unsigned char , unsigned char );
void lcd_cmnd (unsigned char);
void lcd_putc(unsigned char);
void lcd_puts (unsigned char*);
void lcd_ready(void);
void ps2_cmnd (void);


static char n;
static char x=16,y=2;
static char mtrx [16][2];



main()
{
	int i;
	char *txt="AllP?!";
	//lcd_init();
	lcd_cmnd(0x38); /*LCD 2 lines, 5X7 matrix */
	lcd_cmnd(0x0F); /* diplay on, cursor on, blink */
	lcd_cmnd(0x01); /* clear screen */
	lcd_cmnd(0x06); /*shift cursor right */
	lcd_cmnd(0x84);


	ps2_cmnd();
	lcd_puts(txt);
	for(;;){
		P2_5=True;
		for (i=0; i<5000; i++);
		P2_5=False;
		for (i=0; i<5000; i++);
	}
}

/* ********** PS2 related funktions *********/

void ps2_cmnd (void)
{
	int i;
	// send EDH 11101101B to indicate the set LED command then send 00000001 to turn the Scrolllock on.

	CLK= False;
	for (i=0; i<30000; i++);
	DAT=False;
	for (i=0; i<30000; i++);
	CLK=True;
	while(!CLK);

	DAT=True;
		while(CLK);
		while(!CLK);
	DAT=False;
		while(CLK);
		while(!CLK);
	DAT=True;
		while(CLK);
		while(!CLK);
	DAT=True;
		while(CLK);
		while(!CLK);
	DAT=False;
		while(CLK);
		while(!CLK);
	DAT=True;
		while(CLK);
		while(!CLK);
	DAT=True;
		while(CLK);
		while(!CLK);
	DAT=True;
		while(CLK);
		while(!CLK);

	DAT=True;
	while(!CLK);
	while(CLK && DAT);


	CLK= False;
		for (i=0; i<30000; i++);
		DAT=False;
		for (i=0; i<30000; i++);
		CLK=True;
		while(!CLK);

		DAT=True;
			while(CLK);
			while(!CLK);
		DAT=False;
			while(CLK);
			while(!CLK);
		DAT=False;
			while(CLK);
			while(!CLK);
		DAT=False;
			while(CLK);
			while(!CLK);
		DAT=False;
			while(CLK);
			while(!CLK);
		DAT=False;
			while(CLK);
			while(!CLK);
		DAT=False;
			while(CLK);
			while(!CLK);
		DAT=False;
			while(CLK);
			while(!CLK);

		DAT=True;
		while(!CLK);
	while(CLK && DAT);
}

/****************** LCD Functions *****************/


void lcd_init(void)
{
	int i,j,k;
	lcd_cmnd(0x38); /*LCD 2 lines, 5X7 matrix */
	lcd_cmnd(0x0F); /* diplay on, cursor on, blink */
	lcd_cmnd(0x01); /* clear screen */
	lcd_cmnd(0x06); /*shift cursor right */

	k=0;

	for (j=0;j<x;i++)
	{
		for (i=0;i<y;j++)
		{
			mtrx[i][j]=128+k+i;
		}
		k+=64;
	}
}

void lcd_putcursor(unsigned char XPOS, unsigned char YPOS)
{
	if (XPOS<=x && YPOS <=y) lcd_cmnd(mtrx[XPOS][YPOS]);
}

void lcd_cmnd (unsigned char n)
{
	P1=n;
	P2_2=False;
	P2_3=False;
	P2_4=True;
	P2_4=False;
	lcd_ready();
}

void lcd_putc(unsigned char n)
{
	P1=n;
	P2_2=True;
	P2_3=False;
	P2_4=True;
	P2_4=False;
	lcd_ready();
}

void lcd_puts (unsigned char *s)
{
   unsigned char c;
   while (c=*s++) {
	   if (c == '\n') lcd_putc ('\r');
	   lcd_putc (c);
   }
}

void lcd_ready(void)
{
	int i;
	for (i=0;i<800;i++);
	//P1_7=True;
	//P2_2=False;
	//P2_3=True;
	//while(!P1_7)
	//{
	//	P2_4=True;
	//	P2_4=False;
	//}
}

