#ifndef LISTA_CABECA_H
#define LISTA_CABECA_H

/* No da lista com cabecalho. */
typedef struct lc_no {
    int valor;
    struct lc_no *prox;
} lc_no;

/* A lista guarda um no especial (cabecalho) que nao armazena dado valido. */
typedef struct {
    lc_no cabeca;
} lista_cabeca;

void lc_criar(lista_cabeca *lista);
int lc_vazia(const lista_cabeca *lista);
int lc_inserir_inicio(lista_cabeca *lista, int valor);
int lc_inserir_fim(lista_cabeca *lista, int valor);
int lc_inserir_ordenado(lista_cabeca *lista, int valor);
int lc_remover_inicio(lista_cabeca *lista, int *valor_removido);
int lc_buscar(const lista_cabeca *lista, int valor);
int lc_tamanho(const lista_cabeca *lista);
void lc_imprimir(const lista_cabeca *lista);
void lc_limpar(lista_cabeca *lista);

#endif
