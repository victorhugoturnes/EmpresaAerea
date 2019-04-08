//
// Created by Jedson on 3/19/2019.
//

#include "cadastrosClienteUI.h"

void cadastrosCliente() {
    char escolha = 0;

    escolha = escolhaCadastrosCliente();
    do {
        switch (escolha) {
            case 'i':
                inserirCliente();
                break;
            case 'c':
//				consultarCliente();
                break;
            case '0':
                ClearScreen();
                printf("\nSaindo do menu de cadastros de voo.\n\n");
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
    char escolha, choiceList[] = "0ic";

    telaCadastrosCliente();
    printf("\n");
    printf("Opcao: ");
    fflush(stdin);
    scanf("%c", &escolha);

    if (!isdigit(escolha)) return (char) tolower(escolha);

    return choiceList[escolha - '0'];

}

void telaCadastrosCliente() {
    ClearScreen();

    printf("1) (I)nserir Cliente\n");
    printf("2) (C)onsultar Cliente\n");
    printf("\n");
    printf("0) Sair do Menu de Cadastros\n");
}
