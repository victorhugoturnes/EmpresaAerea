#ifndef AEROTRACKER_AERONAVE_COMPARATOR_H
#define AEROTRACKER_AERONAVE_COMPARATOR_H

#include "Aeronave.h"
#include <string.h>

/*
    Nome da Funcao : searchModelo
    Recebe como parametro uma string e um ponteiro de Aeronave
    Objetivo : faz a comparacao da string de forma generica
    Retorno : Boleana se existe a substring
 */
int searchModelo(char *str, Aeronave *aer);

#endif //AEROTRACKER_AERONAVE_COMPARATOR_H
