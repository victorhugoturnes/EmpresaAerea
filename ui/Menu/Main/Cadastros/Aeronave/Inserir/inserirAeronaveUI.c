//
// Created by Jedson on 3/19/2019.
//

#include "inserirAeronaveUI.h"

void inserirAeronave() {
    Aeronave *novaAeronave = createAeronave();
    char cadastroConcluido = 0;

    while (!cadastroConcluido) {
        telaCabecalhoInserirAeronave();

        if (novaAeronave->modelo == NULL) {
            lerModelo(novaAeronave);
            PrintaSeparador();
            continue;
        } else {
            printf("Nome do Programa: %s\n", novaAeronave->modelo);
        }

        cadastroConcluido = mostrarCadastroAeronaveOpcoes(novaAeronave);
    }
}

void telaCabecalhoInserirAeronave() {
    ClearScreen();

    printf("Menu Inserir Aeronave\n");
}

void lerModelo(Aeronave *aeronave) {
    char nomePrograma[MAX_MODELO_LENGTH];
    printf("Modelo: ");
    fflush(stdin);
    fgets(nomePrograma, MAX_MODELO_LENGTH, stdin);
    trim(nomePrograma);

    if (!ehValidoModelo(nomePrograma)) {
        printf("\nModelo fornecido e invalido!\n");
        Pause();

        return;
    }

    aeronave->modelo = updateString(aeronave->modelo, nomePrograma);
}

char ehValidoModelo(char *nome) {
    int i;

    if (nome[0] != '\0' && strlen(nome) < MAX_MODELO_LENGTH - 1) {
        for (i = 0; nome[i]; ++i) {
            if (!isalnum(nome[i]) && nome[i] != ' ') return 0;
        }
        return 1;
    }
    return 0;
}

char mostrarCadastroAeronaveOpcoes(Aeronave *aeronave) {
    char escolha = 0;

    escolha = escolhaInserirAeronave();
    switch (escolha) {
        case 's':
            if (salvarNovaAeronave(aeronave)) {
                ClearScreen();
                PrintaSeparador();
                printf("Aeronave salvo com sucesso!\n");
                PrintaSeparador();
                Pause();
                return 1;
            }
            return 0;
        case 'a':
            alterarNovaAeronave(aeronave);
            return 0;
        case 'c':
        case '0':
            ClearScreen();
            printf("\nSaindo do menu de cadastro de aeronave.\n\n");
            Pause();
            deleteAeronave(&aeronave);
            return 1;
        default:
            PrintaSeparador();
            printf("Nao eh uma opcao valida!\n\n");
            PrintaSeparador();
            Pause();
            return 0;
    }
}

char escolhaInserirAeronave() {
    char escolha[3], choiceList[] = "0sa";

    PrintaSeparador();
    telaRodapeInserirAeronave();
    printf("\n");
    printf("Opcao: ");
    fflush(stdin);
    fgets(escolha, 2, stdin);

    if (!isdigit(escolha[0])) return (char) tolower(escolha[0]);

    return (char) ((escolha[0] - '0' < strlen(choiceList)) ? choiceList[escolha[0] - '0'] : 0);
}

void telaRodapeInserirAeronave() {
    printf("1) (S)alvar - 2) (A)lterar\n");
    printf("0) (C)ancelar Cadastro\n");
}

void alterarNovaAeronave(Aeronave *aeronave) {
    char escolha = 0;

    escolha = escolhaAlterarNovaAeronave();
    do {
        switch (escolha) {
            case 1: //< Nome programa
                free(aeronave->modelo);
                aeronave->modelo = NULL;
                break;
            default:
                break;
        }
        if (escolha >= 1 && escolha <= 7)
            escolha = 0;
    } while (escolha != 0 && (escolha = escolhaAlterarNovaAeronave()));
}


char escolhaAlterarNovaAeronave() {
    char escolha[3];

    telaAlterarNovaAeronave();
    printf("\n");
    printf("Opcao: ");
    fflush(stdin);
    fgets(escolha, 2, stdin);

    if (!isdigit(escolha[0])) return -1;

    return (char) (escolha[0] - '0');
}

void telaAlterarNovaAeronave() {
    ClearScreen();

    printf("Menu Alterar Nova Aeronave:\n\n");

    printf("Selecione o campo a ser alterado:\n\n");

    printf("1) Modelo\t2) Comprimento\n");
    printf("3) Altura\t4) Envergadura\n");

    printf("\n");
    printf("0) Cancelar alteracao\n");
}

int salvarNovaAeronave(Aeronave *aeronave) {
    if (!contains(aeronave->modelo, ListaAeronaves, (int (*)(void *, void *)) &searchModelo)) {
        ListaAeronaves = insert(ListaAeronaves, aeronave);
        return 1;
    }
    PrintaSeparador();
    printf("Aeronave com o mesmo modelo ja cadastrado!\n");
    PrintaSeparador();
    Pause();

    return 0;
}