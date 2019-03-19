#include "VooCadastros.h"

void vooCadastros() {
	char escolha = 0;

	escolha = escolhaVooCadastros();
	do {
		switch(escolha) {
			case 'i':
                vooInserir();
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

	} while(escolha != '0' && (escolha = escolhaVooCadastros()));
}

char escolhaVooCadastros() {
	char escolha, choiceList[] = "0ic";

	telaVooCadastros();
	printf("\n");
	printf("Opcao: ");
	fflush(stdin);
	scanf("%c", &escolha);

	if(!isdigit(escolha)) return (char) tolower(escolha);

	return choiceList[escolha-'0'];
}

void telaVooCadastros() {
	ClearScreen();

	printf("1) (I)nserir VooCadastro\n");
	printf("2) (C)onsultar VooCadastro\n");
	printf("\n");
	printf("0) Sair do Menu de Cadastros\n");
}
