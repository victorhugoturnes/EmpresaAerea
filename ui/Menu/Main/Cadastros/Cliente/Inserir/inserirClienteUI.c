#include "inserirClienteUI.h"

void inserirCliente() {
    Cliente *novoCliente = createCliente();
    char cadastroConcluido = 0;

    while (!cadastroConcluido) {
        telaCabecalhoInserirCliente();

        if (novoCliente->nomePrograma == NULL) {
            PrintaSeparador();
            lerNomePrograma(novoCliente);
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

    printf("Menu Inserir Cliente\n\n");

    printf("Insira as informacoes do cliente a seguir.\n");
    printf("\n");
}

int lerNomePrograma(Cliente *cliente) {
    char nomePrograma[MAX_NOMEPROGRAMA_LENGTH];
    printf("Nome do Programa: ");
    fflush(stdin);
    fgets(nomePrograma, MAX_NOMEPROGRAMA_LENGTH, stdin);
    trim(nomePrograma);

    if (!ehValidoNomePrograma(nomePrograma)) {
        printf("\nNome de programa fornecido e invalido!\n");
        Pause();

        return 0;
    }

    cliente->nomePrograma = updateString(cliente->nomePrograma, nomePrograma);
    return 1;
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

int lerNomeCliente(Cliente *cliente) {
    char nomeCliente[MAX_NOMECLIENTE_LENGTH];
    printf("Nome do Cliente: ");
    fflush(stdin);
    fgets(nomeCliente, MAX_NOMECLIENTE_LENGTH, stdin);
    trim(nomeCliente);

    if (!ehValidoNomeCliente(nomeCliente)) {
        printf("\nNome do cliente fornecido e invalido!\n");
        Pause();

        return 0;
    }

    cliente->nomeCliente = updateString(cliente->nomeCliente, nomeCliente);
    return 1;
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

int lerCpf(Cliente *cliente) {
    char cpf[MAX_CPF_LENGTH];
    printf("CPF do Cliente: ");
    fflush(stdin);
    fgets(cpf, MAX_CPF_LENGTH, stdin);
    trim(cpf);

    if (!ehValidoCpf(cpf)) {
        printf("\nCPF do cliente fornecido e invalido!\n");
        Pause();

        return 0;
    }

    if (contains(cpf, ListaClientes, (int (*)(void *, void *)) &searchCpf)) {
        printf("Um cliente com o mesmo cpf ja existe!\n");
        Pause();

        return 0;
    }

    cliente->cpf = updateString(cliente->cpf, cpf);
    return 1;
}

char ehValidoCpf(char *cpf) {
    int i, j, k;
    int sumJ = 0, sumK = 0;

    if (cpf[0] != '\0' && strlen(cpf) == MAX_CPF_LENGTH - 1) {
        for (i = 0; cpf[i]; ++i) {
            if (!isdigit(cpf[i])) return 0;

            if (i < 10) {
                if (i < 9)
                    sumJ += (cpf[i] - '0') * (10 - i);
                sumK += (cpf[i] - '0') * (11 - i);
            }
        }

        j = (sumJ % 11 <= 1) ? 0 : 11 - sumJ % 11;
        k = (sumK % 11 <= 1) ? 0 : 11 - sumK % 11;

        if ((cpf[9] - '0') != j) return 0;
        if ((cpf[10] - '0') != k) return 0;

        return 1;
    }
    return 0;
}

int lerCategoria(Cliente *cliente) {
    int i = 0;
    char input[MAXSTR] = {0};
    int choice;

    printf("Selecione uma categoria:\n");
    for (i = 1; i < CATEGORIA_LENGTH; ++i) {
        printf("\t%d) %s\n", i, categoriaParaString((Categoria) i));
    }
    printf("Escolha: ");

    fflush(stdin);
    fgets(input, MAXSTR, stdin);
    if (!(choice = strtol(input, NULL, 10)) || choice >= CATEGORIA_LENGTH) {
        printf("Escolha invalida!\n");
        Pause();
        return 0;
    }

    cliente->categoria = (Categoria) choice;
    return 1;
}

char mostrarCadastroClienteOpcoes(Cliente *cliente) {
    char escolha = 0;

    escolha = escolhaInserirCliente();
    switch (escolha) {
        case 's':
            if (salvarNovoCliente(cliente)) {
                ClearScreen();
                PrintaSeparador();
                printf("Cliente salvo com sucesso!\n");
                PrintaSeparador();
                Pause();
                return 1;
            }
            return 0;
        case 'a':
            alterarNovoCliente(cliente);
            return 0;
        case 'c':
        case '0':
            ClearScreen();
            printf("\nSaindo do menu de cadastro de cliente.\n\n");
            Pause();
            deleteCliente(&cliente);
            return 1;
        default:
            PrintaSeparador();
            printf("Nao eh uma opcao valida!\n\n");
            PrintaSeparador();
            Pause();
            return 0;
    }
}

char escolhaInserirCliente() {
    char escolha[3], choiceList[] = "0sa";

    PrintaSeparador();
    telaRodapeInserirCliente();
    printf("\n");
    printf("Opcao: ");
    fflush(stdin);
    fgets(escolha, 2, stdin);

    if (!isdigit(escolha[0])) return (char) tolower(escolha[0]);

    return (char) ((escolha[0] - '0' < strlen(choiceList)) ? choiceList[escolha[0] - '0'] : 0);
}

void telaRodapeInserirCliente() {
    printf("1) (S)alvar - 2) (A)lterar\n");
    printf("0) (C)ancelar Cadastro\n");
}

void alterarNovoCliente(Cliente *cliente) {
    char escolha = 0;

    escolha = escolhaAlterarNovoCliente();
    do {
        switch (escolha) {
            case 1: //< Nome programa
                free(cliente->nomePrograma);
                cliente->nomePrograma = NULL;
                break;
            case 2: //< Nome cliente
                free(cliente->nomeCliente);
                cliente->nomeCliente = NULL;
                break;
            case 3: //< CPF
                free(cliente->cpf);
                cliente->cpf = NULL;
                break;
            case 4: //< Categoria
                cliente->categoria = Nenhuma;
                break;

            default:
                break;
        }
        if (escolha >= 1 && escolha <= 4)
            escolha = 0;
    } while (escolha != 0 && (escolha = escolhaAlterarNovoCliente()));
}


char escolhaAlterarNovoCliente() {
    char escolha[3];

    telaAlterarNovoCliente();
    printf("\n");
    printf("Opcao: ");
    fflush(stdin);
    fgets(escolha, 2, stdin);

    if (!isdigit(escolha[0])) return -1;

    return (char) (escolha[0] - '0');
}

void telaAlterarNovoCliente() {
    ClearScreen();

    printf("Menu Alterar Novo Cliente:\n\n");

    printf("Selecione o campo a ser alterado:\n\n");

    printf("1) Nome do Programa\t2) Nome do Cliente\n");
    printf("3) CPF\t\t\t4) Categoria\n");

    printf("\n");
    printf("0) Cancelar alteracao\n");
}

int salvarNovoCliente(Cliente *cliente) {
    if (!contains(cliente->cpf, ListaClientes, (int (*)(void *, void *)) &searchCpf)) {
        ListaClientes = insert(ListaClientes, cliente);
        return 1;
    }
    PrintaSeparador();
    printf("Cliente com o mesmo CPF ja cadastrado!\n");
    PrintaSeparador();
    Pause();

    return 0;
}