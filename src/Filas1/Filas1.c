#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(){

    struct person ps[] = {
        {"Raquel", 21},
        {"Leonardo", 19},
        {"Andre", 40},
        {"Sandra", 38}
    };

    struct queue fila;

    create(&fila);
    for (unsigned int i = 0; i < sizeof(ps) / sizeof(ps[0]); i++) {
        if (!insert(&fila, ps[i])) {
            perror("Cannot insert person in queue");
            return 1;
        }
    }

    printf("Initial queue:\n");
    print_queue(&fila);

    printf("\nDelete():\n");
    struct person  per = delete(&fila);
    if (per.age != -1)
        print_person(per);

    printf("\nQueue Size: %d\n", size(&fila));
    
    printf("\nAfter clean:\n");
    clean(&fila);
    print_queue(&fila);

    return 0;
}