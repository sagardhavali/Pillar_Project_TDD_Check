#ifndef ROMAN_H
#define ROMAN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int roman2integer(char *);
int indexofletter(char);
char * integer2roman(int);
void postdigit(char*, int*, char, int);
void predigit(char*, int*, char, char);
char * romanAddition(char*, char*);
char * romanSubtraction(char*, char*);

#endif
