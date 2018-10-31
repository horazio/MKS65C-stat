#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <time.h>


char * permissions(int digit){
  char * retval = malloc(10 * sizeof(char));
  switch (digit){
     case 0: strcpy(retval, "---");
            break;
     case 1: strcpy(retval, "--x");
            break;
     case 2: strcpy(retval, "-w-");
            break;
     case 3: strcpy(retval, "-wx");
            break;
     case 4: strcpy(retval, "r--");
            break;
     case 5: strcpy(retval, "r-x");
            break;
     case 6: strcpy(retval, "rw-");
            break;
     case 7: strcpy(retval, "rwx");
            break;
  }
  return retval;
}

int main(){
  struct stat * s = malloc(sizeof(struct stat));
  stat("./a.out", s);

  unsigned int size = s -> st_size;
  char sizestr[20];
  if (size < 1024) sprintf(sizestr , "%dB" , size);
  else if (size < 1024 * 1024) sprintf(sizestr , "%dKB" , size/1024);
  else if (size < 1024 * 1024 * 1024) sprintf(sizestr, "%dMB" , size/(1024 * 1024));
  else sprintf(sizestr , "%dGB" , size/(1024 * 1024 * 1024));

  int mode = s -> st_mode;
  mode = mode % 512;


  const long int timeinsec = (s -> st_atime) - 14400;
  struct tm * realtime = gmtime(&timeinsec);
  char * dayofweek = malloc(10 * sizeof(char));

  switch (realtime -> tm_wday)
 {
     case 0: strcpy(dayofweek, "Sun");
             break;
     case 1: strcpy(dayofweek, "Mon");
             break;
     case 2: strcpy(dayofweek, "Tue");
             break;
     case 3: strcpy(dayofweek, "Wed");
             break;
     case 4: strcpy(dayofweek, "Thur");
             break;
     case 5: strcpy(dayofweek, "Fri");
             break;
     case 6: strcpy(dayofweek, "Sun");
             break;
 }

  char * month = malloc(20 * sizeof(char));

  switch (realtime -> tm_mon)
 {
     case 0: strcpy(month, "Jan");
             break;
     case 1: strcpy(month, "Feb");
            break;
     case 2: strcpy(month, "Mar");
             break;
     case 3: strcpy(month, "Apr");
             break;
     case 4: strcpy(month, "May");
             break;
     case 5: strcpy(month, "Jun");
             break;
     case 6: strcpy(month, "Jul");
             break;
     case 7: strcpy(month, "Aug");
             break;
     case 8: strcpy(month, "Sep");
             break;
     case 9: strcpy(month, "Oct");
             break;
     case 10: strcpy(month, "Nov");
             break;
     case 11: strcpy(month, "Dec");
             break;
 }
  int dayofmonth = realtime -> tm_mday;

  int hour = realtime -> tm_hour;
  char hourstr[10];
  if (hour >= 10) sprintf(hourstr, "%d", hour);
  else sprintf(hourstr, "%d%d", 0,  hour);

  int min = realtime -> tm_min;
  char minstr[10];
  if (min >= 10) sprintf(minstr, "%d", min);
  else sprintf(minstr, "%d%d", 0,  min);

  int sec = realtime -> tm_sec;
  char secstr[10];
  if (sec >= 10) sprintf(secstr, "%d", sec);
  else sprintf(secstr, "%d%d", 0,  sec);

  int year = realtime -> tm_year + 1900;

  char * firstperm = permissions(mode / 64 );

  char * secondperm =  permissions((mode / 8)%8);

  char * thirdperm = permissions(mode%8);

  printf("-%s%s%s l ", firstperm, secondperm, thirdperm );
  printf("%s ", sizestr);
  printf("%s %s %d %s:%s:%s %d a.out\n", dayofweek, month, dayofmonth, hourstr, minstr, secstr, year);
  return 0;

}
