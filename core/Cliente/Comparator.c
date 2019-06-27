#include <stdio.h>
#include "Comparator.h"

/*
    Nome da Funcao : searchCategoria
    Recebe como parametro uma string e um ponteiro de Cliente
    Objetivo : faz a comparacao da string de forma generica
    Retorno : Boleana se existe a substring
 */
int searchCategoria(Categoria *cat, Cliente *cliente) {
    return cliente->categoria == *cat;
}

/*
    Nome da Funcao : searchCpf
    Recebe como parametro uma string e um ponteiro de Cliente
    Objetivo : faz a comparacao da string de forma generica
    Retorno : Boleana se existe a substring
 */
int searchCpf(char *str, Cliente *cliente) {
    return (strstr(cliente->cpf, str) != NULL);
}

/*
    Nome da Funcao : searchNomeCliente
    Recebe como parametro uma string e um ponteiro de Cliente
    Objetivo : faz a comparacao da string de forma generica
    Retorno : Boleana se existe a substring
 */
int searchNomeCliente(char *str, Cliente *cliente) {
    return (strstr(cliente->nomeCliente, str) != NULL);
}

/*
    Nome da Funcao : searchNomePrograma
    Recebe como parametro uma string e um ponteiro de Cliente
    Objetivo : faz a comparacao da string de forma generica
    Retorno : Boleana se existe a substring
 */
int searchNomePrograma(char *str, Cliente *cliente) {
    return (strstr(cliente->nomePrograma, str) != NULL);
}
