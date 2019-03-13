#include <stdio.h>
#include <stdlib.h>
#include "core Headers/Aeroporto.h"
#include "core Headers/Aeronave.h"
#include "input/string.h"


int main() {
    char *read;

    Aeroporto *aeroporto = createAeroporto("aeroporto de teste 1", "aer");
    read = readAeroporto(aeroporto);
    printf("%s\n", read);
    free(read);

    updateAeroporto(aeroporto, "teste aeroporto 2", "nome");
    read = readAeroporto(aeroporto);
    printf("%s\n", read);
    free(read);

    updateAeroporto(aeroporto, "teste aeroporto 2", "sigla");
    read = readAeroporto(aeroporto);
    printf("%s\n", read);
    free(read);

    updateAeroporto(aeroporto, "123", "sigla");
    read = readAeroporto(aeroporto);
    printf("%s\n", read);
    free(read);

    deleteAeroporto(&aeroporto);
    printf("%d\n", aeroporto);


    Aeronave *aeronave = createAeronave("teste de aeronave 1", "aer");
    read = readAeronave(aeronave);
    printf("%s\n", read);
    free(read);

    updateAeronave(aeronave, "aeronave de teste 2", "tipo");
    read = readAeronave(aeronave);
    printf("%s\n", read);
    free(read);

    updateAeronave(aeronave, "aeronave de teste 2", "prefixo");
    read = readAeronave(aeronave);
    printf("%s\n", read);
    free(read);

    updateAeronave(aeronave, "123", "prefixo");
    read = readAeronave(aeronave);
    printf("%s\n", read);
    free(read);

    deleteAeronave(&aeronave);
    printf("%d", aeronave);


    return 0;
}