//
// Created by Jedson on 5/2/2019.
//

#include "statusMenuUI.h"

void menuStatus() {
    ClearScreen();
    printf("menuStatus\n");

    printaVoos();

    ClearScreen();
}

void printaVoos() {
    VooInfo *currentVoo = NULL;
    List *tracer = NULL;

    printf("|%-12s|%-18s|%-32s|%-32s|%-5s|\n", "PREFIXO", "STATUS", "ORIGEM", "DESTINO", "SAIDA");
    for (tracer = ListaVoos; tracer && tracer->active; tracer = tracer->next) {
        currentVoo = tracer->info;
        printf("|%-12s|%-18s|%-32s|%-32s|%-5s|\n",
               currentVoo->prefixo, statusVoo(currentVoo), aeroportoToString(currentVoo->origem),
               aeroportoToString(currentVoo->destino), horaToString(currentVoo->partida));
    }

    Pause();
}
