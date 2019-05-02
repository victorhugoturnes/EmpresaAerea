//
// Created by Jedson on 5/2/2019.
//

#include "deletarVooUI.h"

void deletarVoo(VooInfo *voo) {
    List *tracer = NULL;
    char escolha[3];

    if (!voo) return;

    do {
        printf("Tem certeza que deseja deletar este voo?\n");
        printf("Y/N\n");

        fflush(stdin);
        fgets(escolha, 3, stdin);
    } while (toupper(escolha[0]) == 'Y' || toupper(escolha[0]) == 'N');

    if (toupper(escolha[0]) == 'N') return;

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