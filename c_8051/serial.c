

/* **************** Lock.C *********************** */
/* Hardware Lock Version 1.0.0 */
/* (C) Copyright xaratustra. */
/* All rights reserved. */
/* This code is not free/open software. */
/* Baud Rate : 19200 Baud */
/* *********************************************** */



#include <at89x51.h>

#define False 0
#define True 1

#define RBUFFSIZE 20
#define TBUFFSIZE 20


unsigned char RBUF[RBUFFSIZE];

unsigned char *Rhead = RBUF;
unsigned char *Rtail = RBUF;

unsigned char TBUF[TBUFFSIZE];

unsigned char *Thead = TBUF;
unsigned char *Ttail = TBUF;

unsigned char formula_number = 0;
unsigned char variable = 0;

unsigned char ext1_flag = 0x01;		// active-low external flag     

enum MAIN_STATES { SERIAL, LED , EXT1, SER_XMIT};
enum MAIN_STATES CURR_TIME_SLICE = SERIAL;

enum ALL_STATES { START, GOT_F, GOT_R , GOT_M, GOT_FM, GOT_V, GOT_A, CALC};
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
void calculate (unsigned char, unsigned char);

/***************** ********** MAIN ************* ****************/

void main ( void )
{
     HW_delay(1);
     init_timer0();
     HW_delay(1);
     init_serial();
     HW_delay(1);
     ser_puts("Ready...\n\r$ ");
     for (;;)			// main loop.
	  HW_delay(1);
     
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
	       CURR_TIME_SLICE = SER_XMIT;
	       break;

	  case SER_XMIT:
	       if(Thead != Ttail)
	       {
/* 		    SBUF = *Thead; */
/* 		    if(++Thead == &TBUF[TBUFFSIZE]) */
/* 			 Thead = &TBUF; */
		    TI = True;
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
     TR1 = True;	/* start timer 1 for serial communicaiton */
}

void msg_parser(unsigned char n)
{
     switch (CURR_STATE)
     {
	  case START:
	       if (n == 'F'|| n == 'f')
		    CURR_STATE = GOT_F;
	       else CURR_STATE = START;	       
	       break;

	  case GOT_F:
	       if (n == 'R'|| n == 'r')
		    CURR_STATE = GOT_R;
	       else CURR_STATE = START;
	       break;

	  case GOT_R:
	       if (n == 'M'|| n == 'm')
	       { 
		    CURR_STATE = GOT_M;
	       }
	       else CURR_STATE = START;
	       break;

	  case GOT_M:
	       if(n > 255) 
	       {
		    CURR_STATE = GOT_M;
		    ser_puts("ERR:NUM>2\n\r");
		    break;
	       }
	       formula_number = n;
	       toggle_LED();
	       ser_puts("ACK1");
	       CURR_STATE = GOT_FM;
	       break;

	  case GOT_FM:
	       if(n == 'V' || n == 'v')
		    CURR_STATE = GOT_V;
	       else 
	       {
		    if (n == 'C' || n == 'c')
			 CURR_STATE = START;
		    else CURR_STATE = GOT_FM;
	       }
	       break;

	  case GOT_V:
	       if(n == 'A' || n == 'a')
		    CURR_STATE = GOT_A;
	       else 
	       {
		    if (n == 'C' || n == 'c')
			 CURR_STATE = START;
		    else CURR_STATE = GOT_FM;
	       }
	       break;

	  case GOT_A:
	       if(n == 'R' || n == 'r')
		    CURR_STATE = CALC;
	       else 
	       {
		    if (n == 'C' || n == 'c')
			 CURR_STATE = START;
		    else CURR_STATE = GOT_FM;
	       }
	       break;

	  case CALC:

	       variable = n;
	       toggle_LED();
	       ser_puts("ACK2");
	       calculate(formula_number, variable);
	       CURR_STATE = START;
	       break;
	       
	  default :
	       CURR_STATE = START;
     }

}

void ser_putc (unsigned char c)
{

     *Thead = c;
     if(++Thead == &TBUF[TBUFFSIZE])
	  Thead = &TBUF;
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
          TI = False;
	  if(Thead != Ttail)
	  {
	       SBUF = *Ttail;
	       if(++Ttail == &TBUF[TBUFFSIZE])
		    Ttail = &TBUF;
	  }
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

/*********************** math functions *****************************************/

void calculate (unsigned char formula_number, unsigned char variable)
{
     if(formula_number == 35 ) ser_putc(variable + 10);
     if(formula_number == 40 ) ser_putc(variable * 2);
     formula_number = 0;
     variable = 0;
}
/*********************** MISC methods **************************/
								    
void toggle_LED (void)				    
{								    
     P1_0 = ~P1_0;				    
}								    
