#ifndef AEROTRACKER_AEROPORTO_COMPARATOR_H
#define AEROTRACKER_AEROPORTO_COMPARATOR_H

#include "Aeroporto.h"
#include <string.h>

int searchNome(char *str, Aeroporto *aer);

int searchSigla(char *str, Aeroporto *aer);

int sortNome(Aeroporto *src, Aeroporto *dst);

int sortSigla(Aeroporto *src, Aeroporto *dst);

#endif //AEROTRACKER_AEROPORTO_COMPARATOR_H
