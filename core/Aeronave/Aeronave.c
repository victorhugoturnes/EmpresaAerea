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
Aeronave *createAeronave() {
    Aeronave *aeronave = malloc(sizeof(Aeronave));

    aeronave->modelo = NULL;
    aeronave->comprimento = -1;
    aeronave->altura = -1;
    aeronave->envergadura = -1;
    aeronave->velocidadeCruzeiro = -1;
    aeronave->alcanceMaximo = -1;
    aeronave->qntAcentos = -1;
    aeronave->qntBanheiros = -1;

    return aeronave;
}

/*
    Nome da Funcao : aeronaveToString
    Recebe como parametro um ponteiro de Aeronave
    Objetivo : ler e criar uma string contendo qual o modelo da aeronave
    Returno : devolver string dizendo qual o modelo da aeronave
 */
char *aeronaveToString(Aeronave *aeronave) {
    char buffer[MAXSTR];
    int size;
    char *str;

    size = sprintf(buffer, "Aeronave %s:\n"
                           "\t- Comprimento: %.2lf\n"
                           "\t- Altura: %.2lf\n"
                           "\t- Envergadura: %.2lf\n"
                           "\t- Alcance maximo: %.2lf\n"
                           "\t- Quantidade de acentoa: %d\n"
                           "\t- Quantidade de banheiros: %d\n",
                   aeronave->modelo, aeronave->comprimento, aeronave->altura,
                   aeronave->envergadura, aeronave->alcanceMaximo, aeronave->qntAcentos,
                   aeronave->qntBanheiros);
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
void updateAeronave(Aeronave *aeronave, void *update, char *field) {
    if (!update) return;
    if (!strcmp("modelo", field)) {
        updateString(aeronave->modelo, update);
    }
}

/*
    Nome da Funcao : deleteAeronave
    Recebe como parametro um ponteiro de ponteiro de Aeronave
    Objetivo : Limpar memoria q esta sendo usada para alocar Aeronave]
    Retorno : Nada
 */
void deleteAeronave(Aeronave **aeronave) {
    free((*aeronave)->modelo);
    free((*aeronave));
    *aeronave = NULL;
}
