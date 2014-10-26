#include <stdio.h>
#include <string.h>
main()
{
     char a[2],b[1];
     strcpy(a[1],"A");
     strcpy(b[1],"B");
     strcat(a,b);
     printf("%s \n",strcat(a,b));
}

