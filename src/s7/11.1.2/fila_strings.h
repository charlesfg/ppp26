#ifndef FILA_H
#define FILA_H

#define MAX_STR 100

#define EMPTY_QUEUE_ERR "__EMPTY__QUEUE__ERR___"

struct queue_node {
    char str[MAX_STR];
    struct queue_node* prox;
};

struct queue {
    struct queue_node* inicio;
    struct queue_node* fim;
};

void create(struct queue* p);

int empty(const struct queue* p);

void clean(struct queue* p);

int insert(struct queue* p, char* e);

char* delete (struct queue* p);

void print_queue(struct queue* p);

int size(const struct queue* p);

#endif
