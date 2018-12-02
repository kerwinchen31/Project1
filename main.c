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
  if (!strcmp(args[0], "cd")){
    char *dir = args[1];
    int new = chdir(dir);
  }
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
  int keepRunning = 1;
  while(keepRunning){
    //signal(SIGTERM, sighandler);
    printf("Shell$ ");
    char line[128];
    fgets(line, 128, stdin);
    //for (int j = 0; line[j]; j++) {
    //  printf("%d| %c->", j, line[j]);
    //}
    char ** args = parse_args( line );
    for (int i = 0; args[i]; i++) {
      if (!strcmp(args[i], "exit")){
	//keepRunning = 0;
	//printf("GOTCHA\n");
	exit(0);
      }
      run(space_args(args[i]));
      // printf("%s", line);
    }
  }
  return 0;
}
