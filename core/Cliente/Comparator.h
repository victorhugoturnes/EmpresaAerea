#ifndef AEROTRACKER_CLIENTE_COMPARATOR_H
#define AEROTRACKER_CLIENTE_COMPARATOR_H

#include "Cliente.h"
#include <string.h>

/*
    Nome da Funcao : searchCategoria
    Recebe como parametro uma string e um ponteiro de Cliente
    Objetivo : faz a comparacao da string de forma generica
    Retorno : Boleana se existe a substring
 */
int searchCategoria(Categoria *cat, Cliente *clie);

/*
    Nome da Funcao : searchCpf
    Recebe como parametro uma string e um ponteiro de Cliente
    Objetivo : faz a comparacao da string de forma generica
    Retorno : Boleana se existe a substring
 */
int searchCpf(char *str, Cliente *clie);

/*
    Nome da Funcao : searchNomeCliente
    Recebe como parametro uma string e um ponteiro de Cliente
    Objetivo : faz a comparacao da string de forma generica
    Retorno : Boleana se existe a substring
 */
int searchNomeCliente(char *str, Cliente *clie);

/*
    Nome da Funcao : searchNomePrograma
    Recebe como parametro uma string e um ponteiro de Cliente
    Objetivo : faz a comparacao da string de forma generica
    Retorno : Boleana se existe a substring
 */
int searchNomePrograma(char *str, Cliente *clie);

#endif //AEROTRACKER_CLIENTE_COMPARATOR_H
