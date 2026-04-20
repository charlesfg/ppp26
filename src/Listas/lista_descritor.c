#include <stdio.h>
#include <stdlib.h>
#include "lista_descritor.h"

/* Inicializa descritor com lista vazia e tamanho zero. */
void ld_criar(lista_descritor *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}

/* A lista esta vazia quando nao existe primeiro elemento. */
int ld_vazia(const lista_descritor *lista) {
    return lista->inicio == NULL;
}

/* Insere no inicio em O(1) e atualiza o descritor para manter consistencia. */
int ld_inserir_inicio(lista_descritor *lista, int valor) {
    ld_no *novo = (ld_no *)malloc(sizeof(ld_no));
    if (novo == NULL) {
        return 0;
    }

    novo->valor = valor;
    novo->prox = lista->inicio;
    lista->inicio = novo;

    if (lista->fim == NULL) {
        lista->fim = novo;
    }

    lista->tamanho++;
    return 1;
}

/* Insere no fim em O(1) usando o ponteiro de fim do descritor. */
int ld_inserir_fim(lista_descritor *lista, int valor) {
    ld_no *novo = (ld_no *)malloc(sizeof(ld_no));
    if (novo == NULL) {
        return 0;
    }

    novo->valor = valor;
    novo->prox = NULL;

    if (ld_vazia(lista)) {
        lista->inicio = novo;
        lista->fim = novo;
    } else {
        lista->fim->prox = novo;
        lista->fim = novo;
    }

    lista->tamanho++;
    return 1;
}

/* Insere em ordem crescente e ajusta inicio/fim/tamanho sem perder encadeamento. */
int ld_inserir_ordenado(lista_descritor *lista, int valor) {
    ld_no *novo = (ld_no *)malloc(sizeof(ld_no));
    if (novo == NULL) {
        return 0;
    }

    novo->valor = valor;
    novo->prox = NULL;

    if (ld_vazia(lista)) {
        lista->inicio = novo;
        lista->fim = novo;
        lista->tamanho++;
        return 1;
    }

    if (valor < lista->inicio->valor) {
        novo->prox = lista->inicio;
        lista->inicio = novo;
        lista->tamanho++;
        return 1;
    }

    ld_no *anterior = lista->inicio;
    ld_no *atual = lista->inicio->prox;

    while (atual != NULL && atual->valor <= valor) {
        anterior = atual;
        atual = atual->prox;
    }

    novo->prox = atual;
    anterior->prox = novo;

    if (atual == NULL) {
        lista->fim = novo;
    }

    lista->tamanho++;
    return 1;
}

/* Remove o primeiro no em O(1). Se lista ficar vazia, fim deve virar NULL. */
int ld_remover_inicio(lista_descritor *lista, int *valor_removido) {
    if (ld_vazia(lista)) {
        return 0;
    }

    ld_no *removido = lista->inicio;
    lista->inicio = removido->prox;

    if (lista->inicio == NULL) {
        lista->fim = NULL;
    }

    if (valor_removido != NULL) {
        *valor_removido = removido->valor;
    }

    free(removido);
    lista->tamanho--;
    return 1;
}

/* Busca linear por valor. */
int ld_buscar(const lista_descritor *lista, int valor) {
    ld_no *atual = lista->inicio;
    while (atual != NULL) {
        if (atual->valor == valor) {
            return 1;
        }
        atual = atual->prox;
    }
    return 0;
}

/* Retorna tamanho em O(1) usando campo do descritor. */
int ld_tamanho(const lista_descritor *lista) {
    return lista->tamanho;
}

/* Impressao para depuracao visual da sequencia de elementos. */
void ld_imprimir(const lista_descritor *lista) {
    ld_no *atual = lista->inicio;
    printf("[ ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("]\n");
}

/* Limpa toda a lista e reconfigura descritor para estado inicial. */
void ld_limpar(lista_descritor *lista) {
    ld_no *atual = lista->inicio;
    while (atual != NULL) {
        ld_no *proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}
