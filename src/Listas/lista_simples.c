#include <stdio.h>
#include <stdlib.h>
#include "lista_simples.h"

/* Inicializa a lista vazia. Sem isso, os ponteiros podem ficar com lixo. */
void ls_criar(lista_simples *lista) {
    lista->inicio = NULL;
}

/* Retorna 1 quando a lista nao tem elementos, 0 caso contrario. */
int ls_vazia(const lista_simples *lista) {
    return lista->inicio == NULL;
}

/* Insere no inicio em O(1): novo no passa a ser o primeiro da lista. */
int ls_inserir_inicio(lista_simples *lista, int valor) {
    ls_no *novo = (ls_no *)malloc(sizeof(ls_no));
    if (novo == NULL) {
        return 0;
    }

    novo->valor = valor;
    novo->prox = lista->inicio;
    lista->inicio = novo;
    return 1;
}

/* Insere no fim percorrendo ate o ultimo no. Bom para treinar manipulacao de ponteiros. */
int ls_inserir_fim(lista_simples *lista, int valor) {
    ls_no *novo = (ls_no *)malloc(sizeof(ls_no));
    if (novo == NULL) {
        return 0;
    }

    novo->valor = valor;
    novo->prox = NULL;

    if (ls_vazia(lista)) {
        lista->inicio = novo;
        return 1;
    }

    ls_no *atual = lista->inicio;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    atual->prox = novo;
    return 1;
}

/* Insere mantendo ordem crescente. Casos de borda: lista vazia e insercao no inicio. */
int ls_inserir_ordenado(lista_simples *lista, int valor) {
    ls_no *novo = (ls_no *)malloc(sizeof(ls_no));
    if (novo == NULL) {
        return 0;
    }

    novo->valor = valor;
    novo->prox = NULL;

    if (ls_vazia(lista) || valor < lista->inicio->valor) {
        novo->prox = lista->inicio;
        lista->inicio = novo;
        return 1;
    }

    ls_no *anterior = lista->inicio;
    ls_no *atual = lista->inicio->prox;

    while (atual != NULL && atual->valor <= valor) {
        anterior = atual;
        atual = atual->prox;
    }

    novo->prox = atual;
    anterior->prox = novo;
    return 1;
}

/* Remove o primeiro elemento. Importante retornar falha se a lista estiver vazia. */
int ls_remover_inicio(lista_simples *lista, int *valor_removido) {
    if (ls_vazia(lista)) {
        return 0;
    }

    ls_no *removido = lista->inicio;
    lista->inicio = removido->prox;

    if (valor_removido != NULL) {
        *valor_removido = removido->valor;
    }

    free(removido);
    return 1;
}

/* Busca linear: percorre no a no ate encontrar o valor desejado. */
int ls_buscar(const lista_simples *lista, int valor) {
    ls_no *atual = lista->inicio;
    while (atual != NULL) {
        if (atual->valor == valor) {
            return 1;
        }
        atual = atual->prox;
    }
    return 0;
}

/* Conta elementos por percurso. Ajuda alunos a entender custo O(n). */
int ls_tamanho(const lista_simples *lista) {
    int count = 0;
    ls_no *atual = lista->inicio;
    while (atual != NULL) {
        count++;
        atual = atual->prox;
    }
    return count;
}

/* Mostra conteudo da lista em formato simples para depuracao visual. */
void ls_imprimir(const lista_simples *lista) {
    ls_no *atual = lista->inicio;
    printf("[ ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("]\n");
}

/* Libera toda a memoria alocada para evitar vazamentos. */
void ls_limpar(lista_simples *lista) {
    ls_no *atual = lista->inicio;
    while (atual != NULL) {
        ls_no *proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    lista->inicio = NULL;
}
