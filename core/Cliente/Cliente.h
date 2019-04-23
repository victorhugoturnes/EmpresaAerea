//
// Created by last on 3/13/19.
//

#ifndef CLIENTE_H
#define CLIENTE_H

#define MAX_NOMEPROGRAMA_LENGTH 64
#define MAX_NOMECLIENTE_LENGTH 64
#define MAX_CPF_LENGTH 12
#define CATEGORIA_LENGTH 9


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../input/string.h"

typedef enum Categoria {
    Nenhuma,
    Papel,
    Madeira,
    Pedra,
    Ferro,
    Ouro,
    Diamante,
    Obsidian,
    Bedrock
} Categoria;

typedef struct Cliente {
    char *nomePrograma, *nomeCliente;
    char *cpf;
    Categoria categoria;
    int saldoMilhas;
} Cliente;

Cliente *createCliente();

char *clienteToString(Cliente *cliente);

void deleteCliente(Cliente **pCliente);

char *categoriaParaString(Categoria categoria);

#endif //CLIENTE_H
