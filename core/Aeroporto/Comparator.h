#ifndef AEROTRACKER_AEROPORTO_COMPARATOR_H
#define AEROTRACKER_AEROPORTO_COMPARATOR_H

#include "Aeroporto.h"
#include <string.h>

/*
    Nome da Funcao : searchSigla
    Recebe como parametro uma string e um ponteiro de Aeroporto
    Objetivo : faz a comparacao da string de forma generica
    Retorno : Boleana se existe a substring
 */
int searchSigla(char *str, Aeroporto *aer);

#endif //AEROTRACKER_AEROPORTO_COMPARATOR_H
