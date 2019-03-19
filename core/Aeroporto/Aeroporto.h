//
// Created by last on 3/12/19.
//

#ifndef UNTITLED_AEROPORTO_H
#define UNTITLED_AEROPORTO_H

typedef struct aeroporto {
    char *nome;
    char *sigla;
} Aeroporto;

Aeroporto *createAeroporto(char *nome, char *sigla);

char *readAeroporto(Aeroporto *aeroporto);

void updateAeroporto(Aeroporto *aeroporto, void *update, char* field);

void deleteAeroporto(Aeroporto **aeroporto);

#endif //UNTITLED_AEROPORTO_H
