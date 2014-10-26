# include <stdio.h>

int main (void)
{
     char c = 0x02;
     char e = 0x03;
     int x = (int) c;
     printf("0x%X\n", x);
     x = x << 8;
     printf("0x%X\n", x);
     x |= e;
     printf("0x%X\n", x);
     return 0;
}
