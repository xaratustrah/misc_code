
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/signal.h>

enum MAIN_STATES { LED_POW , LED_SOFT };
enum MAIN_STATES CURR_TIME_SLICE = LED_POW;


//unsigned int Timer10mSec = 100;		// general timer 10mSec.
unsigned int cnt1 = 30;		// local counter for led.
unsigned int cnt2 = 30;			// local counter for led.


void toggle_LED_POW()
{

/* toggle specified pin: The content of PORT is anded with an 8 bit binary having */
/* only one bit at the specified location, if the result was false, it means the  */
/* PORT register had a logic zero on that bit before. */

     if( ! ( PORTD & (1 << PD4) )) PORTD |= (1 << PD4);		
     else PORTD &= ~(1 << PD4);				       

}

void toggle_LED_SOFT()
{

/* toggle specified pin: The content of PORT is anded with an 8 bit binary having */
/* only one bit at the specified location, if the result was false, it means the  */
/* PORT register had a logic zero on that bit before. */

     if( ! ( PORTD & (1 << PD5) )) PORTD |= (1 << PD5);		
     else PORTD &= ~(1 << PD5);				       
}

void delay_us(unsigned int us) 
{		
     while (us)
	  us--;    
}
 

void init_timer0 (){

     cli();					//disable global interrupt enable 
     TCCR0 |= ((1 << CS01) | (1 << CS00));	// prescaling Timer 0 to 1/64 at 1 MHz system freq. is 64us.
     TCNT0 = 125;				// set the refresh rate to 125, it makes 8ms.
     TIMSK |= (1 << TOIE0); 			// Enable Timer0 overflow interrupt.
     sei();					// enable global interrupt enable.
}

void main_FSM(void)
{
     switch (CURR_TIME_SLICE)
     {
	  case LED_POW:

	       if(--cnt1 == 0){
		    toggle_LED_POW();		
		    cnt1 = 10;			// on/off delay of the LED.
	       }
	       CURR_TIME_SLICE = LED_SOFT;
	       break;

	  case LED_SOFT:

	       if(--cnt2 == 0){
		    toggle_LED_SOFT();		
		    cnt2 = 20;			// on/off delay of the LED.
	       }
	       CURR_TIME_SLICE = LED_POW;
	       break;
     }
}

/* ISR interrupt service routine for the timer0 unit. */
/* it will be called every 8ms. */


SIGNAL(SIG_OVERFLOW0)
{
//     if (Timer10mSec) Timer10mSec--;
//     else {
//	  Timer10mSec = 100;
	  main_FSM();				// call the main state machine every 8ms.
//     }
}

int main (void)
{
     delay_us(1);		// some time to breath.
     DDRD |= (1 << DDD4);	// set LED_POW pin as output.
     DDRD |= (1 << DDD5);	// set LED_SOFT pin as output.
     PORTD |= (1<<PD5);
     PORTD |= (1<<PD4);

     init_timer0();

     for(;;){			// here is the main loop.
//	  delay_us(1);		//something in the main loop.
     }

     return 0;
}
 

     
     
