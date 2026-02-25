#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINE 10
#define MAX_COLS 10

void print_matrix_of_int(int m[MAX_LINE][MAX_COLS]) {
    int i, j;

    for (i = 0; i < MAX_LINE; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            printf("%4d ", m[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int test[MAX_COLS][MAX_LINE];

    srand(time(NULL));

    int i, j;

    for (i = 0; i < MAX_LINE; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            test[i][j] = rand() % 1000;
        }
    }

    print_matrix_of_int(test);

    return 0;
}
