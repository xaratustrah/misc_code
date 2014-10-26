
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/signal.h>

#include "led.h"
#include "uart.h"
#include "timer0.h"

int main (void)
{
     timer0_init();
     led_POWER_init(0x00);
     led_SOFT_init(0x00);
     uart_init(0x0C);		// baud rate 4800
     for(;;);			// here is the main loop.
     return 0;
}
 

     
     
