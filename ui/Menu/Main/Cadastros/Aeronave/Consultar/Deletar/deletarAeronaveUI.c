//
// Created by Jedson on 4/30/2019.
//

#include "deletarAeronaveUI.h"

void deletarAeronave(Aeronave *aeronave) {
    List *tracer = NULL;

    if (!aeronave) return;

    for (tracer = ListaAeronaves; tracer; tracer = tracer->next) {
        if (tracer->active && !strcmp(((Aeronave *) tracer->info)->modelo, aeronave->modelo)) {
            tracer->active = 0;
            break;
        }
    }

    if (tracer) {
        printf("Aeronave deletada com sucesso!\n");
        Pause();
    }

}