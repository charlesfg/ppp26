#include <errno.h>
#include <stdio.h>

int main() {
    // Abro o arquivo
    FILE* f = fopen("testasde.txt", "r");

    if (!f) {
        printf("> Deu pau! %d", errno);
    }

    // Escrever Hello World nele
    fprintf(f, "Hello World 2\n");

    fclose(f);

    return 0;
}