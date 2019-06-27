#include <stdio.h>
#include "Comparator.h"

/*
    Nome da Funcao : searchModelo
    Recebe como parametro uma string e um ponteiro de Aeronave
    Objetivo : faz a comparacao da string de forma generica
    Retorno : Boleana se existe a substring
 */
int searchModelo(char *str, Aeronave *aer) {
    return (aer->modelo && strstr(aer->modelo, str) != NULL);
}
