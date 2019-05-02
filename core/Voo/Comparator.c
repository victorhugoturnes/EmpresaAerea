//
// Created by last on 4/19/19.
//

#include <stdio.h>
#include "Comparator.h"

int searchPrefixo(char *str, VooInfo *voo) {
    return (voo->prefixo && strstr(str, voo->prefixo) != NULL);
}

int sortPrefixo(VooInfo *src, VooInfo *dst) {
    return (strcmp(src->prefixo, dst->prefixo));
}

