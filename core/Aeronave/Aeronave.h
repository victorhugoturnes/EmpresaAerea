//
// Created by last on 3/7/19.
//

#ifndef AERONAVE_H
#define AERONAVE_H

#define MAX_MODELO_LENGTH 64

typedef struct aeronave {
    char *modelo;
    double comprimento, altura, envergadura, velocidadeCruzeiro, alcanceMaximo, qntAcentos, qntBanheiros;
} Aeronave;

Aeronave *createAeronave();

char *aeronaveToString(Aeronave *Aeronave);

void updateAeronave(Aeronave *Aeronave, void *update, char *field);

void deleteAeronave(Aeronave **Aeronave);

#endif //AERONAVE_H
