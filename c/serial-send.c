# include <stdio.h>

struct message {
     unsigned char val01;
     unsigned char val02;
     unsigned char stop;
     unsigned int U;
     unsigned char end;
};

int main (void)
{
     struct message * msg;
     char * foo;
     int i;

     foo = (char *) msg;

     msg->val01 = 'Q';
     msg->val02 = 'W';
     msg->stop = 'E';
     msg->U = 12;
     msg->end = 'R';

     printf("Size of msg: %d\n", sizeof(*msg));

     for (i = 0; i < sizeof(*msg); i++)
     {
	  printf ("0x%X\n", *foo);
	  foo++;
     }

     return 0;
}
