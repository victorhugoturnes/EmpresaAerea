#include "consultarAeronaveUI.h"

void consultarAeronave() {
    char escolha = 0;

    escolha = consultarAeronaveEscolha();
    do {
        switch (escolha) {
            case 'm': //< consulta por modelo
                consultaModelo();
                break;
            case '0':
                ClearScreen();
                printf("\nSaindo do menu de consulta de aeronaves.\n\n");
                Pause();
                break;
            default:
                printf("Nao eh uma opcao valida!\n\n");
                Pause();
                break;
        }
    } while (escolha != '0' && (escolha = consultarAeronaveEscolha()));

}

char consultarAeronaveEscolha() {
    char escolha[3], choiceList[] = "0m";

    /// apresenta tela de menu e lê da entrada padrão a escolha \
	do usuário
    telaConsultaAeronave();
    printf("\n");
    printf("Opcao: ");
    fflush(stdin);
    fgets(escolha, 2, stdin);

    /// se não é número, retorna a letra minuscula
    if (!isdigit(escolha[0])) return (char) tolower(escolha[0]);

    /// se for número, converte e retorna letra equivalente
    return (char) ((escolha[0] - '0' < strlen(choiceList)) ? choiceList[escolha[0] - '0'] : 0);
}

void telaConsultaAeronave() {
    ClearScreen();

    printf("Menu Cadastro de Aeronave:\n\n");

    printf("Escolha uma opcao:\n");

    printf("1) Consulta por (M)odelo\n");
    printf("\n");
    printf("0) Sair do Menu de Consultas\n");
}

void consultaModelo() {
    char pesquisa[MAXSTR] = {0};
    List *searchResult = NULL;

    ClearScreen();

    /// lê entrada
    printf("Pesquisa de aeronave por modelo\n\n");
    printf("Digite sua pesquisa: ");

    fflush(stdin);
    fgets(pesquisa, MAXSTR, stdin);
    trim(pesquisa);

    /// pesquisa na lista
    searchResult = search(pesquisa, ListaAeronaves, (int (*)(void *, void *)) &searchModelo);

    mostrarResultadoPesquisaAeronave(searchResult);
}

void mostrarResultadoPesquisaAeronave(List *searchResult) {
    char *str;
    int searchResultLength = length(searchResult);
    Aeronave *aeronaveEscolhida = NULL;

    /// mostra resultados
    if (searchResultLength == 0) {
        printf("Nenhum resultado encontrado!\n");
        Pause();
        return;
    } else if (searchResultLength == 1) {
        printf("%s\n", str = aeronaveToString(searchResult->info));
        free(str);
        Pause();
        aeronaveEscolhida = (Aeronave *) searchResult->info;
    } else if (searchResultLength > 1) {
        aeronaveEscolhida = menuEscolhaListaAeronave(searchResult);
        Pause();
    }

    menuOpcoesAeronave(aeronaveEscolhida);
}

Aeronave *menuEscolhaListaAeronave(List *listaAeronave) {
    int i = 1, escolha = 0;
    List *current = NULL;
    char buf[MAXSTR], *str;

    for (current = listaAeronave; current; current = current->next) {
        printf("[%d] %s", i++, str = aeronaveToString(current->info));
        free(str);
    }

    do {
        fgets(buf, MAXSTR, stdin);
        trim(buf);

        escolha = strtol(buf, NULL, 10);

        if (escolha < 0 && escolha > i) {
            printf("Escolha invalida!\n");
            Pause();
        }

    } while (escolha < 0 && escolha > i);

    for (current = listaAeronave; i; --i) {
        if (current) {
            current = current->next;
        }
    }

    if (!current) return NULL;

    return current->info;
}

void menuOpcoesAeronave(Aeronave *aeronave) {
    char escolha = 0;

    escolha = escolhaAeronave();
    do {
        switch (escolha) {
            case 'a':
                alterarAeronave(aeronave);
                break;
            case 'd':
                deletarAeronave(aeronave);
                escolha = '0';
                break;
            case '0':
                ClearScreen();
                printf("\nSaindo do menu opcoes aeronave.\n\n");
                Pause();
                break;
            default:
                printf("Nao eh uma opcao valida!\n\n");
                Pause();
                break;
        }

    } while (escolha != '0' && (escolha = escolhaAeronave()));
}

char escolhaAeronave() {
    char escolha[3], choiceList[] = "0ad";

    telaOpcoesAeronave();
    printf("\n");
    printf("Opcao: ");
    fflush(stdin);
    fgets(escolha, 2, stdin);

    if (!isdigit(escolha[0])) return (char) tolower(escolha[0]);

    return (char) ((escolha[0] - '0' < strlen(choiceList)) ? choiceList[escolha[0] - '0'] : 0);
}

void telaOpcoesAeronave() {
    ClearScreen();

    printf("Menu Opcoes Aeronave:\n\n");

    printf("Escolha uma opcao:\n");
    printf("1) (A)lterar Aeronave\n");
    printf("2) (D)eletar Aeronave\n");
    printf("\n");
    printf("0) Sair do Menu de Opcoes Aeronave\n");
}

