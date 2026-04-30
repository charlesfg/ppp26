#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Nó da Lista
struct list_node {
    double item;
    struct list_node* next;
};

struct list_node* create(void) {
    struct list_node* aux;
    // Create header node
    double m = -1;
    aux = (struct list_node*)malloc(sizeof(struct list_node));
    if (aux != NULL) {
        aux->item = m;
        aux->next = NULL;
    }
    return aux;
}

int empty(struct list_node* lista) {
    return lista->next == NULL;
}

// Assumes the list is sorted by name
void search(struct list_node* list, double key,
            struct list_node** previous,
            struct list_node** current) {
    *previous = list;
    *current = list->next;
    while ((*current) != NULL && (*current)->item < key) {
        *previous = *current;
        *current = (*current)->next;
    }
}

// Assumes the list is sorted by name and cannot handle duplicate names
void insert(struct list_node* list, double item) {
    // A inserção é feita ordenada
    struct list_node *node, *previous, *useless;

    // criar o nó e colocar o elemento lá
    node = (struct list_node*)malloc(sizeof(struct list_node));
    if (node != NULL) {
        node->item = item;
        search(list, item, &previous, &useless);
        node->next = previous->next;
        previous->next = node;
    }
}

int main() {
    // Declarar uma lista
    struct list_node* lista;

    // Inicializar
    lista = create();

    printf("A lista está vazia? %d\n", empty(lista));

    double a = 1.2445;
    insert(lista, a);

        printf("A lista está vazia? %d\n", empty(lista));
}
