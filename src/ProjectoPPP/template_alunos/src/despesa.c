#include "despesa.h"

#include <stdio.h>

Despesa* despesa_cria(float valor, const char* descricao, Data data) {
    /* TODO(aluno): validar valor/descrição/data e alocar nova despesa. */
    printf("Ainda não implementado: despesa_cria\n");
    (void)valor;
    (void)descricao;
    (void)data;
    return NULL;
}

void despesa_lista_limpa(Despesa** head) {
    /* TODO(aluno): percorrer e libertar todos os nós da lista de despesas. */
    printf("Ainda não implementado: despesa_lista_limpa\n");
    (void)head;
}

int despesa_lista_insere_ordenado(Despesa** head, Despesa* nova) {
    /* TODO(aluno): inserir na ordem desejada (ex.: por data) mantendo encadeamento. */
    printf("Ainda não implementado: despesa_lista_insere_ordenado\n");
    (void)head;
    (void)nova;
    return 1;
}
