//
// Created by last on 4/19/19.
//

#include <stdio.h>
#include "Comparator.h"

int searchCategoria(Categoria cat, Cliente *clie) {
    return clie->categoria == cat;
}

int sortCategoria(Cliente *src, Cliente *dst) {
    if(dst->categoria <  src->categoria) return -1;
    return src->categoria > dst->categoria;
}

int searchCpf(char *str, Cliente *clie) {
    return (strstr(clie->cpf, str) != NULL);
}

int sortCpf(Cliente *src, Cliente *dst) {
    return strcmp(src->cpf, dst->cpf);
}

int searchNomeCliente(char *str, Cliente *clie) {
    return (strstr(clie->nomeCliente, str) != NULL);
}

int sortNomeCliente(Cliente *src, Cliente *dst) {
    return strcmp(src->nomeCliente, dst->nomeCliente);
}

int searchNomePrograma(char *str, Cliente *clie) {
    return (strstr(clie->nomePrograma, str) != NULL);
}

int sortNomePrograma(Cliente *src, Cliente *dst) {
    return strcmp(src->nomePrograma, dst->nomePrograma);
}

