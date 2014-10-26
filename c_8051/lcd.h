
#ifndef __LCD_H__
#define __LCD_H__

#define False 0
#define True 1

#define LCD_RS P2_2
#define LCD_R_W P2_3
#define LCD_EN P2_4
#define LCD_DATA_PORT P1
#define LCD_BUSY P1_7

void _lcd_init(void);
void _lcd_cmnd(unsigned char);
void _delay(unsigned char);
void _lcd_ready();
void _lcd_putc(unsigned char);
int _lcd_puts(unsigned char*, int);

#endif
