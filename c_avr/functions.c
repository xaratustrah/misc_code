
# include <math.h>
# include "functions.h"
# include "uart.h"

const float degtorad = M_PI/180; 

/*  convert degrees */
/*  to radians */

struct outgoing_message om;


int function01 (int x)
{
     float x_in_radians, result;
     x_in_radians = x  * degtorad;
     result = sin(x_in_radians * 3) + 3 * (cos (x_in_radians));
     return (int) result;
}

int function02 (int x)
{
     float x_in_radians, result;
     x_in_radians = x  * degtorad;
     result = log10(tan(x_in_radians) * 1423);
     uart_putc('R');
     return (int) result;
}

void calculate_result(unsigned int local_x_value, unsigned char local_function_number)
{
     om.fill_byte = 0x05;
     om.stop_byte = '\n';
     if (local_function_number > 100 ) 
	  return;
     if (local_function_number == 98)
	  om.y_value = function01(local_x_value);
     if (local_function_number == 99)
	  om.y_value = function02(local_x_value);
     send_result();
     return;
}
void send_result(void)
{
     int i;
     char * foo;
     foo = (char *)&om;
     for (i = 0; i < sizeof(om); i++)
     {
	  uart_putc (*foo); 

          foo++;
     }
     return;
}

/* int main() */
/* { */
/*      calculate_result (30, 2); */
/*      return 0; */
/* } */
