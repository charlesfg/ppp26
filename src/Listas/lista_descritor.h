#ifndef LISTA_DESCRITOR_H
#define LISTA_DESCRITOR_H

/* No da lista com descritor. */
typedef struct ld_no {
    int valor;
    struct ld_no *prox;
} ld_no;

/* Descritor guarda inicio, fim e tamanho para operacoes mais eficientes. */
typedef struct {
    ld_no *inicio;
    ld_no *fim;
    int tamanho;
} lista_descritor;

void ld_criar(lista_descritor *lista);
int ld_vazia(const lista_descritor *lista);
int ld_inserir_inicio(lista_descritor *lista, int valor);
int ld_inserir_fim(lista_descritor *lista, int valor);
int ld_inserir_ordenado(lista_descritor *lista, int valor);
int ld_remover_inicio(lista_descritor *lista, int *valor_removido);
int ld_buscar(const lista_descritor *lista, int valor);
int ld_tamanho(const lista_descritor *lista);
void ld_imprimir(const lista_descritor *lista);
void ld_limpar(lista_descritor *lista);

#endif
