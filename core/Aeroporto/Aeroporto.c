//
// Created by last on 3/12/19.
//

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "Aeroporto.h"
#include "../../input/string.h"

Aeroporto *createAeroporto(char *sigla, char *nome) {
    if (!nome || !sigla) return NULL;
    if (strlen(sigla) != 3) return NULL;

    Aeroporto *aeroporto = malloc(sizeof(Aeroporto));

    aeroporto->nome = malloc(sizeof(char) * strlen(nome) + 1);
    aeroporto->nome = strcpy(aeroporto->nome, nome);

    aeroporto->sigla = malloc(sizeof(char) * 4);
    aeroporto->sigla = strcpy(aeroporto->sigla, sigla);

    return aeroporto;
}

char *aeroportoToString(Aeroporto *aeroporto) {
    char buffer[MAXSTR];
    int size;
    char *str;

    size = sprintf(buffer, "Aeroporto (%s)%s", aeroporto->sigla, aeroporto->nome);
    str = malloc(sizeof(char) * size + 1);

    strcpy(str, buffer);
    return str;
}

void updateAeroporto(Aeroporto *aeroporto, void *update, char *field) {
    if (!update) return;
    if (!strcmp("nome", field)) {
        aeroporto->nome = updateString(aeroporto->nome, update);
    }
    if (!strcmp("sigla", field)) {
        if (strlen(update) != 3) return;
        aeroporto->sigla = updateString(aeroporto->sigla, update);
    }
}

void deleteAeroporto(Aeroporto **aeroporto) {
    free((*aeroporto)->nome);
    free((*aeroporto)->sigla);
    free((*aeroporto));
    *aeroporto = NULL;
}