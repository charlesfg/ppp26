#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void create (struct queue *p) {
    p->inicio = NULL;
    p->fim = NULL;
}

int empty(const struct queue *p) {
    return p->inicio == NULL;
}

void clean(struct queue *p) {
    while (p->inicio) {
        struct queue_node * tmp = p->inicio;
        p->inicio = p->inicio->prox;
        free(tmp);
    }
    p->fim = NULL;
}

int insert(struct queue * p, struct person per) {
    struct queue_node * pnew = malloc(sizeof(struct queue_node));
    if (pnew != NULL) {
        pnew->per = per;
        pnew->prox = NULL;
        if(empty(p)) p->inicio = pnew;
        else p->fim->prox = pnew;
        p->fim = pnew;
    }
    return pnew != NULL;
}

struct person delete(struct queue *p) {
    if (p->inicio == NULL)
        return (struct person) {"", -1};
    struct person reply = p->inicio->per;
    struct queue_node *tmp = p->inicio;
    p->inicio = p->inicio->prox;
    if (empty(p)) p->fim = NULL;
    free(tmp);
    return reply;
}

void print_person(struct person p) {
    printf("%s is %d years old\n", p.name, p.age);
};

void print_queue(struct queue * p) {
    struct queue_node *q = p->inicio;
    while (q != NULL) {
        print_person(q->per);
        q = q->prox;
    }
}

int size(const struct queue *p) {
    int count = 0;
    struct queue_node *q = p->inicio;
    while (q) {
        count++;
        q = q->prox;
    }
    return count;
}
