#include <ser_ir.h>
#include <at89x51.h>
void main (void)
{

	char *n="Hello World!";
	ser_init();
	ser_puts(&n);
	/*while(1)
	{
		hh= ser_getc();
		SBUF=hh;
		while(TI);
		TI=0;
		for (i=0;i <300000; i++);

	}*/
}
