//
// Created by last on 3/7/19.
//

#include "string.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *readString(){
    char *buffer = malloc(sizeof(char) * BUFFER);
    scanf("%[^\n]%*c", buffer);
    buffer = realloc(buffer, strlen(buffer) * sizeof(char));
    return buffer;
}