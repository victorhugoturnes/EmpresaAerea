//
// Created by Jedson on 4/30/2019.
//

#include "deletarClienteUI.h"

void deletarCliente(Cliente *cliente) {
    List *tracer = NULL;
    char escolha[3];

    if (!cliente) return;

    do {
        printf("Tem certeza que deseja deletar este cliente?\n");
        printf("Y/N\n");

        fflush(stdin);
        fgets(escolha, 3, stdin);
    } while (toupper(escolha[0]) != 'Y' && toupper(escolha[0]) != 'N');

    if (toupper(escolha[0]) == 'N') return;

    for (tracer = ListaClientes; tracer; tracer = tracer->next) {
        if (tracer->active && !strcmp(((Cliente *) tracer->info)->cpf, cliente->cpf)) {
            tracer->active = 0;
            break;
        }
    }

    if (tracer) {
        printf("Cliente deletado com sucesso!\n");
        Pause();
    }
}