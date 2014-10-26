# include <stdio.h>

struct message {

     unsigned short x_val;
     unsigned char f_val;
     unsigned char stop;
};

int main (void)
{
     struct message msg;
     char * foo;
     int i;
     
     foo = (char *)&msg;

     msg.x_val = 15;
     msg.f_val = 2;
     msg.stop = '\n';

     printf("Size of msg: %d\n", sizeof(msg));

     for (i = 0; i < sizeof(msg); i++)
     {
		  printf ("0x%X\n", *foo);
		  foo++;
     }

     return 0;
}
