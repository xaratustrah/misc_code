# include <avr/io.h>
# include <avr/interrupt.h>
# include <avr/signal.h>

# include "uart.h"


unsigned char RBUF[RBUFFSIZE];

unsigned char *Rhead = RBUF;
unsigned char *Rtail = RBUF;

unsigned char TBUF[TBUFFSIZE];

unsigned char *Thead = TBUF;
unsigned char *Ttail = TBUF;

SIGNAL(SIG_UART_RECV)
{
     *Rhead = UDR;
     if(++Rhead == &RBUF[RBUFFSIZE])
	  Rhead = &RBUF;
}

SIGNAL(SIG_UART_DATA)
{
     if(Thead != Ttail)
     {
	  UDR = *Ttail;
	  if(++Ttail == &TBUF[TBUFFSIZE])
	       Ttail = &TBUF;
     }
     else
     {
	  UCSRB &= ~(1 << UDRIE );	//disable transmit complete interrupt.
     }
}

void uart_putc (unsigned char c)
{
     *Thead = c;
     if(++Thead == &TBUF[TBUFFSIZE])
	  Thead = &TBUF;
     UCSRB |= (1 << UDRIE );	       //enable transmit complete interrupt.

}
void uart_puts (unsigned char *s)
{
     unsigned char c;
     while (c=*s++) {
	  uart_putc (c);
     }
}

unsigned char uart_getc (void)
{
     unsigned char local;
     if(Rhead == Rtail) return 0;
     local = *Rtail;
     if(++Rtail == &RBUF[RBUFFSIZE])
          Rtail = &RBUF;
     return local;
}


void uart_init(unsigned char baudrate)
{
     cli();
     UBRRL = baudrate;					//baud rate 
     UCSRB |= (1<<RXEN) | (1<<RXCIE) | (1<<TXEN) ;  	// enable the transmitter, receiver and receive interrupt
     sei();
}
 
