//
// Created by Jedson on 3/19/2019.
//

#include "inserirClienteUI.h"

void inserirCliente() {
    Cliente *novoCliente = createCliente();
    char cadastroConcluido = 0;

    while (!cadastroConcluido) {
        telaCabecalhoInserirCliente();

        if (novoCliente->nomePrograma == NULL) {
            lerNomePrograma(novoCliente);
            PrintaSeparador();
            continue;
        } else {
            printf("Nome do Programa: %s\n", novoCliente->nomePrograma);
        }

        if (novoCliente->nomeCliente == NULL) {
            PrintaSeparador();
            lerNomeCliente(novoCliente);
            continue;
        } else {
            printf("Nome do Cliente: %s\n", novoCliente->nomeCliente);
        }

        if (novoCliente->cpf == NULL) {
            PrintaSeparador();
            lerCpf(novoCliente);
            continue;
        } else {
            printf("CPF: %s\n", novoCliente->cpf);
        }

        if (novoCliente->categoria == Nenhuma) {
            PrintaSeparador();
            lerCategoria(novoCliente);
            continue;
        } else {
            printf("Categoria: %s\n", categoriaParaString(novoCliente->categoria));
        }

        cadastroConcluido = mostrarCadastroClienteOpcoes(novoCliente);
    }
}

void telaCabecalhoInserirCliente() {
    ClearScreen();

    printf("Menu Inserir Cliente\n");
}

void lerNomePrograma(Cliente *novoCliente) {
    char nomePrograma[MAX_NOMEPROGRAMA_LENGTH];
    printf("Nome do Programa: ");
    fflush(stdin);
    scanf("%[^\n]%*c", nomePrograma);

    if (!ehValidoNomePrograma(nomePrograma)) {
        printf("\nNome de programa fornecido e invalido!\n");
        Pause();

        return;
    }

    novoCliente->nomePrograma = updateString(novoCliente->nomePrograma, nomePrograma);
}

char ehValidoNomePrograma(char *nome) {
    int i;

    if (nome[0] != '\0' && strlen(nome) < MAX_NOMEPROGRAMA_LENGTH - 1) {
        for (i = 0; nome[i]; ++i) {
            if (!isalnum(nome[i]) && nome[i] != ' ') return 0;
        }
        return 1;
    }
    return 0;
}

void lerNomeCliente(Cliente *novoCliente) {
    char nomeCliente[MAX_NOMEPROGRAMA_LENGTH];
    printf("Nome do Cliente: ");
    fflush(stdin);
    scanf("%[^\n]%*c", nomeCliente);

    if (!ehValidoNomeCliente(nomeCliente)) {
        printf("\nNome do cliente fornecido e invalido!\n");
        Pause();

        return;
    }

    novoCliente->nomeCliente = updateString(novoCliente->nomeCliente, nomeCliente);
}

char ehValidoNomeCliente(char *nome) {
    int i;

    if (nome[0] != '\0' && strlen(nome) < MAX_NOMECLIENTE_LENGTH - 1) {
        for (i = 0; nome[i]; ++i) {
            if (!isalnum(nome[i]) && nome[i] != ' ') return 0;
        }
        return 1;
    }
    return 0;
}

void lerCpf(Cliente *novoCliente) {
    char cpf[MAX_NOMEPROGRAMA_LENGTH];
    printf("CPF do Cliente: ");
    fflush(stdin);
    scanf("%[^\n]%*c", cpf);

    if (!ehValidoCpf(cpf)) {
        printf("\nCPF do cliente fornecido e invalido!\n");
        Pause();

        return;
    }

    novoCliente->cpf = updateString(novoCliente->cpf, cpf);
}

char ehValidoCpf(char *cpf) {
    int i, j , k;
    int sumJ = 0, sumK = 0;

    if (cpf[0] != '\0' && strlen(cpf) == MAX_CPF_LENGTH - 1) {
        for (i = 0; cpf[i]; ++i) {
            if (!isdigit(cpf[i])) return 0;

            if(i < 10) {
                if(i < 9)
                    sumJ += (cpf[i] - '0') * (10 - i);
                sumK += (cpf[i] - '0') * (11 - i);
            }
        }

        j = (sumJ%11 <= 1) ? 0 : 11-sumJ%11;
        k = (sumK%11 <= 1) ? 0 : 11-sumK%11;

        if((cpf[9] - '0') != j) return 0;
        if((cpf[10] - '0') != k) return 0;

        return 1;
    }
    return 0;
}

void lerCategoria(Cliente *novoCliente) {
    int i = 0;
    char input[MAXSTR] = {0};
    int choice;

    printf("Selecione uma categoria:\n");
    for (i = 1; i < CATEGORIA_LENGTH; ++i) {
        printf("\t%d) %s\n", i, categoriaParaString((Categoria) i));
    }

    fflush(stdin);
    scanf("%[^\n]%*c", input);
    if(!(choice = strtol(input, NULL, 10)) || choice >= CATEGORIA_LENGTH) {
        printf("Escolha invalida!\n");
        Pause();
        return;
    }

    novoCliente->categoria = (Categoria) choice;
}

char *categoriaParaString(Categoria categoria) {
    switch (categoria) {
        case Nenhuma:
            return "Nenhuma";
        case Madeira:
            return "Madeira";
        case Pedra:
            return "Pedra";
        case Ferro:
            return "Ferro";
        case Ouro:
            return "Ouro";
        case Diamante:
            return "Diamante";
        case Obsidian:
            return "Obsidian";
        case Bedrock:
            return "Bedrock";
    }

    return NULL;
}

char mostrarCadastroClienteOpcoes(Cliente *novoCliente) {
    char escolha = 0;

    escolha = escolhaInserirCliente(novoCliente);
    switch (escolha) {
        case 's':
//			salvarNovoCliente(novoVoo);
            PrintaSeparador();
            printf("Funcionalidade ainda nao implementada!\n");
            PrintaSeparador();
            Pause();
            return 0;
        case 'a':
            alterarNovoCliente(novoCliente);
            return 0;
        case 'c':
        case '0':
            ClearScreen();
            printf("\nSaindo do menu de cadastro de cliente.\n\n");
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

char escolhaInserirCliente(Cliente *novoCliente) {
    char escolha, choiceList[] = "0sa";

    PrintaSeparador();
    telaRodapeInserirCliente();
    printf("\n");
    printf("Opcao: ");
    fflush(stdin);
    scanf("%c", &escolha);

    if (!isdigit(escolha)) return (char) tolower(escolha);

    return choiceList[escolha - '0'];
}

void telaRodapeInserirCliente() {
    printf("1) (S)alvar - 2) (A)lterar\n");
    printf("0) (C)ancelar Cadastro\n");
}

void alterarNovoCliente(Cliente *novoCliente) {
    char escolha = 0;

    escolha = escolhaAlterarNovoCliente();
    do {
        switch (escolha) {
            case 1: //< Nome programa
                free(novoCliente->nomePrograma);
                novoCliente->nomePrograma = NULL;
                break;
            case 2: //< Nome cliente
                free(novoCliente->nomeCliente);
                novoCliente->nomeCliente = NULL;
                break;
            case 3: //< CPF
                free(novoCliente->cpf);
                novoCliente->cpf = NULL;
                break;
            case 4: //< Categoria
                novoCliente->categoria = Nenhuma;
                break;

            default:
                break;
        }
        if(escolha >= 1 && escolha <= 7)
            escolha = 0;
    } while (escolha != 0 && (escolha = escolhaAlterarNovoCliente()));
}


char escolhaAlterarNovoCliente() {
    char escolha;

    telaAlterarNovoCliente();
    printf("\n");
    printf("Opcao: ");
    fflush(stdin);
    scanf("%c", &escolha);

    if (!isdigit(escolha)) return -1;

    return (char) (escolha - '0');
}

void telaAlterarNovoCliente() {
    ClearScreen();

    printf("Selecione o campo a ser alterado:\n\n");

    printf("1) Nome do Programa\t2) Nome do Cliente\n");
    printf("3) CPF\t\t\t4) Categoria\n");

    printf("\n");
    printf("0) Cancelar alteracao\n");
}