#ifndef INSERIRVOOUI_H
#define INSERIRVOOUI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../../../../../../core/Voo/VooInfo.h"
#include "../../../../../../Environment.h"

void vooInserir();

void telaCabecalhoVooInserir();

void printaSeparador();

void lerPrefixoVoo(VooInfo *novoVoo);

char ehValidoPrefixo(char prefixo[]);

void lerOrigemVoo(VooInfo *novoVoo);

char ehValidoSiglaAeroporto(char sigla[]);

char ehValidoNomeAeroporto(char nome[]);

void lerDestinoVoo(VooInfo *novoVoo);

void lerPartidaVoo(VooInfo *novoVoo);

char ehValidoHorario(Hora horario);

void lerChegadaVoo(VooInfo *novoVoo);

void lerDuracaoVoo(VooInfo *novoVoo);

void lerModeloAeronaveVoo(VooInfo *novoVoo);

char ehValidoModeloAeronave(char modeloAeronave[]);

char escolhaVooInserir(VooInfo *novoVoo);

void telaRodapeVooInserir();

char mostrarCadastroVooOpcoes(VooInfo *novoVoo);

#endif // INSERIRVOOUI_H