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
            case 'n':
//				cadastrosAeronave();
                break;
            case 'p':
//                cadastrosAeroporto();
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
    char escolha, choiceList[] = "0vcpn";

    telaCadastros();
    printf("\n");
    printf("Opcao: ");
    fflush(stdin);
    scanf("%c", &escolha);

    if (!isdigit(escolha)) return (char) tolower(escolha);

    return choiceList[escolha - '0'];
}

/*!
	@brief telaCadastros, apresenta tela de opções ao usuário
	@precondition nenhuma
	@postcondition nenhuma
*/
void telaCadastros() {
    ClearScreen();

    printf("1) Cadastrar (V)oo\n");
    printf("2) Cadastrar (C)liente\n");
    printf("3) Cadastrar Aero(p)orto\n");
    printf("4) Cadastrar Aero(n)ave\n");
    printf("\n");
    printf("0) Sair do Menu de Cadastros\n");
}