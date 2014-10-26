
#ifndef __TASKLIST_H__
#define __TASKLIST_H__

extern enum TASKS { TASK01, TASK02 , TASK03 };

/* unsigned int Timer10mSec = 100;		// general timer 10mSec. */
extern unsigned int cnt1, cnt2;		// local counter for led.

extern void tasklist(void);

#endif 
