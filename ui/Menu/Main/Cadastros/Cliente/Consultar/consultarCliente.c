//
// Created by Jedson on 4/22/2019.
//

#include "consultarCliente.h"


void menuOpcoesCliente(Cliente *cliente);

Cliente *menuEscolhaListaCliente(List *listaCliente);

void consultarCliente() {
    char escolha = 0;

    escolha = consultarClienteEscolha();
    do {
        switch (escolha) {
            case 'p': //< consulta por programa
                consultaPrograma();
                break;
            case 'n': //< consulta por nome
                break;
            case 'c': //< consulta por cpf
                break;
            case 'r': //< consulta por categoria
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
    char escolha, choiceList[] = "0pncr";

    /// apresenta tela de menu e lê da entrada padrão a escolha \
	do usuário
    telaConsultaCliente();
    printf("\n");
    printf("Opcao: ");
    fflush(stdin);
    scanf("%c", &escolha);

    /// se não é número, retorna a letra minuscula
    if (!isdigit(escolha)) return (char) tolower(escolha);

    /// se for número, converte e retorna letra equivalente
    return choiceList[escolha - '0'];
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

void consultaPrograma() {
    char pesquisa[MAXSTR] = {0};
    List *searchResult = NULL;
    int searchResultLength = 0;
    Cliente *clienteEscolhido = NULL;

    ClearScreen();

    // lê entrada
    printf("Pesquisa de cliente por programa de milhagem\n");

    fflush(stdin);
    fgets(pesquisa, MAXSTR, stdin);
    trim(pesquisa);

    // pesquisa na lista
    searchResult = search(pesquisa, ListaClientes, (int (*)(void *, void *)) &searchNomePrograma);
    searchResultLength = length(searchResult);

    // mostra resultados
    if(searchResultLength == 0) {
        printf("Nenhum resultado encontrado!\n");
        Pause();
        return;
    } else if(searchResultLength == 1) {
        printf("%s\n", clienteToString(searchResult->info));
        clienteEscolhido = (Cliente *) searchResult->info;
        menuOpcoesCliente(clienteEscolhido);
        Pause();
    } else if(searchResultLength > 1) {
        clienteEscolhido = menuEscolhaListaCliente(searchResult);
        menuOpcoesCliente(clienteEscolhido);
        Pause();
    }

    menuOpcoesCliente(clienteEscolhido);
}

Cliente *menuEscolhaListaCliente(List *listaCliente) {
    int i = 1, escolha = 0;
    List *current = NULL, *escolhido = NULL;
    char buf[MAXSTR];

    for(current = listaCliente; current; current = current->next) {
        printf("[%d] %s", i++, clienteToString(current->info));
    }

    do {
        fgets(buf, MAXSTR, stdin);
        trim(buf);

        escolha = strtol(buf, NULL, 10);

        if(escolha < 0 && escolha > i) {
            printf("Escolha invalida!\n");
            Pause();
        }

    } while(escolha < 0 && escolha > i);

    for(current = listaCliente; i; --i) {
        if(current) {
            current = current->next;
        }
    }

    if(!current) return NULL;

    return current->info;
}

void menuOpcoesCliente(Cliente *cliente) {

}

