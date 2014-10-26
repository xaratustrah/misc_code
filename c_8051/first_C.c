#include <8051.h>
main()
{
int i;
while(1<2)
{
	ser_puts("HALLO");
	P1_1=0x00;
	for(i=0; i<500000; i++);
	P1_1=0xff;
	for(i=0; i<500000; i++);
}
