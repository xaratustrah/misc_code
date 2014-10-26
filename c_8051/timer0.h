
#ifndef __TIMER0_H__
#define __TIMER0_H__

void _timer0_init(void);
void _timer0_interrupt_handler(void) interrupt 1 using 1;
void _lv_delay(unsigned char t);
void _wait1Sec(void);
void _wait500mSec(void);

#endif

