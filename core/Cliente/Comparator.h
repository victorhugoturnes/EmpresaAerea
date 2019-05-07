#ifndef AEROTRACKER_CLIENTE_COMPARATOR_H
#define AEROTRACKER_CLIENTE_COMPARATOR_H

#include "Cliente.h"
#include <string.h>

int searchCategoria(Categoria *cat, Cliente *clie);

int sortCategoria(Cliente *src, Cliente *dst);

int searchCpf(char *str, Cliente *clie);

int sortCpf(Cliente *src, Cliente *dst);

int searchNomeCliente(char *str, Cliente *clie);

int sortNomeCliente(Cliente *src, Cliente *dst);

int searchNomePrograma(char *str, Cliente *clie);

int sortNomePrograma(Cliente *src, Cliente *dst);

#endif //AEROTRACKER_CLIENTE_COMPARATOR_H
