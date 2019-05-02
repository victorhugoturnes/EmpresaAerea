//
// Created by Jedson on 4/30/2019.
//

#include "alterarAeronaveUI.h"

void alterarAeronave(Aeronave *aeronave) {
    char escolha = 0, *str;

    escolha = escolhaAlterarAeronave();
    do {
        switch (escolha) {
            case 1: //< modelo
                free(aeronave->modelo);
                aeronave->modelo = NULL;
                while (!lerModelo(aeronave)) {
                    ClearScreen();
                }
                break;
            case 2: //< comprimento
                aeronave->comprimento = -1;
                while (!lerComprimento(aeronave)) {
                    ClearScreen();
                }
                break;
            case 3: //< altura
                aeronave->altura = -1;
                while (!lerAltura(aeronave)) {
                    ClearScreen();
                }
                break;
            case 4: //< envergadura
                aeronave->envergadura = -1;
                while (!lerEnvergadura(aeronave)) {
                    ClearScreen();
                }
                break;
            case 5: //< velocidadeCruzeiro
                aeronave->velocidadeCruzeiro = -1;
                while (!lerVelocidadeCruzeiro(aeronave)) {
                    ClearScreen();
                }
                break;
            case 6: //< alcanceMaximo
                aeronave->alcanceMaximo = -1;
                while (!lerAlcanceMaximo(aeronave)) {
                    ClearScreen();
                }
                break;
            case 7: //< qntAcentos
                aeronave->qntAcentos = -1;
                while (!lerQntAcentos(aeronave)) {
                    ClearScreen();
                }
                break;
            case 8: //< qntBanheiros
                aeronave->qntBanheiros = -1;
                while (!lerQntBanheiros(aeronave)) {
                    ClearScreen();
                }
                break;
            default:
                break;
        }
        if (escolha >= 1 && escolha <= 8) {
            escolha = 0;
            printf("Aeronave alterada com sucesso!\n");
        }
    } while (escolha != 0 && (escolha = escolhaAlterarAeronave()));

    printf("\nAeronave alterada:\n");
    printf("%s\n", str = aeronaveToString(aeronave));
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

    printf("Menu Alterar Aeronave:\n\n");

    printf("Selecione o campo a ser alterado:\n\n");

    printf("1) Modelo\t2) Comprimento\n");
    printf("3) Altura\t4) Envergadura\n");
    printf("5) Vel Cruzeiro\t6) Alcance Max\n");
    printf("7) Qnt Acentos\t8) Qnt Banheiros\n");

    printf("\n");
    printf("0) Cancelar alteracao\n");
}
