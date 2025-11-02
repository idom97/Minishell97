#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h> 
#include <sys/types.h> 
#include <ctype.h>
#include <signal.h>
#include <time.h>

#ifndef SYS_H
#define SYS_H
#define PROMPT "? "
typedef char *str;

struct commande {
    char **argv;
    str input;
    str output;
    int append;
    str err;
    int error_output;
    int background;
    int pipe;
    int argc;
};

enum {
    MaxLigne = 1024,
    MaxMot = MaxLigne / 2,
    MaxDirs = 100,
    MaxPathLength = 512,
};

extern char ligne[MaxLigne];
extern char pathname[MaxPathLength];
extern str mot[MaxMot];
extern str dirs[MaxDirs];
extern struct commande cmd, cmd1, cmd2;



#endif // SYS_H
