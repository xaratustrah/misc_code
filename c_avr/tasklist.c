#include "tasklist.h"
#include "led.h"
#include "uart.h"
#include "parser.h"

unsigned int cnt1 = 50;
unsigned int cnt2 = 10;
enum TASKS CURRENT_TASK = TASK01;
unsigned char n;


void tasklist(void)
{
     switch (CURRENT_TASK)
     {
          case TASK01:

               if(--cnt1 == 0){
//                    led_POWER_toggle();           
                    cnt1 = 50;                  // on/off delay of the LED.
               }
               CURRENT_TASK = TASK02;
               break;

          case TASK02:

               if(--cnt2 == 0){
                    led_SOFT_toggle();          
                    cnt2 = 10;                  // on/off delay of the LED.
               }
               CURRENT_TASK = TASK03;
               break;

          case TASK03:                                                                     
	       n = uart_getc();
          
	       if (n != 0x00)
	       {
		    parser (n);
	       }
               CURRENT_TASK = TASK01;
               break;                                                                      

          default :                                                                        
               CURRENT_TASK = TASK01;
               break;                                                                      

     }
}

