#include <stdio.h>

/*
 Construa uma função que substitua, num vetor de inteiros dado, todos os números
ímpares pelo seu dobro
*/

void sub_impar(int v[], int n) {
    for (int i = 0; i < n; i++) {
        // v[i] % 2 != 0 ? v[i] = 2 * v[i] : v[i];
        // ;
        //
        if (v[i] % 2 != 0) {
            v[i] = 2 * v[i];
        }
    }
}

void imprime_vect(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%4d", v[i]);
    }
    printf("\n");
}

int main() {
    printf("Exercicio 511.c\n");
    int vec[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int s = sizeof(vec) / sizeof(int);
    sub_impar(vec, s);
    imprime_vect(vec, s);
    return 0;
}