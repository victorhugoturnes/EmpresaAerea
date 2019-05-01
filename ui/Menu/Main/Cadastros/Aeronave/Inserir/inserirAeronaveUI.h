//
// Created by Jedson on 3/19/2019.
//

#ifndef AEROTRACKER_INSERIRAERONAVEUI_H
#define AEROTRACKER_INSERIRAERONAVEUI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../../../../../../Environment.h"
#include "../../../../../../input/string.h"
#include "../../../../../../core/Aeronave/Aeronave.h"
#include "../../../../../../core/aeronave/Comparator.h"

void inserirAeronave();

void telaCabecalhoInserirAeronave();

void lerModelo(Aeronave *aeronave);

char ehValidoModelo(char *nome);

char mostrarCadastroAeronaveOpcoes(Aeronave *aeronave);

void alterarNovaAeronave(Aeronave *aeronave);

char escolhaAlterarNovaAeronave();

void telaAlterarNovaAeronave();

char escolhaInserirAeronave();

void telaRodapeInserirAeronave();

int salvarNovaAeronave(Aeronave *aeronave);

#endif //AEROTRACKER_INSERIRAERONAVEUI_H
