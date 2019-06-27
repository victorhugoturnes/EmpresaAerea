#include <stdio.h>
#include "Comparator.h"

/*
    Nome da Funcao : searchSigla
    Recebe como parametro uma string e um ponteiro de Aeroporto
    Objetivo : faz a comparacao da string de forma generica
    Retorno : Boleana se existe a substring
 */
int searchSigla(char *str, Aeroporto *aer) {
    return (aer->nome && strstr(aer->sigla, str) != NULL);
}
