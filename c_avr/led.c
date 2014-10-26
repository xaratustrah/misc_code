# include <avr/io.h>
# include "led.h"

void led_POWER_init(unsigned char initial_state)
{
     DDRD |= (1 << DDD4);	// set LED_POWER pin as output.
     led_POWER_value(initial_state);
}

void led_POWER_value(unsigned char value)
{
     if(value) PORTD |= (1<<PD4);
     else PORTD &= ~(1 << PD4);
}

void led_POWER_toggle(void)
{

/* toggle specified pin: The content of PORT is anded with an 8 bit binary having */
/* only one bit at the specified location, if the result was false, it means the  */
/* PORT register had a logic zero on that bit before. */

     if( ! ( PORTD & (1 << PD4) )) PORTD |= (1 << PD4);		
     else PORTD &= ~(1 << PD4);				       

}

void led_SOFT_init(unsigned char initial_state)
{
     DDRD |= (1 << DDD5);	// set LED_POWER pin as output.
     led_SOFT_value(initial_state);
}

void led_SOFT_value(unsigned char value)
{
     if(value) PORTD |= (1<<PD5);
     else PORTD &= ~(1 << PD5);
}

void led_SOFT_toggle(void)
{

/* toggle specified pin: The content of PORT is anded with an 8 bit binary having */
/* only one bit at the specified location, if the result was false, it means the  */
/* PORT register had a logic zero on that bit before. */

     if( ! ( PORTD & (1 << PD5) )) PORTD |= (1 << PD5);		
     else PORTD &= ~(1 << PD5);				       
}
