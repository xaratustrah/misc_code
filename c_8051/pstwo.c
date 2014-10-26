#include <8051.h>

#define SCL P3_2
#define SDA P2_0
//#define LED P2_5;

void x_wait();
void _lv_delay(unsigned char);

//bit in_char[8];
bit r_flag, x_flag;
int in_bit_cnt = 0;

void _ps2_init (void)
{
   EX0 = 0;
//   rcnt = xcnt = rpos = xpos = 0;  /* init buffers */
//   busy = 0;
   IT0 = 1;
   EA = 1;
   EX0 = 1;

}
void _ext0_handler (void) interrupt 0
{
     x_flag =  0;
//     r_flag = 0;
     
}

/* void _ps2_msg_ack() */
/* { */
/*      if(in_bit_cnt == 0 && SDA == 0)wait(); */
/*      in_char[in_bit_cnt] = SDA; */
/*      in_bit_cnt++; */
     
void _ps2_reset()
{
     SDA = 0;
     x_wait();
     SDA = 1;
     x_wait();
     SDA = 1;
     x_wait();
     SDA = 1;
     x_wait();
     SDA = 1;
     x_wait();
     SDA = 1;
     x_wait();
     SDA = 1;
     x_wait();
     SDA = 1;
     x_wait();
     SDA = 1;	//parity
     x_wait();
     SDA = 1;
}

void x_wait ()
{
     x_flag = 1;
     while(x_flag==1);
}
/* void r_wait () */
/* { */
/*      r_flag = 1; */
/*      while(r_flag == 1); */
     
/* } */

void main (void)
{
//     int i;
     _ps2_init();
     _lv_delay(1);
     P2_5 = 0;
     for(;;){
	  P2_5 = ~P2_5;
	  
	  _ps2_reset();
	  _lv_delay(500);
     }
     
     
}
void _lv_delay(unsigned char t)
{
     unsigned int i;
     if (t==0) return;
     while(t--)for (i=0;i<774;i++);
     return;
     
}
