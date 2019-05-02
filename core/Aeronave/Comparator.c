//
// Created by last on 4/19/19.
//

#include <stdio.h>
#include "Comparator.h"

int searchModelo(char *str, Aeronave *aer) {
    return (aer->modelo && strstr(aer->modelo, str) != NULL);
}

int sortModelo(Aeronave *src, Aeronave *dst) {
    return strcmp(src->modelo, dst->modelo);
}

