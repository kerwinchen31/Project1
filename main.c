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

int run(char **args){
  int a;
  a = fork();
  if (!a){
    execvp(args[0], args);
    return 0;
  }else{
    int status;
    wait(&status);
    return 0;
  }
}

int main(){
  while(1){
    printf("Shell$ ");
    char line[128];
    fgets(line, 128, stdin);
    char ** args = parse_args( line );
    run(args);
    printf("%s", line);
  }
  return 0;
}
