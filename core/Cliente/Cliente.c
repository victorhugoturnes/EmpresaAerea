//
// Created by last on 3/13/19.
//

#include "Cliente.h"

Cliente *createCliente() {
    Cliente *novoCliente = (Cliente *)malloc(sizeof(Cliente));

    novoCliente->nomePrograma = NULL;
    novoCliente->nomeCliente = NULL;
    novoCliente->cpf = NULL;
    novoCliente->categoria = Nenhuma;
    novoCliente->saldoMilhas = 0;

    return novoCliente;
}

void deleteCliente(Cliente **pCliente) {
    free((*pCliente)->nomePrograma);
    free((*pCliente)->nomeCliente);
    free((*pCliente)->cpf);

    free(*pCliente);
    *pCliente = NULL;
}
