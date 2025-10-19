#include <stdlib.h>
#include <stdio.h>
#include "../include/analisador_lexico.h"
#include "../include/aceite.h"
#include "../include/analise.h"
#include "../include/cadeia.h"

void imprimir_lexema(Cadeia cadeia, Analise analise) {
    if (analise.aceite == NAO_ACEITO) {
        printf("Lexema não encontrado.");
        return;
    }

    printf("Lexema encontrado: '");
    for (int i = analise.posicao_inicio; i < analise.avanco; i++) {
        printf("%c", cadeia.str[i]);
    }
    printf("'\n");
}

Cadeia ler_cadeia(const char *titulo_leitura, const int chars_quantity);
int length_until_end(const char *str);
char *copy_string(const char *str, int length);

int main(int argc, char *argv[]) {

    const char *titulo_leitura = "Digite a entrada para o autômato: ";
    const int chars_quantity = 100;

    Cadeia cadeia = ler_cadeia(titulo_leitura, chars_quantity);
    
    Analise analise = analisador_lexico(cadeia);

    imprimir_lexema(cadeia, analise);
    return 0;
}

char *ler(const char *titulo_leitura, const int chars_quantity) {
    const int CHARS_QUANTITY = chars_quantity;
    const size_t MAX_STR_SIZE = sizeof(int) * CHARS_QUANTITY;
    char *str = (char *)malloc(MAX_STR_SIZE);

    if (!str) {
        return NULL;
    }

    printf("%s", titulo_leitura);

    fgets(str, MAX_STR_SIZE, stdin);

    return str;
}

Cadeia configurar_cadeia(const char *raw_str) {
    int length = length_until_end(raw_str);

    char *new_string = copy_string(raw_str, length);

    Cadeia cadeia = {
        new_string,
        length
    };

    return cadeia;

}

Cadeia ler_cadeia(const char *titulo_leitura, const int chars_quantity) {
    char *raw_str = ler(titulo_leitura, chars_quantity);
    
    Cadeia cadeia = configurar_cadeia(raw_str);
    
    return cadeia;
}

int length_until_end(const char *str) {
    int i = 0;
    char ch = str[i];

    while (ch != '\n' && ch != '\0') {
        i++;
        ch = str[i];
    }

    return i;
}

char *copy_string(const char *str, int length) {
    char *new_string = (char *)malloc(sizeof(length * 1));
    
    if (!new_string) {
        return NULL;
    }

    for (int i = 0; i < length; i++) {
        new_string[i] = str[i];
    }

    return new_string;
}