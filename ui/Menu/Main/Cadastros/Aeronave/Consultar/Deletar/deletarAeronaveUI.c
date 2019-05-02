//
// Created by Jedson on 4/30/2019.
//

#include "deletarAeronaveUI.h"

void deletarAeronave(Aeronave *aeronave) {
    List *tracer = NULL;
    char escolha[3];

    if (!aeronave) return;

    do {
        printf("Tem certeza que deseja deletar esta aeronave?\n");
        printf("Y/N\n");

        fflush(stdin);
        fgets(escolha, 3, stdin);
    } while (toupper(escolha[0]) == 'Y' || toupper(escolha[0]) == 'N');

    if (toupper(escolha[0]) == 'N') return;

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