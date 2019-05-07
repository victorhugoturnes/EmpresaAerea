#include "Cliente.h"

Cliente *createCliente() {
    Cliente *novoCliente = (Cliente *) malloc(sizeof(Cliente));

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

char *clienteToString(Cliente *cliente) {
    char buffer[MAXSTR];
    int size;
    char *str;

    size = sprintf(buffer, "Cliente %s:\n"
                           "\t- CPF: %s\n"
                           "\t- Programa: %s\n"
                           "\t- Rank: %s\n"
                           "\t- Saldo: %d\n",
                   cliente->nomeCliente, cliente->cpf, cliente->nomePrograma,
                   categoriaParaString(cliente->categoria), cliente->saldoMilhas);
    str = malloc(sizeof(char) * size + 1);

    strcpy(str, buffer);
    return str;
}


char *categoriaParaString(Categoria categoria) {
    switch (categoria) {
        case Nenhuma:
            return "Nenhuma";
        case Papel:
            return "Papel";
        case Madeira:
            return "Madeira";
        case Pedra:
            return "Pedra";
        case Ferro:
            return "Ferro";
        case Ouro:
            return "Ouro";
        case Diamante:
            return "Diamante";
        case Obsidian:
            return "Obsidian";
        case Bedrock:
            return "Bedrock";
    }

    return NULL;
}