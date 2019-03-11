#include <stdio.h>
#include "core/core.h"
#include "input/string.h"
int main() {
    aeroporto aeroporto1;
    aeroporto1.nome = readString();
    printf("%s\n", aeroporto1.nome);
    printf("Hello, World!\n");
    return 0;
}