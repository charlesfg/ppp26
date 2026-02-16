
/*
Desenvolva um programa que determine a hipotenusa
de um triângulo retângulo dados os valores
dos seus catetos.
*/
#include <math.h>
#include <stdio.h>

int main() {
    float cateto1, cateto2, hipotenusa;

    printf("Digite o valor do primeiro cateto: ");
    scanf("%f", &cateto1);

    printf("Digite o valor do segundo cateto: ");
    scanf("%f", &cateto2);

    hipotenusa = sqrt(cateto1 * cateto1 + cateto2 * cateto2);

    printf("A hipotenusa do triângulo retângulo é: %.2f\n", hipotenusa);

    return 0;
}