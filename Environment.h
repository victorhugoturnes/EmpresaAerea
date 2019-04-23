//
// Created by last on 3/13/19.
//

#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "core/List/Operations/List.h"

#ifdef unix
#define ClearScreen() system("clear")
#endif

#ifdef _WIN32
#define ClearScreen() system("cls")
#endif

#define Pause() fflush(stdin); printf("Aperte qualquer tecla para continuar...\n"); getchar();

#define PrintaSeparador() printf("---------------------------\n");

#ifndef GLOBAL_LISTS
#define GLOBAL_LISTS
extern List *ListaClientes;
extern List *ListaVoos;
#endif

#endif //ENVIRONMENT_H
