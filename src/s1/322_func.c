#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// int mdc(int b, int s);

int mdc(int b, int s) {
    int v_mdc = 0;
    int r = 0;

    do {
        // o dividendo pelo divisor
        r = b % s;
        if (r > 0) {
            v_mdc = r;
        }
        b = s;
        s = r;

    } while (r > 0);

    return v_mdc;
}

int main() {
    int n1, n2;
    int v_mdc = 0;

    srand(time(NULL));
    // To avoid user input
    // Limiting the number between 0 and 99
    n1 = rand() % 100;
    n2 = rand() % 100;

    printf("Calcula o MDC entre '%d' e '%d'", n1, n2);

    if (n1 > n2) {
        v_mdc = mdc(n1, n2);

    } else {
        v_mdc = mdc(n2, n1);
    }

    printf("O o MDC entre '%d' e '%d' é %d\n", n1, n2, v_mdc);
}
