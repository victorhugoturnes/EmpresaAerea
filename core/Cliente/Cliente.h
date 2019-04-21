//
// Created by last on 3/13/19.
//

#ifndef CLIENTE_H
#define CLIENTE_H

#define MAX_NOMEPROGRAMA_LENGTH 64
#define MAX_NOMECLIENTE_LENGTH 64
#define MAX_CPF_LENGTH 12
#define CATEGORIA_LENGTH 8


#include "stdio.h"

#include "stdlib.h"

typedef enum Categoria {
    Nenhuma,
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

void deleteCliente(Cliente **pCliente);

#endif //CLIENTE_H