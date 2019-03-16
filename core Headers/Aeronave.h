//
// Created by last on 3/7/19.
//

#ifndef UNTITLED_CORE_H
#define UNTITLED_CORE_H


typedef struct aeronave{
    char *modelo;
}Aeronave;

Aeronave *createAeronave(char *modelo);

char *readAeronave(Aeronave *Aeronave);

void updateAeronave(Aeronave *Aeronave, void *update, char* field);

void deleteAeronave(Aeronave **Aeronave);

#endif //UNTITLED_CORE_H
