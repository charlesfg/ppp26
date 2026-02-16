/*
Construa um programa que determine o menor número de notas e de moedas a
devolver de troco para uma compra inferior a 100 euros
*/
#include <stdio.h>

int main() {
    float valor = 0;

    printf("Insira um Valor:\n");
    scanf("%f", &valor);
    if (valor >= 100.0) {
        printf("Valor precisa ser inferior a 100 euros\n");
        return -1;
    }
    printf("Calculando o menor numerário para %.2f euros!\n", valor);
    return 0;
}