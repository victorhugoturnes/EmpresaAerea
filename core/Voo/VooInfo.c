#include <stdio.h>
#include "VooInfo.h"
#include "../../input/string.h"

VooInfo *createVooInfo() {
    VooInfo *novoVooInfo = (VooInfo *) malloc(sizeof(VooInfo));

    novoVooInfo->prefixo = NULL;
    novoVooInfo->origem = NULL;
    novoVooInfo->destino = NULL;

    novoVooInfo->partida = NULL;
    novoVooInfo->chegada = NULL;
    novoVooInfo->duracao = NULL;

    novoVooInfo->aeronave = NULL;

    return novoVooInfo;
}

Hora *createHora(char hh, char mm) {
    Hora *novaHora = (Hora *) malloc(sizeof(Hora));

    novaHora->hh = hh;
    novaHora->mm = mm;

    return novaHora;
}

void deleteHora(Hora **hora) {
    free(*hora);
    *hora = NULL;
}

char *vooInfoToString(VooInfo *voo) {
    char buffer[MAXSTR];
    int size;
    char *str;

    size = sprintf(buffer, "[%s] - Origem: %s - Destino: %s - Partida: %s - Chegada: %s - Duracao: %s - Aeronave: %s\n", voo->prefixo, aeroportoToString(voo->origem), aeroportoToString(voo->destino), horaToString(voo->partida), horaToString(voo->chegada), horaToString(voo->duracao), aeronaveToString(voo->aeronave));
    str = malloc(sizeof(char) * size + 1);

    strcpy(str, buffer);
    return str;
}

char *horaToString(Hora *hora) {
    char buffer[MAXSTR];
    int size;
    char *str;

    size = sprintf(buffer, "%2d:%2d\n", hora->hh, hora->mm);
    str = malloc(sizeof(char) * size + 1);

    strcpy(str, buffer);
    return str;
}
