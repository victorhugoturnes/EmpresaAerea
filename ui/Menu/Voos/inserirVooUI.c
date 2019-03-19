#include "inserirVooUI.h"

void inserirVoo() {
	VooInfo *novoVoo = createVooInfo();
	char cadastroConcluido = 0;

	while(!cadastroConcluido) {
		telaCabecalhoInserirVoo();

		if(novoVoo->prefixo == NULL) {
			printaSeparador();
			lerPrefixoVoo(novoVoo);
			continue;
		} else {
			printf("Prefixo: %s\n", novoVoo->prefixo);
		}

		if(novoVoo->origem == NULL) {
			printaSeparador();
			lerOrigemVoo(novoVoo);
			continue;
		} else {
			printf("Origem: (%s)%s\n", novoVoo->origem->sigla, novoVoo->origem->nome);
		}

		if(novoVoo->destino == NULL) {
			printaSeparador();
			lerDestinoVoo(novoVoo);
			continue;
		} else {
			printf("Destino: (%s)%s\n", novoVoo->destino->sigla, novoVoo->destino->nome);
		}

		if(novoVoo->partida == NULL) {
			printaSeparador();
			lerPartidaVoo(novoVoo);
			continue;
		} else {
			printf("Partida: %02d:%02d\n", novoVoo->partida->hh, novoVoo->partida->mm);
		}

		if(novoVoo->chegada == NULL) {
			printaSeparador();
			lerChegadaVoo(novoVoo);
			continue;
		} else {
			printf("Chegada: %02d:%02d\n", novoVoo->chegada->hh, novoVoo->chegada->mm);
		}

		if(novoVoo->duracao == NULL) {
			printaSeparador();
			lerDuracaoVoo(novoVoo);
			continue;
		} else {
			printf("Duracao: %02d:%02d\n", novoVoo->duracao->hh, novoVoo->duracao->mm);
		}

		if(novoVoo->aeronave == NULL) {
			printaSeparador();
			lerModeloAeronaveVoo(novoVoo);
			continue;
		} else {
			printf("Modelo aeronave: %s\n", novoVoo->aeronave->modelo);
		}

		cadastroConcluido = mostrarCadastroVooOpcoes(novoVoo);

	}
}

void telaCabecalhoInserirVoo() {
	ClearScreen();

	printf("Insira as informacoes do voo a seguir.\n");
	printf("\n");
}

void printaSeparador() {
	printf("---------------------------\n");
}

void lerPrefixoVoo(VooInfo *novoVoo) {
	char prefixo[MAX_PREFIXO_LENGTH];
	printf("Prefixo: ");
	fflush(stdin);
	scanf("%[^\n]%*c", prefixo);

	if(!ehValidoPrefixo(prefixo)) {
		printf("\nPrefixo fornecido e invalido!\n");
		Pause();

		return;
	}

	novoVoo->prefixo = updateString(NULL, prefixo);
}

char ehValidoPrefixo(char prefixo[]) {
	return (prefixo[0] != '\0' && strlen(prefixo) < MAX_PREFIXO_LENGTH);
}

void lerOrigemVoo(VooInfo *novoVoo) {
	char origemSigla[MAX_AEROPORTO_SIGLA_LENGTH];
	char origemNome[MAX_AEROPORTO_NAME_LENGTH];
	printf("Sigla Origem: ");
	fflush(stdin);
	scanf("%[^\n]%*c", origemSigla);

	if(!ehValidoSiglaAeroporto(origemSigla)) {
		printf("\nSigla fornecida e invalida!\n");
		Pause();

		return;
	}

	printf("Origem: ");
	fflush(stdin);
	scanf("%[^\n]%*c", origemNome);

	if(!ehValidoNomeAeroporto(origemNome)) {
		printf("\nOrigem fornecida e invalida!\n");
		Pause();

		return;
	}

	novoVoo->origem = createAeroporto(origemNome, origemNome);
}

char ehValidoSiglaAeroporto(char sigla[]) {
	if(strlen(sigla) < MAX_AEROPORTO_SIGLA_LENGTH) {
		return (isalpha(sigla[0]) && isalpha(sigla[1]) && isalpha(sigla[2]));
	}
	return 0;
}

char ehValidoNomeAeroporto(char nome[]) {
	int i;

	if(nome[0] != '\0' && strlen(nome) < MAX_AEROPORTO_NAME_LENGTH) {
		for(i = 0; nome[i]; ++i) {
			if(!isalnum(nome[i]) && nome[i] != ' ') return 0;
		}
		return 1;
	}
	return 0;
}

void lerDestinoVoo(VooInfo *novoVoo) {
	char destinoSigla[MAX_AEROPORTO_SIGLA_LENGTH];
	char destinoNome[MAX_AEROPORTO_NAME_LENGTH];
	printf("Sigla Destino: ");
	fflush(stdin);
	scanf("%[^\n]%*c", destinoSigla);

	if(!ehValidoSiglaAeroporto(destinoSigla)) {
		printf("\nSigla fornecida e invalida!\n");
		Pause();

		return;
	}


	if(!strcmp(novoVoo->origem->sigla, destinoSigla)) {
		printf("\nDestino e origem nao podem ser o mesmo!\n");
		Pause();

		return;
	}

	printf("Destino: ");
	fflush(stdin);
	scanf("%[^\n]%*c", destinoNome);

	if(!ehValidoNomeAeroporto(destinoNome)) {
		printf("\nDestino fornecido e invalido!\n");
		Pause();

		return;
	}

	novoVoo->destino = createAeroporto(destinoNome, destinoSigla);
}

void lerPartidaVoo(VooInfo *novoVoo) {
	int readCheck = 0, hh, mm;
	Hora *horario;

	printf("Horario da partida (hh:mm): ");
	fflush(stdin);
	scanf("%d:%d%n", &hh, &mm, &readCheck);
	horario = createHora((char) hh, (char) mm);

	if(!readCheck || !ehValidoHorario(horario)) {
		printf("\nHorario de partida fornecido e invalido!\n");
		Pause();

		return;
	}

	novoVoo->partida = horario;
}

char ehValidoHorario(Hora *horario) {
	return (horario->hh >= 0 && horario->hh < 24 &&
		horario->mm >= 0 && horario->mm < 59);
}

void lerChegadaVoo(VooInfo *novoVoo) {
	int readCheck = 0, hh, mm;
	Hora *horario;

	printf("Horario de chegada (hh:mm): ");
	fflush(stdin);
	scanf("%d:%d%n", &hh, &mm, &readCheck);
	horario = createHora((char) hh, (char) mm);

	if(!readCheck || !ehValidoHorario(horario)) {
		printf("\nHorario de chegada fornecido e invalido!\n");
		Pause();

		return;
	}

	novoVoo->chegada = horario;
}

void lerDuracaoVoo(VooInfo *novoVoo) {
	int readCheck = 0, hh, mm;
	Hora *horario;

	printf("Duracao do voo (hh:mm): ");
	fflush(stdin);
	scanf("%d:%d%n", &hh, &mm, &readCheck);
	horario = createHora((char) hh, (char) mm);

	if(!readCheck || !ehValidoHorario(horario)) {
		printf("\nDuracao fornecida e invalida!\n");
		Pause();

		return;
	}

	novoVoo->duracao = horario;
}

void lerModeloAeronaveVoo(VooInfo *novoVoo) {
	char aeronaveModelo[MAXSTR];

	printf("Modelo aeronave: ");
	fflush(stdin);
	scanf("%[^\n]%*c", aeronaveModelo);

	if(!ehValidoModeloAeronave(aeronaveModelo)) {
		printf("\nAeronave fornecida e invalida!\n");
		Pause();

		return;
	}

	novoVoo->aeronave = createAeronave(aeronaveModelo);
}

char ehValidoModeloAeronave(char modeloAeronave[]) {
	int i;
	if(modeloAeronave[0] != '\0' && strlen(modeloAeronave) < MAX_MODELO_AERONAVE) {
		for(i = 0; modeloAeronave[i]; ++i) {
			if(!isalnum(modeloAeronave[i]) && modeloAeronave[i] != ' ') return 0;
		}
		return 1;
	}
	return 0;
}

char mostrarCadastroVooOpcoes(VooInfo *novoVoo) {
	char escolha = 0;

	escolha = escolhaInserirVoo(novoVoo);
	switch(escolha) {
		case 's':
//			salvarVoo(novoVoo);
			printaSeparador();
			printf("Funcionalidade ainda nao implementada!\n");
			printaSeparador();
			Pause();
			return 0;
		case 'a':
//			alterarVoo();
			printaSeparador();
			printf("Funcionalidade ainda nao implementada!\n");
			printaSeparador();
			Pause();
			return 0;
		case 'c':
		case '0':
			ClearScreen();
			printf("\nSaindo do menu de cadastro de voo.\n\n");
			Pause();
			return 1;
		default:
			printaSeparador();
			printf("Nao eh uma opcao valida!\n\n");
			printaSeparador();
			Pause();
			return 0;
	}
}

char escolhaInserirVoo(VooInfo *novoVoo) {
	char escolha, choiceList[4] = "0sa";

	printaSeparador();
	telaRodapeInserirVoo();
	printf("\n");
	printf("Opcao: ");
	fflush(stdin);
	scanf("%c", &escolha);

	if(!isdigit(escolha)) return (char) tolower(escolha);

	return choiceList[escolha-'0'];
}

void telaRodapeInserirVoo() {
	printf("1) (S)alvar - 2) (A)lterar\n");
	printf("0) (C)ancelar Cadastro\n");
}