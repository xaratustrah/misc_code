

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "plotbake.h"


int main(int argc , char* argv[])
{

     static char* input_file_name; 
     
     static long with_comma, with_carriage_return;
     double start_time = 0;
     double time_step ;

     FILE *input_file;

     char s[256], ch, n;

     int i = 0;

     while ((ch = getopt(argc, argv, ":f:t:c:s:r:")) != -1)
	  switch (ch) {
	       case 't':
		    time_step = strtod(optarg, NULL);
		    break;

	       case 's':
		    start_time = strtod(optarg, NULL);
		    break;

	       case 'f':
		    input_file_name = optarg;
		    break;

	       case 'c':
		    with_comma = strtol(optarg, NULL, 0);
		    break;

	       case 'r':
		    with_carriage_return = strtol(optarg, NULL, 0);
		    break;

	       case '?' :
	       default:
		    usage();
	  }

     argc -= optind;
     argv += optind;

    
     input_file = fopen(input_file_name, "r");
     if (input_file == NULL){
	  printf("Error openning file or file non-existant. \n");
	  return (-1);
     }
     while ((n = fgetc(input_file)) != EOF ){
			     
	  if(n == '\n') {
	       s[i] = '\0';

	       if(with_comma){
		    if (with_carriage_return)  printf("%f,%s\r\n", start_time,  s);
		    else  printf("%f,%s\n", start_time,  s);
	       }
	       else {
		    if(with_carriage_return)
			 printf("%f %s\r\n", start_time,  s);
		    else printf("%f %s\n", start_time,  s);
	       }

	       i = 0;
	       start_time = start_time + time_step;
	  }
	  else {
	       s[i++] = n;
	  }
     }
     s[i] = '\0';

     fclose(input_file);
     return(0);

}

void usage()
{

     fprintf(stderr, "Data-Baker V1.0\n");
     fprintf(stderr, "(c) 2005 by Xaratustra \n");
     fprintf(stderr, "All rights reserved.\n");
     fprintf(stderr,
	     "usage: plotbake -f file -s start_time -t time_step -c with_comma_or_space \\\n");
     exit(1);
}
