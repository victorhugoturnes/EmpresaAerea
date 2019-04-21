//
// Created by last on 3/7/19.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "string.h"

char *readString() {
    char *buffer = malloc(sizeof(char) * MAXSTR);
    scanf("%[^\n]%*c", buffer);
    buffer = realloc(buffer, strlen(buffer) * sizeof(char));
    return buffer;
}

char *updateString(char *original, char *update) {
//    return strcpy(realloc(original, (strlen(update)+1) * sizeof(char)), update);
    free(original);
    original = malloc(sizeof(char) * (strlen(update) + 1));
    original = strcpy(original, update);
    return original;
}

char *trim(char *src) {
    int i, j;
    char *newStr = malloc(strlen(src));
    strcpy(newStr, src);

    for (i = 0; isspace(src[i]) && src[i] != '\0'; i++);

    for (j = (int) strlen(src) - 1; isspace(src[j]) && j >= 0; j--)
        ;

    newStr[j+1] = '\0';

    strcpy(src, newStr+i);

    free(newStr);

    return src;
}
