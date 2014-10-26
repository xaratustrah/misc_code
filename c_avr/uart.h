
#ifndef __UART_H__
#define __UART_H__

#define RBUFFSIZE 100
#define TBUFFSIZE 100

extern void uart_putc (unsigned char);
extern void uart_puts (unsigned char*);
extern unsigned char uart_getc (void);
extern void uart_init(unsigned char);

#endif


