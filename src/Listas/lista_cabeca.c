#include <stdio.h>
#include <stdlib.h>
#include "lista_cabeca.h"

/* Inicializa o no cabecalho: ele existe sempre e aponta para o primeiro dado. */
void lc_criar(lista_cabeca *lista) {
    lista->cabeca.valor = 0;
    lista->cabeca.prox = NULL;
}

/* Com no cabecalho, lista vazia significa cabeca->prox == NULL. */
int lc_vazia(const lista_cabeca *lista) {
    return lista->cabeca.prox == NULL;
}

/* Insere apos o cabecalho. Esse padrao simplifica casos de borda no inicio. */
int lc_inserir_inicio(lista_cabeca *lista, int valor) {
    lc_no *novo = (lc_no *)malloc(sizeof(lc_no));
    if (novo == NULL) {
        return 0;
    }

    novo->valor = valor;
    novo->prox = lista->cabeca.prox;
    lista->cabeca.prox = novo;
    return 1;
}

/* Insere no fim percorrendo desde o cabecalho ate o ultimo no de dados. */
int lc_inserir_fim(lista_cabeca *lista, int valor) {
    lc_no *novo = (lc_no *)malloc(sizeof(lc_no));
    if (novo == NULL) {
        return 0;
    }

    novo->valor = valor;
    novo->prox = NULL;

    lc_no *atual = &lista->cabeca;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    atual->prox = novo;
    return 1;
}

/* Insere em ordem crescente sem mover dados, apenas ponteiros entre nos. */
int lc_inserir_ordenado(lista_cabeca *lista, int valor) {
    lc_no *novo = (lc_no *)malloc(sizeof(lc_no));
    if (novo == NULL) {
        return 0;
    }

    novo->valor = valor;
    novo->prox = NULL;

    lc_no *anterior = &lista->cabeca;
    lc_no *atual = lista->cabeca.prox;

    while (atual != NULL && atual->valor <= valor) {
        anterior = atual;
        atual = atual->prox;
    }

    novo->prox = atual;
    anterior->prox = novo;
    return 1;
}

/* Remove o primeiro no de dados (logo apos o cabecalho). */
int lc_remover_inicio(lista_cabeca *lista, int *valor_removido) {
    if (lc_vazia(lista)) {
        return 0;
    }

    lc_no *removido = lista->cabeca.prox;
    lista->cabeca.prox = removido->prox;

    if (valor_removido != NULL) {
        *valor_removido = removido->valor;
    }

    free(removido);
    return 1;
}

/* Busca linear ignorando o no cabecalho, que nao representa um elemento da lista. */
int lc_buscar(const lista_cabeca *lista, int valor) {
    lc_no *atual = lista->cabeca.prox;
    while (atual != NULL) {
        if (atual->valor == valor) {
            return 1;
        }
        atual = atual->prox;
    }
    return 0;
}

/* Conta apenas nos de dados. O cabecalho nunca entra na contagem. */
int lc_tamanho(const lista_cabeca *lista) {
    int count = 0;
    lc_no *atual = lista->cabeca.prox;
    while (atual != NULL) {
        count++;
        atual = atual->prox;
    }
    return count;
}

/* Impressao focada no aluno: mostra somente os valores validos da lista. */
void lc_imprimir(const lista_cabeca *lista) {
    lc_no *atual = lista->cabeca.prox;
    printf("[ ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("]\n");
}

/* Libera os nos de dados; o cabecalho permanece na estrutura da lista. */
void lc_limpar(lista_cabeca *lista) {
    lc_no *atual = lista->cabeca.prox;
    while (atual != NULL) {
        lc_no *proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    lista->cabeca.prox = NULL;
}
