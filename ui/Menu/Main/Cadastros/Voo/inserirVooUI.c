#include "inserirVooUI.h"

void inserirVoo() {
    VooInfo *novoVoo = createVooInfo();
    char cadastroConcluido = 0;

    while (!cadastroConcluido) {
        telaCabecalhoInserirVoo();

        if (novoVoo->prefixo == NULL) {
            PrintaSeparador();
            lerPrefixoVoo(novoVoo);
            continue;
        } else {
            printf("Prefixo: %s\n", novoVoo->prefixo);
        }

        if (novoVoo->origem == NULL) {
            PrintaSeparador();
            lerOrigemVoo(novoVoo);
            continue;
        } else {
            printf("Origem: (%s)%s\n", novoVoo->origem->sigla, novoVoo->origem->nome);
        }

        if (novoVoo->destino == NULL) {
            PrintaSeparador();
            lerDestinoVoo(novoVoo);
            continue;
        } else {
            printf("Destino: (%s)%s\n", novoVoo->destino->sigla, novoVoo->destino->nome);
        }

        if (novoVoo->partida == NULL) {
            PrintaSeparador();
            lerPartidaVoo(novoVoo);
            continue;
        } else {
            printf("Partida: %02d:%02d\n", novoVoo->partida->hh, novoVoo->partida->mm);
        }

        if (novoVoo->chegada == NULL) {
            PrintaSeparador();
            lerChegadaVoo(novoVoo);
            continue;
        } else {
            printf("Chegada: %02d:%02d\n", novoVoo->chegada->hh, novoVoo->chegada->mm);
        }

        if (novoVoo->duracao == NULL) {
            PrintaSeparador();
            lerDuracaoVoo(novoVoo);
            continue;
        } else {
            printf("Duracao: %02d:%02d\n", novoVoo->duracao->hh, novoVoo->duracao->mm);
        }

        if (novoVoo->aeronave == NULL) {
            PrintaSeparador();
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

void lerPrefixoVoo(VooInfo *novoVoo) {
    char prefixo[MAX_PREFIXO_LENGTH];
    printf("Prefixo: ");
    fflush(stdin);
    fgets(prefixo, MAX_PREFIXO_LENGTH, stdin);
    trim(prefixo);

    if (!ehValidoPrefixo(prefixo)) {
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
    fgets(origemSigla, MAX_AEROPORTO_SIGLA_LENGTH, stdin);
    trim(origemSigla);

    if (!ehValidoSiglaAeroporto(origemSigla)) {
        printf("\nSigla fornecida e invalida!\n");
        Pause();

        return;
    }

    printf("Origem: ");
    fflush(stdin);
    fgets(origemNome, MAX_AEROPORTO_NAME_LENGTH, stdin);
    trim(origemNome);

    if (!ehValidoNomeAeroporto(origemNome)) {
        printf("\nOrigem fornecida e invalida!\n");
        Pause();

        return;
    }

    novoVoo->origem = createAeroporto(origemNome, origemNome);
}

char ehValidoSiglaAeroporto(char sigla[]) {
    if (strlen(sigla) < MAX_AEROPORTO_SIGLA_LENGTH) {
        return (isalpha(sigla[0]) && isalpha(sigla[1]) && isalpha(sigla[2]));
    }
    return 0;
}

char ehValidoNomeAeroporto(char nome[]) {
    int i;

    if (nome[0] != '\0' && strlen(nome) < MAX_AEROPORTO_NAME_LENGTH) {
        for (i = 0; nome[i]; ++i) {
            if (!isalnum(nome[i]) && nome[i] != ' ') return 0;
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
    fgets(destinoSigla, MAX_AEROPORTO_NAME_LENGTH, stdin);
    trim(destinoSigla);

    if (!ehValidoSiglaAeroporto(destinoSigla)) {
        printf("\nSigla fornecida e invalida!\n");
        Pause();

        return;
    }


    if (!strcmp(novoVoo->origem->sigla, destinoSigla)) {
        printf("\nDestino e origem nao podem ser o mesmo!\n");
        Pause();

        return;
    }

    printf("Destino: ");
    fflush(stdin);
    fgets(destinoNome, MAX_AEROPORTO_NAME_LENGTH, stdin);
    trim(destinoNome);

    if (!ehValidoNomeAeroporto(destinoNome)) {
        printf("\nDestino fornecido e invalido!\n");
        Pause();

        return;
    }

    novoVoo->destino = createAeroporto(destinoNome, destinoSigla);
}

void lerPartidaVoo(VooInfo *novoVoo) {
    int hh, mm;
    Hora *horario;
    char buff[MAXSTR], *shh, *smm;

    printf("Horario da partida (hh:mm): ");
    fflush(stdin);
    fgets(buff, MAXSTR, stdin);
    trim(buff);

    shh = strtok(buff, ":");
    smm = strtok(NULL, ":");

    hh = strtol(shh, NULL, 10);
    mm = strtol(smm, NULL, 10);

    horario = createHora((char) hh, (char) mm);

    if (!ehValidoHorario(horario)) {
        printf("\nHorario de partida fornecido e invalido!\n");
        free(horario);
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
    int hh, mm;
    Hora *horario;
    char buff[MAXSTR], *shh, *smm;

    printf("Horario de chegada (hh:mm): ");
    fflush(stdin);
    fgets(buff, MAXSTR, stdin);
    trim(buff);

    shh = strtok(buff, ":");
    smm = strtok(NULL, ":");

    hh = strtol(shh, NULL, 10);
    mm = strtol(smm, NULL, 10);
    horario = createHora((char) hh, (char) mm);

    if (!ehValidoHorario(horario)) {
        printf("\nHorario de chegada fornecido e invalido!\n");
        Pause();

        return;
    }

    novoVoo->chegada = horario;
}

void lerDuracaoVoo(VooInfo *novoVoo) {
    int hh, mm;
    Hora *horario;
    char buff[MAXSTR], *shh, *smm;

    printf("Duracao do voo (hh:mm): ");
    fflush(stdin);
    fgets(buff, MAXSTR, stdin);
    trim(buff);

    shh = strtok(buff, ":");
    smm = strtok(NULL, ":");

    hh = strtol(shh, NULL, 10);
    mm = strtol(smm, NULL, 10);
    horario = createHora((char) hh, (char) mm);

    if (!ehValidoHorario(horario)) {
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

    if (!ehValidoModeloAeronave(aeronaveModelo)) {
        printf("\nAeronave fornecida e invalida!\n");
        Pause();

        return;
    }

    novoVoo->aeronave = createAeronave(aeronaveModelo);
}

char ehValidoModeloAeronave(char modeloAeronave[]) {
    int i;
    if (modeloAeronave[0] != '\0' && strlen(modeloAeronave) < MAX_MODELO_AERONAVE) {
        for (i = 0; modeloAeronave[i]; ++i) {
            if (!isalnum(modeloAeronave[i]) && modeloAeronave[i] != ' ') return 0;
        }
        return 1;
    }
    return 0;
}

char mostrarCadastroVooOpcoes(VooInfo *novoVoo) {
    char escolha = 0;

    escolha = escolhaInserirVoo(novoVoo);
    switch (escolha) {
        case 's':
//			salvarNovoVoo(novoVoo);
            PrintaSeparador();
            printf("Funcionalidade ainda nao implementada!\n");
            PrintaSeparador();
            Pause();
            return 0;
        case 'a':
            alterarNovoVoo(novoVoo);
            return 0;
        case 'c':
        case '0':
            ClearScreen();
            printf("\nSaindo do menu de cadastro de voo.\n\n");
            Pause();
            return 1;
        default:
            PrintaSeparador();
            printf("Nao eh uma opcao valida!\n\n");
            PrintaSeparador();
            Pause();
            return 0;
    }
}

char escolhaInserirVoo(VooInfo *novoVoo) {
    char escolha, choiceList[] = "0sa";

    PrintaSeparador();
    telaRodapeInserirVoo();
    printf("\n");
    printf("Opcao: ");
    fflush(stdin);
    scanf("%c", &escolha);

    if (!isdigit(escolha)) return (char) tolower(escolha);

    return choiceList[escolha - '0'];
}

void telaRodapeInserirVoo() {
    printf("1) (S)alvar - 2) (A)lterar\n");
    printf("0) (C)ancelar Cadastro\n");
}

void alterarNovoVoo(VooInfo *novoVoo) {
    char escolha = 0;

    escolha = escolhaAlterarNovoVoo();
    do {
        switch (escolha) {
            case 1: //< prefixo
                free(novoVoo->prefixo);
                novoVoo->prefixo = NULL;
                break;
            case 2: //< aeroporto origem
                deleteAeroporto(&novoVoo->origem);
                break;
            case 3: //< aeroporto destino
                deleteAeroporto(&novoVoo->destino);
                break;
            case 4: //< hora partida
                deleteHora(&novoVoo->partida);
                break;
            case 5: //< hora chegada
                deleteHora(&novoVoo->chegada);
                break;
            case 6: //< duração
                deleteHora(&novoVoo->duracao);
                break;
            case 7: //< aeronave
                deleteAeronave(&novoVoo->aeronave);
                break;
            default:
                break;
        }
        if (escolha >= 1 && escolha <= 7)
            escolha = 0;
    } while (escolha != 0 && (escolha = escolhaAlterarNovoVoo()));
}

char escolhaAlterarNovoVoo() {
    char escolha;

    telaAlterarNovoVoo();
    printf("\n");
    printf("Opcao: ");
    fflush(stdin);
    scanf("%c", &escolha);

    if (!isdigit(escolha)) return -1;

    return (char) (escolha - '0');
}

void telaAlterarNovoVoo() {
    ClearScreen();

    printf("Selecione o campo a ser alterado:\n\n");

    printf("1) Prefixo\t\t2) Aeroporto de Origem\n");
    printf("3) Aeroporto de Destino\t4) Hora da Partida\n");
    printf("5) Hora da Chegada\t6) Duracao do Voo\n");
    printf("7) Aeronave Utilizada\n");

    printf("\n");
    printf("0) Cancelar alteracao\n");
}
