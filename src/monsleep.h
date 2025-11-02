#include "sys.h"
#ifndef MONSLEEP_H
#define MONSLEEP_H



void invalid(char *prog, char *s);

void dring(int n);

unsigned int sleep(unsigned int nsec);

void monsleep(int ac, char *av[]);


#endif // MONSLEEP_H