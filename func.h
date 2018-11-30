//#ifndef SHELL_H
//#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>

char ** parse_args( char *linee);

char ** space_args( char *line);


//#endif 
