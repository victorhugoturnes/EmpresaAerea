#ifndef AEROTRACKER_CONSULTARAERONAVE_H
#define AEROTRACKER_CONSULTARAERONAVE_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "Alterar/alterarAeronaveUI.h"
#include "Deletar/deletarAeronaveUI.h"
#include "../../../../../../Environment.h"
#include "../../../../../../input/string.h"
#include "../../../../../../core/Aeronave/Comparator.h"
#include "../../../../../../core/Aeronave/Aeronave.h"

void consultarAeronave();

char consultarAeronaveEscolha();

void telaConsultaAeronave();

void consultaModelo();

void mostrarResultadoPesquisaAeronave(List *searchResult);

Aeronave *menuEscolhaListaAeronave(List *listaAeronave);

void menuOpcoesAeronave(Aeronave *cliente);

void telaOpcoesAeronave();

char escolhaAeronave();

#endif //AEROTRACKER_CONSULTARAERONAVE_H
