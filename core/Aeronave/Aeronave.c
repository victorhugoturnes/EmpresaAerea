//
// Created by last on 3/7/19.
//

#include "Aeronave.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../input/string.h"

Aeronave *createAeronave(char *tipo, char *prefixo){
    if(!tipo || !prefixo) return NULL;
    if(strlen(prefixo) != 3) return NULL;

    Aeronave *Aeronave = malloc(sizeof(Aeronave));

    Aeronave->tipo = malloc(sizeof(char) * (strlen(tipo)+1));
    Aeronave->tipo = strcpy(Aeronave->tipo, tipo);

    Aeronave->prefixo = malloc(sizeof(char) * (strlen(prefixo)+1));
    Aeronave->prefixo = strcpy(Aeronave->prefixo, prefixo);

    return Aeronave;
}

char *readAeronave(Aeronave *Aeronave){
    char buffer[MAXSTR];
    int size;
    char *str;

    size = sprintf(buffer, "Aeronave: %s - prefixo: %s", Aeronave->tipo, Aeronave->prefixo);
    str = malloc(sizeof(char) * size+1);

    strcpy(str, buffer);
    return str;
}

void updateAeronave(Aeronave *Aeronave, void *update, char* field){
    if(!update) return;
    if(!strcmp("tipo", field)) {
        updateString(Aeronave->tipo, update);
    }
    if(!strcmp("prefixo", field)){
        Aeronave->prefixo = updateString(Aeronave->prefixo, update);
    }
}

void deleteAeronave(Aeronave **Aeronave){
    free((*Aeronave)->tipo);
    free((*Aeronave)->prefixo);
    free((*Aeronave));
    *Aeronave = NULL;
}
