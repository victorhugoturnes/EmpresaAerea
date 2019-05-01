//
// Created by last on 4/19/19.
//

#ifndef AEROTRACKER_VOOINFO_COMPARATOR_H
#define AEROTRACKER_VOOINFO_COMPARATOR_H

#include "VooInfo.h"
#include <string.h>

int searchPrefixo(char *str, VooInfo *voo);

int sortPrefixo(VooInfo *src, VooInfo *dst);


#endif //AEROTRACKER_VOOINFO_COMPARATOR_H
