#include <stdio.h>
#include "VooInfo.h"

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