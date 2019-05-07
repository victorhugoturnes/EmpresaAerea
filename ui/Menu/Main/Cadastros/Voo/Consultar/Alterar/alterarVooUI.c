//
// Created by Jedson on 5/2/2019.
//

#include "alterarVooUI.h"

void alterarVoo(VooInfo *voo) {
    char escolha = 0, *str;

    getchar();

    escolha = escolhaAlterarVoo();
    do {
        switch (escolha) {
            case 1: //< prefixo
                free(voo->prefixo);
                voo->prefixo = NULL;
                while (!lerPrefixoVoo(voo)) {
                    ClearScreen();
                }
                break;
            case 2: //< origem
                voo->origem = NULL;
                while (!lerOrigemVoo(voo)) {
                    ClearScreen();
                }
                break;
            case 3: //< destino
                voo->destino = NULL;
                while (!lerDestinoVoo(voo)) {
                    ClearScreen();
                }
                break;
            case 4: //< partida
                deleteHora(&voo->partida);
                voo->partida = NULL;
                while (!lerPartidaVoo(voo)) {
                    ClearScreen();
                }
                break;
            case 5: //< chegada
                deleteHora(&voo->chegada);
                voo->chegada = NULL;
                while (!lerChegadaVoo(voo)) {
                    ClearScreen();
                }
                break;
            case 6: //< duração
                deleteHora(&voo->duracao);
                voo->duracao = NULL;
                while (!lerDuracaoVoo(voo)) {
                    ClearScreen();
                }
                break;
            case 7: //< aeronave
                voo->aeronave = NULL;
                while (!lerModeloAeronaveVoo(voo)) {
                    ClearScreen();
                }
                break;
            default:
                break;
        }
        if (escolha >= 1 && escolha <= 7) {
            escolha = 0;
            printf("Voo alterado com sucesso!\n");
        }
    } while (escolha != 0 && (escolha = escolhaAlterarVoo()));

    printf("\nVoo Alterado:\n");
    printf("%s\n", str = vooInfoToString(voo));
    free(str);
    Pause();
}

char escolhaAlterarVoo() {
    char escolha[16];

    telaAlterarVoo();
    printf("\n");
    printf("Opcao: ");
    fflush(stdin);
    fgets(escolha, 16, stdin);
    getchar();

    if (!isdigit(escolha[0])) return -1;

    return (char) strtol(escolha, NULL, 10);
}

void telaAlterarVoo() {
    ClearScreen();

    printf("Menu Alterar Voo:\n\n");

    printf("Selecione o campo a ser alterado:\n\n");

    printf("1) Prefixo\t2) Comprimento\n");
    printf("3) Altura\t4) Envergadura\n");

    printf("\n");
    printf("0) Cancelar alteracao\n");
}
