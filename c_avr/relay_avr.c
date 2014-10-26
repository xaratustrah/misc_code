
# include "uart.h"
# include "led.h"

int main (void)
{
     unsigned char n = 0x00;

     led_SOFT_init(0x00);
     uart_init(0x0C);		// set baud rate to 

     uart_puts("say what !");
     for(;;)
     {
	  n = uart_getc();
	  
	  if (n == 'Q'|| n == 'q')
	  {
	       led_SOFT_toggle();
	  }
     }
     return 0;
}
 
