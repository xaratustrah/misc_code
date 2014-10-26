/************************ MIDI tester ***********************************/

#include <at89x51.h>
#define False 0
#define True 1

void init_midi (void) 
{
     TCON &= 0x33;	// stop timer 1, TCON  = 00XX00XX
     TMOD &= 0x0F;	// clear the upper nibble of TMOD
     TMOD |= 0x20;	// set timer 1 in mode 2 auto reload with GATE = 0 for internal enable using TR1
     SCON = 0x50;	// serial mode 1, 8-data bits, 1 stop and 1 start bit.
     PCON |= 0x80;	// Enable SMOD in PCON to double baud rate.
     TH1 = 0xFE;	/* 31250 Baud rate for 12 MHz Xtal*/
     IE |= 0x90;	/* enable serial interrupt */
     TR1=True;		/* start timer 1 for serial communicaiton */
}
void HW_delay(unsigned char t)
{
     unsigned int i;
     if (t==0) return;
     while(t--)for (i=0;i<774;i++);
     return;
}

void toggle_LED (void)
{
     P1_0 = ~P1_0;
}
void ser_putc (unsigned char c)
{
        SBUF=c;
        while(TI);
        TI=False;
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
     }

}

void main()
{
//     float i;
     init_midi();
     HW_delay(1);

     for(;;){
	  toggle_LED();
	  ser_putc(0x90);
	  HW_delay(1);
	  ser_putc(0x45);
	  HW_delay(1);
	  ser_putc(0x45);
	  HW_delay(100);
	  ser_putc(0x80);
	  HW_delay(1);
	  ser_putc(0x45);
	  HW_delay(1);
	  ser_putc(0x45);
	  HW_delay(100);

     }
}
