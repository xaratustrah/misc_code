
#include <avr/io.h>

void delay_us(unsigned int us) 
{		
     while (us)
	  us--;    
} 

int main (void)
{
     DDRD = 0xFF;
     PORTD |= (1<<PD4);
     PORTD &= (0<<PD6);

     while(1){
	  delay_us(50000000);

/* toggle specified pin: The content of PORT is anded with an 8 bit binary having */
/* only one bit at the specified location, if the result was false, it means the  */
/* PORT register had a logic zero on that bit before. */

     if( ! ( PORTD & (1 << PD4) )) PORTD |= (1 << PD4);		
     else PORTD &= (0 << PD4);				       

/* toggle specified pin: The content of PORT is anded with an 8 bit binary having */
/* only one bit at the specified location, if the result was false, it means the  */
/* PORT register had a logic zero on that bit before. */

     if( ! ( PORTD & (1 << PD5) )) PORTD |= (1 << PD5);		
     else PORTD &= (0 << PD5);				       

     }

     return 0;
}
 

