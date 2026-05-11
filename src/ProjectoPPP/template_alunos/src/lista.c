#include "lista.h"

#include <stdio.h>

struct list_node* create(void) {
    /* TODO(aluno): criar nó cabeça/sentinela para simplificar inserções e remoções. */
    printf("Ainda não implementado: create\n");
    return NULL;
}

int empty(struct list_node* list) {
    /* TODO(aluno): verificar se a lista não possui nós de dados. */
    printf("Ainda não implementado: empty\n");
    (void)list;
    return 1;
}

struct list_node* clean(struct list_node* list) {
    /* TODO(aluno): libertar todos os nós e devolver NULL. */
    printf("Ainda não implementado: clean\n");
    (void)list;
    return NULL;
}

void search(struct list_node* list, char* key, struct list_node** previous, struct list_node** current) {
    /* TODO(aluno): procurar posição pela chave para suportar insert/delete ordenados. */
    printf("Ainda não implementado: search\n");
    (void)list;
    (void)key;
    if (previous != NULL) {
        *previous = NULL;
    }
    if (current != NULL) {
        *current = NULL;
    }
}

void delete(struct list_node* list, char* key) {
    /* TODO(aluno): remover nó da chave se existir e ajustar ligações. */
    printf("Ainda não implementado: delete\n");
    (void)list;
    (void)key;
}

void insert(struct list_node* list, struct person p1) {
    /* TODO(aluno): inserir pessoa mantendo ordenação por nome. */
    printf("Ainda não implementado: insert\n");
    (void)list;
    (void)p1;
}

void print_person(struct person p) {
    /* TODO(aluno): apresentar pessoa de forma legível no terminal. */
    printf("Ainda não implementado: print_person (%s, %d)\n", p.name, p.age);
}

void print(struct list_node* list) {
    /* TODO(aluno): percorrer lista e chamar print_person para cada nó. */
    printf("Ainda não implementado: print\n");
    (void)list;
}
