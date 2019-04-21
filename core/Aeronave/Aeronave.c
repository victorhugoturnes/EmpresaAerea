//
// Created by last on 3/7/19.
//

#include "Aeronave.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "../../input/string.h"


/*
    Nome da Funcao : createAeronave
    Recebe como parametro um ponteiro de char contendo modelo da aeronave
    Objetivo : Criar aeronave com modelo passado
    Retorno : Aeronave criada
 */
Aeronave *createAeronave(char *modelo){
    if(!modelo) return NULL;

    Aeronave *Aeronave = malloc(sizeof(Aeronave));

    Aeronave->modelo = malloc(sizeof(char) * (strlen(modelo) + 1));
    Aeronave->modelo = strcpy(Aeronave->modelo, modelo);

    return Aeronave;
}
/*
    Nome da Funcao : readAeronave
    Recebe como parametro um ponteiro de Aeronave
    Objetivo : ler e criar uma string contendo qual o modelo da aeronave
    Returno : devolver string dizendo qual o modelo da aeronave
 */
char *readAeronave(Aeronave *Aeronave){
    char buffer[MAXSTR];
    int size;
    char *str;

    size = sprintf(buffer, "Aeronave: %s", Aeronave->modelo);
    str = malloc(sizeof(char) * size + 1);

    strcpy(str, buffer);
    return str;
}
/*
    Nome da Funcao : updateAeronave
    Recebe como parametro um ponteiro de Aeronave, um ponteiro de void e um ponteiro de char com novo modelo
    Objetivo : atualizar o modelo da aeronave
    Retorno : Nada
 */
void updateAeronave(Aeronave *Aeronave, void *update, char* field){
    if(!update) return;
    if(!strcmp("modelo", field)) {
        updateString(Aeronave->modelo, update);
    }
}

/*
    Nome da Funcao : deleteAeronave
    Recebe como parametro um ponteiro de ponteiro de Aeronave
    Objetivo : Limpar memoria q esta sendo usada para alocar Aeronave]
    Retorno : Nada
 */
void deleteAeronave(Aeronave **Aeronave){
    free((*Aeronave)->modelo);
    free((*Aeronave));
    *Aeronave = NULL;
}
