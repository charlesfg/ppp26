#include "fila.h"

#include <stdio.h>
#include <stdlib.h>

void create(struct queue* p) {
    p->inicio = NULL;
    p->fim = NULL;
}

int empty(const struct queue* p) {
    return p->inicio == NULL;
}

void clean(struct queue* p) {
    while (p->inicio) {
        struct queue_node* tmp = p->inicio;
        p->inicio = p->inicio->prox;
        free(tmp);
    }
    p->fim = NULL;
}

int insert(struct queue* p, double e) {
    struct queue_node* pnew = malloc(sizeof(struct queue_node));
    if (pnew != NULL) {
        pnew->e = e;
        pnew->prox = NULL;
        if (empty(p))
            p->inicio = pnew;
        else
            p->fim->prox = pnew;
        p->fim = pnew;
    }
    return pnew != NULL;
}

double delete(struct queue* p) {
    if (p->inicio == NULL)
        return -1;
    double reply = p->inicio->e;
    struct queue_node* tmp = p->inicio;
    p->inicio = p->inicio->prox;
    if (empty(p)) p->fim = NULL;
    free(tmp);
    return reply;
}

void print_queue(struct queue* p) {
    struct queue_node* q = p->inicio;
    while (q != NULL) {
        printf("%f", q->e);
        q = q->prox;
    }
}

int size(const struct queue* p) {
    int count = 0;
    struct queue_node* q = p->inicio;
    while (q) {
        count++;
        q = q->prox;
    }
    return count;
}
