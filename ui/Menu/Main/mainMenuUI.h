#ifndef MAINMENUUI_H
#define MAINMENUUI_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "../../../Environment.h"
#include "../../../input/string.h"
#include "Cadastros/cadastrosMenuUI.h"
#include "../../../core/Aeronave/Aeronave.h"
#include "../../../core/Aeroporto/Aeroporto.h"

/*!
	@brief mainMenuEscolha, apresenta opções para o usuário e recolhe \
	sua escolha
	@return escolha feita pelo usuário
	@precondition nenhuma
	@postcondition nenhuma
*/
char mainMenuEscolha();

/*!
	@brief telaMainMenu, apresenta tela de opções ao usuário
	@precondition nenhuma
	@postcondition nenhuma
*/
void telaMainMenu();

// -- //

void menuStatus();

void testarCadastros();

/*!
	@brief confirmacaoSaidaMainMenu, pergunta ao usuário se este confirma \
	saída do programa
	@precondition nenhuma
	@postcondition nenhuma
*/
char confirmacaoSaidaMainMenu();

void populateLists();

void populateAeroportos();

void addAeroportoFromLine(char line[]);

void populateAeronaves();

void addAeronavesFromLine(char line[]);

void populateClientes();

void addClienteFromLine(char line[]);

void populateVoos();

void addVooFromLine(char line[]);

void populateMisto(const char *fileName);

#endif // MAINMENUUI_H