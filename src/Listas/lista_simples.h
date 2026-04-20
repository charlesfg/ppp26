#ifndef LISTA_SIMPLES_H
#define LISTA_SIMPLES_H

/* No da lista simplesmente encadeada. */
typedef struct ls_no {
    int valor;
    struct ls_no *prox;
} ls_no;

/* Estrutura da lista: apenas um ponteiro para o inicio. */
typedef struct {
    ls_no *inicio;
} lista_simples;

void ls_criar(lista_simples *lista);
int ls_vazia(const lista_simples *lista);
int ls_inserir_inicio(lista_simples *lista, int valor);
int ls_inserir_fim(lista_simples *lista, int valor);
int ls_inserir_ordenado(lista_simples *lista, int valor);
int ls_remover_inicio(lista_simples *lista, int *valor_removido);
int ls_buscar(const lista_simples *lista, int valor);
int ls_tamanho(const lista_simples *lista);
void ls_imprimir(const lista_simples *lista);
void ls_limpar(lista_simples *lista);

#endif
