
/*
Faça uma função que receba uma tabela bidimensional e determine a transposição
da matriz recebida. Mostre a matriz resultante no ecrã recorrendo à função
construída no exercício anterior
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define R 2
#define C 3

void print_matrix(int rows, int cols, const int m[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%4d", m[i][j]);
        printf("\n");
    }
}

void transpose(int rows, int cols,
               const int a[rows][cols],
               int t[cols][rows])  // repare: colunas viram linhas
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            t[j][i] = a[i][j];
        }
    }
}

int main(void) {
    int A[R][C] = {{1, 2, 3}, {4, 5, 6}};
    int T[C][R];

    time_t ini_time = time(NULL);
    srand(ini_time);

    int i, j;

    for (i = 0; i < R; i++) {
        for (j = 0; j < C; j++) {
            T[i][j] = rand() % 1000;
        }
    }

    /*
    Exercício de Debugging

    - Alterar o valor de ini_time para 98765, quando o programa for executar a linha 39
    - Na execução da Linha 59, dizer o valor de T[0][2] e o valor de T[1][1]
    */

    printf("A:\n");
    print_matrix(R, C, A);

    transpose(R, C, A, T);

    printf("\nT = transposta(A):\n");
    print_matrix(C, R, T);

    return 0;
}