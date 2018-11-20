#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "func.h"


int main(){
  while (1){
  printf("Shell$ ");
  char line[128];
  scanf("%[^\n]s",line);
  char ** args = parse_args( line );
  execvp(args[0], args);
  return 0;
  }
}
