#include <at89x51.h>

#define False 0
#define True 1

void lcd_cmnd(unsigned char);
void lcd_putc(unsigned char);
void lcd_init(void);
void lcd_puts(unsigned char *);
void lcd_ready(void);
void lcd_putcursor(unsigned char, unsigned char);
void ser_init(void);
void ser_hand(void) interrupt 4;
void ser_putc(unsigned char);
void ser_puts(unsigned char *);


static char n;
static char x=16,y=2;
static char mtrx [16][2];


void main(void)
{
	char *txt1="Voila!";
	char *txt2="Please enter something: ";
	int i;

	lcd_init();
	ser_init();
	lcd_putcursor(3,1);
	lcd_puts(txt1);
	ser_puts(txt2);

while (True){
		P2_5=True;
		for (i=0;i<700000;i++);
		P2_5=False;
		for (i=0;i<700000;i++);
	}

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

/*********** serial communication ******************/

void ser_init(void)
{
	TMOD=0x20;		/* timer 1 mode 2 (auto reload) */
	TH1=-3;			/* 9600 Baud rate*/
	SCON=0x50;		/* 8-bit, 1 stop, receive enabled */
	IE=0x90;		/* Enable serial Interrupt*/
	TR1=True;		/* start timer 1 */
}


void ser_hand (void) interrupt 4
{
	//int i;
	char n;

	if (TI){
		TI=False;
	}
	if (RI){
		n=SBUF;
		RI=False;
		//for (i=0;i<200;i++);
		ser_putc(n);
		lcd_putc(n);
	}
}

void ser_putc(unsigned char c)
{
	SBUF=c;
	while(TI);
	TI=False;
}

void ser_puts (unsigned char *s)
{
   unsigned char c;
   while (c=*s++) {
	   if (c == '\n') ser_putc ('\r');
	   ser_putc (c);
   }
}
