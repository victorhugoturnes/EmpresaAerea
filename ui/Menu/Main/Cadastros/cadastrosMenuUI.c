#include "cadastrosMenuUI.h"

void menuCadastros() {
    char escolha = 0;

    escolha = escolhaCadastros();
    do {
        switch (escolha) {
            case 'v':
                cadastrosVoo();
                break;
            case 'c':
                cadastrosCliente();
                break;
            case 'a':
                cadastrosAeronave();
                break;
            case '0':
                ClearScreen();
                printf("\nSaindo do menu de cadastros.\n\n");
                Pause();
                break;
            default:
                printf("Nao eh uma opcao valida!\n\n");
                Pause();
                break;
        }

    } while (escolha != '0' && (escolha = escolhaCadastros()));
}

/*!
	@brief escolhaCadastros, apresenta opções para o usuário e recolhe \
	sua escolha
	@return escolha feita pelo usuário
	@precondition nenhuma
	@postcondition nenhuma
*/
char escolhaCadastros() {
    char escolha[3], choiceList[] = "0vca";

    telaCadastros();
    printf("\n");
    printf("Opcao: ");
    fflush(stdin);
    fgets(escolha, 2, stdin);

    if (!isdigit(escolha[0])) return (char) tolower(escolha[0]);

    return (char) ((escolha[0] - '0' < strlen(choiceList)) ? choiceList[escolha[0] - '0'] : 0);
}

/*!
	@brief telaCadastros, apresenta tela de opções ao usuário
	@precondition nenhuma
	@postcondition nenhuma
*/
void telaCadastros() {
    ClearScreen();

    printf("Menu Cadastro de Voo:\n\n");

    printf("Escolha uma opcao:\n");

    printf("1) Cadastrar (V)oo\n");
    printf("2) Cadastrar (C)liente\n");
    printf("4) Cadastrar (A)eronave\n");
    printf("\n");
    printf("0) Sair do Menu de Cadastros\n");
}