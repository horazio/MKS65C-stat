#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(){
  struct stat * s = malloc(sizeof(struct stat));
  if(stat("./readme.c", s) == 0){
    printf("\n--Creates stat successfully--\n");
  }else{
    printf("\nfailure\n");
  }
  int size = s -> st_size;
  double time = s -> st_atime;
  int mode = s -> st_mode;

  int base_time = 1540872000;
  char * month = "Nov";
  char * year = "2018";
  int day = (time - base_time) / (3600 * 24);
  char * week[7] = {"Thu", "Fri", "Sat", "Sun", "Mon", "Tue", "Wed"};
  char * dayweek = "Wed";
  if(day < 2){
    day = 31;
    month = "Oct";
  }else{
    day -= 2;
    dayweek = week[day % 7];
    day++;
  }
  
  printf("%s %s %d\n\n", dayweek, month, day);
  return 0;
}
