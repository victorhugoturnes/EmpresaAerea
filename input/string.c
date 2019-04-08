//
// Created by last on 3/7/19.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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