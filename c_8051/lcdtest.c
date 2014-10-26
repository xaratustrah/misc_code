#include <8051.h>


/* // LCD Command Write Register */
/* #define LcdCommandW (*((unsigned char xdata *)0x09000)) */

/* // LCD Command Read Register */
/* #define LcdCommandR (*((unsigned char xdata *)0x09001)) */

/* // LCD Data Write Register */
/* #define LcdDataW    (*((unsigned char xdata *)0x09002)) */

/* // LCD Data Read Register */
/* #define LcdDataR    (*((unsigned char xdata *)0x09003)) */


//lcd definitions

void init_lcd (void);
void lcd_cmnd (unsigned char);
void lcd_putc (unsigned char );
void lcd_puts (unsigned char *);
void HW_delay(unsigned char);


void init_lcd (void)
{

/*      LcdCommandW = 0x38; */
/*      LcdCommandW = 0x0F; */
/*      LcdCommandW = 0x01; */
/*      LcdCommandW = 0x06; */

     lcd_cmnd(0x38);    /*LCD 2 lines, 5X7 matrix */
     lcd_cmnd(0x0F);    /* diplay on, cursor on, blink */
     lcd_cmnd(0x01);    /* clear screen */
     lcd_cmnd(0x06);    /*shift cursor right */

}

void lcd_cmnd (unsigned char n)
{
     unsigned char xdata * cmnd = 0x00;
//     &cmnd = 0x00;      // RS low and R/W low
     HW_delay(10);
     *cmnd = n;
     HW_delay(20);
}

void lcd_putc (unsigned char n)
{
     unsigned char xdata * chr = 0x02;
//     &chr = 0x02;       // RS high and R/W low
     HW_delay(10);
     *chr = n;
     HW_delay(20);
     lcd_cmnd (0x06);
     HW_delay(20);
}

void lcd_puts (unsigned char *s)
{
   unsigned char c;
   while (c=*s++) {
           lcd_putc (c);
   }
}
void HW_delay(unsigned char t)
{
     unsigned int i;
     if (t==0) return;
     while(t--)for (i=0;i<774;i++);
     return;
}
main(){
     init_lcd();
     HW_delay(10);
     
     lcd_putc(0x45);
     for(;;){
     HW_delay(10);
     
     lcd_putc(0x45);

     }

}
