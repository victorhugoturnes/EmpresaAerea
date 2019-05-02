#ifndef INSERIRVOOUI_H
#define INSERIRVOOUI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../../../../../../core/Aeroporto/Comparator.h"
#include "../../../../../../core/Aeronave/Comparator.h"
#include "../../../../../../core/Voo/Comparator.h"
#include "../../../../../../core/Voo/VooInfo.h"
#include "../../../../../../input/string.h"
#include "../../../../../../Environment.h"

void inserirVoo();

void telaCabecalhoInserirVoo();

void lerPrefixoVoo(VooInfo *novoVoo);

char ehValidoPrefixo(char prefixo[]);

void lerOrigemVoo(VooInfo *novoVoo);

char ehValidoSiglaAeroporto(char sigla[]);

char ehValidoNomeAeroporto(char nome[]);

void lerDestinoVoo(VooInfo *novoVoo);

Aeroporto *procurarAeroportoSigla(char *sigla);

void lerPartidaVoo(VooInfo *novoVoo);

char ehValidoHorario(Hora *horario);

void lerChegadaVoo(VooInfo *novoVoo);

void lerDuracaoVoo(VooInfo *novoVoo);

void lerModeloAeronaveVoo(VooInfo *novoVoo);

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