#ifndef VOOINFO_H
#define VOOINFO_H

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Aeroporto/Aeroporto.h"
#include "../Aeronave/Aeronave.h"
#include "../../input/string.h"

#define MAX_PREFIXO_LENGTH 16
#define MAX_AEROPORTO_NAME_LENGTH 64
#define MAX_AEROPORTO_SIGLA_LENGTH 4
#define MAX_MODELO_AERONAVE 64

typedef struct Hora {
    char hh, mm;
} Hora;

typedef struct VooInfo {
    char *prefixo;
    Aeroporto *origem, *destino;
    Hora *partida, *chegada, *duracao;
    Aeronave *aeronave;
} VooInfo;

VooInfo *createVooInfo();

char *vooInfoToString(VooInfo *voo);

Hora *createHora(char hh, char mm);

void deleteHora(Hora **hora);

char *horaToString(Hora *hora);

char *statusVoo(VooInfo *voo);

#endif // VOOINFO_H