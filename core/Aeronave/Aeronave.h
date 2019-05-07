#ifndef AERONAVE_H
#define AERONAVE_H

#define MAX_MODELO_LENGTH 64

typedef struct aeronave {
    char *modelo;
    double comprimento, altura, envergadura, velocidadeCruzeiro, alcanceMaximo;
    int qntAcentos, qntBanheiros;
} Aeronave;

Aeronave *createAeronave();

char *aeronaveToString(Aeronave *aeronave);

void updateAeronave(Aeronave *aeronave, void *update, char *field);

void deleteAeronave(Aeronave **aeronave);

#endif //AERONAVE_H
