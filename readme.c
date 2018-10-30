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
  printf("%d", size);
  return 0;
}
