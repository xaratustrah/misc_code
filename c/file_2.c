#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#ifdef DEBUG_OUT
#define DEBUG(format, args...) printf("%s: "format, __PRETTY_FUNCTION__ ,## args)
#else
#define DEBUG(format, args...)
#endif

#define _PATH_FILENAME .
#define _MAX_ENTRIES 10

char *DBFileName =  (char*)"file.dat";

typedef struct {
     short id ;
     float note ;
     char c;
} ContactSheet;

int main(void){
     int i, inf;
     ContactSheet *Test;
static ContactSheet Addressbook[_MAX_ENTRIES];

     for (i =0; i < _MAX_ENTRIES ; i++ )
	  Addressbook[i].id = i;
     for (i =0; i < _MAX_ENTRIES ; i++ )
	  Addressbook[i].note = 12.23;
     for (i =0; i < _MAX_ENTRIES ; i++ )
	  Addressbook[i].c = (char)"H";

     for (i =0; i < _MAX_ENTRIES ; i++ )
	  printf("%d \n",Addressbook[i].id);
     for (i =0; i < _MAX_ENTRIES ; i++ )
	  printf("%d \n",Addressbook[i].id);
     for (i =0; i < _MAX_ENTRIES ; i++ )
	  printf("%c \n", Addressbook[i].c);

     Test->id = 10;
     Test->note = 13.13;
     Test->c = (char)"N";

     if ((inf = open(DBFileName, O_CREAT | O_TRUNC | O_WRONLY | O_EXCL, 0755)) < 0) {
	  DEBUG("Fehler!");
	  return (-1);
     }
     printf("%d \n", sizeof Test);
     printf("%d \n", inf);

//     write(inf, Addressbook, sizeof Addressbook);
     write(inf, Test, sizeof Test);
     close(inf);

     return (0);
}
