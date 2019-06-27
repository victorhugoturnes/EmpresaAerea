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
    Prata,
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

/*
    Nome da Funcao : createCliente
    Nao recebe Parametros
    Objetivo : Criar Cliente
    Retorno : Cliente criado
 */
Cliente *createCliente();

/*
    Nome da Funcao : clienteToString
    Recebe como parametro um ponteiro de Cliente
    Objetivo : ler e criar uma string contendo informacoes do Cliente
    Returno : devolver string dizendo quais as informacoes do Cliente
 */
char *clienteToString(Cliente *cliente);

/*
    Nome da Funcao : deleteCliente
    Recebe como parametro um ponteiro de ponteiro de Cliente
    Objetivo : Limpar memoria q esta sendo usada para alocar Cliente
    Retorno : Nada
 */
void deleteCliente(Cliente **pCliente);

/*
    Nome da Funcao : categoriaParaString
    Recebe como parametro uma Categoria
    Objetivo : retorna a string equivalente a categoria
    Retorno : string equivalente a categoria
 */
char *categoriaParaString(Categoria categoria);

/*
    Nome da Funcao : getCategoriaFromString
    Recebe como parametro uma  String
    Objetivo : retorna a categoria do cliente
    Retorno : Categoria do cliente
 */
Categoria getCategoriaFromString(char *cat);

#endif //CLIENTE_H
