#include <stdio.h>
#include <unistd.h>
//#undef GETOPTOPTS
//#define GETOPTOPTS "ab:"
#undef USAGE
#define USAGE \
"usage: scancode [-a] [-b]\n"
int main(int argc, char **argv)
{
     int ch, aflag,bflag;
     while ((ch = getopt(argc, argv, "ab")) != -1)
	  switch((char)ch){
	  case 'a':	      
	       aflag=1;
	       break;
	  case 'b':
	       bflag=1;
	       break;
	  default:
	       fputs(USAGE, stderr);
	       break;
	  }

     if(aflag==1)printf("You typed a!\n");
     if(bflag==1)printf("You typed b!\n");
     if(aflag != 1 && bflag != 1)printf("You didn't type any arguments!\n");

     printf("Good work anyway!\n");
     return 0;
}













