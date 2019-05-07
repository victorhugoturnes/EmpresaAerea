//
// Created by Jedson on 5/2/2019.
//

#include "consultarVooUI.h"

void consultarVoo() {
    char escolha = 0;

    getchar();

    escolha = consultarVooEscolha();
    do {
        switch (escolha) {
            case 'p': //< consulta por prefixo
                consultaPrefixo();
                break;
            case '0':
                ClearScreen();
                printf("\nSaindo do menu de consulta de voos.\n\n");
                Pause();
                break;
            default:
                printf("Nao eh uma opcao valida!\n\n");
                Pause();
                break;
        }
    } while (escolha != '0' && (escolha = consultarVooEscolha()));

}

char consultarVooEscolha() {
    char escolha[3], choiceList[] = "0p";

    /// apresenta tela de menu e lê da entrada padrão a escolha \
	do usuário
    telaConsultaVoo();
    printf("\n");
    printf("Opcao: ");
    fflush(stdin);
    fgets(escolha, 2, stdin);
    getchar();

    /// se não é número, retorna a letra minuscula
    if (!isdigit(escolha[0])) return (char) tolower(escolha[0]);
    /// se for número, converte e retorna letra equivalente
    return (char) ((escolha[0] - '0' < strlen(choiceList)) ? choiceList[escolha[0] - '0'] : 0);
}

void telaConsultaVoo() {
    ClearScreen();

    printf("Menu Cadastro de Voo:\n\n");

    printf("Escolha uma opcao:\n");

    printf("1) Consulta por (P)refixo\n");
    printf("\n");
    printf("0) Sair do Menu de Consultas\n");
}

void consultaPrefixo() {
    char pesquisa[MAXSTR] = {0};
    List *searchResult = NULL;

    ClearScreen();

    /// lê entrada
    printf("Pesquisa de voo por prefixo\n\n");
    printf("Digite sua pesquisa: ");

    fflush(stdin);
    fgets(pesquisa, MAXSTR, stdin);
    trim(pesquisa);

    /// pesquisa na lista
    searchResult = search(pesquisa, ListaVoos, (int (*)(void *, void *)) &searchPrefixo);

    mostrarResultadoPesquisaVoo(searchResult);
}

void mostrarResultadoPesquisaVoo(List *searchResult) {
    char *str;
    int searchResultLength = length(searchResult);
    VooInfo *vooEscolhido = NULL;

    /// mostra resultados
    if (searchResultLength == 0) {
        printf("Nenhum resultado encontrado!\n");
        Pause();
        return;
    } else if (searchResultLength == 1) {
        printf("%s\n", str = vooInfoToString(searchResult->info));
        free(str);
        Pause();
        vooEscolhido = (VooInfo *) searchResult->info;
    } else if (searchResultLength > 1) {
        vooEscolhido = menuEscolhaListaVoo(searchResult);
        Pause();
    }

    menuOpcoesVoo(vooEscolhido);
}

void menuOpcoesVoo(VooInfo *voo) {
    char escolha = 0;

    escolha = escolhaVoo();
    do {
        switch (escolha) {
            case 'a':
                alterarVoo(voo);
                break;
            case 'd':
                deletarVoo(voo);
                escolha = '0';
                break;
            case '0':
                ClearScreen();
                printf("\nSaindo do menu opcoes voo.\n\n");
                Pause();
                break;
            default:
                printf("Nao eh uma opcao valida!\n\n");
                Pause();
                break;
        }

    } while (escolha != '0' && (escolha = escolhaVoo()));
}

VooInfo *menuEscolhaListaVoo(List *listaVoo) {
    int i = 1, escolha = 0;
    List *current = NULL;
    char buf[MAXSTR], *str;

    for (current = listaVoo; current; current = current->next) {
        printf("[%d] %s", i++, str = vooInfoToString(current->info));
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

    for (current = listaVoo; i; --i) {
        if (current) {
            current = current->next;
        }
    }

    if (!current) return NULL;

    return current->info;
}

char escolhaVoo() {
    char escolha[3], choiceList[] = "0ad";

    telaOpcoesVoo();
    printf("\n");
    printf("Opcao: ");
    fflush(stdin);
    fgets(escolha, 3, stdin);

    if (!isdigit(escolha[0])) return (char) tolower(escolha[0]);

    return (char) ((escolha[0] - '0' < strlen(choiceList)) ? choiceList[escolha[0] - '0'] : 0);
}

void telaOpcoesVoo() {
    ClearScreen();

    printf("Menu Opcoes Voo:\n\n");

    printf("Escolha uma opcao:\n");
    printf("1) (A)lterar Voo\n");
    printf("2) (D)eletar Voo\n");
    printf("\n");
    printf("0) Sair do Menu de Opcoes Voo\n");
}

