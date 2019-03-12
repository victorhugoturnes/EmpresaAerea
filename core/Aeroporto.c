//
// Created by last on 3/12/19.
//

#include "Aeroporto.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

Aeroporto *createAeroporto(char *nome, char*sigla){
    if(!nome || !sigla) return NULL;
    if(strlen(sigla) != 3) return NULL;
    Aeroporto *aeroporto = malloc(sizeof(Aeroporto));
    aeroporto->nome = malloc(sizeof(char) * strlen(nome)+1);
    aeroporto->nome = strcpy(aeroporto->nome, nome);
    aeroporto->sigla = malloc(sizeof(char) * 4);
    aeroporto->sigla = strcpy(aeroporto->sigla, sigla);
    return aeroporto;
}

char *readAeroporto(Aeroporto *aeroporto){
    char buffer[MAX];
    int size;
    size = sprintf(buffer, "Aeroporto: %s - Sigla: %s", aeroporto->nome, aeroporto->sigla);
    char *str = malloc(sizeof(char) * size+1);
    strcpy(str, buffer);
    return str;
}

void updateAeroporto(Aeroporto *aeroporto, void *update, char* field){

}