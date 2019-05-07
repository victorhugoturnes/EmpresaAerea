#ifndef AEROTRACKER_CONSULTARCLIENTE_H
#define AEROTRACKER_CONSULTARCLIENTE_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "Alterar/alterarClienteUI.h"
#include "Deletar/deletarClienteUI.h"
#include "../../../../../../Environment.h"
#include "../../../../../../input/string.h"
#include "../../../../../../core/Cliente/Comparator.h"

void consultarCliente();

char consultarClienteEscolha();

void telaConsultaCliente();

void consultaNomePrograma();

void consultaNome();

void consultaCPF();

void consultaCategoria();

void mostrarResultadoPesquisaCliente(List *searchResult);

Cliente *menuEscolhaListaCliente(List *listaCliente);

void menuOpcoesCliente(Cliente *cliente);

void telaOpcoesCliente();

char escolhaCliente();

#endif //AEROTRACKER_CONSULTARCLIENTE_H
