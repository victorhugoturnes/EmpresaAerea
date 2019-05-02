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

    size = sprintf(buffer, "Voo [%s]:\n\t- Origem: %s\n\t- Destino: %s\n\t- Partida: %s\n\t- Chegada: %s\n\t- Duracao: %s\n\t- Aeronave: %s\n",
                   voo->prefixo, aeroportoToString(voo->origem), aeroportoToString(voo->destino),
                   horaToString(voo->partida), horaToString(voo->chegada), horaToString(voo->duracao),
                   voo->aeronave->modelo);
    str = malloc(sizeof(char) * size + 1);

    strcpy(str, buffer);
    return str;
}

char *horaToString(Hora *hora) {
    char buffer[MAXSTR];
    int size;
    char *str;

    size = sprintf(buffer, "%02d:%02d", hora->hh, hora->mm);
    str = malloc(sizeof(char) * size + 1);

    strcpy(str, buffer);
    return str;
}
