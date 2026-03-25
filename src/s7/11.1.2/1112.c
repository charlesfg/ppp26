#include <stdio.h>
#include <string.h>  // para strdup e strcmp

#include "fila_strings.h"
#define MAX_STR 100

int main() {
    struct queue f;
    char buffer[MAX_STR];

    // inicializa fila
    create(&f);

    printf("Digite strings (FIM para terminar):\n");

    while (1) {
        printf("> ");
        fgets(buffer, MAX_STR, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';  // remove '\n'

        if (strcmp(buffer, "FIM") == 0)
            break;

        insert(&f, buffer);
    }

    printf("\nStrings inseridas na fila:\n");
    print_queue(&f);

    clean(&f);
    return 0;
}
