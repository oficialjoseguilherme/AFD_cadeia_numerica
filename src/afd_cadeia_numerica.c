#include "../include/analisador_lexico.h"
#include "../include/aceite.h"
#include "../include/analise.h"
#include "../include/cadeia.h"

typedef enum _Estado_ {
    LEITURA_ANTERIOR,
    ESTADO_0,
    ESTADO_1,
    ESTADO_2,
    ESTADO_3,
    ESTADO_4,
    ESTADO_5,
    ERRO
} Estado;


int aceita_digito_numerico(char c) {
    return c >= '0' && c <= '9';
}
int eh_fim_de_entrada(char c) {
    return c == '\0';
}

Analise fluxo_lexico(Cadeia cadeia) {
    Analise analise = {
        0,
        0,
        NAO_ACEITO
    };

    char *entrada = cadeia.str;

    int avanco = analise.avanco;
    int posicao_inicio = -1;
    int cabecote = 0;
    int caractere = entrada[cabecote];

    Estado estado = LEITURA_ANTERIOR;
    while (estado >= LEITURA_ANTERIOR && estado <= ESTADO_4) {
        if (estado == LEITURA_ANTERIOR) cabecote++;

        while (estado >= 0 && estado <= 4) {
            switch (estado) {
                case ESTADO_0:
                    if (caractere == '-') {
                        avanco++;
                        posicao_inicio = cabecote;
                        estado = 1;
                    }
                    else if (aceita_digito_numerico(caractere)) {
                        avanco++;
                        posicao_inicio = cabecote;
                        estado = 2;
                    }
                    else {
                        estado = 6;
                    }
                case ESTADO_1:
                    if (aceita_digito_numerico(caractere)) {
                        avanco++;
                        estado = 2;
                    }
                    else {
                        avanco--;
                        posicao_inicio = -1;
                        estado = 6;
                    }
                case ESTADO_2:
                    if (aceita_digito_numerico(caractere)) {
                        avanco++;
                    }
                    else if (caractere == ',') {
                        avanco++;
                        estado = 3;
                    }
                    else {
                        estado = 5;
                    }
                case ESTADO_3:
                    if (aceita_digito_numerico(caractere)) {
                        avanco++;
                        estado = 4;
                    }
                    else {
                        avanco--;
                        posicao_inicio = cabecote;
                        estado = 5;
                    }
                case ESTADO_4:
                    if (aceita_digito_numerico(caractere)) {
                        avanco++;
                    }
                    else {
                        estado = 5;
                    }
            }
            cabecote++;
            caractere = entrada[cabecote];
        }

        caractere = entrada[cabecote];
    }

    analise.avanco = avanco;
    analise.posicao_inicio = posicao_inicio;
    if (estado == 5) {
        analise.aceite = ACEITO;
        return analise;
    }
    
    analise.aceite = NAO_ACEITO;

    return analise;
}

Analise analise_lexica(Cadeia cadeia) {
    return fluxo_lexico(cadeia);
}

Analise analisador_lexico(Cadeia cadeia) {
    return analise_lexica(cadeia);  
}