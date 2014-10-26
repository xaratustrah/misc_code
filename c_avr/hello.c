
# include "uart.h"


int main (void)
{
     unsigned char n = 0x00;
     uart_init(0x0C);		// set baud rate to 
     uart_puts("say what !");
     for(;;)
     {
	  n = uart_getc();
	  
	  if (n != 0x00)
	  {
	       uart_putc(n);
	       uart_putc(n);
	  }
     }
     return 0;
}
 
