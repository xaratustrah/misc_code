#include <at89x51.h>
#include "lcd.h"

void _lcd_init(void)
{
	_lcd_cmnd(0x38); /*LCD 2 lines, 5X7 matrix */
	_lcd_cmnd(0x0F); /* diplay on, cursor on, blink */
	_lcd_cmnd(0x01); /* clear screen */
	_lcd_cmnd(0x06); /*shift cursor right */
}

void _lcd_cmnd (unsigned char n)
{
	LCD_DATA_PORT = n;
	LCD_RS = False;
	LCD_R_W = False;
	LCD_EN = True;
	LCD_EN = False;
	_lcd_ready();
//	_delay(2);
	
}

void _lcd_putc(unsigned char c)
{
     
 	LCD_DATA_PORT = c;
	LCD_RS = True;
	LCD_R_W = False;
	LCD_EN = True;
	LCD_EN = False;
	_lcd_cmnd(0x06); //shift cursor.
//	_delay(2);
	
	_lcd_ready();
}

int _lcd_puts(unsigned char *str, int size)
{
     int i;
     for (i = 0; i< size; i++){
	  _lcd_putc(*str);
	  str++;
     }
     return 1;
}

void _delay(unsigned char t)
{
     unsigned int i;
     if (t==0) return;
     while(t--)for (i=0;i<774;i++);
     return;
     
}

void _lcd_ready()
{
     LCD_BUSY = 1;
     LCD_RS = 0;
     LCD_R_W = 1;
     LCD_EN = 1;
     LCD_EN = 0;
     while(!LCD_BUSY);
     return;
}


