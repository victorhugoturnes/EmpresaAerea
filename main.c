#include <stdio.h>
#include <stdlib.h>
#include "core/Aeroporto.h"
#include "input/string.h"


int main() {
    Aeroporto *aeroporto = createAeroporto("aeroporto1", "aer");
    char *read = readAeroporto(aeroporto);
    printf("%s\n", read);
    free(read);
    updateAeroporto(aeroporto, "aerporto34", "nome");
    read = readAeroporto(aeroporto);
    updateAeroporto(aeroporto, "aerporto34", "sigla");
    printf("%s\n", read);
    free(read);
    updateAeroporto(aeroporto, "123", "sigla");
    read = readAeroporto(aeroporto);
    printf("%s\n", read);
    free(read);
    deleteAeroporto(&aeroporto);
    printf("%d", aeroporto);
    return 0;
}