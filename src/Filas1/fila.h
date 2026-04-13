#ifndef FILA_H
#define FILA_H

#define MAX_NAME 100

struct person {
    char name[MAX_NAME];
    int age;
};

struct queue_node {
    struct person per;
    struct queue_node * prox;
};

struct queue {
    struct queue_node *inicio;
    struct queue_node *fim;
};

void create (struct queue *p);

int empty(const struct queue *p);

void clean(struct queue *p);

int insert(struct queue *p, struct person per);

struct person delete(struct queue *p);

void print_person(struct person p);

void print_queue(struct queue * p);

int size(const struct queue * p);

#endif
