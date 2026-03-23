#include <stdio.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} data;

data init_data(int dia, int mes, int ano) {
    return (data){dia, mes, ano};
}

int main() {
    data v1[5];
    v1[0] = init_data(4, 5, 2040);
    
    printf("bla");
}