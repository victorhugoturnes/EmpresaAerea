//
// Created by Jedson on 3/19/2019.
//

#include "cadastrosClienteUI.h"
#include "Consultar/consultarClienteUI.h"

void cadastrosCliente() {
    char escolha = 0;

    escolha = escolhaCadastrosCliente();
    do {
        switch (escolha) {
            case 'i':
                inserirCliente();
                break;
            case 'c':
                consultarCliente();
                break;
            case '0':
                ClearScreen();
                printf("\nSaindo do menu de cadastros de cliente.\n\n");
                Pause();
                break;
            default:
                printf("Nao eh uma opcao valida!\n\n");
                Pause();
                break;
        }

    } while (escolha != '0' && (escolha = escolhaCadastrosCliente()));

}

char escolhaCadastrosCliente() {
    char escolha[3], choiceList[] = "0ic";

    telaCadastrosCliente();
    printf("\n");
    printf("Opcao: ");
    fflush(stdin);
    fgets(escolha, 2, stdin);

    if (!isdigit(escolha[0])) return (char) tolower(escolha[0]);

    return (char) ((escolha[0] - '0' < strlen(choiceList)) ? choiceList[escolha[0] - '0'] : 0);

}

void telaCadastrosCliente() {
    ClearScreen();

    printf("Menu Cadastro de Cliente:\n\n");

    printf("Escolha uma opcao:\n");
    printf("1) (I)nserir Cliente\n");
    printf("2) (C)onsultar Cliente\n");
    printf("\n");
    printf("0) Sair do Menu de Cadastros\n");
}
