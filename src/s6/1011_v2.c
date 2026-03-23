#include <stdio.h>
#include <stdlib.h>

/**
 * Le um vetor:
 * v é um parametro de saída
 * n é o tamanho do vetor
 * n tem que ser maior que zero
 */
int le_vetor(int** v, int n) {
    // ve se n é maior que zero
    if (n <= 0) {
        perror("N tem que ser maior que zero");
    }
    // allocar o vetor v
    *v = (int*)malloc(n * sizeof(int));
    // verificar se a alocação deu certo
    if (*v != NULL) {
        // ler os n elementos
        for (int i = 0; i < n; i++) {
            scanf("%d", &(*v[i]));
        }
        // retornar sucesso ou erro
        return 1;
    } else {
        perror("Faiô!");
        return 0;
    }
}

int main() {
    int* v;
    int n = 3;
    if (le_vetor(&v, n)) {
        for (int i = 0; i < n; i++) {
            printf("%d\n", v[i]);
        }
    }
    return 0;
}