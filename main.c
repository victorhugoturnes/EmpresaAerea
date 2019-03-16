#include <stdio.h>
#include <stdlib.h>
#include "ui/mainMenuUI.h"
#include "Environment.h"

int main() {
    char escolha = 0;

    /// printa menu principal e recolhe escolha do usuário
    escolha = mainMenuEscolha();
    do {
        /// entra no menu escolhido pelo usuário
        switch(escolha) {
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
                /// caso de saída
            case '0':
                if(!confirmacaoSaidaMainMenu())
                    escolha = 1;
                break;
                /// opção inválida escolhida
            default:
                printf("Nao eh uma opcao valida!\n\n");
                Pause();
                break;
        }
        /// enquanto escolha diferente de '0' e valida
    } while(escolha != '0' && (escolha = mainMenuEscolha()));

    return 0;
}