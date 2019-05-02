//
// Created by Jedson on 3/19/2019.
//

#ifndef AEROTRACKER_INSERIRCLIENTEUI_H
#define AEROTRACKER_INSERIRCLIENTEUI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../../../../../../Environment.h"
#include "../../../../../../input/string.h"
#include "../../../../../../core/Cliente/Cliente.h"
#include "../../../../../../core/Cliente/Comparator.h"

void inserirCliente();

void telaCabecalhoInserirCliente();

int lerNomePrograma(Cliente *cliente);

char ehValidoNomePrograma(char *nome);

int lerNomeCliente(Cliente *cliente);

char ehValidoNomeCliente(char *nome);

int lerCpf(Cliente *cliente);

char ehValidoCpf(char *cpf);

int lerCategoria(Cliente *cliente);

char mostrarCadastroClienteOpcoes(Cliente *cliente);

void alterarNovoCliente(Cliente *cliente);

char escolhaAlterarNovoCliente();

void telaAlterarNovoCliente();

char escolhaInserirCliente();

void telaRodapeInserirCliente();

int salvarNovoCliente(Cliente *cliente);

#endif //AEROTRACKER_INSERIRCLIENTEUI_H
