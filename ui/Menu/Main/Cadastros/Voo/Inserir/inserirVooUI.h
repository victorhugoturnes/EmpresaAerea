#ifndef INSERIRVOOUI_H
#define INSERIRVOOUI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../../../../../../core/Aeroporto/Comparator.h"
#include "../../../../../../core/Aeronave/Comparator.h"
#include "../../Aeronave/Inserir/inserirAeronaveUI.h"
#include "../../../../../../core/Voo/Comparator.h"
#include "../../../../../../core/Voo/VooInfo.h"
#include "../../../../../../input/string.h"
#include "../../../../../../Environment.h"

void inserirVoo();

void telaCabecalhoInserirVoo();

int lerPrefixoVoo(VooInfo *novoVoo);

char ehValidoPrefixo(char prefixo[]);

int lerOrigemVoo(VooInfo *novoVoo);

char ehValidoSiglaAeroporto(char sigla[]);

char ehValidoNomeAeroporto(char nome[]);

int lerDestinoVoo(VooInfo *novoVoo);

Aeroporto *procurarAeroportoSigla(char *sigla);

int lerPartidaVoo(VooInfo *novoVoo);

char ehValidoHorario(Hora *horario);

int lerChegadaVoo(VooInfo *novoVoo);

int lerDuracaoVoo(VooInfo *novoVoo);

int lerModeloAeronaveVoo(VooInfo *novoVoo);

Aeronave *procurarAeronaveModelo(char *modelo);

char ehValidoModeloAeronave(char modeloAeronave[]);

char escolhaInserirVoo();

char mostrarCadastroVooOpcoes(VooInfo *novoVoo);

void telaRodapeInserirVoo();

void alterarNovoVoo(VooInfo *novoVoo);

char escolhaAlterarNovoVoo();

void telaAlterarNovoVoo();

int salvarNovoVoo(VooInfo *novoVoo);

#endif // INSERIRVOOUI_H