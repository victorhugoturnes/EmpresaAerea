#ifndef AEROPORTO_H
#define AEROPORTO_H

typedef struct aeroporto {
    char *nome;
    char *sigla;
} Aeroporto;

/*
    Nome da Funcao : createAeronave
    Recebe como parametro um ponteiro de char contendo a sigle e outro contendo o nome
    Objetivo : Criar aeroporto com modelo passado
    Retorno : Aeroporto criado
 */
Aeroporto *createAeroporto(char *sigla, char *nome);

/*
    Nome da Funcao : aeroportoToString
    Recebe como parametro um ponteiro de Aeroporto
    Objetivo : ler e criar uma string contendo informacoes do aeroporto
    Returno : devolver string dizendo quais as informacoes do aeroporto
 */
char *aeroportoToString(Aeroporto *aeroporto);

/*
    Nome da Funcao : updateAeroporto
    Recebe como parametro um ponteiro de Aeroporto, um ponteiro de void e um ponteiro de char com novo modelo
    Objetivo : atualizar o modelo do Aeroporto
    Retorno : Nada
 */
void updateAeroporto(Aeroporto *aeroporto, void *update, char *field);

/*
    Nome da Funcao : deleteAeroporto
    Recebe como parametro um ponteiro de ponteiro de Aeroporto
    Objetivo : Limpar memoria q esta sendo usada para alocar Aeroporto
    Retorno : Nada
 */
void deleteAeroporto(Aeroporto **aeroporto);

#endif //AEROPORTO_H
