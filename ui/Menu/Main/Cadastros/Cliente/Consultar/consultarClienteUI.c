//
// Created by Jedson on 4/22/2019.
//

#include "consultarClienteUI.h"

void consultarCliente() {
    char escolha = 0;

    getchar();

    escolha = consultarClienteEscolha();
    do {
        switch (escolha) {
            case 'p': //< consulta por programa
                consultaNomePrograma();
                break;
            case 'n': //< consulta por nome
                consultaNome();
                break;
            case 'c': //< consulta por cpf
                consultaCPF();
                break;
            case 'r': //< consulta por categoria
                consultaCategoria();
                break;
            case '0':
                ClearScreen();
                printf("\nSaindo do menu de consulta de clientes.\n\n");
                Pause();
                break;
            default:
                printf("Nao eh uma opcao valida!\n\n");
                Pause();
                break;
        }
    } while (escolha != '0' && (escolha = consultarClienteEscolha()));

}

char consultarClienteEscolha() {
    char escolha[3], choiceList[] = "0pncr";

    /// apresenta tela de menu e lê da entrada padrão a escolha \
	do usuário
    telaConsultaCliente();
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

void telaConsultaCliente() {
    ClearScreen();

    printf("Menu Cadastro de Cliente:\n\n");

    printf("Escolha uma opcao:\n");

    printf("1) Consulta por (P)rograma de Milhagem\n");
    printf("2) Consulta por (N)ome de Cliente\n");
    printf("3) Consulta por (C)PF\n");
    printf("4) Consulta por (R)ank\n");
    printf("\n");
    printf("0) Sair do Menu de Consultas\n");
}

void consultaNomePrograma() {
    char pesquisa[MAXSTR] = {0};
    List *searchResult = NULL;

    ClearScreen();

    /// lê entrada
    printf("Pesquisa de cliente por programa de milhagem\n\n");
    printf("Digite sua pesquisa: ");

    fflush(stdin);
    fgets(pesquisa, MAXSTR, stdin);
    trim(pesquisa);

    /// pesquisa na lista
    searchResult = search(pesquisa, ListaClientes, (int (*)(void *, void *)) &searchNomePrograma);

    mostrarResultadoPesquisaCliente(searchResult);
}

void consultaNome() {
    char pesquisa[MAXSTR] = {0};
    List *searchResult = NULL;

    ClearScreen();

    /// lê entrada
    printf("Pesquisa de cliente por nome do cliente\n\n");
    printf("Digite sua pesquisa: ");

    fflush(stdin);
    fgets(pesquisa, MAXSTR, stdin);
    trim(pesquisa);

    /// pesquisa na lista
    searchResult = search(pesquisa, ListaClientes, (int (*)(void *, void *)) &searchNomeCliente);

    mostrarResultadoPesquisaCliente(searchResult);
}

void consultaCPF() {
    char pesquisa[MAXSTR] = {0};
    List *searchResult = NULL;

    ClearScreen();

    /// lê entrada
    printf("Pesquisa de cliente por CPF\n\n");
    printf("Digite sua pesquisa: ");

    fflush(stdin);
    fgets(pesquisa, MAXSTR, stdin);
    trim(pesquisa);

    /// pesquisa na lista
    searchResult = search(pesquisa, ListaClientes, (int (*)(void *, void *)) &searchCpf);

    mostrarResultadoPesquisaCliente(searchResult);
}

void consultaCategoria() {
    int i = 0;
    Categoria escolhida;
    char escolha[MAXSTR] = {0};
    int choice;
    List *searchResult = NULL;

    ClearScreen();

    /// lê entrada
    printf("Pesquisa de cliente por Categoria\n\n");

    printf("Selecione uma categoria:\n");
    for (i = 1; i < CATEGORIA_LENGTH; ++i) {
        printf("\t%d) %s\n", i, categoriaParaString((Categoria) i));
    }
    printf("Escolha: ");

    fflush(stdin);
    fgets(escolha, MAXSTR, stdin);
    if (!(choice = strtol(escolha, NULL, 10)) || choice >= CATEGORIA_LENGTH) {
        printf("Escolha invalida!\n");
        Pause();
        return;
    }

    escolhida = (Categoria) choice;

    /// escolha na lista
    searchResult = search(&escolhida, ListaClientes, (int (*)(void *, void *)) &searchCategoria);

    mostrarResultadoPesquisaCliente(searchResult);
}

void mostrarResultadoPesquisaCliente(List *searchResult) {
    char *str;
    int searchResultLength = length(searchResult);
    Cliente *clienteEscolhido = NULL;

    /// mostra resultados
    if (searchResultLength == 0) {
        printf("Nenhum resultado encontrado!\n");
        Pause();
        return;
    } else if (searchResultLength == 1) {
        printf("%s\n", str = clienteToString(searchResult->info));
        free(str);
        Pause();
        clienteEscolhido = (Cliente *) searchResult->info;
    } else if (searchResultLength > 1) {
        clienteEscolhido = menuEscolhaListaCliente(searchResult);
        Pause();
    }

    menuOpcoesCliente(clienteEscolhido);
}

Cliente *menuEscolhaListaCliente(List *listaCliente) {
    int i = 1, escolha = 0;
    List *current = NULL;
    char buf[MAXSTR], *str;

    for (current = listaCliente; current; current = current->next) {
        printf("[%d] %s", i++, str = clienteToString(current->info));
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

    for (current = listaCliente; i; --i) {
        if (current) {
            current = current->next;
        }
    }

    if (!current) return NULL;

    return current->info;
}

void menuOpcoesCliente(Cliente *cliente) {
    char escolha = 0;

    escolha = escolhaCliente();
    do {
        switch (escolha) {
            case 'a':
                alterarCliente(cliente);
                break;
            case 'd':
                deletarCliente(cliente);
                escolha = '0';
                break;
            case '0':
                ClearScreen();
                printf("\nSaindo do menu opcoes cliente.\n\n");
                Pause();
                break;
            default:
                printf("Nao eh uma opcao valida!\n\n");
                Pause();
                break;
        }

    } while (escolha != '0' && (escolha = escolhaCliente()));
}

char escolhaCliente() {
    char escolha[3], choiceList[] = "0ad";

    telaOpcoesCliente();
    printf("\n");
    printf("Opcao: ");
    fflush(stdin);
    fgets(escolha, 2, stdin);

    if (!isdigit(escolha[0])) return (char) tolower(escolha[0]);

    return (char) ((escolha[0] - '0' < strlen(choiceList)) ? choiceList[escolha[0] - '0'] : 0);
}

void telaOpcoesCliente() {
    ClearScreen();

    printf("Menu Opcoes Cliente:\n\n");

    printf("Escolha uma opcao:\n");
    printf("1) (A)lterar Cliente\n");
    printf("2) (D)eletar Cliente\n");
    printf("\n");
    printf("0) Sair do Menu de Opcoes Cliente\n");
}

