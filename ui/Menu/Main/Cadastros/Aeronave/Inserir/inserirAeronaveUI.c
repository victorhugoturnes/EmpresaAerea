#include "inserirAeronaveUI.h"

void inserirAeronave(Aeronave *novaAeronave) {
    if (!novaAeronave) novaAeronave = createAeronave();
    char cadastroConcluido = 0;

    while (!cadastroConcluido) {
        telaCabecalhoInserirAeronave();

        if (novaAeronave->modelo == NULL) {
            PrintaSeparador();
            lerModelo(novaAeronave);
            continue;
        } else {
            printf("Modelo: %s\n", novaAeronave->modelo);
        }

        if (novaAeronave->comprimento == -1) {
            PrintaSeparador();
            lerComprimento(novaAeronave);
            continue;
        } else {
            printf("Comprimento: %.2lfm\n", novaAeronave->comprimento);
        }

        if (novaAeronave->altura == -1) {
            PrintaSeparador();
            lerAltura(novaAeronave);
            continue;
        } else {
            printf("Altura: %.2lfm\n", novaAeronave->altura);
        }

        if (novaAeronave->envergadura == -1) {
            PrintaSeparador();
            lerEnvergadura(novaAeronave);
            continue;
        } else {
            printf("Envergadura: %.2lfm\n", novaAeronave->envergadura);
        }

        if (novaAeronave->velocidadeCruzeiro == -1) {
            PrintaSeparador();
            lerVelocidadeCruzeiro(novaAeronave);
            continue;
        } else {
            printf("Velocidade de cruzeiro: %.2lf nos\n", novaAeronave->velocidadeCruzeiro);
        }

        if (novaAeronave->alcanceMaximo == -1) {
            PrintaSeparador();
            lerAlcanceMaximo(novaAeronave);
            continue;
        } else {
            printf("Alcance maximo: %.2lf pes\n", novaAeronave->alcanceMaximo);
        }

        if (novaAeronave->qntAcentos == -1) {
            PrintaSeparador();
            lerQntAcentos(novaAeronave);
            continue;
        } else {
            printf("Quantidade de acentos: %d\n", novaAeronave->qntAcentos);
        }

        if (novaAeronave->qntBanheiros == -1) {
            PrintaSeparador();
            lerQntBanheiros(novaAeronave);
            continue;
        } else {
            printf("Quantidade de banheiros: %d\n", novaAeronave->qntBanheiros);
        }

        cadastroConcluido = mostrarCadastroAeronaveOpcoes(novaAeronave);
    }
}

void telaCabecalhoInserirAeronave() {
    ClearScreen();

    printf("Menu Inserir Aeronave\n\n");

    printf("Insira as informacoes da aeronave a seguir.\n");
    printf("\n");

}

int lerModelo(Aeronave *aeronave) {
    char modelo[MAX_MODELO_LENGTH];

    printf("Modelo: ");
    fflush(stdin);
    fgets(modelo, MAX_MODELO_LENGTH, stdin);
    trim(modelo);

    if (!ehValidoModelo(modelo)) {
        printf("\nModelo fornecido e invalido!\n");
        Pause();

        return 0;
    }

    if (contains(modelo, ListaAeronaves, (int (*)(void *, void *)) &searchModelo)) {
        printf("Uma aeronave com o mesmo modelo ja existe!\n");
        Pause();

        return 0;
    }

    aeronave->modelo = updateString(aeronave->modelo, modelo);
    return 1;
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

int lerComprimento(Aeronave *aeronave) {
    char buf[MAXSTR];
    double comprimento = 0;

    printf("Comprimento: ");
    fflush(stdin);
    fgets(buf, MAXSTR, stdin);
    trim(buf);
    comprimento = stringToDouble(buf, 10);

    if (comprimento <= 0) {
        printf("\nComprimento fornecido e invalido!\n");
        Pause();

        return 0;
    }

    aeronave->comprimento = comprimento;
    return 1;
}

int lerAltura(Aeronave *aeronave) {
    char buf[MAXSTR];
    double altura = 0;

    printf("Altura: ");
    fflush(stdin);
    fgets(buf, MAXSTR, stdin);
    trim(buf);
    altura = stringToDouble(buf, 10);

    if (altura <= 0) {
        printf("\nAltura fornecido e invalido!\n");
        Pause();

        return 0;
    }

    aeronave->altura = altura;
    return 1;
}

int lerEnvergadura(Aeronave *aeronave) {
    char buf[MAXSTR];
    double envergadura = 0;

    printf("Envergadura: ");
    fflush(stdin);
    fgets(buf, MAXSTR, stdin);
    trim(buf);
    envergadura = stringToDouble(buf, 10);

    if (envergadura <= 0) {
        printf("\nEnvergadura fornecida e invalida!\n");
        Pause();

        return 0;
    }

    aeronave->envergadura = envergadura;
    return 1;
}

int lerVelocidadeCruzeiro(Aeronave *aeronave) {
    char buf[MAXSTR];
    double velocidadeCruzeiro = 0;

    printf("Velocidade de cruzeiro: ");
    fflush(stdin);
    fgets(buf, MAXSTR, stdin);
    trim(buf);
    velocidadeCruzeiro = stringToDouble(buf, 10);

    if (velocidadeCruzeiro <= 0) {
        printf("\nVelocidade de cruzeiro fornecida e invalida!\n");
        Pause();

        return 0;
    }

    aeronave->velocidadeCruzeiro = velocidadeCruzeiro;
    return 1;
}

int lerAlcanceMaximo(Aeronave *aeronave) {
    char buf[MAXSTR];
    double alcanceMaximo = 0;

    printf("Alcance maximo: ");
    fflush(stdin);
    fgets(buf, MAXSTR, stdin);
    trim(buf);
    alcanceMaximo = stringToDouble(buf, 10);

    if (alcanceMaximo <= 0) {
        printf("\nAlcance maximo fornecido e invalido!\n");
        Pause();

        return 0;
    }

    aeronave->alcanceMaximo = alcanceMaximo;
    return 1;
}

int lerQntAcentos(Aeronave *aeronave) {
    char buf[MAXSTR];
    int qntAcentos = 0;

    printf("Quantidade de acentos: ");
    fflush(stdin);
    fgets(buf, MAXSTR, stdin);
    trim(buf);
    qntAcentos = strtol(buf, NULL, 10);

    if (qntAcentos <= 0) {
        printf("\nQuantidade de acentos fornecida e invalida!\n");
        Pause();

        return 0;
    }

    aeronave->qntAcentos = qntAcentos;
    return 1;
}

int lerQntBanheiros(Aeronave *aeronave) {
    char buf[MAXSTR];
    int qntBanheiros = 0;

    printf("Quantidade de baheiros: ");
    fflush(stdin);
    fgets(buf, MAXSTR, stdin);
    trim(buf);
    qntBanheiros = strtol(buf, NULL, 10);

    if (qntBanheiros <= 0) {
        printf("\nQuantidade de baheiros fornecida e invalida!\n");
        Pause();

        return 0;
    }

    aeronave->qntBanheiros = qntBanheiros;
    return 1;
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
            case 1: //< modelo
                free(aeronave->modelo);
                aeronave->modelo = NULL;
                break;
            case 2: //< comprimento
                aeronave->comprimento = -1;
                break;
            case 3: //< altura
                aeronave->altura = -1;
                break;
            case 4: //< envergadura
                aeronave->envergadura = -1;
                break;
            case 5: //< velocidadeCruzeiro
                aeronave->velocidadeCruzeiro = -1;
                break;
            case 6: //< alcanceMaximo
                aeronave->alcanceMaximo = -1;
                break;
            case 7: //< qntAcentos
                aeronave->qntAcentos = -1;
                break;
            case 8: //< qntBanheiros
                aeronave->qntBanheiros = -1;
                break;
            default:
                break;
        }
        if (escolha >= 1 && escolha <= 8)
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
    printf("5) Vel Cruzeiro\t6) Alcance Max\n");
    printf("7) Qnt Acentos\t8) Qnt Banheiros\n");

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