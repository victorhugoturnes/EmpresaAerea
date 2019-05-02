//
// Created by last on 4/19/19.
//

#include <stdio.h>
#include "Comparator.h"

int searchCategoria(Categoria *cat, Cliente *cliente) {
    return cliente->categoria == *cat;
}

int sortCategoria(Cliente *src, Cliente *dst) {
    if (dst->categoria < src->categoria) return -1;
    return src->categoria > dst->categoria;
}

int searchCpf(char *str, Cliente *cliente) {
    return (strstr(cliente->cpf, str) != NULL);
}

int sortCpf(Cliente *src, Cliente *dst) {
    return strcmp(src->cpf, dst->cpf);
}

int searchNomeCliente(char *str, Cliente *cliente) {
    return (strstr(cliente->nomeCliente, str) != NULL);
}

int sortNomeCliente(Cliente *src, Cliente *dst) {
    return strcmp(src->nomeCliente, dst->nomeCliente);
}

int searchNomePrograma(char *str, Cliente *cliente) {
    return (strstr(cliente->nomePrograma, str) != NULL);
}

int sortNomePrograma(Cliente *src, Cliente *dst) {
    return strcmp(src->nomePrograma, dst->nomePrograma);
}

