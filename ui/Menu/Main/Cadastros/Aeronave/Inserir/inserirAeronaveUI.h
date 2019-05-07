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

void inserirAeronave(Aeronave *novaAeronave);

void telaCabecalhoInserirAeronave();

int lerModelo(Aeronave *aeronave);

char ehValidoModelo(char *nome);

int lerComprimento(Aeronave *aeronave);

int lerAltura(Aeronave *aeronave);

int lerEnvergadura(Aeronave *aeronave);

int lerVelocidadeCruzeiro(Aeronave *aeronave);

int lerAlcanceMaximo(Aeronave *aeronave);

int lerQntAcentos(Aeronave *aeronave);

int lerQntBanheiros(Aeronave *aeronave);

char mostrarCadastroAeronaveOpcoes(Aeronave *aeronave);

void alterarNovaAeronave(Aeronave *aeronave);

char escolhaAlterarNovaAeronave();

void telaAlterarNovaAeronave();

char escolhaInserirAeronave();

void telaRodapeInserirAeronave();

int salvarNovaAeronave(Aeronave *aeronave);

#endif //AEROTRACKER_INSERIRAERONAVEUI_H
