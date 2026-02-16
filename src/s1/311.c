/*
Escreva um programa que calcule a
soma de todos os números desde 1 até um
dado limite pedido ao utilizador
*/
#include <stdio.h>

int main() {
    int valor;
    int vfinal = 0;
    printf("Insira um Valor:\n");
    scanf("%d", &valor);

    for (int i = 1; i <= valor; i++) {
        vfinal += i;
    }

    i = 1;

    do {
        vfinal += i;
        i++;
        while (i <= valor)
    }

    printf("Valor final %d\n", vfinal);

    return 0;
}