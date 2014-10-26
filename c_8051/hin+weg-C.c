#include <8051.h>
#include <ser_ir.h>
#define XBUFLEN 10
#define RBUFLEN 10
#define TRUE 1
#define FALSE 0

static unsigned char rbuf[RBUFLEN], xbuf[XBUFLEN];
static unsigned char rcnt, xcnt, rpos, xpos;
static unsigned char busy;


void ser_init (void);
void ser_putc (unsigned char c);
void ser_puts (unsigned char *s);


void main(void)
{
int i;
//unsigned char n="H";
ser_init();

while(TRUE){
//ser_putc(n);

SBUF='J';
while(TI);
TI=FALSE;
for (i=0;i<300000;i++);
}
}



void ser_init (void)
{
   ES = 0;
   rcnt = xcnt = rpos = xpos = 0;  /* init buffers */
   busy = 0;
   SCON = 0x50;
   PCON |= 0x80;                   /* SMOD = 1; */
   TMOD &= 0x0f;                   /* use timer 1 */
   TMOD |= 0x20;
   TL1 = -3; TH1 = -3; TR1 = 1;    /* 19200bps with 11.059MHz crystal */
   ES = 1;
}

void ser_handler (void) interrupt 4
{
   if (RI) {
	   RI = 0;
	   /* don't overwrite chars already in buffer */
	   if (rcnt < RBUFLEN)
		   rbuf [(rpos+rcnt++) % RBUFLEN] = SBUF;
   }
   if (TI) {
	   TI = 0;
	   if (busy = xcnt) {   /* Assignment, _not_ comparison! */
		   xcnt--;
		   SBUF = xbuf [xpos++];
		   if (xpos >= XBUFLEN)
			   xpos = 0;
	   }
   }
}

void ser_putc (unsigned char c)
{
   while (xcnt >= XBUFLEN) /* wait for room in buffer */
	   ;
   ES = 0;
   if (busy) {
	   xbuf[(xpos+xcnt++) % XBUFLEN] = c;
   } else {
	   SBUF = c;
	   busy = 1;
   }
   ES = 1;
}

unsigned char ser_getc (void)
{
   unsigned char c;
   while (!rcnt)   /* wait for character */
	   ;
   ES = 0;
   rcnt--;
   c = rbuf [rpos++];
   if (rpos >= RBUFLEN)
	   rpos = 0;
   ES = 1;
   return (c);
}
#pragma SAVE
#pragma NOINDUCTION
void ser_puts (unsigned char *s)
{
   unsigned char c;
   while (c=*s++) {
	   if (c == '\n') ser_putc ('\r');
	   ser_putc (c);
   }
}
#pragma RESTORE
void ser_gets (unsigned char *s, unsigned char len)
{
   unsigned char pos, c;

   pos = 0;
   while (pos <= len) {
	   c = ser_getc ();
	   if (c == '\r') continue;        /* discard CR's */
	   s[pos++] = c;
	   if (c == '\n') break;           /* NL terminates */
   }
   s[pos] = '\0';
}

unsigned char ser_can_xmt (void)
{
   return XBUFLEN - xcnt;
}

unsigned char ser_can_rcv (void)
{
   return rcnt;
}

/*****************************/

