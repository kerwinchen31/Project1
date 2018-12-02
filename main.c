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
    /* for (int g = 0; g < 3; g++){ */
    /*   printf("%s\n", args[g]); */
    /* } */
    /* if (!(strcmp(args[1], ">") && args[1])){ */
    /*   int greater = 1; */
    /*   int k = 0;/\* */
    /* 		  for (; k < 100; k++){ */
    /* 		  printf("hello\n"); */
    /* 		  printf("yes %s\n", args[k]); */
    /* 		  if (!strcmp(args[k],">")){ */
    /* 		  greater = 1; */
    /* 		  printf("GREATERR %d\n",greater);  */
    /* 		  } */
    /* 		  }*\/ */
    /*   /\*char ** a[50]; */
    /* 	for (int x = 0; x < k; x ++){ */
    /* 	a[x] = args[x]; */
    /* 	}*\/ */
    /*   int fd; */
    /*   int backup = dup(1); */
    /*   fd = open(args[2], O_CREAT | O_WRONLY, 777); */
    /*   dup2(fd, 1); */
    /*   char * temp = args[0]; */
    /*   printf("hello\n"); */
    /*   close(fd); */
    /*   dup2(backup, 1); */
    /*   return 7; */
    /* }else{ */
    /*   return execvp(args[0], args); */
    /* } */
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
    printf("%s Shell~$ ", getcwd(0,0));
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
      char ** input = space_args(args[i]);
      run(input);
      // printf("%s", line);
    }
  }
  
  return 0;
}
