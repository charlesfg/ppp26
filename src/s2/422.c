#include <stdio.h>

int perm(int n, int k) {
    int p = 1;
    for (int i = n; i >= n - k + 1; i--) {
        p *= i;
    }
    return p;
}

int perm2(int n, int k) {
    if (n > n - k + 1)
        return 1;
    return n * perm2(n - 1, k);
}

int main() {
    int n, k;
    printf("Insira um numero:");
    scanf("%d", &n);
    printf("Insira um numero menor que %d:", n);
    scanf("%d", &k);

    if (k >= n) {
        printf("Error!");
        return 1;
    }

    printf("Iterativo: permutação de  (%d,%d) é  %d\n", n, k, perm(n, k));
    printf("Recursivo: permutação de  (%d,%d) é  %d\n", n, k, perm2(n, k));

    return 0;
}
