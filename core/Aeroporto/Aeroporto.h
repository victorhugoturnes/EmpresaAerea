//
// Created by last on 3/12/19.
//

#ifndef AEROPORTO_H
#define AEROPORTO_H

typedef struct aeroporto {
    char *nome;
    char *sigla;
} Aeroporto;

Aeroporto *createAeroporto(char *sigla, char *nome);

char *aeroportoToString(Aeroporto *aeroporto);

void updateAeroporto(Aeroporto *aeroporto, void *update, char *field);

void deleteAeroporto(Aeroporto **aeroporto);

#endif //AEROPORTO_H
