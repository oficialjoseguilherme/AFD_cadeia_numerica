#ifndef ANALISADOR_LEXICO_H_
#define ANALISADOR_LEXICO_H_

typedef enum _Aceite_ Aceite;

typedef struct _Analise_ Analise;

typedef struct _Cadeia_ Cadeia;

Analise analisador_lexico(Cadeia cadeia);
Analise analise_lexica(Cadeia cadeia);
Analise fluxo_lexico(Cadeia cadeia);
int aceita_digito_numerico(char c);

#endif