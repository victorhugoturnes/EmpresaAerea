//
// Created by last on 3/12/19.
//

#ifndef UNTITLED_AEROPORTO_H
#define UNTITLED_AEROPORTO_H
#define MAX 255

typedef struct aeroporto{
    char *nome;
    char *sigla;
}Aeroporto;

Aeroporto *createAeroporto(char *nome, char*sigla);

char *readAeroport(Aeroporto *aeroporto);

#endif //UNTITLED_AEROPORTO_H
