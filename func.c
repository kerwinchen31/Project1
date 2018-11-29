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

char ** parse_args( char *line) {

  //Reduce multiple spaces to single spaces 
  char *copy = malloc(strlen(line) * sizeof(char));
  int i,j=0;
  while (i < strlen(line) ) {
    copy[j] = line[i];
    if ( line[i] == ' ' ) {
      while ( line[i+1] == ' ') {
        i++;
      }
    }
    i++;
    j++;
  }
  copy[j] = '\0';
  i = 0;
  j = 0;

  //Every * of separated holds a command put within semicolons  
  char **separated = calloc( 6 , sizeof(char*) );

  while (copy) {
    separated[i] = strsep(&copy, ";");
    i++; 
  }
  separated[i] = NULL;

  return separated; 


}
