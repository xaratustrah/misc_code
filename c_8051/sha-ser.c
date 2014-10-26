#include <8051.h>

#define BUFFSIZE 100

unsigned char RBUF[100];

unsigned char *head = RBUF;
unsigned char *tail = RBUF;

ser_put_char (unsigned char c)
{
     *head = c;
     if(++head >= &RBUF[BUFFSIZE])
	  head = RBUF;
}

unsigned char ser_get_char ()
{
     unsigned char local;
     if(head == tail) return 0;
     local = *tail;
     if(++tail == &RBUF[BUFFSIZE])
	  tail = &RBUF;
     return local;
     
}

void ser_init (void)
{
   ES = 0;
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

     
