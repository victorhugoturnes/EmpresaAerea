#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "Aeroporto.h"
#include "../../input/string.h"

/*
    Nome da Funcao : createAeronave
    Recebe como parametro um ponteiro de char contendo a sigle e outro contendo o nome
    Objetivo : Criar aeroporto com modelo passado
    Retorno : Aeroporto criado
 */
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

/*
    Nome da Funcao : aeroportoToString
    Recebe como parametro um ponteiro de Aeroporto
    Objetivo : ler e criar uma string contendo informacoes do aeroporto
    Returno : devolver string dizendo quais as informacoes do aeroporto
 */
char *aeroportoToString(Aeroporto *aeroporto) {
    char buffer[MAXSTR];
    int size;
    char *str;

    size = sprintf(buffer, "Aeroporto (%s)%s", aeroporto->sigla, aeroporto->nome);
    str = malloc(sizeof(char) * size + 1);

    strcpy(str, buffer);
    return str;
}

/*
    Nome da Funcao : updateAeroporto
    Recebe como parametro um ponteiro de Aeroporto, um ponteiro de void e um ponteiro de char com novo modelo
    Objetivo : atualizar o modelo do Aeroporto
    Retorno : Nada
 */
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

    /*
        Nome da Funcao : deleteAeroporto
        Recebe como parametro um ponteiro de ponteiro de Aeroporto
        Objetivo : Limpar memoria q esta sendo usada para alocar Aeroporto
        Retorno : Nada
     */
void deleteAeroporto(Aeroporto **aeroporto) {
    free((*aeroporto)->nome);
    free((*aeroporto)->sigla);
    free((*aeroporto));
    *aeroporto = NULL;
}