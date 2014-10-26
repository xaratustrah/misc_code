#include <8051.h>
#include <serial.h>

void main()
{	
     unsigned char c = (unsigned char)'W';
     serial_init();
     serial_putc(c);
     
      for(;;){ 
 	  serial_putc(serial_getc());
     serial_putc(c);

      } 
}
