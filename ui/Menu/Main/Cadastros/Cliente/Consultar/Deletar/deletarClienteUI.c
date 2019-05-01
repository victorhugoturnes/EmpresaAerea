//
// Created by Jedson on 4/30/2019.
//

#include "deletarClienteUI.h"

void deletarCliente(Cliente *cliente) {
    List *tracer = NULL;

    if(!cliente) return;

    for (tracer = ListaClientes; tracer; tracer = tracer->next) {
        if (tracer->active && !strcmp(((Cliente *) tracer->info)->cpf, cliente->cpf)) {
            tracer->active = 0;
            break;
        }
    }

    if(tracer) {
        printf("Cliente deletado com sucesso!\n");
        Pause();
    }

}