//
// Created by last on 3/7/19.
//

#include "../core Headers/Aeronave.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../input/string.h"

Aeronave *createAeronave(char *modelo){
    if(!modelo) return NULL;

    Aeronave *Aeronave = malloc(sizeof(Aeronave));

    Aeronave->modelo = malloc(sizeof(char) * (strlen(modelo)+1));
    Aeronave->modelo = strcpy(Aeronave->modelo, modelo);

    return Aeronave;
}

char *readAeronave(Aeronave *Aeronave){
    char buffer[MAXSTR];
    int size;
    char *str;

    size = sprintf(buffer, "Aeronave: %s", Aeronave->modelo);
    str = malloc(sizeof(char) * size+1);

    strcpy(str, buffer);
    return str;
}

void updateAeronave(Aeronave *Aeronave, void *update, char* field){
    if(!update) return;
    if(!strcmp("modelo", field)) {
        updateString(Aeronave->modelo, update);
    }
}

void deleteAeronave(Aeronave **Aeronave){
    free((*Aeronave)->modelo);
    free((*Aeronave));
    *Aeronave = NULL;
}
