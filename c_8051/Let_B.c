#include <8051.h>
main()
{
char c;
c='B';
TMOD=0x20;
TH1=-6;
SCON=0x50;
TR1=1;
while(1<2){
	SBUF=c;
	while(TI);
	TI=0;
}
}
