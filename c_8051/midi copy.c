/*
**************** MIDI.C ***************
*/


#include <at89x51.h>
#include "LCD.H"

#define False 0
#define True 1

#define RBUFFSIZE 20

unsigned char RBUF[RBUFFSIZE];

unsigned char *Rhead = RBUF;
unsigned char *Rtail = RBUF;

unsigned char ext1_flag = 0x01;		// active-low external flag

enum MAIN_STATES { SERIAL, LED , EXT1};
enum MAIN_STATES CURR_TIME_SLICE = SERIAL;

enum ALL_STATES { START, GOT_Q, GOT_W };
enum ALL_STATES CURR_STATE = START;

void init_serial ( void );
void init_midi ( void );
void init_ext1 ( void );
void toggle_LED (void);
void ser_putc( unsigned char );
void ser_puts( unsigned char *);
unsigned char ser_getc (void);
void msg_parser(unsigned char);

// timer definitions

void main_FSM(void);
unsigned int Timer10mSec = 0;	// general timer 10mSec.
unsigned int cnt = 50;

void init_timer0(void);
void timer0_interrupt_handler(void) interrupt 1;
void HW_delay(unsigned char t);
void wait1Sec(void);
void wait500mSec(void);


//lcd definitions
void init_lcd (void);
void lcd_cmnd (unsigned char);
void lcd_putc (unsigned char );
void lcd_puts (unsigned char *);

/***************** ********** MAIN ************* ****************/

void main ( void )
{
     char tmp;    
     HW_delay(2);
     init_timer0();
     HW_delay(2);
     init_serial();
     HW_delay(300);
     tmp = InitLcd();
     ser_puts("Ola!");

     Putch('>');
     for (;;){			// main loop.
	  HW_delay(1);
     }
     
}


/****************** start of timer functions ***************/

void init_timer0(void)
{
     TCON &= 0xCC;		// stop timer 0, TCON  = XX00XX00
     TMOD &= 0xf0;		// reset the lower 4 bits of the TMOD
     TMOD |= 0x01;		// Timer 0 mode 1 ( 16 bit timer )
     TH0 = 0xDC;		// Timer 0, reload to 10 ms for 11.0592MHz Xtal.
     TL0 = 0x00;		// Timer 0, reload to 10 ms.
     IE |= 0x82;		// enable timer 0 overflow interrupt			
     TR0 = 1;			// start timer 0
}

void timer0_interrupt_handler(void) interrupt 1
{
     TH0 = 0xDC;		// Timer 0, reload to 10 ms 11.0592MHz Xtal.
     TL0 = 0x00;
     TR0 = 1;			// start timer 0 again
     if (Timer10mSec) Timer10mSec--;
     main_FSM();
}

void main_FSM(void)		// hier kommt noch den Haupt Zustandautomat jede 10mSec wird er aufgerufen.
{
     unsigned char n;
     switch (CURR_TIME_SLICE)
     {
	  case SERIAL:
	       n = ser_getc();
	       if(n != 0) msg_parser(n);
	       CURR_TIME_SLICE = LED;
	       break;

	  case LED:

	       if(--cnt <= 0){
		    toggle_LED();		
		    cnt = 200;			// on/off delay of the LED.
	       }
	       CURR_TIME_SLICE = EXT1;
	       break;

	  case EXT1:
	       if(ext1_flag == 0x00)
	       {
		    toggle_LED();
		    ext1_flag = 0x01;
	       }
	       CURR_TIME_SLICE = SERIAL;
	       break;

	  default :
	       CURR_TIME_SLICE = SERIAL;
	       break;
     }
}

void HW_delay(unsigned char t)
{
     unsigned int i;
     if (t==0) return;
     while(t--)for (i=0;i<774;i++);
     return;
}

void wait500mSec(void)
{
     Timer10mSec = 50;
     HW_delay(1);		// give sometime to let the MCU catch up with the commands
     while(Timer10mSec);
}
void wait1Sec(void)
{
     Timer10mSec = 100;
     HW_delay(1);		// give sometime to let the MCU catch up with the commands
     while(Timer10mSec);
}

/*********************** MISC methods **************************/

void toggle_LED (void)
{
     P1_0 = ~P1_0;
}


/*********************** Serial methods **************************/

void init_serial (void) 
{

     TCON &= 0x33;	// stop timer 1, TCON  = 00XX00XX
     TMOD &= 0x0F;	// clear the upper nibble of TMOD
     TMOD |= 0x20;	// set timer 1 in mode 2 auto reload with GATE = 0 for internal enable using TR1
     SCON = 0x50;	// serial mode 1, 8-data bits, 1 stop and 1 start bit.
     PCON |= 0x80;	// Enable SMOD in PCON to double baud rate.
     TH1 = -3;		/* 19200 Baud rate for 11.0592 Xtal*/
     IE |= 0x90;	/* enable serial interrupt */
     TR1 = True;		/* start timer 1 for serial communicaiton */
}

void msg_parser(unsigned char n)
{
     switch (CURR_STATE)
     {
	  case START:
	       if (n == 'Q'|| n == 'q')
		    CURR_STATE = GOT_Q;
	       else CURR_STATE = START;	       
	       break;

	  case GOT_Q:
	       if (n == 'W'|| n == 'w')
		    CURR_STATE = GOT_W;
	       else CURR_STATE = START;
	       break;

	  case GOT_W:
	       if (n == 'E'|| n == 'e')
	       { 
		    toggle_LED();
		    CURR_STATE = START;
	       }
	       else CURR_STATE = START;
	       break;

	  default :
	       CURR_STATE = START;
     }

}
/*
void ser_hand (void) interrupt 4
{
     char n;

     if (TI){
	  TI=False;
     }
     if (RI){
	  n=SBUF;
	  RI=False;
	  msg_parser(n);
     }

}
*/

void ser_putc (unsigned char c)
{
        SBUF=c;
        while(TI);
        TI=False;
	HW_delay(1);
}
void ser_puts (unsigned char *s)
{
   unsigned char c;
   while (c=*s++) {
           ser_putc (c);
   }
}

unsigned char ser_getc (void)
{
     unsigned char local;
     if(Rhead == Rtail) return 0;
     local = *Rtail;
     if(++Rtail == &RBUF[RBUFFSIZE])
          Rtail = &RBUF;
     return local;
}

void ser_hand (void) interrupt 4
{
     if (RI) {
          RI = 0;
          *Rhead = SBUF;
     if(++Rhead == &RBUF[RBUFFSIZE])
          Rhead = &RBUF;


     }
     if (TI) {
          TI = 0;

     }
}

/************************ external interrupt 1 ***********************************/

void init_ext1 (void)
{
//     TCON |= 0x04;	// external interrupt 1 set to edge triggered.
     IE |= 0x84;	// enable external interrupt.
}

void ext1_hand (void) interrupt 0
{
     ext1_flag = 0x00;	// activate the flag till the main_FSM picks it up and set it back inactive-high.
     HW_delay(1);
}

/************************ MIDI methods ***********************************/

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


