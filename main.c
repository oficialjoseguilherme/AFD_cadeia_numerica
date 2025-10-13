#include <stdlib.h>
#include <stdio.h>

typedef struct cadeia {
    char *str;
    int length;
} Cadeia;

typedef struct analise {
    int tamanho;
    int aceite;
} Analise;

Analise analisador_lexico(Cadeia cadeia);
Analise analise_lexica(Cadeia cadeia);
Analise fluxo_lexico(Cadeia cadeia);
int aceita_digito_numerico(char c);

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

Analise analisador_lexico(Cadeia cadeia) {
    return analise_lexica(cadeia);
}

Analise analise_lexica(Cadeia cadeia) {
    Analise analise;

    analise = fluxo_lexico(cadeia);

    return analise;
}

Analise fluxo_lexico(Cadeia cadeia) {
    Analise analise = {
        0,
        0
    };
    
    int aceitou_digito_numerico;
    // Estado 0
    switch (cadeia.str[analise.tamanho]) {
        case '-': // Estado 1
            analise.tamanho++;
            aceitou_digito_numerico = aceita_digito_numerico(cadeia.str[analise.tamanho]);
            if (!aceitou_digito_numerico) {
                return analise; // Parou no estado 1
            }
            analise.tamanho++; // Estado 2
            break;
        default: // Estado 0
            aceitou_digito_numerico = aceita_digito_numerico(cadeia.str[analise.tamanho]);
            if (!aceitou_digito_numerico) { 
                return analise; // Estado 0
            }
            analise.tamanho++; // Estado 2
    }
    analise.aceite = 1; // Estado 2

    while (aceita_digito_numerico(cadeia.str[analise.tamanho])) analise.tamanho++; // Estado 2

    if (cadeia.str[analise.tamanho] != ',') return analise; // Estado 5

    if (!aceita_digito_numerico(cadeia.str[analise.tamanho + 1])) return analise; // Estado 3

    analise.tamanho += 2;

    while (aceita_digito_numerico(cadeia.str[analise.tamanho])) analise.tamanho++;

    return analise;
}

int aceita_digito_numerico(char c) {
    return c >= '0' && c <= '9';
}
