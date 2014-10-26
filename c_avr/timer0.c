
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/signal.h>

#include "tasklist.h"

void timer0_init (void){

     cli();					//disable global interrupt enable 
     TCCR0 |= ((1 << CS01) | (1 << CS00));	// prescaling Timer 0 to 1/64 at 1 MHz system freq. is 64us.
     TCNT0 = 125;				// set the refresh rate to 125, it makes 8ms.
     TIMSK |= (1 << TOIE0); 			// Enable Timer0 overflow interrupt.
     sei();					// enable global interrupt enable.
}
/* ISR interrupt service routine for the timer0 unit. */
/* it will be called every 8ms. */


SIGNAL(SIG_OVERFLOW0)
{
	  tasklist();				// call the main state machine every 8ms.
}
