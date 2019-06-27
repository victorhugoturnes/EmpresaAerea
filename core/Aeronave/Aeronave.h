#ifndef AERONAVE_H
#define AERONAVE_H

#define MAX_MODELO_LENGTH 64

typedef struct aeronave {
    char *modelo;
    double comprimento, altura, envergadura, velocidadeCruzeiro, alcanceMaximo;
    int qntAcentos, qntBanheiros;
} Aeronave;


/*
    Nome da Funcao : createAeronave
    Recebe como parametro um ponteiro de char contendo modelo da aeronave
    Objetivo : Criar aeronave com modelo passado
    Retorno : Aeronave criada
 */
Aeronave *createAeronave();

/*
    Nome da Funcao : aeronaveToString
    Recebe como parametro um ponteiro de Aeronave
    Objetivo : ler e criar uma string contendo qual o modelo da aeronave
    Returno : devolver string dizendo qual o modelo da aeronave
 */
char *aeronaveToString(Aeronave *aeronave);

/*
    Nome da Funcao : updateAeronave
    Recebe como parametro um ponteiro de Aeronave, um ponteiro de void e um ponteiro de char com novo modelo
    Objetivo : atualizar o modelo da aeronave
    Retorno : Nada
 */
void updateAeronave(Aeronave *aeronave, void *update, char *field);

/*
    Nome da Funcao : deleteAeronave
    Recebe como parametro um ponteiro de ponteiro de Aeronave
    Objetivo : Limpar memoria q esta sendo usada para alocar Aeronave]
    Retorno : Nada
 */
void deleteAeronave(Aeronave **aeronave);

#endif //AERONAVE_H
