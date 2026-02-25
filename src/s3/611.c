#include <limits.h>
#include <stdio.h>
#include <strings.h>

// int tamanho_str(char * str){
// }

int tamanho_str2(char str[]) {
    int c = 0;
    while (*str++ != '\0') c++;
    return c;
}

int tamanho_str1(char* str) {
    int c = 0;
    for (int i = 0; str[i] != 0; i++) {
        c++;
    }
    return c;
}

int main() {
    char* a = "Charles";
    printf("strlen - %lu\n", strlen(a));
    printf("minha - %d\n", tamanho_str1(a));
    printf("minha - %d\n", tamanho_str2(a));
    return 0;
}