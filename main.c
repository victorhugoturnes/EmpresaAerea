#include <stdio.h>
#include "ui/Menu/Main/mainMenuUI.h"

List *ListaClientes = NULL;
List *ListaVoos = NULL;
List *ListaAeronaves = NULL;
List *ListaAeroportos = NULL;

int main(int argc, char const *argv[]) {
    char escolha = 0;

    if (argc > 1) populateMisto(argv[1]);

    /// printa menu principal e recolhe escolha do usuário
    escolha = mainMenuEscolha();
    do {
        /// entra no menu escolhido pelo usuário
        switch (escolha) {
            /// abre menu de cadastros
            case 'c':
                menuCadastros();
                break;
                /// abre menu de status
            case 's':
                menuStatus();
                break;
                /// testa cadastros salvos
            case 't':
                testarCadastros();
                break;
            case 'p':
                populateLists();
                break;
                /// caso de saída
            case '0':
                if (!confirmacaoSaidaMainMenu())
                    escolha = 1;
                break;
                /// opção inválida escolhida
            default:
                printf("Nao eh uma opcao valida!\n\n");
                Pause();
                break;
        }
        /// enquanto escolha diferente de '0' e valida
    } while (escolha != '0' && (escolha = mainMenuEscolha()));

    return 0;
}