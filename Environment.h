//
// Created by last on 3/13/19.
//

#ifndef UNTITLED_ENVIRONMENT_H
#define UNTITLED_ENVIRONMENT_H

#ifdef unix
#define ClearScreen() system("clear")
#endif

#ifdef _WIN32
#define ClearScreen() system("cls")
#endif

#define Pause() fflush(stdin); printf("Aperte qualquer tecla para continuar...\n"); getchar();

#define PrintaSeparador() printf("---------------------------\n");

#endif //UNTITLED_ENVIRONMENT_H
