
#include <at89x51.h>
#include "lcd.h"

// serial definitions 

#define BUFFSIZE 100
unsigned char RBUF[BUFFSIZE];
unsigned char *Rhead = RBUF;
unsigned char *Rtail = RBUF;
void _ser_init(void);
void _ser_handler (void) interrupt 4;
unsigned char  _ser_get_char(void);

// timer definitions

void timerJob(void);
unsigned int Timer1mSec = 0;	// general timer 1mSec.
unsigned int cnt = 50;

void _timer0_init(void);
void _timer0_interrupt_handler(void) interrupt 1;
void _lv_delay(unsigned char t);
void _wait1Sec(void);
void _wait500mSec(void);


/*********************************** main *****************************/

void main (void)
{
/*      unsigned char tmp; */

     _timer0_init();
/*      _ser_init(); */
     _lcd_init();

     _lv_delay(300);

     _lcd_puts((unsigned char*)"Yeah! ",6);
     _lv_delay(300);

     for (;;){
	  _lv_delay(1);
/* 	  tmp = _ser_get_char(); */
/* 	  if (tmp == 'a') */
/* 	       _lcd_putc(tmp); */
     }
}

void timerJob(void)
{
     if(--cnt <= 0){
	  P1_0 = ~P1_0;
	  cnt = 50;
	  
     }
}

/****************** start of timer functions ***************/

void _timer0_init(void)
{
     TMOD &= 0xf0;		// reset the lower 4 bits of the TMOD
     TMOD |= 0x01;		// Timer 0 mode 1 ( 16 bit timer )
     TH0 = 0xDC;		// Timer 0, reload to 10 ms.
     TL0 = 0x00;
     ET0 = 1;			// enable timer 0 overflow interrupt
     EA = 1;
     TR0 = 1;
}

void _timer0_interrupt_handler(void) interrupt 1
{
     TH0 = 0xFC;		// Timer 0, reload to 1 ms.
     TL0 = 0x67;
     TR0 = 1;
     if (Timer1mSec) Timer1mSec--;
     timerJob();

}

void _lv_delay(unsigned char t)
{
     unsigned int i;
     if (t==0) return;
     while(t--)for (i=0;i<774;i++);
}

void _wait500mSec(void)
{
     Timer1mSec = 500;
     _lv_delay(1);		// give sometime to let the MCU catch up with the commands
     while(Timer1mSec);
}
void _wait1Sec(void)
{
     Timer1mSec = 1000;
     _lv_delay(1);		// give sometime to let the MCU catch up with the commands
     while(Timer1mSec);
}

/*********************End of Timer functions ************************************/

/******************* start of the serial handling funktions *********************/

void _ser_init (void)
{
   ES = 0;
   SCON = 0x50;
   PCON |= 0x80;                   /* SMOD = 1; */
   TMOD &= 0x0f;                   /* use timer 1 */
   TMOD |= 0x20;
   TL1 = -3; TH1 = -3; TR1 = 1;    /* 19200bps with 11.059MHz crystal */
   ES = 1;
}
unsigned char _ser_get_char ()
{
     unsigned char local;
     if(Rhead == Rtail) return 0;
     local = *Rtail;
     if(++Rtail == &RBUF[BUFFSIZE])
	  Rtail = &RBUF;
     return local;
     
}

void _ser_handler (void) interrupt 4
{
     if (RI) {
	  RI = 0;
	  *Rhead = SBUF;
     if(++Rtail == &RBUF[BUFFSIZE])
	  Rtail = &RBUF;


     }
     if (TI) {
	  TI = 0;

     }
}
