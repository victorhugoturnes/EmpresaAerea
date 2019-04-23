//
// Created by last on 3/7/19.
//

#ifndef AERONAVE_H
#define AERONAVE_H


typedef struct aeronave {
    char *modelo;
} Aeronave;

Aeronave *createAeronave(char *modelo);

char *aeronaveToString(Aeronave *Aeronave);

void updateAeronave(Aeronave *Aeronave, void *update, char *field);

void deleteAeronave(Aeronave **Aeronave);

#endif //AERONAVE_H
