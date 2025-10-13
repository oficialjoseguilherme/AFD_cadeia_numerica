#include <stdlib.h>
#include <stdio.h>
#include "../include/analisador_lexico.h"


void imprimir_lexema(Cadeia cadeia, Analise analise) {
    for (int i = 0; i < analise.tamanho; i++) {
        printf("%c", cadeia.str[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {

    Cadeia cadeia = {
        argv[1],
        4
    };
    Analise analise = analisador_lexico(cadeia);

    imprimir_lexema(cadeia, analise);
    return 0;
}
