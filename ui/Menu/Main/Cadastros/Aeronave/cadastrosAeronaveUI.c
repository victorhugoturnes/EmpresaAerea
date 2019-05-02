//
// Created by Jedson on 3/19/2019.
//

#include "cadastrosAeronaveUI.h"
#include "Consultar/consultarAeronaveUI.h"

void cadastrosAeronave() {
    char escolha = 0;

    escolha = escolhaCadastrosAeronave();
    do {
        switch (escolha) {
            case 'i':
                inserirAeronave(NULL);
                break;
            case 'c':
                consultarAeronave();
                break;
            case '0':
                ClearScreen();
                printf("\nSaindo do menu de cadastros de aeronave.\n\n");
                Pause();
                break;
            default:
                printf("Nao eh uma opcao valida!\n\n");
                Pause();
                break;
        }

    } while (escolha != '0' && (escolha = escolhaCadastrosAeronave()));

}

char escolhaCadastrosAeronave() {
    char escolha[3], choiceList[] = "0ic";

    telaCadastrosAeronave();
    printf("\n");
    printf("Opcao: ");
    fflush(stdin);
    fgets(escolha, 2, stdin);

    if (!isdigit(escolha[0])) return (char) tolower(escolha[0]);

    return (char) ((escolha[0] - '0' < strlen(choiceList)) ? choiceList[escolha[0] - '0'] : 0);

}

void telaCadastrosAeronave() {
    ClearScreen();

    printf("Menu Cadastro de Aeronave:\n\n");

    printf("Escolha uma opcao:\n");
    printf("1) (I)nserir Aeronave\n");
    printf("2) (C)onsultar Aeronave\n");
    printf("\n");
    printf("0) Sair do Menu de Cadastros\n");
}
