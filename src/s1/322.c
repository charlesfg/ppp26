#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int n1, n2;
    int mdc = 0;
    int r = 0;
    // bigger / smaller
    int b, s;

    srand(time(NULL));
    // To avoid user input
    // Limiting the number between 0 and 99
    n1 = rand() % 100;
    n2 = rand() % 100;

    printf("Calcula o MDC entre '%d' e '%d'", n1, n2);

    if (n1 > n2) {
        b = n1;
        s = n2;
    } else {
        b = n2;
        s = n1;
    }

    do {
        // o dividendo pelo divisor
        r = b % s;
        if (r > 0) {
            mdc = r;
        }
        b = s;
        s = r;

    } while (r > 0);

    printf("O o MDC entre '%d' e '%d' é %d\n", n1, n2, mdc);
}