#ifndef STRING_H
#define STRING_H

#define MAXSTR 255

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *readString();

char *updateString(char *original, char *update);

char *trim(char *src);

double stringToDouble(const char *str, int b);

#endif //STRING_H
