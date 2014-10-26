#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <dirent.h>

int main(){
   struct stat buffer;
   struct tm *aTimeDate;
   struct tm *mTimeDate;
   struct tm *curTime;
   struct dirent *dirPath;
   int status,year,mon,day,hour,min,sec,i,tag,monat,jahr;
   char path[255],pathCPY[255],slash[2];
   DIR *curDir;

   slash[0] = '/';
   slash[1] = '\0';
   printf("\nFull path, last modified, last accessed (hh:mm:ss, dd.mm.yyyy) \n\n");
   printf("Where to look? or enter for /: ");
   gets(path);
   printf("Since when? (day)\n");
   scanf("%d", &tag);
   printf("Since when? (month)\n");
   scanf("%d", &monat);
   printf("Since when? (year)\n");
   scanf("%d", &jahr);

   if(path[0] == NULL) 
	strcpy(path,"/");

   i = strlen(path);
//   printf("%d\n",i);
   if(path[i] != '/')
	strcat(path, slash);

   printf("%s\n", path);
   strcpy(pathCPY, path);
   curDir = opendir(path);
   while ((dirPath = readdir(curDir)) != NULL) {
	strcpy(pathCPY, path);
	strcat(pathCPY, dirPath->d_name);
//	printf("%s\n",path2);
	status = stat(pathCPY,&buffer);
	if(status != -1) {
	     printf("%s", pathCPY);
	     aTimeDate = localtime(&buffer.st_atime);
	     mTimeDate = localtime(&buffer.st_mtime);
	     if((*aTimeDate).st_atime.tm_year < jahr || (*mTimeDate).st_mtime.tm_year < jahr)
		  continue;
	     else if(aTimeDate->st_atime.tm_mon < monat || mTimeDate->st_mtime.tm_mon < monat) 
		  continue;
	     else if (aTimeDate->st_atime.tm_day < tag || mTimeDate->st_mtime.tm_day < tag)
		  continue;

	     /* the () around the pointer is mandatory in this case, */
	     /* it's equivalent is timeDate->tm_hour */
	     printf("%s\n", asctime(aTimeDate));
	     printf("%s\n", asctime(mTimeDate));
	} else {
	     printf("Fehler! Maybe the file doesn't exist.\n");
	     return 0;
	}
   //closedir(path);
   }
}
