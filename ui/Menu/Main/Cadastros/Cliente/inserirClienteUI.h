//
// Created by Jedson on 3/19/2019.
//

#ifndef AEROTRACKER_INSERIRCLIENTEUI_H
#define AEROTRACKER_INSERIRCLIENTEUI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../../../../../Environment.h"
#include "../../../../../input/string.h"
#include "../../../../../core/Cliente/Cliente.h"

void inserirCliente();

void telaCabecalhoInserirCliente();

void lerNomePrograma(Cliente *novoCliente);

char ehValidoNomePrograma(char *nome);

void lerNomeCliente(Cliente *novoCliente);

char ehValidoNomeCliente(char *nome);

void lerCpf(Cliente *novoCliente);

char ehValidoCpf(char *cpf);

void lerCategoria(Cliente *novoCliente);

char *categoriaParaString(Categoria categoria);

char mostrarCadastroClienteOpcoes(Cliente *novoCliente);

void alterarNovoCliente(Cliente *novoCliente);

char escolhaAlterarNovoCliente();

void telaAlterarNovoCliente();

char escolhaInserirCliente(Cliente *novoCliente);

void telaRodapeInserirCliente();

#endif //AEROTRACKER_INSERIRCLIENTEUI_H
