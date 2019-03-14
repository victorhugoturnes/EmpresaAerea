#include "VooCadastros.h"

void cadastrosVoo() {
	char escolha = 0;

	escolha = escolhaCadastrosVoo();
	do {
		switch(escolha) {
			case 'i':
				inserirVoo();
				break;
			case 'c':
//				consultarVoo();
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

	} while(escolha != '0' && (escolha = escolhaCadastrosVoo()));
}

char escolhaCadastrosVoo() {
	char escolha, choiceList[3] = "0ic";

	telaCadastrosVoo();
	printf("\n");
	printf("Opcao: ");
	fflush(stdin);
	scanf("%c", &escolha);

	if(!isdigit(escolha)) return tolower(escolha);

	return choiceList[escolha-'0'];
}

void telaCadastrosVoo() {
	ClearScreen();

	printf("1) (I)nserir VooCadastro\n");
	printf("2) (C)onsultar VooCadastro\n");
	printf("\n");
	printf("0) Sair do Menu de Cadastros\n");
}
