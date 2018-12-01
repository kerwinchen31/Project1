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

char ** parse_args(char * linee) {
  char * line = malloc(strlen(linee) * sizeof(char));
  strncpy(line, linee, sizeof(linee) - 1);
  if ( (linee[strlen(linee)-2] == ';') || (linee[strlen(linee)-2] == ' ') ){
    line[sizeof(linee)-2] = '\0';
  }
  else {
    line[sizeof(linee)-1] = '\0';
  }
  printf("made line%sx\n", line);
  char * copy = malloc(strlen(line) * sizeof(char));
  int i, j = 0;
  while (i < strlen(line)) {
    if (line[i] == ' ') {
      if (i == 0) {
        while (line[i] == ' ') {
          i++;
        }
      }
      while (line[i + 1] == ' ') {
        i++;
      }
      if (line[i + 1] == ';') {
        i++;
      }
    }
    copy[j] = line[i];
    if (line[i] == ';') {
      while (line[i + 1] == ' ') {
        i++;
      }
      if (line[i + 1] == '\0') {
        j++;
        break;
      }
    }
    if (line[i + 1] == '\0') {
      break;
    }
    i++;
    j++;
  }
  copy[j] = '\0';
  i = 0;
  j = 0;
  printf("%sx\n", copy);
  printf("bb%c\n", copy[strlen(copy) - 1]);
  if (copy[strlen(copy) - 1] == ';') {
    copy[strlen(copy) - 1] = '\0';
  }
  char ** separated = calloc(6, sizeof(char * ));
  while (copy) {
    separated[i] = strsep( & copy, ";");
    i++;
  }
  separated[i] = NULL;
  while (separated[j]) {
    printf("%s|", separated[j]);
    j++;
  }
  printf("\n");
  return separated;
}

char ** space_args( char *line) {

  // I don't want to modify line.
  char *dummy = malloc(strlen(line) * sizeof(char));
  strcpy(dummy, line);

    // At most 5 arguments of strings (array of chars / char pointers) 
  char **separated = calloc( 6 , sizeof(char*) );
  
  for (int i = 0; dummy; i++) { 
  // i is the current arg of separated, dummy keeps getting split until you hit the NULL at the end
    separated[i] = strsep(&dummy, " "); 
    printf("%sx\n", separated[i]);
  }

  return separated; 
}