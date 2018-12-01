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
    return execvp(args[0], args);
  }else{
    int status;
    wait(&status);
    return WEXITSTATUS(status);
  }
}

int main(){
  while(1){
    printf("Shell$ ");
    char line[128];
    fgets(line, 128, stdin);
    //for (int j = 0; line[j]; j++) {
    //  printf("%d| %c->", j, line[j]);
    //}
    char ** args = parse_args( line );
    for (int i = 0; args[i]; i++) {
    //   printf("running command #%d| %s\n", i, args[i] );
       run(space_args(args[i]));
    }
    // printf("%s", line);
  }
  return 0;
}
