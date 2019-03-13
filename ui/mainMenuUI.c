#include "mainMenuUI.h"
#include "../core/Aeroporto.h"
#include "../core/Aeronave.h"
#include "../input/string.h"
#include "../Environment.h"

/*!
	@brief mainMenuEscolha, apresenta opções para o usuário e recolhe \
	sua escolha
	@return escolha feita pelo usuário
	@precondition nenhuma
	@postcondition nenhuma
*/
char mainMenuEscolha() {
	char escolha, choiceList[3] = "0cs";

	/// apresenta tela de menu e lê da entrada padrão a escolha \
	do usuário
	telaMainMenu();
	printf("\n");
	printf("Opcao: ");
	fflush(stdin);
	scanf("%c", &escolha);

	/// se não é número, retorna a letra minuscula
	if(!isdigit(escolha)) return tolower(escolha);

	/// se for número, converte e retorna letra equivalente
	return choiceList[escolha-'0'];
}

/*!
	@brief telaMainMenu, apresenta tela de opções ao usuário
	@precondition nenhuma
	@postcondition nenhuma
*/
void telaMainMenu() {
	ClearScreen;

	printf("1) Menu (C)adastros\n");
	printf("2) Menu (S)tatus\n");
	printf("\n");
	printf("0) Sair do Programa\n");
}

void menuStatus() {
	ClearScreen;
	printf("menuStatus\n");
	printf("WORK IN PROGRESS...\n");
	ClearScreen;
}

void testarCadastros() {
	ClearScreen;

	char *read;

	Aeroporto *aeroporto = createAeroporto("aeroporto de teste 1", "aer");
	read = readAeroporto(aeroporto);
	printf("%s\n", read);
	free(read);

	updateAeroporto(aeroporto, "teste aeroporto 2", "nome");
	read = readAeroporto(aeroporto);
	printf("%s\n", read);
	free(read);

	updateAeroporto(aeroporto, "teste aeroporto 2", "sigla");
	read = readAeroporto(aeroporto);
	printf("%s\n", read);
	free(read);

	updateAeroporto(aeroporto, "123", "sigla");
	read = readAeroporto(aeroporto);
	printf("%s\n", read);
	free(read);

	deleteAeroporto(&aeroporto);
	printf("%d\n", aeroporto);


	Aeronave *aeronave = createAeronave("teste de aeronave 1", "aer");
	read = readAeronave(aeronave);
	printf("%s\n", read);
	free(read);

	updateAeronave(aeronave, "aeronave de teste 2", "tipo");
	read = readAeronave(aeronave);
	printf("%s\n", read);
	free(read);

	updateAeronave(aeronave, "aeronave de teste 2", "prefixo");
	read = readAeronave(aeronave);
	printf("%s\n", read);
	free(read);

	updateAeronave(aeronave, "123", "prefixo");
	read = readAeronave(aeronave);
	printf("%s\n", read);
	free(read);

	deleteAeronave(&aeronave);
	printf("%p\n", aeronave);

	Pause;
}

/*!
	@brief confirmacaoSaidaMainMenu, pergunta ao usuário se este confirma \
	saída do programa
	@precondition nenhuma
	@postcondition nenhuma
*/
char confirmacaoSaidaMainMenu() {
	char escolha = 0;

	/// pergunta ao usuário se deseja mesmo sair
	ClearScreen;
	printf("Voce deseja sair do programa?\n");
	printf("S / N\n");

	/// lê resposta do usuário
	fflush(stdin);
	scanf("%c", &escolha);
	escolha = tolower(escolha);

	/// enquanto resposta for inválida
	while(escolha != 's' && escolha != 'n') {
		/// limpa tela e pergunta confirmação de saida
		ClearScreen;
		printf("Escolha invalida!\n");
		printf("Voce deseja sair do programa?\n");
		printf("S / N\n");

		/// lê resposta do usuário
		fflush(stdin);
		scanf("%c", &escolha);
		escolha = tolower(escolha);
	}

	/// se usuário deseja sair, retorna 1
	if(escolha == 's') return 1;

	/// caso contrário, retorna 0
	return 0;
}
