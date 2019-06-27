#include "Cliente.h"

/*
    Nome da Funcao : createCliente
    Nao recebe Parametros
    Objetivo : Criar Cliente
    Retorno : Cliente criado
 */
Cliente *createCliente() {
    Cliente *novoCliente = (Cliente *) malloc(sizeof(Cliente));

    novoCliente->nomePrograma = NULL;
    novoCliente->nomeCliente = NULL;
    novoCliente->cpf = NULL;
    novoCliente->categoria = Nenhuma;
    novoCliente->saldoMilhas = 0;

    return novoCliente;
}

/*
    Nome da Funcao : clienteToString
    Recebe como parametro um ponteiro de Cliente
    Objetivo : ler e criar uma string contendo informacoes do Cliente
    Returno : devolver string dizendo quais as informacoes do Cliente
 */
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

/*
    Nome da Funcao : deleteCliente
    Recebe como parametro um ponteiro de ponteiro de Cliente
    Objetivo : Limpar memoria q esta sendo usada para alocar Cliente
    Retorno : Nada
 */
void deleteCliente(Cliente **pCliente) {
    free((*pCliente)->nomePrograma);
    free((*pCliente)->nomeCliente);
    free((*pCliente)->cpf);

    free(*pCliente);
    *pCliente = NULL;
}


/*
    Nome da Funcao : categoriaParaString
    Recebe como parametro uma Categoria
    Objetivo : retorna a string equivalente a categoria
    Retorno : string equivalente a categoria
 */
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
        case Prata:
            return "Prata";
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

/*
    Nome da Funcao : getCategoriaFromString
    Recebe como parametro uma  String
    Objetivo : retorna a categoria do cliente
    Retorno : Categoria do cliente
 */
Categoria getCategoriaFromString(char *cat) {
    int i;
    for (i = 0; i < CATEGORIA_LENGTH; ++i) {
        if (!strcmp(categoriaParaString((Categoria) i), cat))
            return (Categoria) i;
    }

    return Nenhuma;
}
