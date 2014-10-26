
/*KA******************************************************************
* PROJECT:  
**********************************************************************
* FILE: timer.c
**********************************************************************
* CHANGES:
* date      author            description
* --------------------------------------------------------------------
* 11/02/03  sh                final
**********************************************************************
* DESCRIPTION:
* This file contains a simple interrupt driven timer0 driver 
**********************************************************************
* FUNCTIONS DECLARED:
* _timer0_init   Initialization; must be called first
* _lv_delay      low level non interrupt driven delay for init purposes
* _wait500mSec	 delay 500 mSec
* _wait1Sec	 delay 1 Sec
**********************************************************************
* COMPILE TIME OPTIONS: -
* DEBUG OPTIONS: -
******************************************************************KE*/
/*      $Id: _timer0.c,v 1.0 2003/11/02 13:51  Exp $  */

#include <at89x51.h>
#include "timer0.h"

unsigned int Timer1mSec = 0;	// general timer 1mSec.

void _timer0_init(void)
{
     TMOD &= 0xf0;		// reset the lower 4 bits of the TMOD
     TMOD |= 0x01;		// Timer 0 mode 1 ( 16 bit timer )
     TH0 = 0xDC;		// Timer 0, reload to 1 ms.
     TL0 = 0x00;
     ET0 = 1;			// enable timer 1 overflow interrupt
     EA = 1;
     TR0 = 1;
}

void _timer0_interrupt_handler(void) interrupt 1 using 1
{
     TH0 = 0xFC;		// Timer 0, reload to 1 ms.
     TL0 = 0x67;
     TR0 = 1;
     if (Timer1mSec) Timer1mSec--;
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

/*********************End of File************************************/








