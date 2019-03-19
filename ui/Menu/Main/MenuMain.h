#ifndef MAINMENUUI_H
#define MAINMENUUI_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "../../../Environment.h"
#include "../../../input/string.h"
#include "Cadastros/MenuCadastros.h"
#include "../../../core/Aeronave/Aeronave.h"
#include "../../../core/Aeroporto/Aeroporto.h"
/*!
	@brief menuMainEscolha, apresenta opções para o usuário e recolhe \
	sua escolha
	@return escolha feita pelo usuário
	@precondition nenhuma
	@postcondition nenhuma
*/
char menuMainEscolha();

/*!
	@brief telaMenuMain, apresenta tela de opções ao usuário
	@precondition nenhuma
	@postcondition nenhuma
*/
void telaMenuMain();

// -- //

void menuStatus();

void testarCadastros();

/*!
	@brief confirmacaoSaidaMenuMain, pergunta ao usuário se este confirma \
	saída do programa
	@precondition nenhuma
	@postcondition nenhuma
*/
char confirmacaoSaidaMenuMain();

#endif // MAINMENUUI_H