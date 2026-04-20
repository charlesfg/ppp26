#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
// Elemento quer será armazenado internamente em cada nó
struct person {
    char name[MAX];
    int age;
};

// Nó da Lista
struct list_node {
    struct person per;
    struct list_node* next;
};

/**

// Formas de Representar de a list

// 1. Ponteiro para o primeiro elemento (não existe cabeçalho)
// create(só aponta list para NULL)
typedef struct list_node* list;

// 2. Ponteiro para o cabeçalho (dummy node)
// create(cria um nó dummy e aponta `list` para ele)
typedef struct list_node* list;
// A representação da Lista

// 3. Estrutura
typedef struct {
    struct list_node* inicio;
    struct list_node* fim;
    int size;
    // o que mais quiser
} list;

*
 */

struct list_node* create(void) {
    struct list_node* aux;
    // Create header node
    struct person p1 = {"", 0};
    aux = (struct list_node*)malloc(sizeof(struct list_node));
    if (aux != NULL) {
        aux->per = p1;
        aux->next = NULL;
    }
    return aux;
}

int empty(struct list_node* lista) {
    return lista->next == NULL;
}

// Assumes the list is sorted by name
void search(struct list_node* list, char* key,
            struct list_node** previous,
            struct list_node** current) {
    *previous = list;
    *current = list->next;
    while ((*current) != NULL && strcmp((*current)->per.name, key) < 0) {
        *previous = *current;
        *current = (*current)->next;
    }
}

// VAR -> (usar semantica de referencia ) -> &VAR
// VAR = &(int *) == int**

// Assumes the list is sorted by name and cannot handle duplicate names
void insert(struct list_node* list, struct person p1) {
    // A inserção é feita ordenada
    struct list_node *node, *previous, *useless;

    // criar o nó e colocar o elemento lá
    node = (struct list_node*)malloc(sizeof(struct list_node));
    if (node != NULL) {
        node->per = p1;
        search(list, p1.name, &previous, &useless);
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

    struct person a = {"Jão", 15};
    insert(lista, a);

    printf("A lista está vazia? %d\n", empty(lista));
}
