#ifndef FILA_H
#define FILA_H

struct queue_node_double {
    double e;
    struct queue_node* prox;
};

struct queue_node_int {
    int e;
    struct queue_node* prox;
};

struct queue_node {
    double e;
    struct queue_node* prox;
};

struct queue {
    struct queue_node* inicio;
    struct queue_node* fim;
};

struct queue_int {
    struct queue_node_int* inicio;
    struct queue_node_int* fim;
};


void create(struct queue* p);

int empty(const struct queue* p);

void clean(struct queue* p);

int insert(struct queue* p, double e);

double delete (struct queue* p);

void print_queue(struct queue* p);

int size(const struct queue* p);

#endif
