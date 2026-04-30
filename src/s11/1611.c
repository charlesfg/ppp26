/*
 * 16.1.1.
 * Faça um programa que receba do utilizador, da linha de comandos,
 * o nome de um ficheiro de texto origem e de um ficheiro de texto
 * destino, devendo copiar o conteúdo do ficheiro origem
 * para o destino.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
./16.1.1 origem.txt destino.txt
*/
int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_file> <dest_file>\n", argv[0]);
        return 1;
    }
    FILE* source_file = fopen(argv[1], "r");
    if (source_file == NULL) {
        printf("Error opening source file: %s\n", argv[1]);
        return 1;
    }
    FILE* dest_file = fopen(argv[2], "w");
    if (dest_file == NULL) {
        printf("Error opening destination file: %s\n", argv[2]);
        return 1;
    }
    char buffer[4096];
    while (fgets(buffer, sizeof(buffer), source_file) != NULL) {
        fputs(buffer, dest_file);
    }
    fclose(source_file);
    fclose(dest_file);
    return 0;
}
