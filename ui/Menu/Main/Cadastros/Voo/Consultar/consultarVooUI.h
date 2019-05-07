#ifndef AEROTRACKER_CONSULTARVOOUI_H
#define AEROTRACKER_CONSULTARVOOUI_H


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "Alterar/alterarVooUI.h"
#include "Deletar/deletarVooUI.h"
#include "../../../../../../Environment.h"
#include "../../../../../../input/string.h"
#include "../../../../../../core/Voo/Comparator.h"
#include "../../../../../../core/Voo/VooInfo.h"

void consultarVoo();

char consultarVooEscolha();

void telaConsultaVoo();

void consultaPrefixo();

void mostrarResultadoPesquisaVoo(List *searchResult);

VooInfo *menuEscolhaListaVoo(List *listaVoo);

void menuOpcoesVoo(VooInfo *cliente);

void telaOpcoesVoo();

char escolhaVoo();

#endif //AEROTRACKER_CONSULTARVOOUI_H
