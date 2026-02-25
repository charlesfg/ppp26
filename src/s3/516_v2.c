#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINE 10
#define MAX_COLS 10

void print_vector_of_vector_of_int(int** m, int l, int c) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            printf("%4d ", m[i][j]);
        }
        printf("\n");
    }
}

void print_matrix_of_int(int m[MAX_COLS][MAX_LINE]) {
    int i, j;

    for (i = 0; i < MAX_COLS; i++) {
        for (j = 0; j < MAX_LINE; j++) {
            printf("%4d ", m[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int test[MAX_COLS][MAX_LINE];

    srand(time(NULL));

    int i, j;

    for (i = 0; i < MAX_COLS; i++) {
        for (j = 0; j < MAX_LINE; j++) {
            test[i][j] = rand() % 1000;
        }
    }

    print_matrix_of_int(test);

    return 0;
}
