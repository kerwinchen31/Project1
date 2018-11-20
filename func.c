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

  char *dummy = malloc(strlen(line) * sizeof(char));
  strcpy(dummy, line);

  char **separated = calloc( 1025 , sizeof(char*) );
	
  for (int i = 0; dummy; i++) { 
    separated[i] = strsep(&dummy, " "); 
  }

  return separated;	
}
