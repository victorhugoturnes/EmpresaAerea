//
// Created by Jedson on 4/30/2019.
//

#include "alterarAeronaveUI.h"

void alterarAeronave(Aeronave *aeronave) {
    char escolha = 0, *str;

    escolha = escolhaAlterarAeronave();
    do {
        switch (escolha) {
            case 1: //< Nome programa
//                free(aeronave->nomePrograma);
//                aeronave->nomePrograma = NULL;
//                lerNomePrograma(aeronave);
                break;
            case 2: //< Nome aeronave
//                free(aeronave->nomeAeronave);
//                aeronave->nomeAeronave = NULL;
//                lerNomeAeronave(aeronave);
                break;
            case 3: //< CPF
//                free(aeronave->cpf);
//                aeronave->cpf = NULL;
//                lerCpf(aeronave);
                break;
            case 4: //< Categoria
//                lerCategoria(aeronave);
                break;
            default:
                break;
        }
        if (escolha >= 1 && escolha <= 4) {
            escolha = 0;
            printf("Aeronave alterado com sucesso!\n");
        }
    } while (escolha != 0 && (escolha = escolhaAlterarAeronave()));

    printf("\nAeronave Alterado: \n");
    printf("\t%s\n", str = aeronaveToString(aeronave));
    free(str);
    Pause();
}

char escolhaAlterarAeronave() {
    char escolha[3];

    telaAlterarAeronave();
    printf("\n");
    printf("Opcao: ");
    fflush(stdin);
    fgets(escolha, 2, stdin);

    if (!isdigit(escolha[0])) return -1;

    return (char) (escolha[0] - '0');
}

void telaAlterarAeronave() {
    ClearScreen();

    printf("Menu Alterar Novo Aeronave:\n\n");

    printf("Selecione o campo a ser alterado:\n\n");

    printf("1) Nome do Programa\t2) Nome do Aeronave\n");
    printf("3) CPF\t\t\t4) Categoria\n");

    printf("\n");
    printf("0) Cancelar alteracao\n");
}
