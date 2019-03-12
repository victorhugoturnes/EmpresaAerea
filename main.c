#include <stdio.h>
#include "core/Aeroporto.h"
#include "input/string.h"
int main() {
    Aeroporto *aeroporto = createAeroporto("aeroporto1", "aer");
    printf("%s\n", readAeroport(aeroporto));
    return 0;
}