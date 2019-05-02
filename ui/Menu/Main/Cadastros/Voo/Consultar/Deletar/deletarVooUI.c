//
// Created by Jedson on 5/2/2019.
//

#include "deletarVooUI.h"

void deletarVoo(VooInfo *voo) {
    List *tracer = NULL;

    if (!voo) return;

    for (tracer = ListaVoos; tracer; tracer = tracer->next) {
        if (tracer->active && !strcmp(((VooInfo *) tracer->info)->prefixo, voo->prefixo)) {
            tracer->active = 0;
            break;
        }
    }

    if (tracer) {
        printf("Voo deletado com sucesso!\n");
        Pause();
    }
}