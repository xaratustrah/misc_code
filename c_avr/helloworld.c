
/* Test routine for the serial port  */
/* using an ATMEGA 8 device. */

# include <avr/io.h>

# define CPU_CLK_SPEED 1000000
# define BAUD_RATE 4800
# define BAUD_RATE_REG  (unsigned int)(CPU_CLK_SPEED / (16 * BAUD_RATE) ) - 1


void init_uart()
{

/* Set baud rate */ 

/*      UBRRH = (unsigned char)( BAUD_RATE_REG >> 8); */
/*      UBRRL = (unsigned char) BAUD_RATE_REG; */
    UBRRL = 0x0C;


/* Set frame format: 8data, 2stop bit  */

/*      UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0); */

/* Enable Receiver and Transmitter */ 

/*      UCSRB = (1<<RXEN)|(1<<TXEN);  */
     UCSRB = (1<<TXEN); 

}

void output_ch(char data)
	{
	while ((UCSRA & (1<<UDRE)) != (1<<UDRE))
		{
		continue;
		}
	UDR = data;
	
	return;
	}

/* void output_ch( unsigned char data )  */
/* {  */

/* /\* Wait for empty transmit buffer *\/  */
/*      while ( !( UCSRA & (1<<UDRE)) ) ;  */
/* /\* Put data into buffer, sends the data *\/  */
/*      UDR = data;  */
/* } */

void delay_us(unsigned int us) 
{		
     while (us)
	  us--;    
}

int main (void)
{
     char n = 'L';

     DDRD = 0xFF;
     PORTD |= (1<<PD5);

     init_uart();
     delay_us(10);

     output_ch('B');
     output_ch('Y');
     output_ch('E');
     output_ch('!');

//     output_ch('E');

/*      while(1){ */

/* 	  delay_us(8000000); */
/* 	  output_ch(n); */

/* /\* toggle specified pin: The content of PORT is anded with an 8 bit binary having *\/ */
/* /\* only one bit at the specified location, if the result was false, it means the  *\/ */
/* /\* PORT register had a logic zero on that bit before. *\/ */

/* 	  if( ! ( PORTD & (1 << PD5) )) PORTD |= (1 << PD5);		 */
/* 	  else PORTD &= (0 << PD5);				        */

/*      } */

     return 0;
}
 
