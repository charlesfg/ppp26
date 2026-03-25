#include <stdio.h>
#include <stdlib.h>

#include "fila.h"

int main() {
    int n;
    struct queue fila;

    printf("Insira o tamanho de n:\n");
    scanf("%d", &n);

    // criar a fila
    create(&fila);

    for (int i = 0; i < n; i++) {
        double e;
        printf("Insira o elemento %d:\n", i);
        scanf("%lf", &e);
        // inserir na fila
        if (!insert(&fila, e)) {
            fprintf(stderr, "Faiô!\n");
        }
    }

    // imprime a fila
    print_queue(&fila);
}