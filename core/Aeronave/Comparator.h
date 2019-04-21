//
// Created by last on 4/19/19.
//

#ifndef AEROTRACKER_AERONAVE_COMPARATOR_H
#define AEROTRACKER_AERONAVE_COMPARATOR_H

#include "Aeronave.h"
#include <string.h>


int searchModelo(char *str, Aeronave *aer);

int sortModelo(Aeronave *src, Aeronave *dst);

#endif //AEROTRACKER_AERONAVE_COMPARATOR_H
