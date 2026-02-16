/*
Escreva um programa que
receba um número inteiro
e que indique no ecrã se o
número é par ou ímpar
*/

#include <stdio.h>

int main() {
    int var = 0;
    // ler um número inteiro
    printf("Insira um número inteiro:\n");
    scanf("%d", &var);
    printf("Li o %d!\n",var);
    // testar se é par/impar
    if (var % 2 == 0) {
        printf("Par!\n");
    }
    else
        printf("Impar!\n");
    // prover alguma mensagem
    return 0;
}