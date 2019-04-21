//
// Created by last on 4/19/19.
//

#include <stdio.h>
#include "Comparator.h"

int searchNome(char *str, Aeroporto *aer) {
    return strstr(aer->nome, str);
}

int searchSigla(char *str, Aeroporto *aer) {
    return strstr(aer->sigla, str);
}

int sortNome(Aeroporto *src, Aeroporto *dst) {
    return strcmp(src->nome, dst->modelo);
}

int sortSigla(Aeroporto *src, Aeroporto *dst) {
    return strcmp(src->sigla, dst->modelo);
}

