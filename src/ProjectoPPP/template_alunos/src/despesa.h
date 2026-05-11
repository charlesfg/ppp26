#ifndef DESPESA_H
#define DESPESA_H

#include "conf.h"
#include "data.h"

typedef struct Despesa {
    float valor;
    char descricao[MAX_STR];
    Data data;
    struct Despesa* next;
} Despesa;

Despesa* despesa_cria(float valor, const char* descricao, Data data);
void despesa_lista_limpa(Despesa** head);
int despesa_lista_insere_ordenado(Despesa** head, Despesa* nova);

#endif
