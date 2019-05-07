//
// Created by Jedson on 4/30/2019.
//

#include "alterarClienteUI.h"

void alterarCliente(Cliente *cliente) {
    char escolha = 0, *str;

    getchar();

    escolha = escolhaAlterarCliente();
    do {
        switch (escolha) {
            case 1: //< Nome programa
                free(cliente->nomePrograma);
                cliente->nomePrograma = NULL;
                while (!lerNomePrograma(cliente)) {
                    ClearScreen();
                }
                break;
            case 2: //< Nome cliente
                free(cliente->nomeCliente);
                cliente->nomeCliente = NULL;
                while (!lerNomeCliente(cliente)) {
                    ClearScreen();
                }
                break;
            case 3: //< CPF
                free(cliente->cpf);
                cliente->cpf = NULL;
                while (!lerCpf(cliente)) {
                    ClearScreen();
                }
                break;
            case 4: //< Categoria
                while (!lerCategoria(cliente)) {
                    ClearScreen();
                }
                break;
            default:
                break;
        }
        if (escolha >= 1 && escolha <= 4) {
            escolha = 0;
            printf("Cliente alterado com sucesso!\n");
        }
    } while (escolha != 0 && (escolha = escolhaAlterarCliente()));

    printf("\nCliente Alterado: \n");
    printf("\t%s\n", str = clienteToString(cliente));
    free(str);
    Pause();
}

char escolhaAlterarCliente() {
    char escolha[3];

    telaAlterarCliente();
    printf("\n");
    printf("Opcao: ");
    fflush(stdin);
    fgets(escolha, 2, stdin);
    getchar();

    if (!isdigit(escolha[0])) return -1;

    return (char) (escolha[0] - '0');
}

void telaAlterarCliente() {
    ClearScreen();

    printf("Menu Alterar Cliente:\n\n");

    printf("Selecione o campo a ser alterado:\n\n");

    printf("1) Nome do Programa\t2) Nome do Cliente\n");
    printf("3) CPF\t\t\t4) Categoria\n");

    printf("\n");
    printf("0) Cancelar alteracao\n");
}
