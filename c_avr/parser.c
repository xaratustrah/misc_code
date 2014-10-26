
#include "parser.h"
#include "led.h"
#include "uart.h"
#include "functions.h"

/* struct message { */
/*      unsigned int x_value; */
/*      unsigned char f_value; */
/*      unsigned char stop; */
/* }; */


enum STATES CURRENT_STATE = STATE01;

unsigned int local_x_value;
unsigned char local_function_number;

void parser(unsigned char n)
{
     int tmp_high_byte;
     switch (CURRENT_STATE)
     {
          case STATE01:
	       local_x_value = (unsigned int) n;
	       CURRENT_STATE = STATE02;
               break;

          case STATE02:
	       tmp_high_byte = (int) n;
	       tmp_high_byte = ( tmp_high_byte << 8 );
	       local_x_value |= tmp_high_byte;
	       CURRENT_STATE = STATE03;
               break;

          case STATE03:                                                                     
	       local_function_number = n;
	       CURRENT_STATE = STATE04;
               break;                                                                      

          case STATE04:                                                                     

	       if (n == '\r' || n == '\n')
	       {
		    CURRENT_STATE = STATE01;
		    led_POWER_toggle();
//		    uart_puts("ACK\n");
		    calculate_result(local_x_value, local_function_number);
	       }
               break;                                                                      

          default :                                                                        
               CURRENT_STATE = STATE01;
               break;                                                                      

     }
}

/* int send_message(struct message msg) */
/* { */
/*      int i; */
/*      char * foo; */
/*      foo = (char *)&msg; */
/*      for (i = 0; i < sizeof(msg); i++) */
/*      { */
/* 	  parser(*foo); */
/* 	  foo++; */
/*      } */
/*      return 0; */
/* } */

/* int main(void) */
/* { */
/*      struct message msg; */
/*      msg.x_value = 13681; */
/*      msg.f_value = 2; */
/*      msg.stop = '\n'; */

/*      send_message(msg); */

/*      return 0; */
/* } */

