
#include <at89x51.h>
#include "lcd.h"


#define BUSY		0x80

void lcd_cs(void)
{
     P3_5 = 0x01;
     P3_5 = 0x00;

}

unsigned char get_busy(void)
{
     unsigned char local_flag;
     local_flag = LcdCommandR;
     lcd_cs();
     return local_flag;
}

char LcdReady(void)
{
	unsigned char flag;
	while( (flag = get_busy()) & BUSY)  
	{
		if(flag == 0xFF) return -1;  
	}
	return 1;
}

void ClrScr(void)       
{
	LcdReady();
	LcdCommandW = 0x01;
	lcd_cs();
}

char InitLcd(void)
{
	if(-1 ==LcdReady()) return -1;
	LcdCommandW = 0x38;
	lcd_cs();

	LcdReady();
	LcdCommandW = 0x0C;
	lcd_cs();

	ClrScr();
	GotoXY(0,0);
}


/*
Description    :  Move Cursor to X Column, Y Row.
Argument      :  x - Column to move(INPUT), 
                      y - Row to move(INPUT), 
Return Value :
Note             :  LCD to be offered by WIZnet is '2*16' Dimension, so Row(Argument y) is not above 1.
*/
void GotoXY(unsigned char x, unsigned char y)
{
    LcdReady();
    switch(y){
        case 0 : LcdCommandW = 0x80 + x; lcd_cs();break;
        case 1 : LcdCommandW = 0xC0 + x; lcd_cs();break;
        case 2 : LcdCommandW = 0x94 + x; lcd_cs();break;
        case 3 : LcdCommandW = 0xD4 + x; lcd_cs();break;
    }
}


/*
Description    :  Output character string in current Cursor.
Argument      :   str - Character to be output in LCD. (INPUT)
Return Value :   Character string's Pointer to be output 
Note :
*/
char *Puts(char* str)
{
	unsigned char i;

	for (i=0; str[i] != '\0'; i++){
		LcdReady();
		LcdDataW = str[i];
		lcd_cs();
	}
	return str;
}

/*
Description    :   Output 1 character in current Cursor.
Argument      :  str - Character to be output in LCD. (INPUT)
Return Value :   
Note             :
*/
void Putch(char ch)
{
	LcdReady();
	LcdDataW = ch;
	lcd_cs();
}

/*
###############################################################################
Unused Function Implementation Part
###############################################################################
*/

#ifndef __LCD_UNUSED

/*
Description    :   Decide Cursor type.
Argument      :   type - Cursor type(INPUT)
Return Value :   
Note             :
*/
void SetCursorType(unsigned char type)	
{
	LcdReady();
	switch(type) 
	{
			//No Cursor 
	        case 0 : LcdCommandW = 0x0C; lcd_cs();break;  
			// Normal Cursor 
	        case 1 : LcdCommandW = 0x0E; lcd_cs();break; 
		// No Cursor | Blink
		case 2 : LcdCommandW = 0x0D; lcd_cs();break; 
			// Normal Cursor | Blink 
	        case 3 : LcdCommandW = 0x0F; lcd_cs();break; 
	}
}
/*
Description    :  Shift to Left and Right current Cursor.
Argument      :   dir - Decide direction to be Shift.(INPUT)  dir !=0  -> Right Shift, dir == 0 -> Left Shift
Return Value :   
Note             :   
*/

void ShiftCursor(unsigned char dir)	
{
	LcdReady();
	LcdCommandW = (dir ? 0x14: 0x10);
	lcd_cs();
}

/*
Description    : Move Cursor first Column.
Argument      :
Return Value  :
Note :
*/
void HomeCursor(void)       
{
	LcdReady();
	LcdCommandW = 2;
	lcd_cs();
}

#endif
